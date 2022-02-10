/**
  *@filename:网络分析
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-13 19:48
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 10000 + 5;
const int mod = 1e9+7;

int n,m;
int father[maxn];//集合。
int value[maxn];//信息大小。
int find(int x){
    if(father[x]==x||father[father[x]]==father[x])return father[x];//这里的第二条语句就是为了不作二次find。
    //进行更新，这里必须使用递归去做。
    int r=find(father[x]);
    value[x]+=value[father[x]];
    father[x]=r;
    return r;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)father[i]=i;
    //m条操作。
    int t,a,b;
    while(m--){
        cin>>t>>a>>b;
        if(t==1){
            //也就是合并a和b。
            a=find(a),b=find(b);
            if(a!=b){
                //我们就需要进行合并，这里要注意合并需要将信息更改。
                father[a]=b;
                value[a]-=value[b];
            }
        }
        else{
            //发送信息大小，我们找到根结点，在其上进行更改即可。
            a=find(a);
            value[a]+=b;
        }
    }
    //我们打印即可。
    for(int i=1;i<=n;i++){
        if(find(i)==i){
            cout<<value[i]<<" ";
        }
        else{
            cout<<value[i]+value[find(i)]<<" ";//找到根结点。
        }
    }
    cout<<endl;
    return 0;
}