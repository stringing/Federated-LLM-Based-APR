#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    for(int k = 0;k < n;k++) {
        getchar();
        string s;
        getline(cin,s);
        for(int i = 0;i < s.length();i++) {
            if(s[i] >= 'A' && s[i] <= 'Z' && s[i] != 'I') 
                s[i] += 32;
            if(s[i] == '?')
                s[i] = '!';
        }
        int x = 0;
        string f[1005];
        for(int i = 0;i < s.length();i++) {
            if(s[i] != ' ') {
                f[x] += s[i];
                x++;
            }
            for(int j = 0;j <= x;j++) {
                if((f[j] == "can"|| f[j] == "could") && f[j+1] == "you") 
                    cout << "I " << f[i] << " ";
                else if(f[j] == "I" || f[j] == "me") cout << "you" << " ";
                else cout << f[i] <<  " ";
            }
        }     
    }
    cout << endl;
}
