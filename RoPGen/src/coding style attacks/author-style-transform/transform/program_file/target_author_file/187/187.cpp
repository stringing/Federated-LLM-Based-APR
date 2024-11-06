#include <iostream>
#include <string>
using namespace std;
int main () {
    int n;
    cin >> n;
    string q[105];
    int l = 0, r = 0;
    int flag = 0;
    while(n--){
        int k;
        cin >> k;
        if(k == 1){
            string name;
            cin >> name;
            for(int i = l; i < r; i++){
                if(q[i][0] == name[0]){
                    for(int j = r; j > i + 1; j++){
                        q[j] = q[j - 1];
                    }
                    q[i + 1] = name;
                    flag = 1;
                    break;
                }
            }
            if(!flag){
                q[r] = name;
            }
            r++;
        }else{
            cout << q.front() << endl;
            if(front() < rear()){
                front++;
            }
            
        }
    }
    return 0;
}
