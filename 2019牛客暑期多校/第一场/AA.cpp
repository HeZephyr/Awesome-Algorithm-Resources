#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e5+7;
int a[N], b[N];
int n, m;
struct a_node{
    int x, id;
}aa[N], bb[N];
bool cmp(a_node a, a_node b){
    return a.x < b.x;
}
bool judge(int x){
    for(int i = 1; i <= x; ++i){
        aa[i].x = a[i];
        aa[i].id = i;  
        bb[i].x = b[i];
        bb[i].id = i;  
    }
    sort(aa + 1, aa + x + 1, cmp);
    sort(bb + 1, bb + x + 1, cmp);
    for(int i = 1; i <= n; ++i){
        if(aa[i].id != bb[i].id)return false;
    }
    return true;

}

int main(){
    while(cin >> n){
        for(int i = 1; i <= n; ++i){
            scanf("%d", &a[i]);
        }
        for(int i = 1; i <= n; ++i){
            scanf("%d", &b[i]);
        }
        /*int ans = 1;
        for(int i = 1; i < n; ++i){
            if(a[i] < a[i + 1] && b[i] > b[i + 1]){
                ans = i;
                break;
            }
            if(a[i] > a[i + 1] && b[i] < b[i + 1]){
                ans = i;
                break;
            }
            if(i == n - 1)ans = n;
        }*/
        int ans = 1;
        int L = 1, R = n;
        while(L <= R){
            int mid = (L + R)>>1;
            if(judge(mid))L = mid + 1, ans = mid;
            else R = mid - 1;
        }
        printf("%d\n", ans);
    }
}