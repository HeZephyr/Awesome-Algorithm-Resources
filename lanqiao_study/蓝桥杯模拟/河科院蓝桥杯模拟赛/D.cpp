#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int a[]={2,3,3,3,5,6,6,7,7,8};
bool check(vector<int> num){
    vector<int> temp(num);
    sort(num.begin(),num.end());
    if(num==temp){
        return true;
    }
    sort(num.begin(),num.end(),greater<int>() );
    if(num==temp){
        return true;
    }
    else{
        return false;
    }
}
bool judge(){
    vector<int> temp1,temp2,temp3;
    for(int i=0;i<8;i++){
        for(int j=i+1;j<9;j++){
            temp1.clear(),temp2.clear(),temp3.clear();
            for(int k=0;k<=i;k++)temp1.push_back(a[k]);
            for(int k=i+1;k<=j;k++)temp2.push_back(a[k]);
            for(int k=j+1;k<10;k++)temp3.push_back(a[k]);
            if(check(temp1)&&check(temp2)&&check(temp3)){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int ans=0;
    do{
        if(judge())ans++;
    }while(next_permutation(a,a+10));
    cout<<ans<<endl;//21456
    return 0;
}