#include<bits/stdc++.h>

using namespace std;
using ll = long long;
const int N = 1e6 + 7;
char a[N];
int b[N], n;
bool vis[N];
bool check(int x){
    bool flag = false;
    int last = 0;//上个1剩下的。
    for(int i = 1; i <= n + 1; ++ i){
        if(a[i] == '1'){
            //b[i] - b[i - 1];
            int temp = b[i] - b[i - 1] - 1;
            if(i == n + 1)x = 0;
            if(temp > x + last){
                flag = true;
                break;
            }
            else if(temp == x + last){
                last = max(x - 1, 0);
            }
            else{
                last = x;
            }
        }
    }
    return flag;
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        scanf("%s", a + 1);
        for(int i = 1; i <= n; ++ i){
            if(a[i] == '1')b[i] = i;
            else b[i] = b[i - 1];
        }
        a[n + 1] = '1';
        b[n + 1] = n + 1;
        int l = 0, r = n + 1;
        while(l < r){
            int mid = (l + r) >> 1;
            if(!check(mid)){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        printf("%d\n", l);
    }
}