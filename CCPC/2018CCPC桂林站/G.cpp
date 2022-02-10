#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+7;

int a[N];
int main(){
    int t, n;
    scanf("%d", &t);
    for(int tt = 1;tt <= t;tt++){
        scanf("%d", &n);
        int gc = 0;
        for(int i = 1;i <= n;i++){
            scanf("%d", &a[i]);
        }
        sort(a+1, a+1+n);
        n = unique(a + 1, a + n + 1) - a - 1;
        for(int i = 1;i <= n;i++){
            gc = __gcd(gc, a[i]);
        }
        printf("Case %d: ", tt);
        if(gc>1){
            printf("0\n");
            continue;
        }
        //cout << n << endl;
        gc = 0;
        for(int i = 1;i < n;i++){
            gc = __gcd(gc, a[i+1]-a[i]);
        }
        if(!gc){
            printf("1\n");
            continue;
        }
        vector<int> v;
        //if(gc>1) v.push_back(gc);
        for(int i = 2;i*i <= gc;i++){
            if(gc%i==0){
                v.push_back(i);
                while(gc%i==0){
                    gc/=i;
                }
            }
        }
        if(gc>1) v.push_back(gc);
        int ans = INT_MAX;
        for(auto it:v){
            int tem = a[1]%it;
            for(int i = 2;i <= n;i++){
                if(a[i]%it!=tem){
                    break;
                }
                if(i==n){
                    ans = min(ans, it-tem);
                }
            }
        }
        if(ans==INT_MAX) printf("-1\n");
        else printf("%d\n", ans);
    }
    return 0;
}
