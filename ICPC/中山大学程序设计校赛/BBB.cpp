#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 +10;
int r[N],c[N];
typedef long long LL;

void solve()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i ++)
    r[i] = c[i] = 0;
    int dia = 0,rcnt = 0,ccnt = 0,diacnt = 0;
    while (m -- )
    {
        char op[2];
        scanf("%s",op); 
        if(op[0] == 'D') {if(dia > 0) {dia = 0;} else if(dia == 0) {dia = 1;}}
        else 
        {
            int x; scanf("%d",&x);
            //printf("x = %d\n",x);
            if(op[0] == 'R')// 要将 x 这一行的灯都点亮了
            {
                if(r[x] == 0) {r[x] = 1;rcnt ++;}
                else if(r[x] == 1){r[x] = 0;rcnt --;}
                //diacnt 记录的是对角线上的亮灯的数量
                if(r[x] ^ c[x] == 0) diacnt -- ;//如果当前的 x 这一行和 x 这一列都被点亮了 那么dia[x] 就要熄灭了
                else if(r[x] ^ c[x] != 0)diacnt ++;//r[x] 
            }
            else 
            {
                if(c[x] == 0) {c[x] = 1;ccnt ++;}
                else if(c[x] == 1){c[x] = 0;ccnt --;}
                //diacnt 记录的是对角线上的亮灯的数量
                if(r[x] ^ c[x] == 0) diacnt -- ;//如果当前的 x 这一行和 x 这一列都被点亮了 那么dia[x] 就要熄灭了
                else diacnt ++;
            }
        }
       // printf("%d %d %d %d \n",rcnt,ccnt,diacnt,dia);
        printf("%lld\n",(LL)1 * (LL)(rcnt + ccnt) * (LL)n - (LL)rcnt * (LL)ccnt * 2 + (LL)(n - 2 * diacnt) * (LL)dia);
        // 若 dia 为 1 说明主对角线要亮起来
        // (rcnt + ccnt) * n - rcnt * ccnt * 2 : 还未考虑对角线上的情况
        // (n - 2 * diacnt) * dia : 主对角线亮起时 对角线上原本就已经有 diacnt 个灯是亮着的了 
        // 因此考虑其贡献为 (n - 2 * cnt)
        // 对角线不亮起的话 那么只需要考虑行和列的基本情况即可
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T --)
    {
        solve();
    }
    return 0;
}
