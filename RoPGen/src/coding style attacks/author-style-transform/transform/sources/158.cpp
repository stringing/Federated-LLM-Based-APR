    #include <iostream>
    #include <cstdio>
    #include <algorithm>
    #include <string>
    using namespace std;
    string n;
    int a[1001],len=0,add=0;
    int main(){
        freopen("bigadd.in","r",stdin);
        freopen("bigadd.out","w",stdout);
        cin>>n;
        len=n.size();
        for(int i=1;i<=len;i++){
            a[i]+=(int)(n[i])-'0';
        }
        a[1]+=2018;
        while(a[add]){
            if(a[add]>9){
                a[add+1]+=a[add]%10;
                a[add]=a[add]/10;
            }
            add++;
        }
        for(int i=1;i<=add;i++){
            cout<<a[i];
        }
}


