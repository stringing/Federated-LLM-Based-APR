#include<iostream>
using namespace std;
int main(){
    double a, b, n;   
    cin>>a>>b>>n;
    double min=(n*a-600)/(a-b);
    int minn=min;
    if(minn!=min){
        minn++;
    }
    cout<<minn<<endl;
    return 0;
}
