#include<bits/stdc++.h>
using namespace std;
int b[100005];
int main()
{
    int t, n, m;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        for(int i = 1;i <= m;i++)
            scanf("%d", &b[i]);
        sort(b+1, b+1+m);
        int tem = b[1]*2;
        for(int i = 2;i < m;i++)
        {
            if(b[i]<=tem) tem+=2;
            else tem = b[i-1]+(b[i]-tem)*2;
        }
        if(b[m] < tem)
        {
            if(m-1 >= n-tem-1) printf("1YES\n");
            else printf("1NO\n");
        }
        else
        {
            if(b[m]-tem <= n-tem && b[m]-tem+m-1 >= n-tem) printf("2YES\n");
            else printf("2NO\n");
        }

    }
    return 0;
}