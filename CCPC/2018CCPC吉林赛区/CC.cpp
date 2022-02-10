#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e5 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t, n, a[N];
struct node{
    int w, id;
    node(int _w = 0, int _id = 0) : w(_w), id(_id) {}
    bool operator < (const node &A) const {
        return w < A.w;
    }
};
priority_queue<node> q;
int father[N << 2];
int find(int x){
    return father[x] == 0 ? x : find(father[x]);
}
void solve(){
    node head1, head2;
    bool flag  = false;//代表是否成功分成。
    int idx = n + 1;//新增节点的编号。
    int fu, fv;
    int ans1, ans2;
    while(q.size() >= 2){
        head1 = q.top();
        q.pop();
        head2 = q.top();
        q.pop();
        if(head1.w != head2.w){
            q.push(head2);
        }
        else{
            if(head1.w == 1){
                ans1 = head1.id;
                ans2 = head2.id;
                flag = true;//说明合成了。
                break;
            }
            else{
                //合成。
                father[head1.id] = idx, father[head2.id] = idx;
                q.push({head1.w - 1, idx ++});
            }
        }
    }
    if(!flag){
        puts("NO");
    }
    else{
        puts("YES");
        for(int i = 1; i <= n; ++ i){
            fu = find(i);
            if(fu == ans1)printf("1");
            else if(fu == ans2)printf("0");
            else printf("%d", i & 1);
        }
        puts("");
    }
}
int main(){	
    scanf("%d", &t);
    for(int k = 1; k <= t; ++ k){
        scanf("%d", &n);
        memset(father, 0, sizeof(father));
        while(!q.empty())q.pop();
        for(int i = 1; i <= n; ++ i){
            scanf("%d", &a[i]);
            q.push({a[i], i});
        }
        printf("Case %d: ", k);
        solve();
    }
    return 0;
}