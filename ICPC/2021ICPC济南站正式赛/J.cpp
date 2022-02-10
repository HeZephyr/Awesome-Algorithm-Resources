#include<bits/stdc++.h>
#define double long double
using namespace std;
const int maxn = 220;
double a[maxn][maxn];
int n;
double eps = -1e-8;
int Gauss(int n){
    int r = 1;
    int sum = 0;
    for(int i = 1; i <= n; ++i){
        int maxi = r;
        for(int j = r + 1; j <= n; ++j){
            if(fabs(a[j][i]) > fabs(a[maxi][i])){
                maxi = j;
            }
        }
        if(!a[maxi][i]){
            sum++;
            continue;
        }
        for(int j = 1; j <= n + 1; ++j){
            swap(a[r][j], a[maxi][j]);
        }
        if(r != maxi){
            for(int j = 1; j <= n; ++j)
                a[r][j] *= -1.0;
        }
        for(int j = 1; j <= n; ++j){
            if(r != j){
                double temp = a[j][i] / a[r][i];
                for(int k = i + 1; k <= n + 1; ++k){
                    a[j][k] -= a[r][k] * temp;
                }
                a[j][i] = 0;
            }
        }
        r++;
    }
    return sum;
}
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        string s;
        cin >> s;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                scanf("%Lf", &a[i][j]);
            }
        }
        Gauss(n);
        /*
        printf("-------\n");
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                printf("%Lf ", a[i][j]);
            }
            printf("\n");
        }
        */
        int ans = 1;
        double sum = 1;
        for(int i = 1; i <= n; ++i){
            if(a[i][i] < eps)ans *= -1;
            //sum *= a[i][i];
        }
        if(ans > 0)printf("+\n");
        else printf("-\n");
        //const double xx = 1e9;
        //if((1e9 - xx < eps))cout << "YES" << endl;
        //printf("%lf", (1e9 - xx));
        //cout << " ans : " << sum << endl;
    }
    return 0;
}