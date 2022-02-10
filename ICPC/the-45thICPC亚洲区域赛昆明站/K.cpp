#include <bits/stdc++.h> //code by cjj490168650
using namespace std;

int T;
char s[110];
int cnt[50],tmp[50],sum[10];

int get_id(char x,char y)
{
    int re=x-'0';
    if (y=='b') re+=10;
    if (y=='s') re+=20;
    if (y=='z') re+=30;
    return re;
}

char get_col(int id)
{
    if (id<10) return 'w';
    if (id<20) return 'b';
    if (id<30) return 's';
    return 'z';
}

bool can_hu_2(int *cnt) //判断去掉雀头后能否和牌
{
    for (int i=1;i<=29;i++)
    {
        if (cnt[i]%3)
        {
            if (cnt[i+1]<cnt[i]%3) return false;
            if (cnt[i+2]<cnt[i]%3) return false;
            cnt[i+1]-=cnt[i]%3;
            cnt[i+2]-=cnt[i]%3;
        }
    }
    for (int i=31;i<=37;i++)
    {
        if (cnt[i]%3) return false;
    }
    return true;
}

bool can_hu() //判断能否和牌
{
    bool ok=false;
    for (int i=1;i<=37;i++) //枚举雀头
    {
        if (cnt[i]>=2)
        {
            cnt[i]-=2;
            memcpy(tmp,cnt,sizeof(cnt));
            if (can_hu_2(tmp)) ok=true;
            cnt[i]+=2;
            if (ok) return true;
        }
    }
    return false;
}

void get_cnt()
{
    memset(cnt,0,sizeof(cnt));
    memset(sum,0,sizeof(sum));
    for (int i=1;i<=28;i+=2)
    {
        int id=get_id(s[i],s[i+1]);
        cnt[id]++;
        sum[id/10]++;
    }
}

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",s+1);
        get_cnt();
        if (can_hu()) printf("Tsumo!\n");
        else
        {
            map<int,vector<int>> ans;
            for (int i=1;i<=37;i++) //枚举打出的牌
            {
                if (!cnt[i]) continue;
                cnt[i]--;
                sum[i/10]--;
                for (int j=1;j<=37;j++) //枚举进张的牌
                {
                    if (j%10==0) continue;
                    cnt[j]++;
                    sum[j/10]++;
                    if (can_hu())
                    {
                        ans[i].push_back(j);
                    }
                    cnt[j]--;
                    sum[j/10]--;
                }
                cnt[i]++;
                sum[i/10]++;
            }
            printf("%d\n",(int)ans.size());
            for (auto [i,v]:ans)
            {
                printf("%d%c ",i%10,get_col(i));
                for (int j:v)
                {
                    printf("%d%c",j%10,get_col(j));
                }
                printf("\n");
            }
        }
    }
    return 0;
}