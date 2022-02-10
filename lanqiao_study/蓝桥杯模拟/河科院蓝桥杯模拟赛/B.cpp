#include<iostream>
#include<string> 
#include<set>

using namespace std;

//iawaswapwauawhawdwafwanbiopwanivgbikvblvbwawawawvolyuvgbololvolgbyolgyowagbolgawgboplwawaolgyolwaogblwaygbowawagwabwayawopwawagyowabwaowapjwapcfrtuywawacvujwawawaufttyfuftywawawatifgugbgbyguwawawawayugbigwwwytigwygwgbwyoawawgoghwaogwborgrewabouyhwabyuhowabhnwawauygbawyawuwaoawfcawaaaahwaywauwagwawefwaafmbawklawjiawihnwanhawawawawijwajiofjeriofgjrefjhwaewarwaowagwahwauwaiwarwaiwaqwarwahwaqwawwaowapfweofbwewafwahwaiwaewawwawawawawafwawawawaeiufwepfhnewfwahwajwatwafowawajtokshwawafwaiwahwafwahmgoewawawawafkfjkewnwawafiewhfwawawafjkernhawkrenwawawawafujnrheiowanwakawawawawwanoifewajrwaoawawfweojnwawawawawawawafjkwenawawferkwmpwawawawaforeijawawferhfiueorghwuwafguwegfwaghrwiufgwahweofgowaidwiweaiwwawieyiwe
string s;
int ans1,ans2;//ans1为错误，ans2为警告。
void solve(){
    ans1=0,ans2=0;
    //遍历。
    s+="      ";//避免越界判断。
    int i=0,len=s.size();
    while(i<len){
        if(s[i]=='w'&&s[i+1]=='a'){
            if(s[i+2]=='w'&&s[i+3]=='a'){
                while(s[i]=='w'&&s[i+1]=='a')i+=2;
                ans1++;
            }
            else{
                ans2++;
                i+=2;
            }
        }
        else if(s[i]=='a'&&s[i+1]=='w'){
            if(s[i+2]=='a'&&s[i+3]=='w'){
                while(s[i]=='a'&&s[i+1]=='w')i+=2;
                ans1++;
            }
            else{
                ans2++;
                i+=2;
            }
        }
        else{
            i++;
        }
    }
    cout<<ans2<<"\n"<<ans1<<endl;//78 25
}
int main(){
    while(cin>>s){
        solve();
    }
    return 0;
}

