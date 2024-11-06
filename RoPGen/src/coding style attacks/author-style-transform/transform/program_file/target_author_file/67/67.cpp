#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string a[101];
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;i<=n;j++){
            cin>>a[j];
            if(a[j]=="I"||a[j]=="me")a[j]="you";
            else if(a[j-1]=="can"&&a[j]=="you"){
                a[j-1]="I";
                a[j]="can";
            }else if(a[j-1]=="could"&&a[j]=="you"){
                a[j-1]="I";
                a[j]="could";
            }else if(a[j]=="?"){
                a[j]="!";
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;i<=n;j++){
            cout<<a[j]<<" ";
            if(a[j]=="!")break;
        }
        cout<<endl;
    }
}
