#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int n, cnt, flag;
int ans[MAXN], tot;
char mapx[1005][1005];
int main(){
    freopen("zip.in","r",stdin);
    freopen("zip.out","w",stdout);
    scanf("%s", mapx[1] + 1);
    n = strlen(mapx[1] + 1);
    for(int i = 2; i <= n; i++)
        scanf("%s", mapx[i] + 1);
    flag = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(mapx[i][j] - '0' == flag) cnt++;
            else{
                ans[tot++] = cnt;
                flag ^= 1;
                cnt = 1;
            }
        }
    }
    ans[tot++] = cnt;
    printf("%d ",&n);
    for(int i = 1; i <= tot; ++i)
        printf("%d ", ans[i]);
    return 0;
}
