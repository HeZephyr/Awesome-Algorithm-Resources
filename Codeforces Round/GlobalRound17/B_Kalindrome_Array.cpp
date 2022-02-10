#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 2e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, a[N];
void solve(){
    int l = 1, r = n;
    int last = 0;
    while(a[l] == a[r])++ l, -- r;
    if(l >= r){
        puts("YES");
        return;
    }
    int templ = l, tempr = r;
    last = a[l];
    bool flag = false;
    while(l < r){
        if(a[l] == a[r])++ l, -- r;
        else if(a[l] == last){
            ++ l;
        }
        else if(a[r] == last){
            -- r;
        }
        else{
            break;
        }
    }
    if(l >= r){
        puts("YES");
        return;
    }
    l = templ, r = tempr;
    last = a[r];
    while(l < r){
        if(a[l] == a[r])++ l, -- r;
        else if(a[l] == last){
            ++ l;
        }
        else if(a[r] == last){
            -- r;
        }
        else{
            break;
        }
    }
    if(l >= r){
        puts("YES");
        return;
    }
    puts("NO");
}
int main(){	
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &n);
        for(int i = 1, x; i <= n; ++ i){
            scanf("%d", &a[i]);
        }
        solve();
    }
    return 0;
}