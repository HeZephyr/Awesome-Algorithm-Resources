/**
  *@filename:D
  *@author: pursuit
  *@created: 2021-08-11 10:22
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,k,a[N];
char s[N];
vector<vector<int> > ans;
void solve(){
    //将每轮左转的存入数组中。
    int sum = 0;
    while(true){
        vector<int> now;
        for(int i = 1; i < n; ++ i){
            if(a[i] && !a[i + 1]){
                now.push_back(i);
                //debug(i);
                swap(a[i],a[i + 1]);
                i ++;
            }
        }
        //判断是否还存在转身的。
        if(now.empty())break;
        sum += now.size();//转身对数。
        ans.push_back(now);
    }
    //由于需要使得序列中转身k轮后且恰好不出现转身的序列。
    //若sum > k我们可以填充。
    if(ans.size() > k || sum < k){
        puts("-1");
    }
    else{
        int res = k - ans.size();//需要填充的轮次。
        for(auto now : ans){
            while(now.size() > 1 && res > 0){
                printf("1 %d\n", now.back());
                now.pop_back();
                res --;
            }
            printf("%d ", now.size());
            for(auto x : now){
                printf("%d ", x);
            }
            puts("");
        }
    }
}
int main(){	
    scanf("%d%d", &n, &k);
    scanf("%s", s + 1);
    for(int i = 1; i <= n; ++ i){
        if(s[i] == 'R')a[i] = 1;
    }
    solve();
    return 0;
}