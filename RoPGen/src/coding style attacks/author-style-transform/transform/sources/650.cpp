#include<bits/stdc++.h>
using namespace std;
int ans = INT_MAX,n,shelf,hight[30];
void dfs(int k,int sum){
    if(k > n){
        if(sum < ans){
            ans = sum;
        }
        return;
    }
    if(sum >= ans) return;
    dfs(k+1,sum + hight[k]);
    dfs(k+1,sum);
}
int main(){
    freopen("shelf.in","r",stdin);
    freopen("shelf.out","w",stdout);
    scanf("%d%d",&n,&shelf);
    for(int i = 1;i <= n;i++){
        scanf("%d",&(hight[i]));
    }
    dfs(1,0);
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
