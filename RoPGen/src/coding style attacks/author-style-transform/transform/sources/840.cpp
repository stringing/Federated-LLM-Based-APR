#include <bits/stdc++.h>
using namespace std;
int mp[10][10],black[10],white[10],visblack[10],viswhite[10],ans,cnt,cnt1,cnt2,n,a[100],temp;
void dfswhite(int p){
    if(p==n+1){
        cnt = cnt1 = cnt2 = temp = 0;
        memset(a,0,sizeof(a));
        for(int i=1; i<=n; i++){
            if(mp[i][white[i]]==1){
                cnt = cnt + 1;
            }
            for(int k=0; k<n; k++){
                if(i+white[i]==n+1+k){
                    a[k] = a[k] + 1;
                }
            }
            for(int k=1; k<n; k++){
                if(i+white[i]==n+1-k){
                    a[n+k-1] = a[n+k-1] + 1;
                }
            }
            for(int k=0; k<n; k++){
                if(white[i]==i+k){
                    a[2*n-1+k] = a[2*n-1+k] + 1;
                }
            }
            for(int k=1; k<n; k++){
                if(white[i]==i-k){
                    a[3*n+k-2] = a[3*n+k-2] + 1;
                }
            }
        }
        for(int k=0; k<30; k++){
            if(a[k]>1){
                cnt = cnt - 1;
            }
        }
        if(cnt==n){
            ans = ans + 1;
        }
        return ;
    }
    for(int i=1; i<=n; i++){
        if(!viswhite[i]){
            viswhite[i] = 1;
            white[p] = i;
            dfswhite(p+1);
            viswhite[i] = 0;
        }
    }
    return ;
}
void dfsblack(int s){
    if(s==n+1){
        cnt = cnt1 = cnt2 = temp = 0;
        memset(a,0,sizeof(a));
        for(int j=1; j<=n; j++){
            if(mp[j][black[j]]==1){
                cnt = cnt + 1;
            }
            for(int k=0; k<n; k++){
                if(j+black[j]==n+1+k){
                    a[k] = a[k] + 1;
                }
            }
            for(int k=1; k<n; k++){
                if(j+black[j]==n+1-k){
                    a[n+k-1] = a[n+k-1] + 1;
                }
            }
            for(int k=0; k<n; k++){
                if(black[j]==j+k){
                    a[2*n-1+k] = a[2*n-1+k] + 1;
                }
            }
            for(int k=1; k<n; k++){
                if(black[j]==j-k){
                    a[3*n+k-2] = a[3*n+k-2] + 1;
                }
            }
        }
        for(int k=0; k<30; k++){
            if(a[k]>1){
                cnt = cnt - 1;
            }
        }
        if(cnt==n){
            for(int j=1; j<=n; j++){
                mp[j][black[j]] = 0;
            }
            dfswhite(1);
            for(int j=1; j<=n; j++){
                mp[j][black[j]] = 1;
            }
        }
        return ;
    }
    for(int j=1; j<=n; j++){
        if(!visblack[j]){
            visblack[j] = 1;
            black[s] = j;
            dfsblack(s+1);
            visblack[j] = 0;
        }
    }
    return ;
}
int main(){
    freopen("queen.in","r",stdin);
    freopen("queen.out","w",stdout);
    cin >> n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin >> mp[i][j];
        }
    }
    dfsblack(1);
    cout << ans;
    return 0;
}
