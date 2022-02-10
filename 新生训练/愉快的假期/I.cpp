#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

const int maxn=1e6+7;
bool notprimer[maxn];
long long primer[maxn];
bool Interval_primer[maxn*10];//即区间l~r的素数，我们将其放小，即0~r-l。
long long l,r;//区间[l,r]。
int cnt=0;
void init(int maxn){
    //将素数筛出。
    for(int i=2;i<=maxn;i++){
        if(!notprimer[i]){
            primer[cnt++]=i;
            for(int j=i*i;j<=maxn;j+=i){
                notprimer[i]=true;
            }
        }
    }
}
void solve(){
}
int main(){
    init(5e4);//将素数筛除，再利用素数筛的思想。
    while(cin>>l>>r){
        memset(Interval_primer,true,sizeof(Interval_primer));//一开始默认这区间的数都是素数。
        if(l==1)l++;//避免1的干扰。
        for(int i=0;i<cnt;i++){
            long long temp1=(l-1)/primer[i]+1;//这里为了确保temp1*primer[i]要大于l.找出区间的最小倍数因子。当然最小为2.
            if(temp1==1)temp1++;
            long long temp2=r/primer[i];//找出区间的最大倍数因子。
            for(long long j=temp1;j<=temp2;j++)Interval_primer[j*primer[i]-l]=false;
        }
        //筛完之后就可以开始遍历了。
        long long temp=-1,min_l,min_r,max_l,max_r,maxx=-1,minn=1e9;//其中temp代表前一个素数。
        for(long long i=0;i<=r-l;i++){
            if(Interval_primer[i]){
                if(temp==-1){
                    temp=i;
                    continue;
                }
                if(maxx<i-temp){
                    //更新。
                    maxx=i-temp;
                    max_l=temp+l;
                    max_r=i+l;
                }
                if(minn>i-temp){
                    minn=i-temp;
                    min_l=temp+l;
                    min_r=i+l;
                }
                temp=i;//更新上一个素数。
            }
        }
        if(maxx==-1){
            //说明不存在两个素数以上。
            printf("There are no adjacent primes.\n");
        }
        else{
            printf("%lld,%lld are closest, %lld,%lld are most distant.\n",min_l,min_r,max_l,max_r);
        }
    }
    return 0;
}