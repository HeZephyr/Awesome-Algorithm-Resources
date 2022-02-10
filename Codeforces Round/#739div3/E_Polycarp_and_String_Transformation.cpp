/**
  *@filename:E_Polycarp_and_String_Transformation
  *@author: pursuit
  *@created: 2021-08-19 15:26
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<string,string> pss;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t;
string s;
int cnt[26];//统计字母出现次数。
pss work(string s){
    string order = "";
    //从后往前遍历，得到删除的逆顺序。
    reverse(s.begin(),s.end());
    for(auto c : s){
        if(!cnt[c - 'a']){
            order += c;
        }
        cnt[c - 'a'] ++;
    }
    int len = 0,n = order.size();//为原来的字符串长度。
    for(int i = 0; i < n; ++ i){
        //依次出现了m - i次。
        len += cnt[order[i] - 'a'] / (n - i);
    }
    reverse(order.begin(),order.end());//将顺序回正。
    //由于这里我们发转了，所以我们需要从后取到前。
    return {string(s.rbegin(),s.rbegin() + len), order};
}
bool check(pss ans){
    string result = ans.first;
    for(auto c : ans.second){
        string temp ;
        //将c删除。
        for(auto d : ans.first){
            if(d != c){
                temp += d;
            }
        }
        result += temp;
        ans.first = temp;
    }
    return s == result;
}
void solve(){
    pss ans = work(s);
    //验证正确性。
    if(check(ans)){
        cout << ans.first << " " << ans.second << endl;
    }
    else{
        cout << -1 << endl;
    }
}
int main(){
    cin >> t;
    while(t -- ){
        memset(cnt,0,sizeof(cnt));
        cin >> s;
        solve();
    }	
    return 0;
}