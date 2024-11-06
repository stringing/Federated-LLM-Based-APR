#include<iostream>
#include<string>
using  namespace std;
int main(){
    string a , h;
    int index= 0 , num =0 , max =0 , min = 0  , z = 0;
    getline(cin , a);
    for(int i =0;i < a.size() ; i++){
        if(a[i] != ' '){
            num++;
        }
        else{
            if(max < num){
                max = num;
                min = i;
                for(int j = i;j < a.size();j++){
                    if(a[j] == ' '){
                        z = j;
                    }
                }
            }
            index++;
            num = 0;
        }
    }
    for(int i = min;i < z;i++){
        cout << a[i];
    }
    return 0;
}
