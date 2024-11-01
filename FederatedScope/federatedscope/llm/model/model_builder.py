from federatedscope.llm.model.adapter_builder import AdapterModel


def get_model_from_huggingface(model_name, config):
    """
    Load a causal language model from HuggingFace transformers library.

    Args:
        model_name (str): The name of the pre-trained model to load.
        config (Config): The configuration object that contains the model
            parameters.

    Returns:
        AutoModelForCausalLM: A causal language model object.
    """
    from transformers import AutoModelForCausalLM

    kwargs = {}
    if len(config.llm.cache.model):
        kwargs['cache_dir'] = config.llm.cache.model
    
    args = config.llm.adapter.args[0]
    if args.get('adapter_method', 'lora') in ['qlora', 'qlora-pissa']:
        from transformers import BitsAndBytesConfig
        import torch
        bnb_config = BitsAndBytesConfig(
            load_in_4bit=args.pop('load_in_4bit', True),
            bnb_4bit_quant_type=args.pop('bnb_4bit_quant_type', 'nf4'),
            bnb_4bit_compute_dtype=torch.bfloat16 if args.pop('bnb_4bit_compute_dtype', True) else torch.float32,
            bnb_4bit_use_double_quant=args.pop('bnb_4bit_use_double_quant', True),
        )
        kwargs['quantization_config'] = bnb_config
        if args.get('bnb_4bit_compute_dtype', True):
            kwargs['torch_dtype'] = torch.bfloat16
    kwargs['device_map'] = f'cuda:{config.device}'

    return AutoModelForCausalLM.from_pretrained(model_name, **kwargs)


def get_model_from_modelscope(model_name, config):
    """
    Load a causal language model from ModelScope models library.

    Args:
        model_name (str): The name of the pre-trained model to load.
        config (Config): The configuration object that contains the model
            parameters.

    Returns:
        Model: A causal language model object.
    """
    from modelscope import AutoModelForCausalLM

    kwargs = {}
    if len(config.llm.cache.model):
        kwargs['cache_dir'] = config.llm.cache.model

    return AutoModelForCausalLM.from_pretrained(model_name, **kwargs)


def get_llm(config):
    """
    Get a causal language model based on the configuration.

    Args:
        config (Config): The configuration object that contains the model
            parameters.

    Returns:
        AdapterModel: A causal language model object with optional adapter
            layers.
    """
    from federatedscope.llm.dataloader import get_tokenizer

    model_config = config.model
    model_name, model_hub = model_config.type.split('@')
    if model_hub == 'huggingface_llm':
        model = get_model_from_huggingface(model_name=model_name,
                                           config=config)
    elif model_hub == 'modelscope_llm':
        model = get_model_from_modelscope(model_name=model_name, config=config)
    else:
        raise NotImplementedError(f'Not support LLM {model_name} in'
                                  f' {model_hub}.')

    # Resize LLM model based on settings
    tokenizer, num_new_tokens = \
        get_tokenizer(model_name, config.data.root, config.llm.tok_len,
                      model_hub)
    model.resize_token_embeddings(len(tokenizer))
    if num_new_tokens > 0:
        input_embeddings = model.get_input_embeddings().weight.data
        output_embeddings = model.get_output_embeddings().weight.data

        input_embeddings_avg = input_embeddings[:-num_new_tokens].mean(
            dim=0, keepdim=True)
        output_embeddings_avg = output_embeddings[:-num_new_tokens].mean(
            dim=0, keepdim=True)

        input_embeddings[-num_new_tokens:] = input_embeddings_avg
        output_embeddings[-num_new_tokens:] = output_embeddings_avg

    args = config.llm.adapter.args[0] if len(
        config.llm.adapter.args[0]) > 0 else {}
    
    # print('---------------before lora: {}'.format(sum(p.numel() for p in model.parameters())))
    model = AdapterModel(model, use_adapter=config.llm.adapter.use, **args)
    # print('---------------after lora: {}'.format(sum(p.numel() for p in model.parameters())))

    return model
