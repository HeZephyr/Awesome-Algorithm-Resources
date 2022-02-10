/**
  *@filename:F
  *@author: pursuit
  *@created: 2021-08-22 13:27
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 200 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,m;
char s[N],t[N];
struct node{
    int x,y,z;
    char c;//c表示该位置为左括号还是右括号。
    node(int x = 0,int y = 0,int z = 0,char c = ' ') : x(x), y(y), z(z), c(c){}
}p[N][N][N];//表示dp的路径。为了我们输出解决方案。
vector<char> res;//结果串。
int f[N][N][N];//dp数组。
void bfs(){
    //bfs寻找。
    memset(f,-1,sizeof(f));
    f[0][0][0] = 0;//初始状态值。
    queue<node> q;
    q.push(node());
    node head;
    while(!q.empty()){
        head = q.front();
        q.pop();
        //为了保证序列的合法性，我们每次都要放入一对括号。
        //这里添加左括号，判断是不是匹配成功了。 
        int nxtX = head.x + (head.x + 1 <= n && s[head.x + 1] == '(');
        int nxtY = head.y + (head.y + 1 <= m && t[head.y + 1] == '(');
        int nxtZ = head.z + 1;
        if(nxtZ < N && f[nxtX][nxtY][nxtZ] == -1){
            //由于我们是进行bfs，所以第一次放入一定是最小值。
            f[nxtX][nxtY][nxtZ] = f[head.x][head.y][head.z] + 1;
            p[nxtX][nxtY][nxtZ] = node(head.x,head.y,head.z,'(');//保存路径。
            q.push(node(nxtX,nxtY,nxtZ));//再将该位置入队。
        }
        //这里添加右括号。判断是不是匹配成功了，如果匹配成功自然+1.
        nxtX = head.x + (head.x + 1 <= n && s[head.x + 1] == ')');
        nxtY = head.y + (head.y + 1 <= m && t[head.y + 1] == ')');
        nxtZ = head.z - 1;
        if(nxtZ >= 0 && f[nxtX][nxtY][nxtZ] == -1){
            f[nxtX][nxtY][nxtZ] = f[head.x][head.y][head.z] + 1;
            p[nxtX][nxtY][nxtZ] = node(head.x,head.y,head.z,')');//保存路径。
            q.push(node(nxtX,nxtY,nxtZ));//再将该位置入队。
        }
    }
}
void dfs(node cur){
    if(cur.x == 0 && cur.y == 0 && cur.z == 0){
        printf("%c", cur.c);
        return;
    }
    dfs(p[cur.x][cur.y][cur.z]);
    printf("%c", cur.c);
}
void solve(){
    n = strlen(s + 1), m = strlen(t + 1);
    bfs();
    dfs(p[n][m][0]);
}
int main(){	
    scanf("%s%s", s + 1, t + 1);
    solve();
    return 0;
}