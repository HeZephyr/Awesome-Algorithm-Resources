#include<bits/stdc++.h>
 
using namespace std;
 
const int maxn=1e6+10;
 
int n;
char s[maxn];
char result[maxn];
int find(char *num,char x,int len){
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
    scanf("%d%s", &n, s+1);
    result[0] = s[1];
    int len=1;
    for(int i=2;i<=n;i++){
        if(s[i] >= result[len-1]){
            result[len] = s[i],len ++ ;
        }
        else{
            //维护一个单调队列，这个思想实际上就是我们替换中间的对整体长度没有影响，但可以为后面的多种选择。
            int index=find(result,s[i],len);//找到第一个大于等于它的位置替换掉。
            result[index]=s[i];
        }
    }
    printf("%d\n",n - len);
    return 0;
}