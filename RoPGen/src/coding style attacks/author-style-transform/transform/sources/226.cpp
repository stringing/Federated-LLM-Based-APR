#include <iostream>
#include <string>
#include<cmath>
using namespace std;
int main() {
    string s;
    int cnt=0,ans=-999999,temp;
    getline(cin,s);
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==' ')
        {
            cnt=0;
            temp=i+1;
        }
        else
        {
            cnt++;
        }
        if(cnt>ans)
        {
            ans=cnt;
            temp=i; 
            cout<<s[temp]<<endl;
        }
    }
   
    return 0;
}
