#include <fstream>
using namespace std;
int inorder[1005],postorder[1005];
int l[1005],r[1005];
int vis[1005];
int dfs(int l1,int r1,int l2,int r2){
    
    
    
    int k;
    for(k=l2;k<=r2;k++){
        if(postorder[r1]==inorder[k]){
            break;
        }
    }
    
    
    if(l2!=k){
        int len=k-l2;
        l[postorder[r1]]=dfs(l1,l1+len-1,l2,k-1);
    }
    
    if(r2!=k){
        int len=r2-k;
        r[postorder[r1]]=dfs(r1-len,r1-1,k+1,r2);
    }
    return postorder[r1];
}
int main(){
    ifstream fin;
    ofstream fout;
    fin.open("sort.in");
    fout.open("sort.out");
    int N;
    for(int i=1;i<=N;i++){
        fin>>postorder[i];
        vis[postorder[i]]=true;
    }
    for(int i=1;i<=N;i++){
        fin>>inorder[i];
    }
    dfs(1,N,1,N);
    for(int i=1;i<1000;i++){
        if(vis[i]){
            fout<<l[i]<<" "<<r[i]<<endl;
        }
    }
    return 0;
}
