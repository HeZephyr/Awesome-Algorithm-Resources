#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
int a[5][5];
int flag[20]={0};
int ans=0;
//34是1~16的和除以4
bool Check(int x, int y)
{
    if(x<3)
    {
        if(y<3) return true;
        if(a[x][0]+a[x][1]+a[x][2]+a[x][3]==34)//x<3,y==3时：判断该行的和是否为34
            return true;
        return false;
    }
    else//x>3时
    {
        if(y==0)//判断第一列的和与右边对角线的和是不是为34
            if((a[0][0]+a[1][0]+a[2][0]+a[3][0]!=34)||(a[0][3]+a[1][2]+a[2][1]+a[3][0]!=34)) return false;
        if(y==1||y==2)//判断第2列和第3列的和是不是34
            if(a[0][y]+a[1][y]+a[2][y]+a[3][y]!=34) return false;
        if(y==3)//判断第4列和左对角线的和是不是34
            if((a[0][y]+a[1][y]+a[2][y]+a[3][y]!=34)||(a[0][0]+a[1][1]+a[2][2]+a[3][3])!=34) return false;
        return true;
    }
}
 
 
void dfs(int x, int y)
{
    if(x==4)
    {
        ans++;
        return;
    }
    for(int num=1; num<=16; num++)
    {
        if(flag[num]==0)
        {
            a[x][y]=num;
            flag[num]=1;
            if(Check(x,y))//剪枝
            {
                if(y<3) dfs(x,y+1);
                else dfs(x+1,0);
            }
            flag[num]=0;
        }
    }
 
 
}
 
int main()
{
    flag[1]=1;
    a[0][0]=1;
    dfs(0,1);
    cout<<ans;
 
    return 0;
}