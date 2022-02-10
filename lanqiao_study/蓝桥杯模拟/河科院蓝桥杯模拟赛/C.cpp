#include<iostream>

using namespace std;

typedef long long ll;
ll fib[20];
void init(){
    fib[1]=1,fib[2]=1;
    for(int i=3;i<=19;i++){
        fib[i]=fib[i-1]+fib[i-2];
    }
}
ll gcd(ll n,ll m){
    return n%m?gcd(m,n%m):m;
}
struct node{
    ll a,b;
};
node nums[15];
int main(){
    init();
    for(int i=1;i<=13;i++){
        nums[i].a=1,nums[i].b=(fib[i]*fib[i+1]);
    }
    /* node result;
    result.a=nums[1].a,result.b=nums[1].b;
    for(int i=2;i<=13;i++){
        ll temp1=result.a*nums[i].b;
        ll temp2=nums[i].a*result.b;
        result.b=result.b*nums[i].b;
        result.a=temp1+temp2;
        temp1=gcd(result.a,result.b);
        result.a/=temp1,result.b/=temp1;
        cout<<result.a<<"/"<<result.b<<endl;
    }
    cout<<result.a<<"/"<<result.b<<endl;//6535086616739/3684083162760
    return 0; */
    cout<<6535086616739.0/3684083162760.0<<endl;
    double ans=0;
    for(int i=1;i<=13;i++){
        ans+=(double)(nums[i].a)/(double)(nums[i].b);
    }
    cout<<ans<<endl;
}

/* #include<iostream>

using namespace std;

int main(){
    cout<<"6535086616739.0/3684083162760.0"<<endl;

    return 0;
} */