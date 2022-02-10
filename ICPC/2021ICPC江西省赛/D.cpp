#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int t, n, d;
int a[N], b[N];
void print(){
    for(int i = 1; i <= n; ++ i){
        printf("%d%c", a[i], i == n ? '\n' : ' ');
    }
}
bool check(){
    for(int i = 1; i <= n; ++ i){
        if(b[i] == 1){
            return true;
        }
    }
    return false;
}
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d%d", &n, &d);
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
            ++ b[a[i]];
        }
        sort(a + 1, a + 1 + n);
        if(d == 1 || check()){
            print();
            continue;
        }
        int idx = n;
        bool flag = false;
        int minn = 0, x, idx1, idx2;
        while(idx >= 1){
            int st = idx - b[a[idx]] + 1;
            int ed = st + (b[a[idx]] - 1) * d;
            if(ed <= minn){
                idx -= b[a[idx]];
                continue;
            }
            //cout << ed << " " << endl;
            if(ed <= n){
                int cnt = 1, temp = st + 1;
                while(cnt < b[a[idx]]){
                    a[temp] = a[st + cnt * d];
                    ++ cnt, ++ temp;
                }
                cnt = 1;
                while(cnt < b[a[idx]]){
                    a[st + cnt * d] = a[idx];
                    ++ cnt;
                }
                print();
                flag = true;
                break;
            }
            else{
                idx1 = n - (b[a[idx]] - 1) * d;
                //cout << idx << endl;
                if(idx1 >= 1){
                    if(minn < idx1){
                        minn = idx1;
                        idx2 = idx;
                        x = a[idx];
                    }
                }
            }
            idx -= b[a[idx]];
        }
        if(!flag){
            if(minn == 0){
                puts("-1");
            }
            else{
                int cnt = 0;
                //cout << x << " " << cnt << endl;
                while(cnt < b[x] - 1){
                    a[idx] = a[n - cnt * d];
                    -- idx;
                    ++ cnt;
                }
                cnt = 0;
                while(cnt < b[x] - 1){
                    a[n - cnt * d] = x;
                    ++ cnt;
                }
                print();
            }
        }
        for(int i = 1; i <= n; ++ i){
            b[i] = 0;
        }
    }
    return 0;
}
/* 10
9
2
1 1 2 2 2 3 3 3 3
1 1 2 2 3 3 2 3 3 */