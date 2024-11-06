#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main() {
    string word,j = "",maxword = "";
    int max;
    getline(cin,word);
    max = 0;
    for (int i = 0;i < word.size();i++){
        if (word[i] == ' '){
            if (j.size() > max){
                max = j.size();
                maxword = j;
            }
            j = "";
        }else{
            j = j + word[i];
        }
    }
    cout << maxword << endl;
    return 0;
}
