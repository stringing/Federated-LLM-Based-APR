#include<iostream>
#include<string>
using  namespace std;
int main(){
    string a , h;
    int index= 0 , num =0 , max =0 ;
    cin >> a;
    for(int i =0;i < a.size() ; i++){
        if(a[i] != ' '){
            num++;
        }
        else{
            if(max < num){
                max = num;
                h = a[i];
            }
            index++;
            num = 0;
        }
    }
    cout << h << endl;
    return 0;
}
