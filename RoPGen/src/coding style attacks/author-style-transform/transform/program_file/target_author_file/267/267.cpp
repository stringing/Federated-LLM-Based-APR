#include<bits/stdc++.h>
using namespace std;
int n,a[1010],b[1010];
double c[1010];
struct node{int kind,prise,id;}temp;
vector<node>baoshi;
bool cmp(node x,node y){
    if(x.kind != y.kind) return c[x.kind] > c[y.kind];
    else if(x.kind == y.kind && x.prise != y.prise) return x.prise > y.prise;
    return x.id < y.id;
}
int main(){
    int i,j,num;
    long long sum = 0,k = 1;
    scanf("%d",&n);
    for(i = 1;i <= n;i++){
        scanf("%d%d%d",&temp.kind,&temp.prise,&num);
        b[temp.kind] += num;
        a[temp.kind] += temp.prise * num;
        c[temp.kind] = (a[temp.kind]*1.0) / (b[temp.kind]*1.0);
        for(j = 0;j < num;j++){
            temp.id = k+j;
            baoshi.push_back(temp);
        }k += num;
    }
    sort(baoshi.begin(),baoshi.end(),cmp);
    for(i = 0;i < (int)(baoshi.size());i++){
        sum += abs((i+1) - baoshi[i].id);
    }
    printf("%lld",sum);
    return 0;
}
