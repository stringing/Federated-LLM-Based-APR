#include <iostream>
#include <fstream>
using namespace std;
int ans = 0;

int num;
bool fallensquare[10][10];
bool row[10],x1[20],x2[20];
bool check(int c,int i){
    return !row[i]&&!x1[c+i]&&!x2[c-i+num]&&fallensquare[c][i];
}
void dfs(int c){
    if(c==num){
        ans++;
        return;
    }
    for(int i=0;i<num;i++){
        if(check(c,i)){
            row[i]=x1[c+i]=x2[c-i+num]=true;
            dfs(c+1);
            row[i]=x1[c+i]=x2[c-i+num]=false;
        }
    }
}
int main() {
    ifstream fin;
    ofstream fout;
    fin.open("queen.in");
    fout.open("queen.out");
    fin>>num;
    for(int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            fin>>fallensquare[i][j];
        }
    }
    dfs(0);
    fout<<ans<<endl;
    fin.close();
    fout.close();
    return 0;    
}
