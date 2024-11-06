#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("p.in","r",stdin);
    freopen("p.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>vec[1000];
        for(int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            vec[a].push_back(b);
            vec[b].push_back(a);
        }
        int p=0;
        for(int i=0;i<n;i++){
            int flag=1;
            for(int j=0;j<vec[i].size();j++){
                if(vec[vec[i][j]].size()>vec[i].size()){
                    flag=0;
                    break;
                }
            }
            if(vec[i].size()==0){
                flag=0;
            }
            if(flag==1){
                p++;
            }
        }
        cout<<p<<endl;
    }
}
