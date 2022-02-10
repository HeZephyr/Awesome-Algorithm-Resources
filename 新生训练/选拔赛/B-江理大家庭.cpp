#include<bits/stdc++.h>

using namespace std;

string s;
bool judge1(char a){
    if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u'){
        return true;
    }
    else{
        return false;
    }
}
bool judge2(string s){
    bool flag1=false,flag2=true,flag3=true;
    int flag=-1;//若为1说明前者为元音，若为-1说明还没有确定，若为0说明前者为辅音。
    int len=s.size();
    int cnt=1;//统计连续的原因。
    char pre='0';
    for(int i=0;i<len;i++){
        if(judge1(s[i]))flag1=true;
        if(pre!='0'){
            //连续字母的判断。
            if(pre==s[i]){
                if(pre!='e'&&pre!='o'){
                    flag3=false;
                }
            }
            else{
                pre=s[i];
            }
        }
        if(flag!=-1){
            if(flag){
                //说明为元音，那么判断后者是否为元音。
                if(judge1(s[i])){
                    cnt++;
                }
                else{
                    //为辅音就改变。
                    cnt=1;
                    flag=0;
                }
            }
            else{
                if(!judge1(s[i])){
                    cnt++;
                }
                else{
                    cnt=1;
                    flag=1;
                }
            }
            if(cnt==3)flag2=false;
        }
        if(pre=='0')pre=s[i]; 
        if(flag==-1){
            if(judge1(s[i]))flag=1;
            else flag=0;
        }
    }
    if(flag1&&flag2&&flag3)return true;
    else return false;
}
int main(){
    while(cin>>s){
        if(s=="end")break;
        cout<<"<"<<s<<"> ";
        if(judge2(s)){
            cout<<"is acceptable."<<endl;
        }
        else{
            cout<<"is not acceptable."<<endl;
        }
    }
    return 0;
}