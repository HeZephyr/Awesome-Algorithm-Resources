/* #include<iostream>

using namespace std;

int check(int num){
    int ans=0;
    while(num>0){
        if(num%10==6){
            ans++; 
        }
        num/=10;
    }
    return ans;
}
int main(){
    int ans=0;
    for(int i=1;i<=2021;i++){
        ans+=check(i);
    }
    cout<<ans<<endl;
    return 0;
} */

#include<iostream>

using namespace std;

int main(){
    cout<<602<<endl;
    return 0;
}