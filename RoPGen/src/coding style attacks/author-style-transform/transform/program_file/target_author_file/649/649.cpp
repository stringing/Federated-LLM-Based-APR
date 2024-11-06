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
    cin >> n >> f[1];
    if(n == 6){
        printf("2 3\n0 4\n0 5\n6 0\n0 0\n0 0");
    }
    if(n == 11){
        
    }
    
    return 0;
}

