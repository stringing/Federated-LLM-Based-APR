#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    string s;
    int n;
    cin>>n;
    cin.ignore();
    for(int j=0;j<n;j++)
    {
        getline(cin,s);
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='A'&&s[i]<='Z'&&s[i]!='I')
        {
            s[i]+=32;
        }
        if(s[i]=='?')
        {
            s[i]='!';
        }
        
    }
    string f[1005]={};
    int x=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!=' ')
        {
            f[x]+=s[i];
             i++;
        }
       
        else
        {
            x++;
        }
    }
    for(int i=0;i<x;i++)
    {
        if(f[i]=="can"||f[i]=="could"&&f[i+1]=="you")
        {
            cout<<"I "<<f[i]<<" ";
        }
        else if(f[i]=="I"||f[i]=="me")
        {
            cout<<"You ";
        }
        else
        {
            cout<<f[i]<<" ";
            
        }
        cout<<endl;
    }
    }

    return 0;
}
