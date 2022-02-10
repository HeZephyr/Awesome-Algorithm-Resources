/**
  *@filename:B_Make_it_Divisible_by_25
  *@author: pursuit
  *@created: 2021-10-13 22:39
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t;
string s;
struct node{
    string s;
    int step;
};
bool check(string s){
    ll temp = stoll(s);
    if(temp % 25 == 0)return true;
    return false;
}
void solve(){
    queue<node> q;
    q.push({s, 0});
    set<string> st;
    st.insert(s);
    node head, temp;
    while(!q.empty()){
        head = q.front();
        //cout << head.s << endl;
        q.pop();
        if(check(head.s)){
            cout << head.step << endl;
            break;
        }
        if(head.s.size() == 1)continue;
        temp.step = head.step + 1;
        for(int i = 0; i < head.s.size(); ++ i){
            if(i == 0)temp.s = head.s.substr(1);
            else if(i == head.s.size() - 1){
                temp.s = head.s.substr(0, head.s.size() - 1);
            }
            else{
                temp.s = head.s.substr(0, i) + head.s.substr(i + 1);
            }
            if(st.find(temp.s) == st.end()){
                st.insert(temp.s);          
                q.push(temp);
            }
        }
    }
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> s;
        solve();
    }
    return 0;
}