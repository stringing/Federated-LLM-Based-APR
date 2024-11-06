#include <bits/stdc++.h>
using namespace std;
int sum(int x){
    int s=0;
    while(x){
        s=x%10;
        x/=10;
    }
    return s;
}
int cmp(int a,int b){
    if(sum(a)!=sum(b)){
        return sum(a)<sum(b);
    }
    return a<b;
}
int main() {
    int s[10000];
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    sort(s,s+n,cmp);
    for(int i=0;i<n;i++){
        cout<<s[i]<<" ";
    }
    return 0;
}

