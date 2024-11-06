#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, l = 0,r = 0;
    string q[105];
    cin >> n;
    while(n--) {
        int k;
        cin >> k;
        if(k == 1){
            string name;
            cin >> name;
            bool flag = 0;
            for(int i = l;i < r;i++) {
                if(q[i][0] == name[0]) {
                    for(int j = r;j > i+1;j--) q[j] = q[j-1];
                    q[i+1] = name;
                    flag = 1;
                    break;
                }
            }
            if(!flag) {
                q[r] = name;
            }
            r++;
        }else {
            l++;
        } 
    }
    return 0;
}
