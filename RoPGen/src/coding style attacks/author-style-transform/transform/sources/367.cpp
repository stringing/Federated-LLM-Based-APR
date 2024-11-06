#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,l=0,r=0;
    cin>>n;
    int k;
    string name;
    string q[2*n]={"0"};
    while(n--)
    {
        cin>>k;
        if(k==1)
        {
            cin>>name;
            bool f=false;
            int i;
            for(i=l;i<r;i++)
            {
                if(q[i][0]==name[0])
                {
                    f=!f;
                    break;
                }
            }
            if(!f)
            {
                q[r]=name;
                r++;
                continue;
            }
            for(int j=r;j>i+1;j--)
            {
                swap(q[j],q[j-1]);
            }
            q[i+1]=name;
        }
        else
        {
            cout<<q[l]<<endl;
            q[l]="0";
            l++;
        }
    }
    return 0;
}
