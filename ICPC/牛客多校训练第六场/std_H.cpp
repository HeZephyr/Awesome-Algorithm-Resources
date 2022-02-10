#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll d;
struct line {//表示为线的矩形的左右边界
	ll x, y1, y2;
	ll add;
};
bool cmp(line a, line b) {
	return a.x < b.x;
}
struct SegmentTree {
	ll p, l, r, val, mn, add;//mn是子区间覆盖次数最小值，add是延迟标记
} t[200005 * 4];
void build(ll p, ll l, ll r) {
    //cout << p << " " << l << " " << r << endl;
	t[p].l = l, t[p].r = r;
	t[p].mn = 0;
	if(l == r) {
		return;
	}
	ll mid = (l + r) >> 1;
	build(2 * p, l, mid);
	build(2 * p + 1, mid + 1, r);
	return;
}
void spread(ll p) {
	if(t[p].add != 0) {
		t[2 * p].mn +=t[p].add;
		t[2 * p + 1].mn +=t[p].add;
		t[2 * p].add += t[p].add;//!!!!!!
		t[2 * p + 1].add += t[p].add;
		t[p].add = 0;
	}
}
void change(ll p, ll L, ll R, ll v) {
	if(t[p].l >= L && t[p].r <= R) {
		t[p].mn += v;//整个已经覆盖了
		t[p].add += v;
		return;
	}
	spread(p);
	ll mid = (t[p].l + t[p].r) >> 1;
	if(L <= mid) change(2 * p, L, R, v);
	if(R > mid) change(2 * p + 1, L, R, v);
	t[p].mn = min(t[2 * p].mn, t[2 * p + 1].mn);
}
ll ask(ll p, ll L, ll R) {
	if(t[p].l >= L && t[p].r <= R) {
		return t[p].mn;
	}
	spread(p);
	int mid = (t[p].l + t[p].r) >> 1;
	ll ret = 0x3f3f3f3f;
	if(L <= mid) ret = min(ret, ask(2 * p, L, R));
	if(R > mid) ret = min(ret, ask(2 * p + 1, L, R));
	return ret;
}
vector<line> Line[100005];//如果写成vector<vector<line> > Line(d + 5)会报非常奇怪的错
void add(ll x1, ll y1, ll x2, ll y2) {////注意这里(0, 0)(0, 0)实际上代表(0, 0)(1, 1)这个矩形
    //cout << x1 << " " << x2 << " " << y1 << " " << y2 << endl;
	Line[x1].push_back({x1, y1, y2, 1});
	Line[x2 + 1].push_back({x2 + 1, y1, y2, -1});//注意这里是x2 + 1 类似差分的思想
}
int main() {
	cin >> n >> d;
	for(int i = 1; i <= n; i++) {
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x2--, y2--;//点化为块
		//下面两句画图理解一下
		if(x2 - x1 + 1 >= d) x1 = 0, x2 = d - 1; 
		if(y2 - y1 + 1 >= d) y1 = 0, y2 = d - 1;
		x1 = (x1 % d + d) % d, x2 = (x2 % d + d) % d, y1 = (y1 % d + d) % d, y2 = (y2 % d + d) % d;//矩形取模
		if(x2 >= x1) {//不要忘记取等号 //把一个矩形分为1、2或4个矩形
			if(y2 >= y1) {
				add(x1, y1, x2, y2);
			} else {
				add(x1, y1, x2 ,d - 1);
				add(x1, 0, x2 ,y2);
			}
		} else {
			if(y2 >= y1) {
				add(x1, y1, d - 1, y2);
				add(0, y1, x2, y2);
			} else {
				add(x1, y1, d - 1, d - 1);
				add(0, y1, x2, d - 1);
				add(x1, 0, d - 1, y2);
				add(0, 0, x2, y2);
			}
		}
	}
	build(1, 0, d - 1);
	ll ansx = -1, ansy = -1;
	for(ll i = 0; i < d; i++) {
		if(ansx != -1) break;
		for(auto l : Line[i]) {
			change(1, l.y1, l.y2, l.add);//必须先修改再查询
		}
		if(ask(1, 0, d - 1) == 0) {//如果有没有被覆盖的位置
			for(ll j = 0; j <= d - 1; j++) {
				if(ask(1, j, j) == 0) {
					ansx = i, ansy = j;
					break;
				}
			}
		} 
	}
	if(ansx != -1) {
		puts("YES");
		cout << ansx << " " << ansy << endl;
	} else {
		puts("NO");
	}
	return 0;
}

// 3 4
// 0 0 2 2
// 1 0 3 4
// 0 2 4 4

