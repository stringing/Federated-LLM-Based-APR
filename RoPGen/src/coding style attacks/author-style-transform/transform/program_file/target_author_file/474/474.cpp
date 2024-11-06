#include <iostream>
#include <cstdio>
using namespace std;
int ans = 0,N;
bool row[10],x1[20],x2[20],sjdsd[10][10];
bool check(int i,int c){
    return !row[i]&&!x1[i+c]&&!x2[i-c+N]&&sjdsd[i][c];
}
void dfs(int c){
    if(c==2*N){
        ans++;
        return;
    }
    for(int i=0;i<N;i++){
        if(check(i,c)){
            row[i]=x1[i+c]=x2[i-c+N]=true;
            sjdsd[i][c]=false;
            dfs(c+1);
            row[i]=x1[i+c]=x2[i-c+N]=false;
            sjdsd[i][c]=true;
        }
    }
}
int main() {
    freopen("queen.in","r",stdin);
    freopen("queen.out","w",stdout);
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int djdsjfds;
            cin>>djdsjfds;
            sjdsd[i][j]=djdsjfds;
        }
    }
    dfs(0);
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;    
}
