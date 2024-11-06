#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
char s[N];
int n;
bool a(){
    if(n % 8 != 0) return false;
    for(int i = 1; i <= n; i++){
        if(s[i] != 0 && s[i] != 1) return false;
    }
    for(int i = 1; i <= n; i += 8){
        if(strncmp(s + i, "100", 3) == 0 || strncmp(s + i, "110", 3) == 0) return false;
        if(s[i] == '0'){
            if(i + 8 > n || s[i + 8] != '0') return false;
            i += 8;
        }
        if(strncmp(s + i, "101", 3) == 0) {
            int tmp = 0;
            for(int j = i + 3; j < i + 8; ++j) tmp = tmp * 2 + (s[j] - '0');
            if(tmp >= 26) return false;
        }
    }
}
int main(){
    freopen("information.in", "r", stdin);
    freopen("information.out", "w", stdout);
    scanf("%s", s + 1);
    n = strlen(s + 1);
    if(!a()){
        cout << "Error" << endl;
    }else{
        for(int i = 1; i <= n; i += 8){
            if(strncmp(s + i, "101", 3) == 0) {
                int tmp = 0;
                for(int j = i + 3; j < i + 8; ++j) tmp = tmp * 2 + (s[j] - '0');
                printf("%c", 'A' + tmp);
            }else if(strncmp(s + i, "111", 3) == 0) printf(" ");
            else{
                int tmp1 = 0, tmp2 = 0;
                for(int j = i + 1; j < i + 8; ++j) tmp1 = tmp1 * 2 + (s[j] - '0');
                i += 8;
                for(int j = i + 1; j < i + 8; ++j) tmp2 = tmp2 * 2 + (s[j] - '0');
                printf("%d", (tmp1 >> 1) + (tmp2 >> 1));
            }
        }
    }
    return 0;
}