#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a[105];
    int n;
    cin >> n;
    int front = 1;
    int rear = n;
    for (int i = 1;i <= n;i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            string name;
            cin >> name;
            int x;
            int q;
            for (int j = front;j <= rear;j++)
            {
                x = 0;
                if (a[j][0] == name[0] && x == 0)
                {
                    x = 1;
                    q = x;
                }
            }
            if (q == 1)
            {
                for (int j = rear;j >= q + 2;j--)
                {
                    a[j + 1] = a[j];
                }
                rear++;
                a[x + 1] = name;
            }
            else
            {
                rear++;
                a[rear] = name;
            }
        }
        else
        {
            if (rear - front > 0)
            {
                cout << a[front] << endl;
                front++;
            }
            else
            {
                cout << "0" << endl;
            }
        }
    }
    return 0;
}
