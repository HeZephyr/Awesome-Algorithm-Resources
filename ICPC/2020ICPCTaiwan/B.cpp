/**
  *@filename:B
  *@author: pursuit
  *@created: 2021-08-10 15:08
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int l1,r1,l2,r2,q,x;
void change(int &l3,int &r3){
    if(x >= l3 && x <= r3){
        //说明在内部。
        l3 = x - l3;
        r3 = r3 - x;
        r3 = max(l3,r3);
        l3 = 0;
    }
    else if(x < l3){
        //说明在左边。
        l3 -= x,r3 -= x;
    }
    else{
        //说明在右边。
        r3 = x - r3;
        l3 = x - l3;
        swap(l3,r3);
    }
}
void solve(){
    while(q -- ){
        cin >> x;
        //从x点分开。我们需要获取更新后的坐标。
        int l3 = l1,r3 = r1,l4 = l2,r4 = r2;
        change(l3,r3),change(l4,r4);
        //判断区间覆盖。保证l3在l4左边。
        if(l3 > l4){
            swap(l3,l4),swap(r3,r4);
        }
        //cout << l3 << " " << r3 << endl;
        //cout << l4 << " " << r4 << endl;
        if(r3 <= l4){
            cout << r3 - l3 + r4 - l4 << endl;
        }
        else if(r3 <= r4){
            //>l4 <r4
            cout << r4 - l3 << endl;
        }
        else{
            cout << r3 - l3 << endl;
        }
    }
}
int main(){	
    cin >> l1 >> r1 >> l2 >> r2 >> q;
    solve();
    return 0;
}