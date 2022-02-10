/**
  *@filename:FFT
  *@author: pursuit
  *@created: 2021-08-05 20:57
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl;

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e7 + 10;//注意需要开大一点。
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);//圆周率PI。

char s1[N],s2[N];
struct Complex{
    double x,y;//复数，x代表实部，y代表虚部。
    Complex(double _x = 0, double _y = 0){
        x = _x,y = _y;
    }
}a[N],b[N];//多项式a和b，相乘。
int ans[N];//存储结果值。
int n,m,l,r[N],limit = 1;//n为a的次数,m为b的次数。limit即为最大限制。2^n次方，而l为二进制的位数
//运算符重载。
Complex operator + (Complex a, Complex b){
    return Complex(a.x + b.x, a.y + b.y);
}
Complex operator - (Complex a, Complex b){
    return Complex(a.x - b.x, a.y - b.y);
}
//复数相乘，则模长相乘，幅度相加。
Complex operator * (Complex a, Complex b){
    return Complex(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}
void fft(Complex * A,int type){
    for(int i = 0; i < limit; ++ i){
        if(i < r[i])swap(A[i], A[r[i]]);
        //求出要迭代的区间。小于r[i]时才交换，防止同一个元素交换两次，回到原来的位置。
    }
    //从底层往上合并。
    for(int mid = 1; mid < limit; mid <<= 1){
        //待合并区间长度的一半，最开始是两个长度为1的序列合并,mid = 1;
        Complex Wn(cos(PI / mid), type * sin(PI / mid));//单位根。
        for(int len = mid << 1, j = 0; j < limit; j += len){
            //len是区间的长度，j是当前的位置，也就是合并到了哪一位。
            Complex w(1,0);//幂，一直乘，得到平方，三次方。
            for(int k = 0; k < mid; ++ k,w = w * Wn){
                //枚举左半部分。蝴蝶变换得到右半部分的答案。w为wn * k
                Complex x = A[j + k], y = w * A[j + mid + k];//左半部分和右半部分。
                A[j + k] = x + y;//左边加。
                A[j + mid + k] = x - y;//右边减。
            }
        }
    }
}
void solve(){
    while(limit < n + m){
        limit <<= 1, l ++;
    }
    //初始化r数组。
    for(int i = 0; i <= limit; ++ i){
        r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
    }
    fft(a,1);//将a的系数转化为点值表示，
    fft(b,1);//将b的系数转化为点值表示。
    for(int i = 0; i <= limit; ++ i){
        //对应项相乘，得到点值表示的解。
        a[i] = a[i] * b[i];
    }
    fft(a,-1);
    int tot = 0;
    for(int i = 0; i <= limit; ++ i){
        ans[i] = (int)(a[i].x / limit + 0.5);
        if(ans[i] >= 10){
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
            limit += (i == limit);//进一位。
        }
    }
    while(!ans[limit] && limit >= 1)limit --;
    limit ++;
    while(-- limit >= 0)printf("%d", ans[limit]);
    puts("");
}
int main(){	
    scanf("%s%s", s1,s2);
    n = strlen(s1), m = strlen(s2);
    int cnt = 0;
    for(int i = n - 1; i >= 0; -- i){
        a[cnt ++].x = s1[i] - '0';
    }
    cnt = 0;
    for(int i = m - 1; i >= 0; -- i){
        b[cnt ++].x = s2[i] - '0';
    }
    solve();
    return 0;
}