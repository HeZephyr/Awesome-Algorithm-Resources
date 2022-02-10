/**
  *@filename:D_Make_a_Power_of_Two
  *@author: pursuit
  *@created: 2021-08-18 23:10
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

//擦除使得成为2^k次幂。前导零不会被删除。
map<string,int> p1;
map<string,int> p2;//存储二次幂。
int t,minn;
string n;
void init(){
    ll temp = 1;
    while(temp <= 1e14){
        p2[to_string(temp)] ++;
        temp *= 2;
    }
}
void solve(){
    minn = INF;
    queue<pair<string,int> > q;
    pair<string,int> head,temp;
    q.push({n,0});
    while(!q.empty()){
        head = q.front();
        q.pop();
        if(p2.count(head.first) > 0){
            minn = min(minn,head.second);
            //cout << head.second << endl;
            //cout << head.first << endl;
            break;
        }
        if(p1[head.first])continue;
        p1[head.first] ++;
        //删除。注意不会留出前导零。
        string s = head.first;
        if(s.size() == 0){
            minn = min(head.second + 1,minn);
            continue;
        }
        //cout << s << endl;
        for(auto &x : p2){
            //cout << x.first << endl;
            if(x.first.size() > s.size()){
                bool flag = false;
                for(int i = 0; i < s.size(); ++ i){
                    if(s[i] != x.first[i]){
                        flag = true;
                        break;
                    }
                }
                if(!flag){
                    minn = min(head.second + int(x.first.size()) - int(s.size()),minn);
                    //cout << x.first << endl;
                    break;
                }
            }
        }
        if(s.size() == 1)q.push({"",head.second + 1});
        else{
            for(int i = 0; i < s.size(); ++ i){
                if(i == 0){
                    if(s[i + 1] == '0')continue;
                    q.push({s.substr(1),head.second + 1}); 
                }
                else if(i + 1 == s.size()){
                    q.push({s.substr(0,s.size() - 1), head.second + 1});
                }
                else{
                    q.push({s.substr(0,i) + s.substr(i + 1), head.second + 1});
                }
            }
        }

    }
    cout << minn << endl;
}
int main(){	
    cin >> t;
    init();
    while(t -- ){
        p1.clear();
        cin >> n;
        solve();
    }
    return 0;
}