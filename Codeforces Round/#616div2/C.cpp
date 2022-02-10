/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-08-22 16:43
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 4e3 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

//行首的人选择第一个或者最后一个元素，将其删除并保留。然后下一个人继续这个过程。
//开始之前可以让指定最多k个人说服他们呢轮到它们的时候选择第一个或者最后一个数。
//求处最大的x，使得不管没有选择的人有任何决策产生的数都>=x。
int t,n,m,k,a[N];
void solve(){
    //枚举前m - 1个中k个人的选择方案和剩下的人的选择方案。
    //由于m可能很靠前，所以我们修改以下k的值。
    if(k >= m)k = m - 1;
    int res = 0;
    for(int i = 0; i <= k; ++ i){
        //i个人选择第一个元素，k - i个人选择最后一个元素。这是可以确定的，所以这里为最大值。
        int minn = INF;
        for(int j = 0; j <= m - k - 1; ++ j){
            //j个人选择第一个元素，m - k - j - 1个人选择最后一个元素。这是不确定的，所以这里取最小值。
            //所以总共有i + j个人选择第一个元素，k - i + m - k - j - 1 = m - i - j - 1个人选择了最后一个元素。
            minn = min(minn, max(a[i + j + 1], a[n - (m - i - j - 1)]));
            //cout << i << " " << j << " " << i + j + 1 << " " << n - (m - i - j - 1) << " " << endl;
        }
        res = max(res, minn);
    }
    printf("%d\n", res);
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
        }
        solve();
    }
    return 0;
}