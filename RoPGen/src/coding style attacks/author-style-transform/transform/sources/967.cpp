#include <bits/stdc++.h>
using namespace std;
int dp[1009][1009],a[1009][1009];
int main(){
    freopen("escape.in","r",stdin);
    freopen("escape.out","w",stdout);
    int n,m,x,y,v,c;
    cin>>n>>m;
    cin>>x>>y;
    cin>>v>>c;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>a[i][j];
        }
    }
    a[x][y]=v;
    for(int i=x;i>=1;i--){
        for(int j=y;j>=1;j--){
            if(i==x){
                dp[i][j]=dp[i][j+1];
            }
            else if(j==y){
                dp[i][j]=dp[i+1][j];
            }
            else{
                dp[i][j]=max(dp[i+1][j],dp[i][j+1])+a[i][j];
                if(dp[i][j]>=c){
                    dp[i][j]=c;
                }
                if(dp[i][j]<=0){
                    dp[1][1]=0;
                    break;
                }   
            }
        }
    }
    for(int i=x;i>=1;i--){
        for(int j=y;j<=m;j++){
            if(i==x){
                dp[i][j]=dp[i][j-1];
            }
            else if(j==y){
                dp[i][j]=dp[i+1][j];
            }
            else{
                dp[i][j]=max(dp[i+1][j],dp[i][j-1])+a[i][j];
                if(dp[i][j]>=c){
                    dp[i][j]=c;
                }
                if(dp[i][j]<=0){
                    dp[1][m]=0;
                    break;
                }   
            }
        }
    }
    for(int i=x;i<=n;i++){
        for(int j=y;j>=1;j--){
            if(i==x){
                dp[i][j]=dp[i][j+1];
            }
            else if(j==y){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j+1])+a[i][j];
                if(dp[i][j]>=c){
                    dp[i][j]=c;
                }
                if(dp[i][j]<=0){
                    dp[n][1]=0;
                    break;
                }   
            }
        }
    }
    for(int i=x;i<=n;i++){
        for(int j=y;j<=m;j++){
            if(i==x){
                dp[i][j]=dp[i][j-1];
            }
            else if(j==y){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1])+a[i][j];
                if(dp[i][j]>=c){
                    dp[i][j]=c;
                }
                if(dp[i][j]<=0){
                    dp[n][m]=0;
                    break;
                }   
            }
        }
    }
    if(dp[1][1]==0&&dp[1][m]==0&&dp[n][1]==0&&dp[n][m]==0){
        cout<<"-1";
    }
    else{
        cout<<max(dp[1][1],max(dp[1][m],max(dp[n][1],dp[n][m])));
    }
}
