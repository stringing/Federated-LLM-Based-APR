
#include <iostream>
using namespace std;
int main() { 
    int y, m;
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12){
        cout<<"31"<<endl;
    }
    else if (m == 4 || m == 6 || m == 9 || m == 11){
        cout<<"30"<<endl;
    }
    if (y % 400 == 0 ||y  % 10 != 0 && m == 2 && m %4  == 0 ){
       cout<<"29"<<endl;
    }  
    else{
        cout<<"28"<<endl;
    }

    return 0;
}
