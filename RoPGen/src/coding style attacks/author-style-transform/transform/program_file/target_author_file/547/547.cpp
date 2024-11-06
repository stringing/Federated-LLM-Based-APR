#include <iostream>
#include <algorithm>
using namespace std;
int num[1000005];
int main() {
    freopen("ball.in", "r", stdin);
    freopen("ball.out", "w", stdout);
    int n, m, x;
    scanf("%d%d",&m,&n);
    for (int i = 0; i < n; i++) {
        scanf("%d",&num[i]);
    }
    sort(num,num+m);
    for(int i=0;i<n;i++){
        scanf("%d",&k);
        if(binary_search(num,num+m,k)){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
