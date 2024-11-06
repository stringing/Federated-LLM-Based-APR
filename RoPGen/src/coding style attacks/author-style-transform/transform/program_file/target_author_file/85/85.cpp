#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int inOrder[1001];
int postOrder[1001];
int n;
int lc[1001],rc[1001];
int dfs(int l1,int l2,int r1,int r2){
    if(l1>r1){
        return 0;
    }
    int root=postOrder[r1],pos;
    for(pos=l2;pos<=r2;pos++){
        if(inOrder[pos]==root){
            break;
        }
    }
    int lsize=pos-l2,rsize=r2-pos;
    lc[root]=dfs(l1,l1+lsize-1,l2,pos-1);
    rc[root]=dfs(r1-rsize,r1-1,pos-1,r2);
    return root;
}
int main(){
    freopen("sort.in","r",stdin);
    freopen("sort.out","w",stdout);
    
    
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>postOrder[i];
    }
    for(int i=1;i<=n;i++){
        cin>>inOrder[i];
    }
    dfs(1,n,1,n);
    sort(inOrder+1,inOrder+n+1);
    for(int i=1;i<=n;i++){
        cout<<lc[inOrder[i]]<<' '<<rc[inOrder[i]]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

