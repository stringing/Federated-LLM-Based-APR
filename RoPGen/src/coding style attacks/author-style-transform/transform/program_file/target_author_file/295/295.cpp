#include <iostream>
using namespace std;
int ans = 0,n;
bool row[10],x1[20],x2[20];
bool check(int c,int i){
                return !row[i]&&!x1[c+i]&&!x2[c-i+n];
        }
void dfs(int c){
        if(c==n){
                ans++;
                return;
        }
        for(int i=0;i<n;i++){
                if(check(c,i)){
                        row[i]=x1[c+i]=x2[c-i+n]=true;
                        dfs(c+1);
                        row[i]=x1[c+i]=x2[c-i+n]=false;
                }
       }
        for(int j=0;j<n;j++){
                if(check(c,j)){
                        row[j]=x1[c+j]=x2[c-j+n]=true;
                        dfs(c+1);
                        row[j]=x1[c+j]=x2[c-j+n]=false;
                }
        }
        
}
int main() {
        freopen("queen.in","r",stdin);
        freopen("queen.out","w",stdout);
        cin>>n;
    dfs(0);
        cout<<ans<<endl;
    return 0;    
}
