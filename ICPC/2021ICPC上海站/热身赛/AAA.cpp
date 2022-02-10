#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n;
double y[N];
bool vis[N];
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%lf", &y[i]);
    }
    double sum = 0.0, Max1 = 0.0, Max2 = 0.0, Max = 0.0;
    int pos = -1;
    for(int i = 1;i <= n+1;i++){
        sum += sqrt(1 + (y[i]-y[i-1])*(y[i]-y[i-1]));
        if(i<=n && sqrt(1+(y[i]-y[i-1])*(y[i]-y[i-1])) + sqrt(1+(y[i]-y[i+1])*(y[i]-y[i+1])) > sqrt(4+(y[i+1]-y[i-1])*(y[i+1]-y[i-1]))){
            if(sqrt(1+(y[i]-y[i-1])*(y[i]-y[i-1])) + sqrt(1+(y[i]-y[i+1])*(y[i]-y[i+1])) - sqrt(4+(y[i+1]-y[i-1])*(y[i+1]-y[i-1])) > Max1){
                Max1 = sqrt(1+(y[i]-y[i-1])*(y[i]-y[i-1])) + sqrt(1+(y[i]-y[i+1])*(y[i]-y[i+1])) - sqrt(4+(y[i+1]-y[i-1])*(y[i+1]-y[i-1]));
                pos = i;
            }
        }
    }
    vis[pos-1] = vis[pos+1] = vis[pos] = 1;
    for(int i = 1;i <= n;i++){
        if(vis[i]) continue;
        if(sqrt(1 + (y[i]-y[i-1])*(y[i]-y[i-1])) + sqrt(1+(y[i]-y[i+1])*(y[i]-y[i+1])) > sqrt(4+(y[i+1]-y[i-1])*(y[i+1]-y[i-1]))){
            if(sqrt(1 + (y[i]-y[i-1])*(y[i]-y[i-1])) + sqrt(1+(y[i]-y[i+1])*(y[i]-y[i+1])) - sqrt(4+(y[i+1]-y[i-1])*(y[i+1]-y[i-1])) > Max2){
                Max2 = sqrt(1 + (y[i]-y[i-1])*(y[i]-y[i-1])) + sqrt(1+(y[i]-y[i+1])*(y[i]-y[i+1])) - sqrt(4+(y[i+1]-y[i-1])*(y[i+1]-y[i-1]));
            }
        }
    }
    for(int i = 1;i < n;i++){
        if(sqrt(1 + (y[i]-y[i-1])*(y[i]-y[i-1])) + sqrt(1+(y[i]-y[i+1])*(y[i]-y[i+1])) + sqrt(1+(y[i+2]-y[i+1])*(y[i+2]-y[i+1]))> sqrt(9+(y[i+2]-y[i-1])*(y[i+2]-y[i-1]))){
            if(sqrt(1 + (y[i]-y[i-1])*(y[i]-y[i-1])) + sqrt(1+(y[i]-y[i+1])*(y[i]-y[i+1])) + sqrt(1+(y[i+2]-y[i+1])*(y[i+2]-y[i+1])) - sqrt(9+(y[i+2]-y[i-1])*(y[i+2]-y[i-1])) > Max){
                Max = sqrt(1 + (y[i]-y[i-1])*(y[i]-y[i-1])) + sqrt(1+(y[i]-y[i+1])*(y[i]-y[i+1])) + sqrt(1+(y[i+2]-y[i+1])*(y[i+2]-y[i+1])) - sqrt(9+(y[i+2]-y[i-1])*(y[i+2]-y[i-1]));
            }
        }
    }
    //printf("sum = %lf, Max1 = %lf, Max2 = %lf, Max = %lf\n",sum, Max1, Max2, Max);
    printf("%.8lf\n", sum-max(Max1+Max2, Max));
    return 0;
}