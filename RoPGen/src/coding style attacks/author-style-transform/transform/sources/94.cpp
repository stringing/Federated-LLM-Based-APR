#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    string q[101];
    int b = 0, e = 0;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        if(k == 1){
            string name;
            cin >> name;
            bool flag = 0;
            for(int j = b; j < e; j++) {
                if(q[j][0] == name[0]) {
                    for (int h = e; h > j + 1; h--) {
                        q[h] = q[h - 1];
                    }
                    q[j + 1] = name;
                    flag = 1;
                    break;
                }
            }
            if(flag != true) {
                q[e] = name;
            }
            e++;
        }else{
            cout << q[b] << endl;
            b++;
        }
    }
    return 0;
}
