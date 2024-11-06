#include<iostream>
#include<cstdio>
using namespace std;
int n,ans;
bool maze[8][8],row[20],x1[20],x2[20];
bool check1(int c,int i){
    return !row[i]&&!x1[c+i]&&!x2[i-c+n]&&maze[i][c];
}
bool check2(int c,int i){
    return !row[i+10]&&!x1[c+i+10]&&!x2[i-c+n+10]&&maze[i][c];
}
void dfs(int c){
    if(c==n){
        ans++;
        return;
    }
    for(int i=0;i<n;i++){
        if(check1(c,i)){
            row[i]=x1[c+i]=x2[i-c+n]=true;
            maze[i][c]=false;
            for(int j=0;j<n;j++){
                if(check2(c,j)){
                    row[j+10]=x1[c+j+10]=x2[j-c+n+10]=true;
                    maze[j][c]=false;
                    dfs(c+1);
                    row[j+10]=x1[c+j+10]=x2[j-c+n+10]=false;
                    maze[j][c]=true;
                }
            }
            row[i]=x1[c+i]=x2[i-c+n]=false;
            maze[i][c]=true;
        }  
    }
    return;
}
int main(){
    freopen("queen.in","r",stdin);
    freopen("queen.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>maze[i][j];
        }
    }
    dfs(0);
    cout<<ans<<endl;
    return 0;
}
