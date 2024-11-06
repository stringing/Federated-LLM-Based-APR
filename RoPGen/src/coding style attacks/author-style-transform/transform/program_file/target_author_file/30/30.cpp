#include <iostream>
#include <string>
using namespace std;
int main() {
    string s1, s2;
    cin >> s1 >> s2;
    
    int rel = 0;
    int len = s2.size();
    for(int i = 0;i < len;i++){
        rel += (len - i) * (s2[i] - '0');
    }
    
    int result = 0;
    int len1 = s1.size();
    int num = 0; 
    for (int i = 0; i < len1;i++){
        if (s1[i] == '?'){
            num = len1 - i;
        }else{
            result += (len1 - i) * (s1[i] - "0");
        }
    }
    
    int ans = rel - result;
    if(ans / num >= 0 && ans / num <= 9 && ans % num == 0){
        cout << ans / num << endl;
    }else{
        cout << "Lier";
    }
    
    return 0;
}
