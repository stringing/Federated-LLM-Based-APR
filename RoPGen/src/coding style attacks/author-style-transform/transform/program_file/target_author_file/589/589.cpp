#include<bits/stdc++.h>
using namespace std;
int n,ans;
bool MAP[10][10];
bool x1[20],x2[20],row1[10];
bool z1[20],z2[20],row2[10];
bool check1(int c,int r){
    if(x1[c+r] == false && x2[c-r+8] == false && MAP[r][c] == true && row1[r] == false){
        return true;
    }else return false;
}
bool check2(int c,int r){
    if(z2[c+r] == false && z2[c-r+8] == false && MAP[r][c] == true && row2[r] == false){
        return true;
    }else return false;
}

void dfs(int c){
    if(c == n+1){
        ans++;
        return;
    }
    bool flag1 = false,flag2 = false;
    int temp1,temp2;
    for(int i = 1;i <= n;i++){
        if(check1(c,i) == true){
            x1[c+i] = true;
            x2[c-i+8] = true;
            row1[c] = true;
            flag1 = true;
            temp1 = i;
        }
        if(check2(c,i) == true){
            z1[c+i] = true;
            z2[c-i+8] = true;
            row2[c] = true;
            flag2 = true;
            temp2 = i;
        }
        if(flag1 == true && flag2 == true){
            dfs(c+1);
            flag1 = false;
            flag2 = false;
            x1[c+temp1] = false;
            x2[c-temp1+8] = false;
            row1[c] = false;
            z1[c+temp2] = false;
            z2[c-temp2+8] = false;
            row2[c] = false;
        }
    }
}
int main(){
    freopen("queen.in","r",stdin);
    freopen("queen.out","w",stdout);
    int i,j,temp;
    scanf("%d",&n);
    for(i = 1;i <= n;i++){
        for(j = 1;j <= n;j++){
            scanf("%d",&temp);
            if(temp == 1) MAP[i][j] = true;
        }
    }
    dfs(1);
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
