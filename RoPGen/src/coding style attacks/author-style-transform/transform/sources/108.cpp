#include <fstream>
using namespace std;
ifstream fin;
ofstream fout;
int n,m,k,ans=-1;
int a[25],c[25][25],dp[300000][25];
int num(int x){
    int cnt=0;
    while(x>0){
        cnt+=x%2;
        x/=2;
    }
    return cnt;
}
int main(){
    fin.open("meal.in");
    fout.open("meal.out");
    fin>>n>>m>>k;
    for(int i=0;i<n;i++){
        fin>>a[i];
    }
    for(int i=0;i<k;i++){
        int x,y,v;
        fin>>x>>y>>v;
        c[x-1][y-1]=v;
    }
    for(int i=0;i<n;i++){
        dp[1<<i][i]=a[i];
    }
    for(int i=0;i<=(1<<n)-1;i++){
        for(int j=0;j<n;j++){
            if(!(i&(1<<j))){
                for(int k=0;k<n;k++){
                    if(i&(1<<k)){
                        dp[i|(1<<j)][j]=dp[i][k]+a[j]+c[k][j];
                    }
                }
            }
        }
    }
    for(int i=0;i<=(1<<n)-1;i++){
        
        if(num(i)==m){
            for(int j=0;j<n;j++){
                
                ans=max(ans,dp[i][j]);
            }
            
        }
    }
    fout<<ans<<endl;
    fin.close();
    fout.close();
    return 0;
}
