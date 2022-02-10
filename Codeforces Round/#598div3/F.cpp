/**
  *@filename:F
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-28 20:34
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t,n;
string s1,s2;
int cnt1[26],cnt2[26];
void solve(){
    memset(cnt1,0,sizeof(cnt1));
    memset(cnt2,0,sizeof(cnt2));
    for(int i = 0; i < n; ++ i){
        cnt1[s1[i] - 'a'] ++;
        cnt2[s2[i] - 'a'] ++;
    }
    bool flag = false;
    for(int i = 0; i < 26; ++ i){
        if(cnt1[i] != cnt2[i]){
            flag = true;
            break;
        }
    }
    if(flag){
        cout << "NO" << endl;
    }
    else{
        for(int i = 0; i < 26; ++ i){
            if(cnt1[i] >= 2){
                flag = true;
                break;
            }
        }
        if(flag){
            cout << "YES" << endl;
        }
        else{
            //最后判断交换情况，我们模拟交换，即构造前n - 2个，然后利用t中的最后两个一直轮换。
            for(int i = 0; i < n - 2; ++ i){
                int pos = -1;
                for(int j = 0; j < n; ++ j){
                    if(s1[i] == s2[j]){
                        pos = j;
                        break;//获取第一个于s1[i]相等的位置。
                    }
                }
                while(pos > i){
                    swap(s1[n - 1],s1[n - 2]);
                    swap(s2[pos],s2[pos - 1]);
                    pos --;
                }
            }
            if(s1[n - 1] == s2[n - 1]){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
    }
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> n;
        cin >> s1 >> s2;
        solve();
    }
    return 0;
}