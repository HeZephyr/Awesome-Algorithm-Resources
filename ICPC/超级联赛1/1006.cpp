/**
  *@filename:1006
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-07-21 09:57
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 3000000 + 5;
const int P = 1e9+7;

int t,n,k,tot,trie[N][2],a[N],cnt[N],l,r;
int query(int i){
	int res = -1, rt = 1;
	for(int j = 30; j >= 0; -- j){
		int u = (a[i] >> j) & 1;//获取a[i]的第j位上的值。
		int v = (k >> j) & 1;//获取k上的第j位上的值。
		if(!v){
			//如果为0，我们这个时候只要异或形成1就保证大于k了。
			if(trie[rt][u ^ 1]){
				res = max(res, cnt[trie[rt][u ^ 1]]);//获取其位置。
			}
			rt = trie[rt][u];//当然，我们也可以选择和u相同的，此时继续往下。
		}
		else{
			//如果为1，我们要保证不小于k，这个时候必须要为1.
			rt = trie[rt][u ^ 1];
		}
		if(!rt)break;//说明不存在子树了。
	}
	if(rt){
		res = max(res, cnt[rt]);
	}
	return res;
}
void insert(int i){
	int rt = 1;
	for(int j = 30; j >= 0; -- j){
		int u = (a[i] >> j) & 1;
		if(!trie[rt][u]){
			//如果该节点不存在，就创建。
			trie[rt][u] = ++ tot;
			cnt[tot] = -1;
			trie[tot][0] = trie[tot][1] = 0;
		}
		rt = trie[rt][u];
		//更新左端的节点。
		cnt[rt] = max(cnt[rt],i);
	}
}
void solve(){
	//这里默认1为根节点。即管理整个字典树的节点。
	tot = 1, l = -1, r = n;
	cnt[1] = -1;//最初的时候左端点默认都为-1.
	trie[1][0] = trie[1][1] = 0;
	for(int i = 1; i <= n; ++ i){
		int res = query(i);
		//判断获取的最大节点是否有效。
		if(res >= 0 && i - res < r - l){
			r = i, l = res;
		}
		insert(i);
	}
	//注意这里的l需要+1.因为取到的区间是(l + 1,r);
	//这里因为区间异或和决定的。
	if(l >= 0)printf("%d %d\n", l + 1, r);
	else printf("-1\n");
}
int main(){
	scanf("%d", &t);
	while(t -- ){
		scanf("%d%d", &n, &k);
		for(int i = 1; i <= n; ++ i){
			scanf("%d", &a[i]);
			a[i] ^= a[i - 1];//求异或前缀和
		}
		solve();
	}
	return 0;
}