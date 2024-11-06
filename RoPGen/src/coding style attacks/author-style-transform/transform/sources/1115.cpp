#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main() {
    int a,c;
  string b;
    
  vector<string> v;
    cin >>  a;
  while (cin >> b >> c) {
    v.push_back(b);
    cout << b;
  }
  for(int i = 0; i < v.size(); i++){
      if (v[i] == "kaomianjin") {
         if (a >= 0 && v[i + 1] != "tingtingting") {
           cout << "Congratulations!";
         } else {
           cout << "Hahaha.2";
         }
         return 0;
       } else if(v[i + 1] == "tingtingting" || v[i] == "tingtingting" ) {

       }else {
         int s;
         cin >> s;
         a -= s;
         if (a < 0) {
          cout << "Hahaha.1";
           
         }
       }
  }

    return 0;
}
