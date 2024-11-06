#include<iostream>
using namespace std;
int flag[1000001];
void fly(long long x){
    if(flag[x] != 2){
        if(x % 2 == 0){
            fly(x/2);
            flag[x]++;
        }else{
            fly(6*(x-1)/2+6);
            flag[x]++;
        }
    }
    if(x == 12){
        x = 6;
        flag[x]++;
    }else if(x == 6){
        x = 3;
        flag[x]++;
    }else if(x == 3){
        x = 12;
        flag[x]++;
    }
    cout<<x<<", ";
    
    
    
    
    
    
    
    
    

}

int main(){
    int n;
    cin>>n;

    fly(n);
    return 0;
}
