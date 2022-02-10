/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-08-09 17:30
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 4e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n,a[N];
void solve(){
    vector<int> pos;
    for(int i = 2; i <= n; ++ i){
        if(a[i] != a[i - 1]){
            pos.push_back(i);
        }
    }
    if(pos.size() < 3){
        puts("0 0 0");
        return;
    }
    int g,s = n,b = n;
    g = pos[0] - 1;
    int idx = 0;
    for(int i = idx + 1; i < pos.size(); ++ i){
        //根据间隔获取银牌数量。
        int temp = pos[i] - pos[idx];
        if(g < temp){
            s = temp;
            idx = i;
            break;
        }
    }
    for(int i = idx + 1; i < pos.size(); ++ i){
        //根据间隔获取铜牌数量。
        int temp = pos[i] - pos[idx];
        if(g + s + temp > n / 2){
            break;
        }
        else{
            b = temp;
        }
    }
    //cout << g << " " << s << " " << b << endl;
    //判断是否符合题目要求。
    if(g >= s || g >= b || g + s + b > n / 2){
        puts("0 0 0");
    }
    else{
        printf("%d %d %d\n", g, s, b);
    }
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
        }
        solve();
    }	
    return 0;
}