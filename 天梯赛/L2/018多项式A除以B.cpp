/**
  *@filename:018多项式A除以B
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-21 14:37
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

//多项式相除所以我们要知道规则，实际上就是不断消去最高次，例如A=x^3+2x^2+x-1 B=x+1
//那么我们就是模拟竖式除法，先消去x^3,则商C=x^2 ，A=x^2+x-1 再消去x^2，则商C=x^2+x A=-1。此时A的最高次比B要小
//故除法进行完成。商为C，余数为进行除法完后的A。
int n,m;
double A[maxn],B[maxn],C[maxn];
void solve(){
}
int main(){
    int c,e;
    int maxx_a=0,maxx_b=0;//获取a和b的最高次，便于进行除法。
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>e;
        cin>>A[e];
        maxx_a=max(maxx_a,e);
    }
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>e;
        cin>>B[e];
        maxx_b=max(maxx_b,e);
    }
    //开始进行除法。
    for(int i=maxx_a;i>=maxx_b;i--){
        double temp=A[i]/B[maxx_b];//获取系数。
        C[i-maxx_b]=temp;
        //开始改变A。
        int k=0;
        for(int j=maxx_b;j>=0;j--,k++){
            A[i-k]-=temp*B[j];
        }
    }
    //存储非零系数。
    vector<pair<int,double> > result;
    for(int i=maxx_a-maxx_b;i>=0;i--){
        if(fabs(C[i])>=0.05){
            result.push_back({i,C[i]});
        }
    }
    int len=result.size();
    if(len==0)puts("0 0 0.0");
    else{
        printf("%d ",len);
        for(int i=0;i<len;i++){
            printf("%d %.1f%c",result[i].first,result[i].second,i==len-1?'\n':' ');
        }
    }
    result.clear();
    for(int i=maxx_b-1;i>=0;i--){
        if(fabs(A[i])>=0.05){
            result.push_back({i,A[i]});
        }
    }
    len=result.size();
    if(len==0)puts("0 0 0.0");
    else{
        printf("%d ",len);
        for(int i=0;i<len;i++){
            printf("%d %.1f%c",result[i].first,result[i].second,i==len-1?'\n':' ');
        }
    }
    return 0;
}