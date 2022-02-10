/**
  *@filename:G
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-14 17:18
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 200000 + 5;
const int mod = 1e9+7;

int n,m;
vector<int> a[maxn],b[maxn];
void exChange(){
	if(n>m){
		//矩阵转置。
		for(int i=0;i<=m;i++){
			b[i].resize(n+7);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				b[j][i]=a[i][j];
			}
		}
		swap(n,m);
	}
	else{
		for(int i=0;i<=n;i++){
			b[i].resize(m+7);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				b[i][j]=a[i][j];
			}
		}
	}
	for(int i=1;i<=n;i++){
		//对行求前缀和。
		for(int j=1;j<=m;j++){
			b[i][j]+=b[i-1][j];	
		}
	}
}
void solve(){
	exChange();
	int ans=-1e9;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			//枚举顶行和底行。
			int now=0;
			for(int k=1;k<=m;k++){
				//枚举列。
				now=max(now,0)+b[j][k]-b[i-1][k];
				ans=max(now,ans);
			}
		}
	}
	cout<<ans<<endl;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<=n;i++){
		//申请动态内存空间。
		a[i].resize(m+7);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	solve();
	return 0;
}