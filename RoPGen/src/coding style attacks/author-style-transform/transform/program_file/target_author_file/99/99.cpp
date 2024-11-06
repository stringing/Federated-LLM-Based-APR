#include<bits/stdc++.h>
using namespace std;
string book[101];
bool pd(int x,int y){
    int sumx,sumy;
    for(int i = 1;i < 5;i++){
        sumx += x % 10;
        x /= 10;
    }
    for(int i = 1;i < 5;i++){
        sumy += y % 10;
        y /= 10;
    }
    if(sumx != sumy){
        return x < y;
    }else{    
        return x < y;
    }
}
int main(){
    int n;
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> book[i];
    }
    sort(book,book + n,pd);
    for(int i = 0;i < n;i++){
        cout << book[i] << " ";
    }
    return 0;
}









