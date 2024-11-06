#include <bits/stdc++.h>
#include <cmath>
#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <termio.h>
#include <array>
#include <random>
static const auto io_sync_off = []()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    return nullptr;
}();
inline int read()
{
    int s=0,w=1;
    char ch=getchar();
    while (!(ch>='0'&&ch<='9'))
    {
        if(ch=='-') 
        {
            w=-1;
        }
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        s=s*10+ch-'0';
        ch=getchar();
    }
    return s*w;
}

struct Actor
{
    std::string name;
    int time;
}
ac;

int main()
{
    int t;
    scanf("%d",&t);
    std::vector<Actor>a;
    while(std::cin>>ac.name)
    {
        if(ac.name!="tingtingting")
        {
            scanf("%d",&ac.time);
            if(t>=0)
            {
                t-=ac.time;
                if(ac.name=="kaomianjin")
                {
                    printf("Congratulations!");
                    return 0;
                }
            }
            else
            {
                printf("Unfortunately.");
                return 0;
            }
            a.push_back(ac);
        }
        else
        {
            t+=a[a.size()-1].time;
            if(a[a.size()-1].name=="kaomianjin")
            {
                printf("Hahaha.");
                return 0;
            }
            a.pop_back();
        }
    }
    return 0;
}
