#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main() {
    string a,b;
    getline(cin,a);
    int k=0,n=0,max1=0,c=0;
    for(int i=0;i<a.size();i++)
    {
        k=0;
        if(a[i]>='a'&&a[i]<='z')
        {
             k++;
        }
         if(a[i]>='A'&&a[i]<='Z')
        {
            k++;
        }
        
        if(a[i]==' '||a[i]==a.size()-1)
        {
            if(k>max1)
            {
                  max1=k;
                  c=i-k+1;
            } 
        }
    }
    b=a.substr(c,max1);
    cout<<b<<endl;
    return 0;
}

