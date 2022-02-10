/**
  *@filename:K
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-31 12:40
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int n,m,k,a[N];
int q1[N],q2[N];//维护一个递增队列和一个递减队列。
int s1,e1,s2,e2;
ll ans;
void solve(){
    while(m -- ){
        scanf("%d", &k);
        ans = 0;
        s1 = s2 = 1,e1 = e2 = 0;
        int r = 0;
        for(int i = 1; i <= n; ++ i){
            //维护单调递增和单调递减队列。
            while(s1 <= e1 && a[q1[e1]] >= a[i])e1 --;
            while(s2 <= e2 && a[q2[e2]] <= a[i])e2 --;
            q1[++e1] = i, q2[++e2] = i;
            //直到极差小于等于k。
            //当退出循环的时候我们已经找到了那个最小的r，很明显，[1,r]的都符合。所以区间个数有r个。
            while(s1 <= e1 && s2 <= e2 && a[q2[s2]] - a[q1[s1]] > k){
                //cout << a[q2[s2]] << " " << a[q1[s1]] << endl;
                if(s1 <= e1 && (s2 > e2 || q1[s1] < q2[s2])){
                    //如果最大值队列为空或者该队首元素靠前。。
                    r = q1[s1 ++];//记录下标。
                }
                else{
                    r = q2[s2 ++];
                }
            }
            //cout << i << " " << r << endl;
            ans += r;
        }
        printf("%lld\n", ans);
    }
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    solve();
    return 0;
}