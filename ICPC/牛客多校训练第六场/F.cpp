/**
  *@filename:F
  *@author: pursuit
  *@created: 2021-08-06 21:27
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

//m个平底锅，n个汉堡牛排，第i个汉堡需要t_i时间。其可以在一个锅中煎t_i分钟或者在两个不同的锅中煎a_i和b_i分钟，其中a_i+b_i=t_i。
//其中一个平底锅最多同时煎一个，一个汉堡最多同时放在一个锅中。
//最小化煎的时间。
//输出n行，其中每行第一个整数k，代表在几个锅中煎。其中k个元祖为平底锅编号id，开始时间和结束时间，即[l,r]。
int n,m;
struct node{
    int id;
    ll l,r;
};
vector<node> plans[N];
priority_queue<pii> q;//存储结束时间和汉堡排的编号。
ll T;
void solve(){
    T = max((T + m - 1) / m,1LL * q.top().first);//获取最小耗时T.
    ll time = 0;//当前时刻。
    int id = 1;//平底锅编号。
    while(!q.empty()){
        int t = q.top().first, i = q.top().second;
        q.pop();
        if(time + t <= T){
            //说明时间足够。
            plans[i].push_back({id,time,time + t});
            time += t;
        }
        else{
            //说明时间不够，超出了，我们需要用两个锅分配。
            plans[i].push_back({id,time,T});
            t -= (T - time);//获取还需要操作的时间。
            id ++;
            time = t;
            plans[i].push_back({id,0,time});
        }
        if(time == T){
            time = 0;
            id ++;
        }
    }
    for(int i = 1; i <= n; ++ i){
        if(plans[i].size() == 1){
            printf("1 %d %lld %lld\n", plans[i][0].id, plans[i][0].l,plans[i][0].r);
        }
        else{
            printf("2 %d %lld %lld %d %lld %lld\n", plans[i][1].id, plans[i][1].l,plans[i][1].r, plans[i][0].id, plans[i][0].l,plans[i][0].r);
        }
    }
}
int main(){
    scanf("%d%d", &n, &m);
    int x;
    for(int i = 1; i <= n; ++ i){
        scanf("%lld", &x);
        q.push({x,i});//煎所需的时间。
        T += x;
    }	
    solve();
    return 0;
}