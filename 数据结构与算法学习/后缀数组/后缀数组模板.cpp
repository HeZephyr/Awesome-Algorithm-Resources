#include<bits/stdc++.h>

using namespace std;

const int maxn=1e3+10;
//定义Suffix Array数组(sa数组)用于保存从小到大排好序之后的后缀。而RANK名次数组(rk数组)用来保存后缀S[i...n]在
//所有后缀中是第几小的后缀。sa数组表示的是“排第几的是谁”，rk数组表示的是“你的排名是多少”。
//DC3算法步骤如下：
/*
1. 先将后缀分成两部分，然后对第一部分的后缀排序。
2. 利用1的结果，对第二部分的后缀排序。
3. 将(1)和(2)的结果合并，即完成对所有后缀排序。
*/
int wa[maxn],wb[maxn],wv[maxn],ws[maxn];
int cmp(int *r,int a,int b,int l){
    return r[a]==r[b]&&r[a+1]==r[b+1];
}
void solve(){
}
int main(){
    return 0;
}