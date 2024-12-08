from federatedscope.register import register_regularizer
try:
    from torch.nn import Module
    import torch
except ImportError:
    Module = object
    torch = None
import gc

REGULARIZER_NAME = "proximal_regularizer"


class ProximalRegularizer(Module):
    """Returns the norm of the specific weight update.

        Arguments:
            p (int): The order of norm.
            tensor_before: The original matrix or vector
            tensor_after: The updated matrix or vector

        Returns:
            Tensor: the norm of the given udpate.
    """
    def __init__(self):
        super(ProximalRegularizer, self).__init__()

    def forward(self, ctx, p=2):
        norm = 0.
        for w_init, w in zip(ctx.weight_init, ctx.model.parameters()):
            w_cpu = w.cpu()
            w_init_cpu = w_init.cpu()
            norm += torch.pow(torch.norm((w_cpu - w_init_cpu).float(), p), p)
        norm = norm * 1. / float(p)
        # torch.cuda.empty_cache()
        # gc.collect()
        return norm.to(torch.device('cuda:1'))


def call_proximal_regularizer(type):
    if type == REGULARIZER_NAME:
        regularizer = ProximalRegularizer
        return regularizer


register_regularizer(REGULARIZER_NAME, call_proximal_regularizer)
