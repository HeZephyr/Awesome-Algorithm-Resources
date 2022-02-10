#include<bits/stdc++.h>

using namespace std;

//维护一个最大长方形即可。
int n,maxx[2],temp[2];
char op[2];
int main(){
    while(scanf("%d",&n)!=EOF){
        maxx[0]=maxx[1]=0;//初始无长方形。
        for(int i=0;i<n;i++){
            scanf("%s%d%d",op,&temp[0],&temp[1]);
            sort(maxx,maxx+2),sort(temp,temp+2);//默认小的做宽，大的做高。
            if(op[0]=='+'){
                //更新最大长方形。
                maxx[0]=max(maxx[0],temp[0]);
                maxx[1]=max(maxx[1],temp[1]);
            }
            else{
                //判断是否可行。
                if(maxx[0]<=temp[0]&&maxx[1]<=temp[1]){
                    puts("YES");
                }
                else{
                    puts("NO");
                }
            }
        }
    }
    return 0;
}