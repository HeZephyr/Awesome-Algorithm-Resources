/**
  *@filename:D
  *@author: pursuit
  *@created: 2021-08-09 18:01
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int num[4],cnt,temp[4];
void solve(){
    //枚举出发点。
    vector<int> ans(cnt);
    for(int st = 0; st < 4; ++ st){
        if(num[st]){
            bool flag = true;
            int last = st,idx = 1;
            ans[0] = st;
            for(int i = 0; i < 4; ++ i)temp[i] = num[i];
            temp[st] --;
            for(int i = 0; i < cnt - 1; ++ i){
                if(last + 1 < 4 && temp[last + 1]){
                    temp[++last] --;
                    ans[idx++] = last;
                }
                else if(last - 1 >= 0 && temp[last - 1]){
                    temp[--last] --;
                    ans[idx++] = last;
                }
                else{
                    flag = false;
                    break;
                }
            }
            if(flag){
                cout << "YES" << endl;
                for(int i = 0; i < cnt; ++ i){
                    cout << ans[i] << " ";
                }
                cout << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
}
int main(){
    for(int i = 0; i < 4; ++ i){
        cin >> num[i];
        cnt += num[i];
    }	
    solve();
    return 0;
}