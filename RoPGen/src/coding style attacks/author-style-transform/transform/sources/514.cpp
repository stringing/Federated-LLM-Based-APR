#include <bits/stdc++.h>
using namespace std;
int m[35],b[35];
int treel[35],treer[35];
int n;
void dfs(int l,int r){
    if(l<=r){
        for(int i=l;i<=r;i++){
            if(m[i]==b[r]){
                treel[m[i]]=b[i-1];
                treer[m[i]]=b[r-1];
                dfs(l,i-1);
                dfs(i+1,r);
                break;
            }
        }
    } 
    return;
} 
int main(){
    freopen("sort.in","r",stdin);
    freopen("sort.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> b[i];
    }
    for(int i=1;i<=n;i++){
        cin >> m[i];
    }
    dfs(1,n);
    for(int i=1;i<=n;i++){
        cout << treel[i] << ' ' << treer[i] << endl;
    }
    return 0;
} 
