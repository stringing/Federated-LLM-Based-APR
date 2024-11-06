#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n;
char s[MAXN];
int f(char a, char b, char c, char d, char e){
    return (e - '0') * 1 + (d - '0') * 2 + (c - '0') * 4 + (b - '0') * 8 + (a - '0') * 16; 
}
int f1(char a, char b, char c, char d, char e, char f, char g, char i){
    return (i - '0') * 1 + (g - '0') * 2 + (f - '0') * 4 + (e - '0') * 8 + (d - '0') * 16 + (c - '0') * 32 + (b - '0') * 64;
}
bool judge() {
    if (n % 8 != 0) {
        return false;
    }
    for (int k = 0; k < n; k += 8) {
        if (s[k] == '1' && s[k + 1] == '0' && s[k + 2] == '1') {     
            if(f(s[k + 3], s[k + 4], s[k + 5], s[k + 6], s[k + 7]) > 25)
                return false;
        } 
        else if (s[k] == '1' && s[k + 1] == '1' && s[k + 2] == '1') {
            continue;
        }
        else if (s[k] == '0'){
            k += 8;
            if(s[k] == '0')
                continue;
            else
                return false;
        }
        else {
            return false;
        }
    }
    return true;
}
int main(){
    freopen("information.in", "r", stdin);
    freopen("information.out", "w", stdout);
    scanf("%s", s);
    if(!judge()){
        cout << "Error" << endl;        
    }    
    else{
        for(int k = 0; k < n; k += 8){
            if (s[k] == '1' && s[k + 1] == '0' && s[k + 2] == '1'){
                int p = f(s[k + 3], s[k + 4], s[k + 5], s[k + 6], s[k + 7]);
                cout << (char)(p + 'A');
            }
            else if(s[k] == '1' && s[k + 1] == '1' && s[k + 2] == '1')
                cout << " ";
            else if(s[k] == '0'){
                int sum;
                sum = f1(s[k], s[k + 1], s[k + 2], s[k + 3], s[k + 4], s[k + 5], s[k + 6], s[k + 7]);
                k += 8;
                sum += f1(s[k], s[k + 1], s[k + 2], s[k + 3], s[k + 4], s[k + 5], s[k + 6], s[k + 7]);
                cout << sum;
            }
        }        
    }
    return 0;
}
