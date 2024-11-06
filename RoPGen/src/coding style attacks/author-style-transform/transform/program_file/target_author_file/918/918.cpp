#include<iostream>
#include<algorithm>
using namespace std;
bool cum(int a,int b){
        int suma = 0;
        int sumb = 0;
        int aa = a;
        int bb = b;
        while(aa){
            suma += aa % 10;
            aa / 10;
        }
        while(bb){
            sumb += bb % 10;
            bb / 10;
        }
        if(suma != sumb){
            return suma < sumb;
        }
    }
int main(){
    int n;
    cin >> n;
    int i[n];
    for(int j = 0;j < n;j++){
        cin >> i[n];
    }
    sort(i,i + n,cum);
    for(int j = 0;j < n;j++){
        cout << i[n] <<" ";
    }
}
