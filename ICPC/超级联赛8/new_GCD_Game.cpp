#include<bits/stdc++.h>
#define LL long long
#define INF INT64_MAX
#define MOD 1000000007
#define stree SegTree[root]
#define lson SegTree[root << 1]
#define rson SegTree[root << 1 | 1]
using namespace std;
typedef pair<int,int>pa;
const int N = 1e7+7;
char s[N];
int b[N],ans[N];
bool vis[N];
int main()
{
    int t, n, x;
    scanf("%d", &t);
    int cnt = 0;
    for(int i=2;i<=1e7;i++)
    {
        //printf("i = %d\n", i);
        if(!vis[i]) b[++cnt] = i;//如果这个数是质数，就将其保存下来
        for(int j = 1;j <= cnt;j++)//将这个数与已有的质数进行操作
        {
            if(i*b[j]>1e7) break;
            //printf("j = %d\n", j);
            vis[i*b[j]] = true;//将这个数与该质数的积标记为非质数
            if(!(i%b[j])) break;//如果当前数是该质数的倍数，就退出循环（这个在后面会进行解释）
        }
    }
    for(int i = 2; i <= 1e7; ++ i){
        int temp = i;
        for(int j = 1; j <= cnt; ++ j){
            if(temp < b[j])break;
            while(temp % b[j] == 0){
                temp /= b[j];
                ans[i] ++;
            }
        }
        if(temp > 1){
            ans[i] ++;
        }
    }
    while(t--)
    {
        scanf("%d", &n);
        int res = 0;
        //printf(" vis = %d, %d\n", vis[1], vis[2]);
        for(int i = 1;i <= n;i++)
        {
            scanf("%d", &x);
            res ^= ans[x];
        }
        if(!res) printf("Bob\n");
        else printf("Alice\n");
    }
    return 0;
}