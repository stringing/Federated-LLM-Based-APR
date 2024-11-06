#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[50],c[50][50],dp[300010][20];
template<typename T>void read(T &x){
    x=0; T f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    x*=f;
}
int num(int x){
    int anss=0;
    while(x>0){
        if(x%2==1)
            anss++,x--;
        x/=2;
    }
    return anss;
}
int main(){
    freopen("meal.in","r",stdin);
    freopen("meal.out","w",stdout);
    read(n),read(m),read(k);
    for(register int i=0; i<n; i++)
        read(a[i]);
    for(register int i=0,x,y,ci; i<k; i++){
        read(x),read(y),read(ci);
        c[x-1][y-1]=ci;
    }
    for(register int i=0; i<n; i++)
        dp[1<<i][i]=a[i];
    for(register int i=0; i<(1<<n); i++)
        for(register int j=0; j<n; j++)
            if(!((i>>j)&1))
                for(register int k=0; k<n; k++)
                    if((i>>k)&1)
                        dp[i|(1<<j)][j]=max(dp[i|(1<<j)][j],dp[i][k]+c[k][j]+a[j]);
    int ans=0;
    for(register int i=1; i<(1<<n); i++)
        if(num(i)==m)
            for(register int j=0; j<n; j++)
                ans=max(ans,dp[i][j]);
    printf("%d",ans);
    return 0;
}
