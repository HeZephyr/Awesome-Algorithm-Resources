#include <bits/stdc++.h>

using namespace std;

const int maxn=1e3+5;
string s1,s2;
int len_a,len_b,a[maxn],b[maxn],result[maxn<<1],rem[10][maxn];//rem存储计算结果，利用空间换取时间。
void solve(){
    //将0~9乘a的结果存储起来。
    for(int i=1;i<=9;i++){
        for(int j=0;j<len_a;j++){
            rem[i][j]=i*a[j];
        }
    }
    //开始模拟乘法。
    for(int i=0;i<len_b;i++){
        if(b[i]==0)continue;
        for(int k=i;k<i+len_a;k++){
                result[k]+=rem[b[i]][k-i];
        }
    }
    //我们易知位数为len_a+len_b-1开始进位。
    int result_len=len_a+len_b-1;
    for(int i=1;i<=result_len;i++){
        result[i]+=result[i-1]/10;
        result[i-1]%=10;
    }
    //默认最高位有进位。
    result_len++;
    //清除前导0.
    while(result[result_len-1]==0&&result_len>1){
        result_len--;
    }
    //打印输出。
    for(int i=result_len-1;i>=0;i--){
        cout<<result[i];
    }
    cout<<endl;
}
int main(){
    while(cin>>s1>>s2){
        //进行特判。
        if(s1[0]=='0'||s2[0]=='0'){
            cout<<0<<endl;
            continue;
        }
        len_a=s1.size(),len_b=s2.size();
        //为了方便，从低位存储到高位。
        for(int i=len_a-1;i>=0;i--){
            a[(len_a-1)-i]=s1[i]-'0';
        }
        for(int i=len_b-1;i>=0;i--){
            b[(len_b-1)-i]=s2[i]-'0';
        }
        memset(result,0,sizeof(result));
        solve();
    }
    return 0;
}