#include<bits/stdc++.h>

using namespace std;

const int maxn=1e5+10;

int n;
int a[maxn];
int find(vector<int> num,int x,int len){
    int l=0,r=len-1;
    while(l<r){
        int mid=(l+r)>>1;
        if(num[mid]>=x){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    return l;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    vector<int> result;
    result.push_back(a[1]);
    int len=1;
    for(int i=2;i<=n;i++){
        if(a[i]>result[len-1]){
            result.push_back(a[i]),len++;
        }
        else{
            //维护一个单调队列，这个思想实际上就是我们替换中间的对整体长度没有影响，但可以为后面的多种选择。
            int index=find(result,a[i],len);//找到第一个大于等于它的位置替换掉。
            result[index]=a[i];
        }
    }
    cout<<len<<endl;
    return 0;
}