#include<bits/stdc++.h>
using namespace std;
long long a[1005][1005];
long long ans=0,sum=0;
int n,m;
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
            sum+=a[i][j];
        }
    }
    for(int x1=0;x1<n;x1++){
        for(int x2=x1;x2<n;x2++){
            for(int y1=0;y1<m;y1++){
                for(int y2=y1;y2<m;y2++){
                    sum=0;
                    for(int i=x1;i<=x2;i++){
                        for(int j=y1;j<=y2;j++){
                            sum+=a[i][j];
                        }
                    }
                    if(sum>ans){
                        ans=sum;
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
