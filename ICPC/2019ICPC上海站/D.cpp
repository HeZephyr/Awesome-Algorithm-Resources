#include<bits/stdc++.h>

using namespace std;

int main(){
    int t, n;
    scanf("%d", &t);
    for(int c = 1;c <= t;c++){
        scanf("%d", &n);
        printf("Case #%d: %d\n", c, n/2);
        if(n&1){
            int m = n/2, tem = 0;
            while(m--){
                tem++;
                int st = 1, x;
                for(int i = 1, j = 1;j <= n-1;i = x, j++){
                    x = (i+tem)%n==0 ? n : (i+tem)%n;
                    if(x == st){
                        printf("%d %d\n", i, st+1);
                        st++;
                        x = st;
                    }
                    else{
                        printf("%d %d\n", i, (i+tem)%n==0 ? n : (i+tem)%n);
                    }
                }
            }
        } else {
            int m = n/2-1, tem = 0;
            n--;
            while(m--){
                tem++;
                int st = 1, x;
                for(int i = 1, j = 1;j <= n-1;i = x, j++){
                    x = (i+tem)%n==0 ? n : (i+tem)%n;
                    if(x == st){
                        printf("%d %d\n", i, st+1);
                        st++;
                        x = st;
                    }
                    else{
                        printf("%d %d\n", i, (i+tem)%n==0 ? n : (i+tem)%n);
                    }
                }
                printf("%d %d\n", n+1, n+1-tem);
            }
            n++;
            for(int i = 2;i <= n/2;i++){
                printf("%d %d\n", i, n);
            }
            for(int i = n/2+1;i <= n;i++){
                printf("1 %d\n", i);
            }
        }
    }
    return 0;
}