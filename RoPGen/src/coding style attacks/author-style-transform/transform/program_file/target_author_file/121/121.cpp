#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<string>

using namespace std;

int getInSun(int num){
    int sum =0;
    while(num>0){
        int i=num%10;
        sum = sum+i;
        num=num/10;
    }
    return sum;        
}

int cmp(int a, int b)
{
    if(getInSun(a) != getInSun(b)){
        return getInSun(a)<getInSun(b);
    }else{
        return a<b;
    }
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
