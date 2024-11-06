#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main()
{
    int n;
    cin>>n;
    stack<int> s1,s2;
    for(int i=0;i<n;i++)
    {
        char c,x;
        cin>>x>>c;
        if(x=='A')
        {
            if(c=='I')
            {
                int data;
                cin>>data;
                s1.push(data);
            }
            else if(c=='D')
            {
                if(s1.size())
                    s1.pop();
            }
            else if(c=='M')
            {
                stack<int> s3;
                while(s2.size())
                {
                    s3.push(s2.top());
                    s2.pop();
                }
                while(s3.size())
                {
                    s1.push(s3.top());
                    s3.pop();
                }
            }
        }
        if(x=='B')
        {
            if(c=='I')
            {
                int data;
                cin>>data;
                s2.push(data);
            }
            else if(c=='D')
            {
                if(s2.size())
                    s2.pop();
            }
            else if(c=='M')
            {
                stack<int> s3;
                while(s1.size())
                {
                    s3.push(s1.top());
                    s1.pop();
                }
                while(s3.size())
                {
                    s2.push(s3.top());
                    s3.pop();
                }
            }
        }
    }
    while(s1.size())
    {
        cout<<s1.top()<<" ";
        s1.pop();
    }
    cout<<endl;
    while(s2.size())
    {
        cout<<s2.top()<<" ";
        s1.pop();
    }
    cout<<endl;
    return 0;
}
