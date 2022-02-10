#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
const int N = 1000 + 10;
int n;
struct node{
    ll a,b,c;
    int id;
    bool operator < (const node &A){
        ll temp1 = c * (A.a + A.b);
        ll temp2 = A.c * (a + b);
        if(temp1 == temp2){
            return id < A.id;
        }
        return temp1 > temp2;
    }
}nums[N];
void solve(){
    sort(nums + 1,nums + 1 + n);
    for(int i = 1; i <= n; ++ i){
        printf("%d%c", nums[i].id, i == n ? '\n' : ' ');
    }
}
int main(){
    while(~scanf("%d", &n)){
        for(int i = 1; i <= n; ++ i){
            scanf("%lld%lld%lld", &nums[i].a, &nums[i].b, &nums[i].c);
            nums[i].id = i;
        }
        solve();
    }
    return 0;
}