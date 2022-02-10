/**
  *@filename:更新二进制位
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-28 11:20
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 5;
const int P = 1e9+7;

int n,m,i,j;
int updateBits(int n,int m,int i,int j){
    for(int pos = i; pos <= j; pos ++ ){
        n &= ~(1 << pos);
    }
    return n | (m << i);
}
int main(){
    scanf("%d%d%d%d", &n, &m, &i, &j);
    printf("%d\n",updateBits(n,m,i,j));
    return 0;
}
void swap(int &a,int &b){
    a ^= b;
    b ^= a;
    a ^= b;
}
