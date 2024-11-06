#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    string q[101];
    int l = 0,r = 0;
    while (n--){
        int k;
        cin >> k;
        if (k == 1){
            string name;
            cin >> name;
            bool flag = 0;
            for (int i = 0;i < r;i++){
                if (q[i][0] == name[0]){
                    for (int j = r;j > i + 1;j--){
                        q[j] = q[j - 1];
                    }
                    q[i + 1] = name;
                    flag = 1;
                    break;
                }
            }
            if (!flag){
                q[r] = name;
            }
            r++;
        }else{
            if (l == r){
                cout << 0 << endl;
            }else{
                cout << q[l] << endl;
                l++;
            }
        }
    }
}
