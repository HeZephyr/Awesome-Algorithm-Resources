/**
  *@filename:瓷砖样式
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-29 17:05
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 1000 + 5;
const int mod = 1e9+7;

//对于这个题，我们可以直接用dfs模拟，那么方格表示我们可以用二维数组来实现。
//其中1表示黄色，0表示黄色，-1表示未填，注意用set判重，判重的方法我们可以采用倍增思想表示一个数。
int n,m;//n*m大小的方格。  
int a[maxn][maxn];
set<int> t;
bool judge(){
    //由于我们用值来表示，也就是说若存在2*2颜色相同的方格，那么其中的值一定模4为0。
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < m-1; j++){
            if((a[i][j]+a[i+1][j]+a[i][j+1]+a[i+1][j+1])%4==0){
                return false;
            }
        }
    }
    return true;
}
void add(){
    int ans=0,temp=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans+=a[i][j]*temp;
            temp*=2;
        }
    }
    t.insert(ans);
}
void dfs(int step){
    //用step来抽象化二维坐标。
    if(step == n*m){
        //由于下标从0开始，说明已经过完了n*m个坐标。开始判断。
        if(judge()){
            add();
        }
        return;
    }
    int x = step / m , y = step % m ;
    if(a[x][y]!=-1)dfs(step+1);
    else{
        //判断是否能横着放或者竖着放。
        if(x+1<n&&a[x+1][y]==-1){
            //说明能竖着放。
            a[x][y]=a[x+1][y]=1;
            dfs(step+1);
            a[x][y]=a[x+1][y]=0;
            dfs(step+1);
            a[x][y]=a[x+1][y]=-1;//复原。
        }
        //注意这里一定要两边都要抉择。
        if(y+1<m&&a[x][y+1]==-1){
            //说明能横着放。
            a[x][y]=a[x][y+1]=1;
            dfs(step+1);
            a[x][y]=a[x][y+1]=0;
            dfs(step+1);
            a[x][y]=a[x][y+1]=-1;//复原。
        }
    }
}
void solve(){
    //我们.要注意模拟。
    memset(a,-1,sizeof(a));
    dfs(0);
    cout<<t.size()<<endl;//101466
}
int main(){
    cin>>n>>m;
    solve();
    return 0;
}