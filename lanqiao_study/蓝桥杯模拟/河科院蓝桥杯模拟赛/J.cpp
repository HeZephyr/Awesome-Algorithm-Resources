#include <bits/stdc++.h>
using namespace std;

bool win(int k) {
	return
	(((k>>1)&1) & ((k>>2)&1) & ((k>>3)&1)) ||
	(((k>>4)&1) & ((k>>5)&1) & ((k>>6)&1)) ||
	(((k>>7)&1) & ((k>>8)&1) & ((k>>9)&1)) ||
	(((k>>1)&1) & ((k>>4)&1) & ((k>>7)&1)) ||
	(((k>>2)&1) & ((k>>5)&1) & ((k>>8)&1)) ||
	(((k>>3)&1) & ((k>>6)&1) & ((k>>9)&1)) ||
	(((k>>1)&1) & ((k>>5)&1) & ((k>>9)&1)) ||
	(((k>>3)&1) & ((k>>5)&1) & ((k>>7)&1));
}

int dp[1<<10][1<<10];

int dfs(int a, int b) {
	if(dp[a][b] != -1) return dp[a][b];//说明此状态已经确定。
	if(win(a)) return 0;//如果a赢了。
	if(a + b == (1<<10)-2) return 1;//如果a+b就这些都填满了。
	int res = 0;
	for(int i = 1; i <= 9; i++) {
        //判断这个点是否已经被填充。
		if((a>>i)&1 || (b>>i)&1) continue;
		
		int t = dfs(b+(1<<i), a);//填充这个点。再递归下去
		if(t == 0) res = max(res, 2);
		if(t == 1) res = max(res, 1);
		if(t == 2) res = max(res, 0);
	}
	return dp[a][b] = res;
}

void out(int k) {
	int num = 10;
	while(num--) {
		printf("%d", k&1);
		k >>= 1;
	}
	puts("");
}

int main() {
	memset(dp, -1, sizeof(dp));
	int _; scanf("%d", &_); while(_--) {
		int X = 0, O = 0;
		int n; scanf("%d", &n); for(int i = 1; i <= n; i++) {
			int x, y; scanf("%d %d", &x, &y);
			if(i % 2) X += 1<<((x-1)*3+y);
			else O += 1<<((x-1)*3+y);//已经填了的。
		}
		out(X); 
        out(O);
		if(n%2) {
			int res = dfs(X, O);
			if(res == 0) puts("X");
			if(res == 1) puts("-1");
			if(res == 2) puts("O");
		}
		else {
			int res = dfs(O, X);
			if(res == 0) puts("O");
			if(res == 1) puts("-1");
			if(res == 2) puts("X");
		}
	}
}
