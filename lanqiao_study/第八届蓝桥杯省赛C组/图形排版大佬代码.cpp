#include "algorithm"
#include "cstdio"
#include "iostream"
#pragma GCC optimize(3)
using namespace std;
typedef pair<int, int> PII;
const int MAXN = 100005;
const int INF = 0x3f3f3f3f;
// 存n张图片,first为宽，second为高
PII arr[MAXN];

// 预处理,f[i]表示第i张图到第n张图需要的高度
int f[MAXN];
int n, m;
// Add用于往一个行里加入第k张图片
void Add(PII *p, int k)
{

    if (p->first + arr[k].first < m)
    {
        p->first += arr[k].first;
        p->second = max(p->second, arr[k].second);
    }
    else
    {
        p->second = max(p->second, (arr[k].second * (m - p->first) - 1) / arr[k].first + 1);
        p->first = m;
    }
}
int getF(PII p, int k)
{
    while (k <= n && p.first < m)
    {
        Add(&p, k);
        k++;
    }
    // 因为已经求出f[k]了,所以k后面就不用再算了;
    return p.second + f[k];
}
int main()
{
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &arr[i].first, &arr[i].second);//输入图片的宽和高。
    for (int i = n; i >= 1; i--)
        f[i] = getF(make_pair(0, 0), i);
    // pre表示在now表示的行上面已经存在的高度;
    int pre = 0, res = INF;
    // now表示当前正在填充的行
    PII now = make_pair(0, 0);
    for (int i = 1; i <= n; i++)
    {
        res = min(res, pre + getF(now, i + 1));
        Add(&now, i);
        if (now.first == m)
        {
            pre += now.second;
            now.first = now.second = 0;
        }
    }
    printf("%d\n", res);
    return 0;
}
/**************************************************************
    Problem: 1336
    User: yf_peng
    Language: C++
    Result: 人品问题-愚人节快乐
    Time:20 ms
    Memory:3260 kb
****************************************************************/