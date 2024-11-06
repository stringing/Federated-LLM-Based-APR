#include<iostream>
#include<string>
#define ull unsigned long long
using namespace std;
int main()
{
    string s;int max,sum,begin,end;
    getline(cin,s);
    for (int i = 0; i < s.size(); i++){
        if(s[i] != ' '){
            sum++;
        }else{
            if(sum > max){
                max = sum;
                begin = i-sum;
                end = i;
            }
        }
        sum=0;
    }
    for(int i = begin; i <= end; i++){
        cout<<s[i];
    }
    return 0;
}
