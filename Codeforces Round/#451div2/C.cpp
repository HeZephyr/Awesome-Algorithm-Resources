/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-08-12 14:31
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 22 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,cnt;
map<int,string> p1;
map<string,int> p2;
vector<string> ans[N];
string s,num;
//按字符串长度排序。
bool cmp(string a,string b){
    return a.size() < b.size();
}
void solve(){
    cout << p2.size() << endl;
    for(int i = 1; i <= cnt; ++ i){
        //处理每个人的号码。 
        sort(ans[i].begin(),ans[i].end(),cmp);
        for(int j = 0; j < ans[i].size(); ++ j){
            string num1 = ans[i][j];
            for(int k = j + 1; k < ans[i].size(); ++ k){
                string num2 = ans[i][k];
                if(num2.substr(num2.size() - num1.size()) == num1){
                    ans[i].erase(ans[i].begin() + j);
                    j --;
                    break;
                }
            }
        }   
        cout << p1[i] << " " << ans[i].size() << " ";
        for(int j = 0; j < ans[i].size(); ++ j){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
int main(){
    cin >> n;
    for(int i = 1; i <= n; ++ i){
        cin >> s;
        if(!p2[s]){
            p2[s] = ++ cnt;
            p1[cnt] = s;
        }
        int id = p2[s],tot;
        cin >> tot;
        while(tot -- ){
            cin >> num;
            ans[id].push_back(num);
        }
    }	
    solve();
    return 0;
}