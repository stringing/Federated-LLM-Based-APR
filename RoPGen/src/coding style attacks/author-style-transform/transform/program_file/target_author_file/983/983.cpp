#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    string w;
    char x = {100005};
    getline(cin, w);
    for(int i = 0; i < w.size(); i++){
        if(w[i] != " "){
            x[i]++;
        }else {
            i += 1;
        }
    }
    for (int j = 0; j < x.size(); j++){
      if (x[1] > x[j] || x[1] = x[j]){
        continue;
      }else {
          n = j;
            }
        }
    cout << w[a];
    return 0;
}
