/**
  *@filename:C_Need_for_Pink_Slips
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-07 23:41
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int t;
double c,m,p,v;
struct node{
    double c,m,p;
    double pre;//先前的概率。
    int step;
};
vector<double> s;
void solve(){
    s.clear();
    double ans = 0;
    queue<node> q;
    q.push({c,m,p,1,1});
    // cout << q.front().c << " " << q.front().m << " " << q.front().p << " " << q.front().step << endl;
    node head,temp;
    while(!q.empty()){
        head = q.front();
        q.pop();
        if(head.p == 0)continue;
        s.push_back(head.pre * head.p * head.step);
        //分两种情况看，一种选c，一种选m。需要判断是否为0.
        for(int i = 0; i < 2; ++ i){
            temp = head;
            temp.step = head.step + 1;
            if(i == 0){
                temp.pre *= temp.c;
                if(temp.c == 0){
                    continue;
                }
                else if(temp.c <= v){
                    if(temp.m == 0){
                        temp.p += temp.c;
                    }
                    else{
                        temp.m += temp.c / 2;
                        temp.p += temp.c / 2;
                    }
                    temp.c = 0;
                }
                else{
                    if(temp.m == 0){
                        temp.p += v;
                    }
                    else{
                        temp.m += v / 2;
                        temp.p += v / 2;
                    }
                    temp.c -= v;
                }
            }
            else{
                temp.pre *= temp.m;
                if(temp.m == 0){
                    continue;
                }
                else if(temp.m <= v){
                    if(temp.c == 0){
                        temp.p += temp.m;
                    }
                    else{
                        temp.p += temp.m / 2;
                        temp.c += temp.m / 2;
                    }
                    temp.m = 0;
                }
                else{
                    if(temp.c == 0){
                        temp.p += v;
                    }
                    else{
                        temp.c += v / 2;
                        temp.p += v / 2;
                    }
                    temp.m -= v;
                }
            }
            /* cout << temp.c << " " << temp.m << " " << temp.p << " " << 
            temp.pre << " " << temp.step << endl; */ 
            q.push(temp);
        }
    }  
    for(auto &x : s){
        //cout << x << endl;
        ans += x;
    }
    printf("%.12lf\n",ans);
}
int main(){
    cin >> t;
    while(t -- ){
        cin >> c >> m >> p >> v;
        solve();
    }    
    return 0;
}