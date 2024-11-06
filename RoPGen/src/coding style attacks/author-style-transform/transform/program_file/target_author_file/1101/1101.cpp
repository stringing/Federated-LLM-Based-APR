#include<cstdio>
#include<vector>
#include<iostream> 
#include<algorithm>
#include<cstring>
using namespace std;
vector<int> l[1005];
int t, n,cnt, father[1005],a,b,ans[105] = {0};
void dfs(int num){
    int sum = 0,f = l[father[num]].size();
    for(int i = 0;i < l[num].size();i++){
        sum += l[l[num][i]].size();
    }
    if(sum <= l[num].size()&&f <= l[num].size()){
        cnt++;
    }
}
int main(){
    freopen("p.in", "r", stdin);
    freopen("p.out", "w", stdout);
    scanf("%d",&t);
    int j = t;
    while(j --){
        scanf("%d",&n);
        for(int i = 0;i < n-1;i ++){
            scanf("%d%d",&a,&b);
            father[b] = a;
            l[a].push_back(b);
        }
        for(int i = 1;i <= n;i ++){
            dfs(i);
        }
        for(int i = 1;i <= n;i ++){
            l[i].clear();
            father[i] = 0;
        }
        ans[j] = cnt;
        cnt = 0;
        
    }
    while(t--){
        cout<<ans[t]<<endl;
    }
    return 0;
} 
题目
给出一颗有向树，总共 nn 个节点，如果一个节点的度不小于它所有的儿子以及他的父亲的度（如果存在父亲或者儿子），那么我们称这个点为 pp 节点，现在给你一棵树你需要统计出 pp 节点的个数。

这里的度数指树上的度数，即一个节点的子节点数。

输入格式
输入的第一行包含一个整数 tt（1\le t\le 1001≤t≤100），表示数据组数。

接下来 tt 组数据，每组数据第一行一个数 nn（1\le n\le 10001≤n≤1000），表示树的节点数。

然后 n-1n−1 行，每行两个数 xx，yy（0\lt x,y\lt n0<x,y<n），代表 yy 是 xx 的儿子节点，两数之间以一个空格分隔。

输出格式
输出 tt 行，每一行一个整数，代表 pp 节点的个数。

输出时每行末尾的多余空格，不影响答案正确性

要求使用「文件输入输出」的方式解题，输入文件为 p.in，输出文件为 p.out
