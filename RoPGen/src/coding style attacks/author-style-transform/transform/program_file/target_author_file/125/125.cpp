#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main() {
    int n;
    cin >> n;
    string a[n];
    int l = 0,r = 0;
    while (n--){
        int k;
        cin >> k;
        if (k == 1){
            string name;
            cin >> name;
            bool flag = 0;
            for (int i = l;i < r;i++){
                if (a[i][0] == name[0]){
                    for(int j = r;j > i+1;j--){
                        a[j] = a[j - 1];
                    }
                    a[i+1] = name;
                    flag = 1;
                    break;
                }
            }
            if (!flag){
                a[r] = name;
            }r++;
        }else{
            int x = 0;bool flag = 1;
            while (n+1){
                if (a[x] != " "){
                    cout << a[x] << endl;
                    flag = 0;
                    a[x] = " ";
                    break;
                }
                x++;
            }
            if (flag == 1){
                cout << 0 << endl;
            }
        }
    }
}
