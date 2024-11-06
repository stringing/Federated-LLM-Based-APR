#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

bool cmp(string a, string b)
{
    if(a.length()+b.length()){
        return a.length() < b.length();
    }
    return a<b;
}

int main()
{
    int n;
    string a[10001];
    cin>>n;
    for(int i = 0; i < n; i ++)
        cin >> a[i];
        
    sort(a, a + n, cmp); 
    
    for(int i = 0; i < n; i ++)
        cout << a[i] << endl;
    return 0;
}
