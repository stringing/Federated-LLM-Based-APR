#include <iostream>


using namespace std;
int main(int argc, char** argv) {
int n,a,b;
cin>>n>>a>>b;
if((600-n*a)%(a-b)<(a-b)/2){
cout<<(600-n*a)/(a-b)+1;    
}else{
    cout<<(600-n*a)/(a-b);
}

    
    return 0;
}
