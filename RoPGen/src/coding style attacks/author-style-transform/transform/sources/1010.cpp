#include <iostream>
#include <string>
#include<cmath>
using namespace std;
int main() {
    string s;
    int cnt=0,ans,a;
    getline(cin,s);
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==' ')
        {
            cnt=0;
            ans=i+1;
        }
    }
    cout<<s<<endl;
    return 0;
}

