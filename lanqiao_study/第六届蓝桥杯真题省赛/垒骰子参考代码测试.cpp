#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 6, P = 1e9 + 7;

int n, m;
int op[] = {3, 4, 5, 0, 1, 2};
int h[7][7];
bool st[N][N];

void mul(int c[], int a[], int b[][N])
{
    int temp[N] = {0};
    for (int i = 0; i < N; i ++ )
    {
        for (int j = 0; j < N; j ++ )
        {
            temp[i] = (temp[i] + (LL)a[j] * b[j][i]) % P;
        }
    }
    memcpy(c, temp, sizeof(temp));
}

void mul(int c[][N], int a[][N], int b[][N])
{
    int temp[N][N] = {0};
    for (int i = 0; i < N; i ++ )
    {
        for (int j = 0; j < N; j ++ )
        {
            for (int k = 0; k < N; k ++ )
            {
                temp[i][j] = (temp[i][j] + (LL)a[i][k] * b[k][j]) % P;
            }
        }
    }

    memcpy(c, temp, sizeof(temp));
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i ++ )
    {
        int a, b;
        cin >> a >> b;
        st[a - 1][b - 1] = st[b - 1][a - 1] = true;
    }

    int f1[N] = {4, 4, 4, 4, 4, 4};
    int a[N][N];
    for (int i = 0; i < N; i ++ )
    {
        for (int j = 0; j < N; j ++ )
        {
            if (st[j][op[i]]) a[j][i] = 0;
            else a[j][i] = 4;
        }
    }

    n -- ;
    while(n)
    {
        if (n & 1) mul(f1, f1, a);
        mul(a, a, a);
        n >>= 1;
    }

    int res = 0;
    for (int i = 0; i < N; i ++ )
    {
        res = (res + f1[i]) % P;
    }
    cout << res;

    return 0;
}