/**
 *@author: pursuit
 *@email: 2825841950@qq.com
 *@created: 2021-03-13-16:03
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;
const ll mod = 1e9+7;
const int N = 7;

bool h[N][N];
int op[N]={0,4,5,6,1,2,3};
int n,m;
struct mat{
    ll A[N][N];
    mat(){
        memset(A,0,sizeof(A));
    }
    //等于这里必须使用引用。
    mat&  operator=(const mat &arg){
        for(int i=1;i<N;i++){
            for(int j=1;j<N;j++){
                A[i][j]=arg.A[i][j];
            }
        }
    }
    mat operator*(const mat &arg){
        mat temp;//临时矩阵，存储运算结果。
        //矩阵相乘，A矩阵的第i行乘以B矩阵的第j列。
        for(int i=1;i<N;i++){
            //代表第i行
            for(int j=1;j<N;j++){
                //代表第j列。
                for(int k=1;k<N;k++){
                    temp.A[i][j]=(temp.A[i][j]+arg.A[i][k]*A[k][j])%mod;
                }
            }
        }
        return temp;
    }
};
mat init_e(){
    mat temp;
    //初始化为单位矩阵。
    for(int i=1;i<N;i++){
        for(int j=1;j<N;j++){
            if(i==j){
                temp.A[i][j]=1;
            }
        }
    }
    return temp;
}
mat quick_pow(mat A,int q){
    mat ans = init_e();
    while(q){
        if(q&1)ans=ans*A;
        A=A*A;
        q>>=1;
    }
    return ans;
}
mat res,ans;//代表我们的矩阵A。
void solve(){
    ll result=0;
    ans=quick_pow(res,n-1);
    for(int i=1;i<N;i++){
        for(int j=1;j<N;j++){
            result=(result+4*ans.A[i][j])%mod;
        }
    }
    cout<<result<<endl;
}
int main() {
    cin>>n>>m;
    int a,b;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        h[a][b]=h[b][a]=true;
    }
    for(int i=1;i<N;i++){
        for(int j=1;j<N;j++){
            if(!h[i][op[j]]){
               res.A[i][j]=4; 
            }
        }
    }
    solve();
    return 0;
}