/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-08-20 14:53
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

/*
n个十字路口，每个路口都有公交车或者有轨电车站。
si = A表示第i个十字路口有公交车站，为B则表示有有轨电车。
初始在第1个十字路口，目标达到最后一个。
从i到j，需要[i,j)处的都是同一个类型的。且需要花费a卢布来坐车。
*/
int t;
ll a,b,p;//做bus需要a，做tram需要b，总共有p。
char s[N];
void solve(){
    vector<int> v;
    int n = strlen(s + 1);
    char cur = s[0];
    for(int i = 1; i <= n; ++ i){
        if(s[i] != cur){
            v.push_back(i);
            cur = s[i];
        }
    }
    int len = v.size();
    if(v[len - 1] == n)v.pop_back(),len --;
    cur = s[1];
    for(int i = 0; i < len; ++ i){
        ll cnt = 0;
        if(cur == 'A'){
            cnt = 1LL * (len - i + 1) / 2 * a + (len - i) / 2 * b;
            cur = 'B';
        }
        else{
            cnt = 1LL * (len - i + 1) / 2 * b + (len - i) / 2 * a;
            cur = 'A';
        }
        if(p >= cnt){
            cout << v[i] << endl;
            return;
        }
    }
    cout << n << endl;
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%lld%lld%lld", &a, &b, &p);
        scanf("%s", s + 1);
        solve();
    }
    return 0;
}