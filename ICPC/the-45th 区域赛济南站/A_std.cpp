#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e2 + 7;
const int mod = 998244353;
int a[maxn][maxn];//增广矩阵
int x[maxn];//解集
int freeX[maxn];//自由变元
int n;
int A[maxn][maxn],B[maxn][maxn];
ll poww(ll a,ll b){
       ll ans=1;
       while(b > 0){
            if(b & 1) ans = ans * a % mod;
            a = a * a % mod;
            b >>= 1;

       }
       return ans;
}
int Gauss(int equ,int var){
    for(int i=0;i<=var;i++){
        x[i]=0;
        freeX[i]=0;
    }
    int col=0;//当前处理的列
    int num=0;//自由变元的序号
    int row;//当前处理的行
    for(row=0;row<equ&&col<var;row++,col++){//枚举当前处理的行
        int maxRow=row;//当前列绝对值最大的行
        for(int i=row+1;i<equ;i++){//寻找当前列绝对值最大的行
            if(abs(a[i][col])>abs(a[maxRow][col]))
                maxRow=i;
        }
        if(maxRow!=row){//与第row行交换
            for(int j=row;j<var+1;j++)
                swap(a[row][j],a[maxRow][j]);
        }
        if(a[row][col]==0){//col列第row行以下全是0，处理当前行的下一列
            freeX[num++]=col;//记录自由变元
            row--;
            continue;
        }
        for(int i=row+1;i<equ;i++){
            if(a[i][col]!=0){
                for(int j=col;j<var+1;j++){//对于下面出现该列中有1的行，需要把1消掉
                    a[i][j]^=a[row][j];
                }
            }
        }
    }
    for(int i=row;i<equ;i++)
        if(a[i][col]!=0)
            return -1;
    int temp=var-row;//自由变元有var-row个
    if(row<var)//返回自由变元数
        return temp;
    return 0;
}
void init() {
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            a[i][j] = A[i][j];
        }
    }
}
void print(int a[][maxn]){
    for(int i = 0; i < n; ++ i){
        for(int j = 0; j < n; ++ j){
            printf("%d%c", a[i][j], j == n - 1 ? '\n' : ' ');
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            scanf("%d",&A[i][j]);
            a[i][j] = A[i][j];
        }
    }
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            scanf("%d",&B[i][j]);
        }
    }
    ll ans = 1;
    for(int r = 0;r < n; r ++){
        init();
        for(int i = 0; i < n; i ++){
            a[i][i] = (A[i][i] - B[i][r] + 2) % 2;
        }
        print(a);
        int freeNum=Gauss(n,n);//获取自由元
        if(freeNum == -1) continue;
        ans = (ans  *  poww(2 , freeNum)) % mod;
    }
    printf ("%lld\n",ans);
    return 0;
}

