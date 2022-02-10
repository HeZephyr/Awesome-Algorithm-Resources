/**
  *@filename:F2_Nearest_Beautiful_Number_hard_version
  *@author: pursuit
  *@created: 2021-08-19 14:24
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,k;
string s1;
void solve(){
    while(true){
        set<char> s;//检索当前构造的数有多少个不同的数。
        for(int i = 0; i < s1.size(); ++ i)s.insert(s1[i]);
        if(s.size() <= k){
            //符合题目要求。
            cout << s1 << endl;
            break;
        }
        s.clear();
        int idx = 0;
        while(true){
            //构造。
            s.insert(s1[idx]);
            if(s.size() > k){
                //说明这里出现了分歧错误。我们需要提高这里的值。
                while(s1[idx] == '9'){
                    //这里进位相当于是进位了，我们找到最开始进位的那个即可。
                    idx --;
                }
                s1[idx] ++;//增加一位再判断。
                for(int i = idx + 1; i < s1.size(); ++ i){
                    s1[i] = '0';
                }
                break;
            }
            idx ++;
        }
    }
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> s1 >> k;
        solve();
    }
    return 0;
}