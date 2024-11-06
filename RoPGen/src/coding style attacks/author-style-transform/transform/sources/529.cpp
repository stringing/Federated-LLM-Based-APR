#include<bits/stdc++.h>
using namespace std;
int n1,n2,n3;
int a1[110],b1[110];
int a2[110],b2[110];
int main(){
    freopen("health.in","r",stdin);
    freopen("health.out","w",stdout);
    int i,j,dp[5010]={0};
    scanf("%d%d%d",&n1,&n2,&n3);
    for(i = 1;i <= n1;i++) scanf("%d",&a1[i]);
    for(i = 1;i <= n1;i++) scanf("%d",&b1[i]);
    for(i = 1;i <= n2;i++) scanf("%d",&a2[i]);
    for(i = 1;i <= n2;i++) scanf("%d",&b2[i]);
    for(i = 1;i <= n1;i++)
        for(j = n3;j >= 0;j--){
            if(j >= a1[i]) dp[j] = max(dp[j],dp[j-a1[i]]+b1[i]);
        }
    for(i = 1;i <= n2;i++)
        for(j = n3;j >= 0;j--){
            if(j >= a2[i] && dp[j]) dp[j] = max(dp[j],dp[j-a2[i]]+b2[i]);
        }
    printf("%d",dp[n3]);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
