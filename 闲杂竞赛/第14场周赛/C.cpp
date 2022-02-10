/**
  *@filename:C
  *@author: pursuit
  *@created: 2021-08-28 19:21
**/
#include <bits/stdc++.h>
#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e6 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int t,n,Next[N];
string s,temp;
void getNext(string s,int len){
	int k=-1,j=0;
	Next[0]=-1;
	while(j<len){
		if(k==-1||s[j]==s[k]){
			k++;
			j++;
			Next[j]=k;
		}
		else k=Next[k];
	}
}
void solve(){
    n = s.size();
    getNext(s,n);
    int l=Next[n],flag=0,ans=0;
	if(l==0) flag=0;
	else{
		while(l){
			for(int i=2;i<=n-1;i++){
				if(Next[i]==l){
					flag=1;
					break;
				}
			}
			if(flag) break;
			l=Next[l];
		}
	}
	if(!flag) cout << "not exist" << endl;
	else{
		for(int i=0;i<l;i++)
			cout<<s[i];
        cout << endl;
	}
}
int main(){	
    cin >> t;
    while(t -- ){
        cin >> s;
        solve();
    }
    return 0;
}