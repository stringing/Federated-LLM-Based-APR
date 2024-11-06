#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;
vector<int> v;
int main(){
    string s;
    int t,x,sum = 0;
    cin >> x;
    x*=60;
    while (cin >> s){
        if(s == "tingtingting"){
            v.pop_back();
            sum = v[v.size() - 1];
}
        cout << "Congratulations!" << endl;
            return 0;
        }
        else {
            cin >> t;
            sum += t;
            if(sum >= x)break;
            v.push_back(sum);
        }
    }
    cout << "Unfortunately." << endl;
    return 0;
}
       
