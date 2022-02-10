#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

typedef double db;
const int N = 105;
const int M = 1e4 + 5;
const int inf = 0x3f3f3f3f;

struct edge {
	int frm, to;
	db v;
}W[M];

int X[N], Y[N];
db IN[N];
int PRE[N], ID[N], VIS[N];
int n, m, sz;

db dtc(int a, int b) {
	return sqrt((X[a] - X[b]) * (X[a] - X[b]) * 1.0
						 + (Y[a] - Y[b]) * (Y[a] - Y[b]) * 1.0);
}

void add_edge(int x, int y) {
	W[++sz].frm = x; W[sz].to = y;
	W[sz].v = dtc(x, y);
}

db zhuliu(int rt) {
	db ans = 0;
	while (true) {
		for (int i = 1; i <= n; ++i)
			IN[i] = inf;
		for (int i = 1; i <= sz; ++i)
			if (W[i].to == W[i].frm) continue; //第一次是不会有这种情况的, 但是缩点后就有这种情况了
			else if (IN[W[i].to] > W[i].v) {
				PRE[W[i].to] = W[i].frm;
				IN[W[i].to] = W[i].v; //找指向自己权值最小的边
			}
		for (int i = 1; i <= n; ++i)
			if (i != rt && IN[i] == inf) return -1; // 不能构成树
		int cnt = 0;
		memset(ID, 0, sizeof (ID));
		memset(VIS, 0, sizeof (VIS));
		//ID数组的初始化要与cnt记录的环数相匹配, 这里ID用0初始化, 则cnt从1开始记录, 也可以用-1初始化, 让cnt从0开始记录
		//初始化要注意, 因为这里的节点是从1开始编号的, 所以VIS数组中不会出现0, 可以用0来初始化, 若节点是从0开始编号, 则VIS中会有0, 不能用0初始化
		IN[rt] = 0; //删去rt的入边
		for (int i = 1; i <= n; ++i) {
			ans += IN[i];
			int v = i;
			// ID[v]!=0表示找到了一个之前已知在环上的节点
			// v==rt标示找到了根
			// VIS[v]==i表示找到了一个本次查找已经找过的节点, 形成了环
			while (!ID[v] && v != rt && VIS[v] != i) {
				VIS[v] = i;
				v = PRE[v];
			}
			if (v != rt && !ID[v]) {
				ID[v] = ++cnt; //cnt从1开始记录
				for (int j = PRE[v]; j != v; j = PRE[j])
					ID[j] = cnt; //给同一环上的节点打一个标示所属环的标记
			}
		}
		if (!cnt) break; // 没有环, 树成立
		for (int i = 1; i <= n; ++i)
			if (!ID[i])
				ID[i] = ++cnt; // 缩点
		for (int i = 1; i <= m; ++i) {
			int x = W[i].frm , y = W[i].to;
			W[i].frm = ID[x]; W[i].to = ID[y];
			if (ID[x] != ID[y])
				W[i].v -= IN[y]; // 重新处理边
			// 这里有点难理解, 因为环被缩成了一个点, 而根又必定不在环上, 所以下一轮操作会给这个新点加入一个入边, 设这个入边原本指向环上一点x, 则加入这条经过处理的新边实际上相当于用它取代了原本指向x的老边, 环也就被拆开了
		}
		n = cnt;
		rt = ID[rt]; // 维护新的点数目和根
	}
	return ans;
}

int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		sz = 0;
		for (int i = 1; i <= n; ++i)
			scanf("%d%d", &X[i], &Y[i]);
		for (int i = 1; i <= m; ++i) {
			int a, b;
			scanf("%d%d", &a, &b);
			if (a != b) add_edge(a, b); //读入数据顺便处理自环
		}
		db ans = zhuliu(1);
		if (ans == -1) printf("poor snoopy\n");
		else printf("%.2lf\n", ans);
	}
	return 0;
}