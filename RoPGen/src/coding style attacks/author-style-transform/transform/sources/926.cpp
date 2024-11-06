#include<bits/stdc++.h>
using namespace std;
int main(){    
    string q[105];
    int n,rs=0,o=0;
    cin>>n;
    while(n--){
        int k;
        cin>>k;
        if(k==1){
            int d=0;
            rs++;
            string name;
            cin>>name;
            for(int i=0;i<n;i++){
                if(name[0]==q[i][0]){
                    n++;
                    for(int j=i;j<n;i++){
                        q[j+1]=q[j];
                    }
                    q[i]=name;
                    d=1;
                    break;
                }
            }
            if(d!=1){
                n++;
                q[i]
            }
        }
        else{
            if(rs!=0){
                cout<<q[o]<<endl;
                o++;
            }
            else{
                couy<<0;
            }
        }
    }
}
