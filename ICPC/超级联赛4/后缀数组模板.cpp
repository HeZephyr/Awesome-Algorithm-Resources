/**
  *@filename:后缀数组模板
  *@author: pursuit
  *@created: 2021-08-05 11:16
**/
#include <bits/stdc++.h>
#define debug(a) cout << (#a)<< ":" << a << endl;

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n;
char s[N];
int buf1[N], buf2[N], buc[N], sa[N], rnk[N], height[N];
//sa[i]表示排第i的是suffix(sa[i]),rnk[i]表示suffix(i)在所有后缀中排第几。
//height[i]表示后缀sa[i - 1]和后缀sa[i]的最长公共前缀。height数组表示排名相邻的两个后缀的最长公共前缀。
void suffix_sort(){
    int *x = buf1, *y = buf2, m = 127; //m是基数排序的基数的最大值
    //buf1和buf2是两个用来缓存的临时数组，用指针定义方便循环使用
    /**** 接下来先对所有单个字符基数排序 ****/
    for(int i = 0; i <= m; ++ i) buc[i] = 0; //先把桶清空
    for(int i = 1; i <= n; ++ i) buc[x[i] = s[i]]++; //此时，x[i]是一个字符串的“值”
    for(int i = 1; i <= m; ++ i) buc[i] += buc[i - 1];
    for(int i = n; i; -- i) sa[buc[x[i]]--] = i;
    for(int k = 1; k <= n; k <<= 1){
        //倍增枚举所比较的字符串的长度（字符串的长度的一半是k，即x[i]中此时存储的信息来自i开头长为k的字符串）
	int p = 0; //p统计当前放入新桶的字符串的个数
        //由于上一轮排序后，sa数组中存储的顺序相当于这一轮的第二关键字排序结果
        //所以接下来把上一轮的排序结果转译成这一轮字符串的按第二关键字排序结果，把排好序的后缀放在y数组中
	for(int i = n - k + 1; i <= n; i++) y[++p] = i;
        //对于所有右半部分为空的字符串，它们的第二关键字最小，所以排在最前面
	for(int i = 1; i <= n; i++) if(sa[i] > k) y[++p] = sa[i] - k;
        //按顺序枚举上一轮排序后的sa数组中的字符串，如果它作为第二关键字对某个字符串有贡献
        //则将被贡献字符串放入y数组
        //至此，y数组中是1~n的后缀编号，已按第二关键字大小升序排列。
	for(int i = 0; i <= m; ++ i) buc[i] = 0; //再进行一次基数排序
	for(int i = 1; i <= n; ++ i) buc[x[y[i]]]++;
        //还记得x[i]存的是什么吗？是i开头长为k的字符串的“值”，即第一关键字
	for(int i = 1; i <= m; ++ i) buc[i] += buc[i - 1];
	for(int i = n; i; i--) sa[buc[x[y[i]]]--] = y[i];
        /**** 接下来更新一个字符串的“值”——这次是长为2k的字符串的“值”了 ****/
	swap(x, y), x[sa[1]] = p = 1;
        //注意这里交换了一下x和y……现在y是上一轮（长为k）的“值”，x是这一轮（长为2k）的“值”
	for(int i = 2; i <= n; i++)
	    if(y[sa[i - 1]] == y[sa[i]] && y[sa[i - 1] + k] == y[sa[i] + k]) x[sa[i]] = p;
        //两个字符串的两个关键字完全相同，则新的“值”也相同
	    else x[sa[i]] = ++p; //否则它对应着一个新的“值”
	if((m = p) >= n) break; //如果每个后缀对应值都不一样，则已经排好序了
    }
    /**** 接下来记录rank数组 ****/
    for(int i = 1; i <= n; ++ i) rnk[sa[i]] = i;
    /**** 接下来处理height数组：sa[i]和sa[i - 1]对应字符串的LCP ****/
    for(int i = 1, j, k = 0; i <= n; ++ i){
	if(rnk[i] == 1) continue;
        if(k) k--; //h[i] >= h[i - 1] - 1，k记录上一个h[i]
        j = sa[rnk[i] - 1];
        while(s[i + k] == s[j + k] && i + k <= n && j + k <= n) k++;
        height[rnk[i]] = k;
    }
}
void solve(){
    n = strlen(s + 1);
    suffix_sort();
    for(int i = 1; i <= n; ++ i){
        printf("%d%c", sa[i], i == n ? '\n' : ' ');
    }
    for(int i = 1; i <= n; ++ i){
        printf("%d%c", rnk[i], i == n ? '\n' : ' ');
    }
    for(int i = 2; i <= n; ++ i){
        printf("%d%c", height[i], i == n ? '\n' : ' ');
    }
}
int main(){	
    scanf("%s", s + 1);
    solve();
    return 0;
}