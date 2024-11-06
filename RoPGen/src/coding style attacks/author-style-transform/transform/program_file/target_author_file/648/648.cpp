#include <bits/stdc++.h>
#include <map>
#include<vector>
#include <set>
using namespace std;
int n,f[100],s[100],ch[1005][2];
set<int> fd;
void dfs(int num,int x,int y,int xx,int yy){
    
    if(xx == yy)return;
    int l,ln;
    fd.clear(); 
    for(int i = x;i <= y;i++){
        if(s[i] == num){
            l = s[i-1];
            ln = i;
            fd.insert(i);
            break;
        }
    }
    for(int i = xx;i <= yy;i++){
        if(fd.empty()){
            ch[num][0] = i-1;
            ch[num][1] = i;
            dfs(l,x,ln-1,xx,i);
            dfs(l,ln+1,y,i+1,yy);
            break;
        }else{
            fd.erase(s[i]);
        }
    }
}
int main(){
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    cin >> n;
    for(int i = 1;i <= n;i ++)cin >> f[i];
    for(int j = 1;j <= n;j ++)cin >> s[j];
    dfs(f[n],1,n,1,n-1);
    for(int i = 1;i <= n;i ++){
        cout<<ch[i][0]<<" "<<ch[i][1]<<endl;
    }
    return 0;
}

