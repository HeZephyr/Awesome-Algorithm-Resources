/**
  *@filename:022重排链表
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-21 19:08
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100010 + 5;
const int mod = 1e9+7;

struct node{
    int id,data,next;//当前结点编号，当前结点数据，下一个结点的编号。
};
int n,head;
node nodes[maxn];
int main(){
    cin>>head>>n;
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        nodes[temp].id=temp;
        cin>>nodes[temp].data>>nodes[temp].next;
    }
    vector<node> v1,v2;
    while(head!=-1){
        v1.push_back(nodes[head]);
        head=nodes[head].next;
    }
    //存储好之后利用双指针来实现链表重排。
    int l=0,r=v1.size()-1;
    while(true){
        v2.push_back(v1[r]);
        r--;
        if(l>r)break;
        v2.push_back(v1[l]);
        l++;
        if(l>r)break;
    }
    int len=v2.size();
    for(int i=0;i<len;i++){
        if(i!=len-1){
            printf("%05d %d %05d\n",v2[i].id,v2[i].data,v2[i+1].id);
        }
        else{
            printf("%05d %d %d\n",v2[i].id,v2[i].data,-1);
        }
    }
    return 0;
}