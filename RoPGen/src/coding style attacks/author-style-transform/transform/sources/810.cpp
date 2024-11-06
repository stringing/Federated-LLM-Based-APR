#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
        string q[10005];
    int l=0,r=0;
    for(int i=0;i<n;i++){
        int k;
        cin>>k;
        if(k==1){
            string s;
            cin>>s;
            bool flag=0;
            for(int i=1;i<r;i++){
                if(q[i][0]==s[0]){
                    for(int j=r;j>i+1;j--){
                        q[j]=q[j-1];
                    }
                    q[i+1]=s;
                    flag=1;
                    break;
                }
            }
            if(!flag){
                q[r]=s;
            }
            r++;
        }else{
            cout<<q[l]<<endl;
            l++;
            }
        }
    return 0;
}
