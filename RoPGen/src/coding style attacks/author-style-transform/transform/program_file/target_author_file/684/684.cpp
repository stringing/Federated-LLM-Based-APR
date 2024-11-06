#include<stdio.h>
int n,m,k;
int a[18],p[18][18],l,r,w;
int dp[1<<19][18];
int max(int a,int b){return a>b?a:b;}
bool pd(int a){
    int cnt=0;
    while (a){
        if (a&1) cnt++;
        a>>=1;
        if (cnt>m) return 0;
    }
    return (cnt==m);
}
main(){
    freopen("meal.in","r",stdin);
    freopen("meal.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    int ans=0;
    for (int i=0;i<n;++i) scanf("%d",a+i),dp[1<<i][i]=a[i];
    for (int i=0;i<k;++i) scanf("%d%d%d",&l,&r,&w),p[l-1][r-1]=w;
    for (int i=0;i<(1<<n);++i)
            for (int k=0;k<n;++k)
                if (!(i&(1<<k)))
                    for (int j=0;j<n;++j)
                        if ((i&(1<<j)))
                            dp[i|(1<<k)][k]=max(dp[i|(1<<k)][k],dp[i][j]+a[k]+p[j][k]);
    for (int i=0;i<(1<<n);++i)
        for (int j=0;j<n;++j)
            if (pd(i)) ans=max(ans,dp[i][j]);
    printf("%d\n",ans);
}
