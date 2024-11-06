#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("information.in","r",stdin);
    freopen("information.out","w",stdout);
    char sz[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    string s,ASD="";
    cin>>s;
    stack<int>a;
    if(s.size()%8!=0){
        cout<<"Error"<<endl;
        return 0;
    }
    for(int i=0;i<s.size();i+=8){
        string S="";
        int j;
        for(j=i;j<=i+2&&S[0]!='0';j++){
            S+=s[j];
        }
        if(S=="101"){
            int ans=0;
            for(int o=0,j=i+7;j>=i+3;j--,o++){
                ans+=pow(2,o)*int(s[j]-'0');
            }
            if(ans>25){
                cout<<"Error"<<endl;
                return 0;
            }
            else{
                ASD+=sz[ans];
            }
        }
        else if(S=="111"){
            ASD+=' ';
        }
        else if(S[0]=='0'){
            int ans=0;
            for(int o=0,j=i+7;j>=i+1;j--,o++){
                ans+=pow(2,o)*int(s[i]-'0');
            }
            if(a.size()){
                int x=(a.top()+ans)/2; 
                ASD+=char(x+'0');
                a.pop();
            }
            else{
                a.push(ans);
            }
        }
        else{
            cout<<"Error"<<endl;
            return 0;
        }
    }
    if(a.size()){
        cout<<"Error"<<endl;
        return 0;
    }
    cout<<ASD;
}
