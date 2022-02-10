#include <bits/stdc++.h>
#define ll long long

using namespace std;
void swap(int& x, int& y) { x ^= y ^= x ^= y; }
const int maxn = 1e5 + 7;
struct e_node {
    int to;
    int next;
    int flag = 0;
}e[maxn << 1];
int head[maxn];
int tot;
void add_e(int u, int v) {
    e[++tot].to = v;
    e[tot].next = head[u];
    head[u] = tot;
}
struct a_node {
    int x;
    int id;
    int dep;
}a[maxn];
int b[maxn];
bool cmp(a_node a, a_node b) {
    return a.x > b.x;
}
int ans[maxn];
void dfs1(int u, int father) {

    int maxx = 0, maxid = 0;
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        if (e[i].flag)continue;
        if (v == father) {
            e[i].flag = 1;
            continue;
        }
        if (maxx < b[v])maxx = b[v], maxid = v;
    }
    add_e(maxid, u);
    add_e(u, maxid);
    dfs1(maxid, u);
}
void dfs2(int u, int father) {
    ans[u] = 1;
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].to;
        if (e[i].flag)continue;
        if (v == father)continue;
        ans[v] = ans[u] + 1;
    }
}

void solove() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_e(u, v);
        add_e(v, u);
    }
    for (int i = 1; i <= n; ++i)
        scanf("%d", &a[i].x), a[i].id = i, b[i] = a[i].x;
    sort(a + 1, a + n + 1, cmp);
    add_e(n + 1, a[1].id);
    add_e(a[1].id, n + 1);
    dfs1(n + 1, 0);
    dfs2(a[1].id, n + 1);
    for (int i = 1; i <= n; ++i)printf("%d\n", ans[i]);
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        tot = 0;
        memset(head, 0, sizeof(head));
        memset(ans, 0, sizeof(ans));
        solove();
    }
    return 0;
}
