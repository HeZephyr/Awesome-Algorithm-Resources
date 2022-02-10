/**
  *@filename:C_Interesting_Story
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-23 23:22
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 200000 + 5;
const int P = 1e9+7;

int t,n;
string s;
struct node{
    int cnt[5];
    int len,num;//num为我们要判断的字符的长度。
    bool operator < (const node & A){
        return num > A.num;
    }
}temp[N],ans[N];
void solve(){
    int maxx = 0;
    for(int c = 0; c < 5; ++ c){
        for(int i = 1; i <= n; ++ i){
            ans[i] = temp[i];
            ans[i].num = temp[i].cnt[c] * 2 - temp[i].len;
        }
        sort(ans + 1,ans + 1 + n);
        int sum = 0;
        for(int i = 1; i <= n + 1; ++ i){
            if(i == n + 1){
                maxx = n;
                break;
            }
            //cout << ans[i].num << " ";
            sum += ans[i].num;
            if(sum <= 0){
                maxx = max(maxx, i - 1);
                break;
            }
        }
        //cout << endl;
    }
    for(int i = 1; i <= n; ++ i){
        memset(temp[i].cnt,0,sizeof(temp[i].cnt));
    }
    cout << maxx << endl;
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n;
        for(int i = 1; i <= n; ++ i){
            cin >> s;
            temp[i].len = s.size();
            for(int j = 0; j < s.size(); ++ j){
                temp[i].cnt[s[j] - 'a'] ++;
            }
        }
        solve();
    }
    return 0;
}