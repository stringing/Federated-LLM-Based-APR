#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct baoshi
{
    int r,p,k,flag;
};
int main()
{
    vector<baoshi> vec,vec2;
    vector<int> vec3,vec4;
    int n;
    cin>>n;
    int sum=1;
    for(int i=0;i<n;i++)
    {
        baoshi a;
        cin>>a.r>>a.p>>a.k;
        
        for(int j=0;j<a.k;j++)
        {
            vec3.push_back(sum);
            vec4.push_back(sum);
            sum+=1;
            
        }
        vec.push_back(a);
        vec2.push_back(a);
        
    }
    int temp[10001]={0};
    int temp2[10001]={0};
    int temp3[10001]={0};
    for(int i=vec.size()-1;i>=0;i--)
    {
        temp[i]=vec[i].r;
        temp2[i]=vec[i].p*vec[i].k;
        for(int j=0;j<i;j++)
        {
            
            if(vec[i].r==vec[j].r)
            {
                temp[i]+=vec[j].r;
                temp2[i]+=vec[j].p*vec[j].k;
            }
        }
        temp3[i]=temp2[i]/temp[i];
    }
    for(int i=vec.size()-1;i>=0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(temp3[i]<temp3[j])
            {
                swap(temp3[i],temp3[j]);
                swap(vec[i],vec[j]);
                swap(vec3[i],vec3[j]);
            }
            else if(vec[i].r==vec[j].r&&vec[i].p<vec[j].p)
            {
                swap(temp3[i],temp3[j]);
                swap(vec[i],vec[j]);
                swap(vec3[i],vec3[j]);
            }
            else if(vec[i].r==vec[j].r&&vec[i].p==vec[j].p&&vec3[i]>vec3[j])
            {
                swap(temp3[i],temp3[j]);
                swap(vec[i],vec[j]);
                swap(vec3[i],vec3[j]);
            }
        }
        
    }
    sum=0;
    for(int i=0;i<vec.size()-1;i++)
    {
        sum+=abs(vec4[i]-vec3[i]);
    }
    cout<<sum;
    return 0;
}
