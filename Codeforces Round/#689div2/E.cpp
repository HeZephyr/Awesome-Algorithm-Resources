/**
  *@filename:E
  *@author: pursuit
  *@created: 2021-08-19 20:03
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e6 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

/*
最初包含恰好k L的水，决定水量处于区间[l,r]。
在办公室待t天，其同事每天使用x L水。每天开始的时候可以添加y L水(可以选择不加)。判断是否可以保存在区间。

需要清楚的是，我们需要保证每个时间段都在区间中。所以使用水的时候可能会破坏，这个时候无解。
添加水的时候可能会破坏，这个时候不加水。
*/
ll k,l,r,t,x,y;
bool vis[N];//为y > x做判别用的。
void solve(){
    k -= l, r -= l;//预留出l L水，这样可以取消对l的考虑。
    if(y == x){
        //此时用水量和增水量都是相同的。我们只需要考虑单次加是否符合即可。
        //即第一天就加或者第二天再加。符合其中一种均可。
        printf("%s\n", (k + y <= r || k - x >= 0) ? "YES" : "NO");
    }
    else if(y < x){
        //说明供水量不够，我们肯定是加水就更优。不过这里我们也需要特判第一天的情况，即是否会超过r。
        /*
        如果k + y <= r则可以每天一开始就加水。
        这样消耗量是x - y。所以最多消耗tt = k / d。我们判断是否满足即可。
        倘若不满足，我们判断k - x >= 0即可，即从第二天开始加水。这样我们就需要判断能消耗tt = (k - x) / d，我们判断是否满足即可。
        */
       if(k + y <= r && k / (x - y) >= t){
          puts("YES");
       }
       else if(k - y >= 0 && (k - x) / (x - y) + 1 >= t){
          puts("YES");
       }
       else{
          puts("NO");
       }
    }
    else{
        //说明供水量足够，这个情况就比较复杂， 我们贪心的来向，先让同事喝水，知道不能再消耗为止。
        //此时我们再添水。然后继续等同时喝水，然后继续加。然后只要将要加但还没加的水已经出现过。说明会形成一个可行的循环。
        ll cnt = 0;
        while(true){
            cnt += k / x;
            k %= x;
            if(vis[k]){
                //说明出现可行的循环。一定可行。
                cnt = t;
                break;
            }
            vis[k] = true;
            k += y;
            if(k > r)break;//知道加水超过r说明不可行。
        }
        if(cnt >= t){
            puts("YES");
        }
        else{
            puts("NO");
        }
    }
}
int main(){	
    cin >> k >> l >> r >> t >> x >> y;
    solve();
    return 0;
}