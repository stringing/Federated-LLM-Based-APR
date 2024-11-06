#include<bits/stdc++.h>
int in[1005];
int book[1005];
int b[1005];
int main()
{
    
    int t;
    int n;
    scanf("%d",&t);
    while(t--)
    {
        freopen ("p.in","r",stdin);
     freopen ("p.out","w",stdout);
    memset(book,0,sizeof(book));
    memset(b,0,sizeof(b));
    memset(in,0,sizeof(in));
    scanf("%d",&n);
    int i,x,y,j;
    for(i=1;i<n;i++)
    {
    scanf("%d%d",&x,&y);
    book[y]=x;
    in[x]++;
    }
    int sum=0;
    for(i=1;i<=n;i++)
    {
    if(in[book[i]]<in[i])
    {
    b[book[i]]=1;
    }
    if(in[book[i]]>in[i]){
    b[i]=1;     
    }
    }
    for(i=1;i<=n;i++){
    if(b[i]==0){
    
    sum++;
}
}
    printf("%d\n",sum);     
    }
    return 0;
}
