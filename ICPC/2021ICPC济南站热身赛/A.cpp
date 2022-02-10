#include<bits/stdc++.h>
using namespace std;
const int N = 77;

int sgn[N], a[N], b[N], c[N];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1;i <= n;i++){
        scanf("%d", &sgn[i]);
    }
    for(int i = 1;i <= n;i++){
        scanf("%d", &a[i]);
    }
    for(int i = 1;i <= n;i++){
        scanf("%d", &b[i]);
        c[i] = a[i]+b[i];
    }
    for(int i = 1;i <= n;i++){
        if(c[i]>=2){
            //printf("i = %d\n", i);
            int tem = c[i]/2;
            c[i] = c[i]%2;
            for(int j = i+1;j <= n;j++){
                //printf("j = %d, tem = %d\n", j, tem);
                c[j] += tem;
                if(sgn[j]==sgn[i]) break;
            }
        }
    }
    for(int i = 1;i <= n;i++){
        printf("%d", c[i]);
        if(i!=n) printf(" ");
    }
    return 0;
}