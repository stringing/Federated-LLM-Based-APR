#include <bits/stdc++.h>
using namespace std;
string s[1000];
int len,t,ans=0,f;
int main(){
    freopen("zip.in","r",stdin);
    freopen("zip.out","w",stdout);
    getline(cin,s[0]);
    len = s[0].size();
    for(int i=1; i<len; i++){
        getline(cin,s[i]);
    }
    t = s[0][0];
    cout << len << " ";
    if(t!=0){
        cout << 0 << " ";
    }
    for(int i=0; i<len; i++){
        for(int j=0; j<len; j++){
            if(i==len-1&&j==len-1&&t==s[i][j]){
                cout << ans + 1;
            }
            if(t==s[i][j]){
                ans = ans + 1;
            }
            else{
                cout << ans << " ";
                ans = 1;
                t = s[i][j];
            }
        }
    }
    if(s[len-1][len-2]!=s[len-1][len-1]){
        cout << 1;
    }
    return 0;
}
