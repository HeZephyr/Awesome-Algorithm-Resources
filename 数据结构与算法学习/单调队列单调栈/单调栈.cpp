#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int n,x,s[N],top;//s为单调栈。
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &x);
        while(top && s[top] >= x)s[top] --;
        if(!top)printf("-1 ");
        else printf("%d ",s[top]);
        s[++ top] = x;
    }
    printf("\n");
    return 0;
}
/*
int n,x;
stack<int> s;
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i){
        scanf("%d", &x);
        while(!s.empty() && s.top() >= x)s.pop();
        if(s.empty())printf("-1 ");
        else printf("%d ",s.top());
        s.push(x);
    }
    printf("\n");
    return 0;
}
*/