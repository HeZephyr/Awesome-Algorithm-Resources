#include<bits/stdc++.h>

using namespace std;

const int N = 110;
int t, m, a[N], b[N];
int main(){
    scanf("%d", &t);
    while(t -- ){
        scanf("%d", &m);
        for(int i = 1; i <= m; ++ i){
            scanf("%d", &a[i]);
        }
        for(int i = 1; i <= m; ++ i){
            scanf("%d", &b[i]);
        }
        int idx = -1;
        for(int i = 1; i <= m; ++ i){
            if(3 * a[i] < b[i]){
                idx = i;
                break;
            }
        }
        printf("%d\n", idx);
    }
    return 0;
}