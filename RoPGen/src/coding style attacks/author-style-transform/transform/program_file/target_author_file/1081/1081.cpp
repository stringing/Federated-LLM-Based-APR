#include <iostream>
#include <vector>
using namespace std;
struct xx{
    string name;
    int s;
};
int main() {
    int n;
    cin>>n;
    vector<xx> vec;
    while(n--) {
        xx a;
        cin>>a.name>>a.s;
        vec.push_back(a);
    }
    for (int i = 0; i < vec.size(); i++) {
        if(vec[i].name=="kaomianjin" and vec[i+1].name=="tingtingting"){
            cout<<"Hahaha.";
            return 0;
        }
    }   
    cout<<"Congratulations!";
    return 0;
}
