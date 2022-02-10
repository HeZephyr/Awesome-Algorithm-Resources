/**
 *@author: pursuit
 *@email: 2825841950@qq.com
 *@created: 2021-03-12 17:55
**/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n,q;//n表示方阵的长度，q我们要求的幂
//矩阵快速幂，跟快速幂的想法是一样的。
struct mat{
    int m[100][100];
    mat(){
        memset(m,0,sizeof(m));
    }
    //等于这里必须使用引用。
    mat&  operator=(const mat &A){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                m[i][j]=A.m[i][j];
            }
        }
    }
    mat operator*(const mat &A){
        mat temp;//临时矩阵，存储运算结果。
        //矩阵相乘，A矩阵的第i行乘以B矩阵的第j列。
        for(int i=0;i<n;i++){
            //代表第i行
            for(int j=0;j<n;j++){
                //代表第j列。
                for(int k=0;k<n;k++){
                    temp.m[i][j]=temp.m[i][j]+A.m[i][k]*m[k][j];
                }
            }
        }
        return temp;
    }
};
mat ans,res;//ans是结果，res是最初的方针。
mat init_e(){
    mat temp;
    //初始化为单位矩阵。
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j){
                temp.m[i][j]=1;
            }
        }
    }
    return temp;
}
mat quick_pow(mat A,int q){
    //接下来和快速幂就没什么区别了。
    mat ans = init_e();
    while(q){
        if(q&1){
            ans=ans*A;
        }
        A=A*A;
        q>>=1;//向右移位
    }
    return ans;
}
int main() {
    cin>>n>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>res.m[i][j];
        }
    }
    ans = quick_pow(res,q);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ans.m[i][j];
            if(j!=n-1){
                cout<<" ";
            }
            else{
                cout<<endl;
            }
        }
    }
    return 0;
}