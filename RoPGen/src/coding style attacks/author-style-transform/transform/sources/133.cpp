#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, a, b, minn = 0, sum = 0;
    double min;
    cin>>n>>a>>b;
    sum = n * a - 600;
    min = sum / (b - a);
    minn = int(min);
    if(minn != min){
        minn++;
    }
    cout<<minn<<endl;
    return 0;
}
