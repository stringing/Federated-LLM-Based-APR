import subprocess
import os, glob
import sys
import uuid
import multiprocessing

def test(id, name, tag):
    time_limit = 60
    tname = str(uuid.uuid4())
    command = "cat /root/autodl-tmp/model/" + tag + '/evalrepair-cpp-res/fixed' + str(id) + "/" + name + f".cpp /root/morepair-1024/evalrepair-cpp-res/extend-test/{name}.cpp > tmp/{tname}.cpp && g++ --std=c++17 tmp/{tname}.cpp -lcrypto -o tmp/{tname} && timeout %d ./tmp/{tname}" % time_limit
    print(command)
    process = subprocess.Popen(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    stdout, stderr = process.communicate()
    print("Standard Output:", stdout.decode('utf-8', 'ignore'))
    print("Standard Error:", stderr.decode('utf-8', 'ignore'))
    print(process.returncode)
    return [process.returncode, str(stdout) + str(stderr)]

def process_folder(id, tag):
    directory_path = f"/root/autodl-tmp/model/{tag}/evalrepair-cpp-res/fixed{id}/"
    local_ac = {}
    local_ac5 = {}
    local_res_map = {}
    
    if os.path.exists(directory_path) and os.path.isdir(directory_path):
        for file_path in sorted(glob.glob(os.path.join(directory_path, '*.cpp')), reverse=False):
            print(file_path)
            name = file_path.split('/')[-1].split('.')[0]
            ret, detail = test(id, name, tag)
            if name not in local_res_map:
                local_res_map[name] = [1] * 10
            if ret == 0:
                local_res_map[name][id] = 0
                local_ac[name] = local_ac.get(name, 0) + 1
                if id < 5:
                    local_ac5[name] = local_ac5.get(name, 0) + 1

    return local_ac, local_ac5, local_res_map

def main(tag):
    with multiprocessing.Pool(10) as pool:
        results = pool.starmap(process_folder, [(i, tag) for i in range(10)])

    # Combine results from all processes
    combined_ac = {}
    combined_ac5 = {}
    combined_res_map = {}

    for ac, ac5, res_map in results:
        for name in ac:
            if name not in combined_ac:
                combined_ac[name] = 0
            combined_ac[name] += ac[name]
        
        for name in ac5:
            if name not in combined_ac5:
                combined_ac5[name] = 0
            combined_ac5[name] += ac5[name]

        for name in res_map:
            if name not in combined_res_map:
                combined_res_map[name] = [1] * 10
            for idx in range(10):
                combined_res_map[name][idx] = min(combined_res_map[name][idx], res_map[name][idx])

    print('TOP-10:', len(combined_ac) / 164 * 100, 'TOP-5:', len(combined_ac5) / 164 * 100)

if __name__ == '__main__':
    main(sys.argv[1])