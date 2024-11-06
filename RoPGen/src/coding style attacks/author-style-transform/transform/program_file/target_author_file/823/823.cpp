#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string data[1005];
char dataa[1005];
int floor = 0,rear = 0;
void pop(){
    if(floor = rear){
        cout << "0" <<endl;
    }else{
        floor += 1;
    }
}
void push(string a){
    bool is_dataa = 0;
    for(int i = 0;i < 1005;i++){
        if(dataa == a[0]){
            is_dataa = 1;
            for(int j = 1004;j > i;j--){
                data[j] = data[j+1];
            }
            data[i] = a;
            rear += 1;
            break;
        }
    }
    if(!is_dataa){
        data[rear] = a;
        rear += 1;
    }
}
int main(){
    int n;
    cin >> n;
    while(n--){
        int op;
        cin >> op;
        if(op == 1){
            string name;
            cin >> name;
            push(name);
        }else{
            pop();
        }
    }
}
