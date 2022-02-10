#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

//可以买折扣卡，免租数次。如果购买了一张免租k次、有效期d天的优惠卡后，那么接下来的d天里，k次房租不需要任何的费用。
//无论何时在t天购买该卡，那么都会在t + d - 1天结束过期。然后新的折扣卡即使仍然有效也会覆盖之前的折扣卡，即购买新的折扣卡时，前一张折扣卡的剩余免费金额将立即作废。
//现在有n种类型的折扣卡，免租ki，有效期di天的i类卡，可以无限次购买任何类型的折扣卡。
//有m条租房记录。代表在pi天租自行车qi次。
void solve(){
}
int main(){	
    solve();
    return 0;
}