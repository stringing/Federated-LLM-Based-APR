#include <bits/stdc++.h>
using namespace std;
int m[35],b[35];
int treel[35],treer[35];
int n;
void dfs(int l,int r,int root,int way){
    for(int i=l;i<=r;i++){
        if(m[i]==b[r]){;
            if(root>=1&&root<=n){
                if(way==1) treel[root]=m[i];
                else if(way==2) treer[root]=m[i];
            }
            dfs(l,i-1,i,1);
            dfs(i+1,r,i,2);
            break;
        }
    }
    return;
} 
int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> b[i];
    }
    for(int i=1;i<=n;i++){
        cin >> m[i];
    }
    dfs(1,n,-1,0);
    for(int i=1;i<=n;i++){
        cout << treel[i] << ' ' << treer[i] << endl;
    }
    return 0;
} 
