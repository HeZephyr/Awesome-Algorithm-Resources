#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int inf=1e9;
const int N=1e5+10;
const int M=3e6+10;
const int mo=998244353;
int p[M][2],mx[M],a[N];
void sol(){
	int n,k;
	scanf("%d%d",&n,&k);
	rep(i,1,n){
		scanf("%d",&a[i]);
		a[i]^=a[i-1];
	}
	int anl=-1,anr=n,tot=1;
	mx[1]=-1;//max为最左的端点。
	p[1][0]=p[1][1]=0;//根节点。p为字典树。
	rep(i,1,n){
		//i为枚举的右节点。通过扫描遍历并同步插入维护字典树。
		int x=1,res=-1;
		//res为不断缩小满足的左端点。
        //遍历前i - 1个前缀和。
		dep(j,29,0){
			//w则表示a[i]的第j个位置是否为1.
			int w=(a[i]>>j)&1;
			//判断k的第j个位置是否为1.
			if(!((k>>j)&1)){
				if(p[x][w^1])res=max(res,mx[p[x][w^1]]);
				//由于其第j个位置为0。所以如果相异的节点存在，则说明使得其大于k。更新即可。到这个说明异或的结果必大于k。
				x=p[x][w];
			}else x=p[x][w^1];//如果为1，就获取其与a[i]相异的子节点。保证在该位上与其相等。
			if(!x)break;//如果为0，说明不存在子树了，就直接退出。
		}
		if(x)res=max(res,mx[x]);//如果x>0，就肯定满足。
		if(res>=0&&i-res<anr-anl)anl=res,anr=i;
		x=1;
		dep(j,29,0){
			int w=(a[i]>>j)&1;
			if(!p[x][w]){
				//说明这个点没有存在过，我们需要插入。
				p[x][w]=++tot;mx[tot]=-1;
				p[tot][0]=p[tot][1]=0;
			}
			x=p[x][w];//遍历子节点。
            //获取最大的左端点。
			mx[x]=max(mx[x],i);
		}
	}
	if(anl>=0)printf("%d %d\n",anl+1,anr);
	else printf("-1\n");
}
int main(){int t;
	//freopen("in.txt","r",stdin);
	//freopen("ans.txt","w",stdout);
	scanf("%d",&t);
	rep(i,1,t)sol();
}
