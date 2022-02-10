/**
  *@filename:图形排版
  *@author: pursuit
  *@CSDNBlog:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-04-01 21:14
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int n,m;
struct pic{
    int w,h;//图片的宽和高。
}pics[maxn];
int f[maxn];//这代表这i号图片及之后的图片另起一行插入得到的高度。
struct line{
    int w,h;//已经使用的宽度，当前的高度。
    line(){w=0,h=0;}
    line(int _w,int _h){
        w=_w,h=_h;
    }
    line operator+(pic temp){
        if(w+temp.w>m){
            //说明空间不够，我们需要对图片进行压缩。
            temp.h=ceil(1.0*temp.h*(m-w)/temp.w);
            temp.w=m-w;
        }
        return line(w+temp.w,max(h,temp.h));//更新当前的高度。
    }
    bool full(){
        return w==m;//判断空间是否已经用完了。
    } 
    void clr(){
        w=0,h=0;
    }
};
//在已有的line基础上，从第k张图开始插入，最终能得到的整体高度。
int push_till_full(line a,int k){
    for(;k<=n&&!a.full();k++){
        a=a+pics[k];
    }
    return a.h+f[k];
}
int main(){
    while(cin>>m>>n){
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++){
            cin>>pics[i].w>>pics[i].h;
        }
        for(int i=n;i>=1;i--){
            f[i]=push_till_full(line(0,0),i);//预处理获得从第i张图片开始到第n张图片另起一行的高度。
        }
        //删除不要的图片。
        line a;//一开始没有宽度和高度。
        int ans=1e7,pre=0;//pre记录之前完整行累计的高度。
        for(int i=1;i<=n;i++){
            //不要第i张图片。
            //历史上完整行的高度是per，从i+1张图片插入得出的整体完整高度。
            ans=min(ans,pre+push_till_full(a,i+1));//用第i+1张图片填入a这个line。
            a=a+pics[i];//将第i张图片放入，作为下次迭代的line。也就是说我们每次将不要的图片加起来。
            if(a.full()){
                //行已经填满了，我们需要重置line，并且结算一个整行的高度。
                pre+=a.h;
                a.clr();//开启一个新行。
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}