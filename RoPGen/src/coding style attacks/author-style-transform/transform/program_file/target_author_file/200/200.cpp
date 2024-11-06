#include <bits/stdc++.h>
using namespace std;
string a;
int chang = 0;
bool pd(){
    int d = 0;
    if(chang % 8 != 0){
        return false;
    }for(int i = 0; i < chang; i += 8){
        if(a[i] == '1' && a[i + 1] == '0' && a[i + 2] == '1'){
            int temp = 0;
            for(int j = i + 3; j < i + 8; j++){
                temp = temp * 2 + (a[j] - '0');
            }
            if(temp >= 26){
                return false;
            }
        }else if(a[i] == '1' && a[i + 1] == '1' && a[i + 2] == '1'){
            continue;
        } else if(a[i] == '0'){
            d++;
        }
    }
    if(d % 2 != 0){
        return false;
    }
    return true;
}
int main(){
    freopen("information.in","r",stdin);
    freopen("information.out","w",stdout);
    cin >> a;
    chang = a.size();
    long long bc = 0, pan = 0;
    if(!pd()){
        cout << "Error" << endl;
        return 0;
    }else {
        for(int i = 0; i < chang; i += 8){
            if(a[i] == '1' && a[i + 1] == '0' && a[i + 2] == '1'){
                int temp = 0;
                for(int j = i + 3; j < i + 8; j++){
                    temp = temp * 2 + (a[j] - '0');
                    cout << 'A' + temp;
                }
            }else if(a[i] == '1' && a[i + 1] == '1' && a[i + 2] == '1'){
                cout << " ";
            }else if(a[i] == '0'){
                int temp = 0;
                for(int j = i + 1; j < i + 8; j++){
                    temp = temp * 2 + a[j];
                    pan++;
                    bc += temp / 2;
                    if(pan % 2 == 0){
                        cout << bc;
                        bc = 0;
                        pan = 0;
                    }
                }
            }
        }
    }
    return 0;
}
