#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    int front = 0, rear = 0;
    string a[101];
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        if(k == 1){
            string name;
            cin >> name;
            int ans = 0;
            for(int j = front; j < rear; j++){
                if(a[j][0] == name[0]){
                    for(int q = rear; q < j + 1; q++){
                        a[q] = a[q - 1];
                    }
                    a[j + 1] = name;
                    ans++;
                    break;
                }
            }
            if(ans == 0){
                rear++;
                a[rear - 1] = name;
            }
            rear++;
        } else {
            if(front != rear){
                cout << a[front] << endl;
            } else {
                cout << 0 << endl;
            }
            front++;
        }
    }
    return 0;
}
