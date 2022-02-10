/**
  *@filename:E
  *@author: pursuit
  *@created: 2021-08-16 16:59
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
两种类型的查询。
第一种是给出下标i获取ai的值。
第二种是给出x返回是否存在严格大于x的元素，即判断x是不是最大值。
首先我们可以通过第二种操作二分找到最大值。
*/
int n;
map<int,bool> p;
int find(){
    int l = 0,r = 1e9,x;
    while(l < r){
        int mid = (l + r) >> 1;
        cout << "> " << mid << endl;
        cout.flush();
        cin >> x;
        if(x){
            l = mid + 1;
        }
        else{
            r = mid;
        }
    }
    return l;
}
void solve(){
    int maxx = find(),x,d = 0;
    //开始随机查询。
    mt19937 rnd(1e9 + 7);
    for(int i = 1; i <= min(30,n); ++ i){
        int idx;
        while(idx = rnd() % n + 1){
            if(p[idx])continue;
            p[idx] = 1;
            break;
        }
        cout << "? " << idx << endl;
        cin >> x;
        d = __gcd(d,maxx - x);
    }
    cout << "! " << maxx - (n - 1) * d << " " << d << endl;
}
int main(){	
    cin >> n;
    solve();
    return 0;
}