/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-08-07 19:03
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl;

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

string s;
int minn;
set<string> v;
struct node{
    string s;
    int step;
};
void bfs(){
    queue<node> q;
    node head;
    head.s = s,head.step = 0;
    q.push(head);
    bool flag = false;
    while(!q.empty()){
        head = q.front();
       //cout << head.s << endl;
        q.pop();
        if(head.s[0] == '0' || head.s.size() == 0)continue;
        if(v.find(head.s) != v.end())continue;
        else v.insert(head.s);
        int n = stoll(head.s);
        int temp = sqrt(n);
        if(temp * temp == n){
            flag = true;
            cout << head.step << endl;
            break;
        }
        else{
            for(int i = 0; i < head.s.size(); ++ i){
                string temp;
                if(i == 0){
                    temp = head.s.substr(i + 1);
                }
                else if(i == head.s.size() - 1){
                    temp = head.s.substr(0,i);
                }
                else{
                    temp = head.s.substr(0,i) + head.s.substr(i + 1);
                }
                q.push({temp,head.step + 1});
            }
        }
    }
    if(!flag){
        cout << - 1 << endl;
    }
}
void solve(){
    bfs();
}
int main(){
    int t;
    cin >> t;
    while(t -- ){
        v.clear();
        cin >> s;
        solve();
    }	
    return 0;
}