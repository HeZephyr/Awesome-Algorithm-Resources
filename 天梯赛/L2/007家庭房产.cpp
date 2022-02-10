/**
  *@filename:007家庭房产
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-20 17:17
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 10000 + 5;
const int mod = 1e9+7;

struct node{
    int id,cnt;//最小编号和家庭成员数
    int num,area;//房产总数和面积总和。
    double num_avg,area_avg;//平均值。
    node(){
        cnt=0,num=0,area=0;
    }
    bool operator<(const node A){
        if(A.area_avg==area_avg)return id<A.id;
        return area_avg>A.area_avg;
    }
}; 
int n;
node member[maxn];
bool vis[maxn];//判断编号是否出现过。
int father[maxn];//并查集。
int house[maxn],area[maxn];
int find(int x){
    int r=x;
    while(r!=father[r])r=father[r];
    int i=x,j;
    while(father[i]!=r){
        j=father[i];
        father[i]=r;
        i=j;
    }
    return r;
}
void merge(int x,int y){
    int fx=find(x),fy=find(y);
    //这里要注意编号大小，我们需要保留最小编号。即最小编号作为根结点。
    if(fx<fy){
        father[fy]=fx;
    }
    else{
        father[fx]=fy;
    }
}
void solve(){
    //去累加。
    int root;
    for(int i=0;i<=9999;i++){
        if(vis[i]){
            //将信息合并到根结点。
            root=find(i);
            member[root].cnt+=1;
            member[root].num+=house[i];
            member[root].area+=area[i];
        }
    }
    //合并完之后开始并入。
    int cnt=0;
    for(int i=0;i<=9999;i++){
        if(vis[i]&&find(i)==i){
            //找到根结点。
            member[cnt].id=i;
            member[cnt].cnt=member[i].cnt;
            member[cnt].num_avg=member[i].num*1.0/member[i].cnt;
            member[cnt].area_avg=member[i].area*1.0/member[i].cnt;
            cnt++;
        }
    }
    //排序。
    sort(member,member+cnt);
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++){
        printf("%04d %d %.3f %.3f\n",member[i].id,member[i].cnt,member[i].num_avg,member[i].area_avg);
    }
}
int main(){
    cin>>n;
    int id,fa,mo,son;
    for(int i=0;i<=9999;i++)father[i]=i;//初始化。
    int temp;
    for(int i=1;i<=n;i++){
        cin>>id>>fa>>mo;
        vis[id]=true;
        //合并。
        if(fa!=-1){
            vis[fa]=true;
            merge(id,fa);
        }
        if(mo!=-1){
            vis[mo]=true;
            merge(id,mo);
        }
        cin>>temp;
        for(int j=1;j<=temp;j++){
            cin>>son;
            vis[son]=true;
            merge(id,son);
        }
        cin>>house[id]>>area[id];
    }
    solve();
    return 0;
}