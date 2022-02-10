/**
  *@filename:3485最大异或和
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-10 19:23
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100010;
const int mod = 1e9+7;

int n,m,x;
int pre[maxn];//记录前缀和异或数组。
//对一个连续区间每个数可以从高位到低位，建Trie树。把连续的一些数扔进Trie树。1^1=0,1^0=1。(异或运算称为不进位的加法。)
//这些数中的任一个与x异或，会得到一个值，求最大的这个值：二进制位从高到低查找Trie树。
//如果x当前位为0，就找1的，否则找0的，这样贪心最大，当然如果找不到就只能找一样的了。
int trie[maxn*31][2],cnt[maxn*31];//trie树。cnt[i]为以i为结点，有多少个子树。
int tot;//编号。
void insert(int x,int v){
    //v取+1和-1，+表示添加，-表示删除。
    int p=0;
    for(int i=30;i>=0;i--){
        int u=x>>i&1;
        if(!trie[p][u])trie[p][u]=++tot;
        p=trie[p][u];
        cnt[p]+=v;//变化了v个结点。
    }
}
int query(int x){
    int res=0,p=0;//res答案。p为指针。
    for(int i=30;i>=0;i--){
        int u=x>>i&1;
        if(cnt[trie[p][!u]]){
            //如果和我们不一样的子树有点的话。
            p=trie[p][!u];
            res=res*2+1;
        }
        else{
            //只能走相同的。
            p=trie[p][u];
            res=res*2;
        }
    }
    return res;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x;
        pre[i]=pre[i-1]^x;//前缀异或和。      
    }
    int res=0;//答案。
    insert(pre[0],1);
    for(int i=1;i<=n;i++){
        if(i>m){
            //我们需要删除前i-m-1个数。
            insert(pre[i-m-1],-1);
        }
        res=max(res,query(pre[i]));
        //cout<<res<<endl;
        insert(pre[i],1);//不断加入前缀异或和。
    }
    cout<<res<<endl;
    return 0;
}