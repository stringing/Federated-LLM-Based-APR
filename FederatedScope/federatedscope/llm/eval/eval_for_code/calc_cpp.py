import subprocess
import os, glob
import sys
import uuid


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

cnt = {}
ac = {}
ac5 = {}
bug = 0

res_map = {}


for id in range(10):
    directory_path = f"/root/autodl-tmp/model/{sys.argv[1]}/evalrepair-cpp-res/fixed{id}/"
    if os.path.exists(directory_path) and os.path.isdir(directory_path):
        for file_path in sorted(glob.glob(os.path.join(directory_path, '*.cpp')), reverse=False):
            print(file_path)
            name = file_path.split('/')[-1].split('.')[0]
            ret, detail = test(id, name, sys.argv[1])
            if name not in res_map:
                res_map[name] = [1] * 10
            if ret == 0:
                res_map[name][id] = 0
                ac[name] = ac.get(name, 0) + 1
                if id < 5:
                    ac5[name] = ac5.get(name, 0) + 1

# print(res_map)
print('TOP-10:', len(ac) / 164 * 100, 'TOP-5:', len(ac5) / 164 * 100)
