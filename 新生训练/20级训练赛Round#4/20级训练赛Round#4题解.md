

[TOC]



# 前言

> 诶，大部分人好像都没补题的习惯，是因为太难了还是没有题解呀？不过还是希望大家认真补题，如果碰到不会的不去弄懂那下次还是不会的。==~~因为我太懒了，所以每次训练赛都没有准备题解~~==,之后题解我会尽量做，如果没有的话希望大家自己能主动去网上找题解，积极主动！
>
> 相信过了这么久，其实大家也已经进步许多了，一定要坚持下去，不要松懈，你们就是江理$ACM$的希望！

# [A.凯少的动作序列](https://codeforces.com/problemset/problem/954/A)

* **解题思路**

  ==按照贪心思想，我们的目标自然就是替换尽可能多的RU和UR对。== 所以，当为RU和UR对的时候我们及时替换即可，这种策略自然是全局最优的。我们这里列举证明：$RUR$,最多一种，我们及时替换$RU$，对于$RU$之后的序列，我们并不会影响，而对于替换$RU$之前的序列，由于已经被遍历过，前面即是最优解了，所以这种策略是合理的。

* **参考代码**

  ```c++
  #include<bits/stdc++.h>
  
  using namespace std;
  
  const int N = 110;
  int n;
  char s[N];
  void solve(){
      int ans = n;//什么都不替换自然为n。
      for(int i = 1; i < n; ++ i){
          if((s[i] == 'R' && s[i + 1] == 'U' || s[i] == 'U' && s[i + 1] == 'R')){
              ans -- ;
              i ++;
          }
      }
      printf("%d\n",ans);
  }
  int main(){
      while(scanf("%d", &n) != EOF){
          scanf("%s", s + 1);
          solve();
      }
      return 0;
  }
  ```

# [B.凯少的秘密消息](https://codeforces.com/problemset/problem/959/B)

* **解题思路**

  首先我们需要记录每个字符串的序号（因为我们需要通过字符串得到其序号），这很容易想到用$map$记录。 ==那么对于分组，我们用$group$来存储，其中每组我们按花费来排序，那么最优的替换选择就是同组内的第一个元素。== 我们自然也需要记录字符串在那个组，这样才能知道字符串需要替换成哪个，所以我们需要用$idx$数组记录字符串所在的组别。这样，题目自然解决了，对于输入的$m$个的单词，索引它所在的组，获取其组中的第一个字符串即可。累加最小花费。

* **参考代码**

  ```c++
  #include<bits/stdc++.h>
  
  using namespace std;
  
  const int N = 1e5 + 10;
  
  //自然是想着将同意义的单词分组，然后排序取最低费用即可。
  int n,k,m;
  map<string,int> p;
  int cost[N],idx[N];//idx[i]表示第i个单词所在的组序号。
  string s;
  vector<int> group[N];
  //重写比较方法，根据花费来排序。
  bool cmp(int i,int j){
      return cost[i] < cost[j];
  }
  void solve(){
      for(int i = 1; i <= k; ++ i){
          sort(group[i].begin(),group[i].end(),cmp);
      }
      for(int i = 1; i <= k; ++ i){
          /*
          cout << i << " group" << endl;
          for(auto &x:group[i]){
              cout << x << " " << cost[x] << endl;
          }
          */
      }
      long long ans = 0;
      while(m -- ){
          cin >> s;
          //获取序号。
          int pos = p[s];
          //根据组号选择最小值。
          //cout << s << " " << idx[pos] << endl;
          ans += cost[group[idx[pos]][0]];
      }
      cout << ans << endl;
  }
  int main(){
      ios::sync_with_stdio(false);
      cin.tie(nullptr),cout.tie(nullptr);
      cin >> n >> k >> m;
      for(int i = 1; i <= n; ++ i){
          cin >> s;
          p[s] = i;//记录其所在下标。
      }
      for(int i = 1; i <= n; ++ i){
          cin >> cost[i];
      }
      int cnt,x;
      for(int i = 1; i <= k; ++ i){
          cin >> cnt;
          while(cnt --){
              cin >> x;
              group[i].push_back(x);
              //记录x所在的组。
              idx[x] = i;
          }
      }
      solve();
      return 0;
  }
  ```

# [C.尚佬的投篮得分](https://codeforces.com/problemset/problem/961/B)

* **解题思路**

  双指针维护一个长度为$k$的区间。 ==处理其中的概率为$0$的点，注意区间移动的时候要剔除掉过期元素。==

* **参考代码**

  ```c++
  #include<bits/stdc++.h>
  
  using namespace std;
  
  const int N = 1e5 + 10;
  
  int n,k;
  int a[N],p[N],ans;//ans统计得分。
  void solve(){
      //此题易知用双指针获取最大值，注意，我们需要时刻更新我们能用的次数。
      int l = 1,r = 1;
      int maxx = 0;
      while(r <= n){
          while(r <= n && r - l  < k){
              if(!p[r]){
                  ans += a[r];
              }
              r ++ ;
          }
          maxx = max(ans,maxx);//保存最大值。
          if(!p[l]){
              ans -= a[l];
          }
          l ++;
      }
      printf("%d\n",maxx);
  }
  int main(){
      scanf("%d %d", &n, &k);
      for(int i = 1; i <= n; ++ i){
          scanf("%d", &a[i]);
      }
      for(int i = 1; i <= n; ++ i){
          scanf("%d", &p[i]);
          if(p[i]){
              ans += a[i];
          }
      }
      solve();
      return 0;
  }
  ```

# [D.以旧换新](https://codeforces.com/problemset/problem/915/C)

* **解题思路**

  对于$a,b$，由于题目中一定有解，所以$a<=b$。我们有几种讨论的情况，当$a$的位数小于$b$的位数的时候，不管$a$怎么变化，始终小于$b$，所以我们自然是将$a$的位数排序构造即可；当$a=b$，此时最大则是$b$，直接输出即可；而当$a<b$，此时$a$受$b$的限制，我们构建$a$的时候需要考虑$b$，由于存在未知情况，所以我们需要用$dfs$去搜索，==注意贪心搜索和剪枝== 。那么何为贪心搜索，在构造$a$的时候，我们自然想往$b$上靠，如果我们目前不知道构建的$a$是否大于等于$b$，那么我们自然只会进行两种搜索策略，一种是当前位等于$b$对应的位，这种即是持续往$b$相等那里靠，另一种则是当前位小于$b$对应的位（从可选择的选择最大值，其余的跳过），一但构建这种，那么构建的数一定小于$b$。那么如果我们已知构建的$a$小于$b$，那么我们只会有一种搜索策略，就是构建位数上的可选最大值。有了这两种思想，按照优先顺序列写，我们最先构建出来的数一定是最大值。注意利用一个全局变量控制$dfs$的进行，即代表是否找到最优解。此题特别具有代表性，希望大家好好整理，当然，方法不只一种，有其他方法也可以去学习讨论。

* **参考代码**

  ```c++
  #include<bits/stdc++.h>
  
  using namespace std;
  
  string a,b;//利用字符串存储更方便。
  int cnt[10];
  bool ok;//判断是否找到最优解。
  void dfs(long long ans = 0,int len = 0,bool flag = false){
      //flag代表当前路径构造的ans是否已经知晓其小于0了。
      //经过我们的过滤，实际上我们已经得到了对应的结果。
      if(len == a.size()){
          ok = true;
          cout << ans << endl;
          return;
      }
      for(int i = 9; i >= 0; -- i){
          if(ok)return;
          if(cnt[i]){
              if(flag){
                  //填充最大的。
                  cnt[i] --;
                  dfs(ans * 10 + i,len + 1,flag);
                  cnt[i] ++;
                  break;
              }
              else{
                  if(i == b[len] - '0'){
                      cnt[i] --;
                      dfs(ans * 10 + i,len + 1,flag);
                      cnt[i] ++;
                  }
                  else if(i < b[len] - '0'){
                      cnt[i] --;
                      dfs(ans * 10 + i,len + 1,true);
                      cnt[i] ++;
                  }
              }
          }
      }
  }
  void solve(){
      if(a.size() < b.size()){
          //说明a不依赖于b，我们输出所能构建的最大a。
          sort(a.begin(),a.end(),greater<char>() );
          cout << a << endl;
      }
      else if(a == b){
          cout << a << endl;
      }
      else{
          for(auto &x : a){
              cnt[x - '0'] ++;
          }
          dfs();
      }
  }
  int main(){
      ios::sync_with_stdio(false);
      cin.tie(nullptr),cout.tie(nullptr);
      cin >> a >> b;
      solve();
      return 0;
  }
  ```

# [E.交换相邻元素](https://vjudge.net/problem/CodeForces-920C)

* **解题思路**

  ==贪心，题目实际上告诉我们只能将连续1的段$[l,r]$，使得$[l,r + 1]$变成有序的== ，所以我们对这些连续1的段所控制的区间排序即可。

  最后判断是否是有序的即可。

* **参考代码**

  ```c++
  #include<bits/stdc++.h>
  
  using namespace std;
  
  const int N = 2e5 + 10;
  
  int n,a[N];
  char s[N];
  void solve(){
      for(int i = 1; i <= n - 1; ++ i){
          if(s[i] == '1'){
              int j = i;
              while(j + 1 <= n - 1 && s[j + 1] == '1'){
                  j ++ ;
              }
              sort(a + i,a + 1 + j + 1);
              i = j;//注意这里需要直接跳到j。
          }
      }
      for(int i = 1; i <= n; ++ i){
          if(a[i] != i){
              puts("NO");
              return;
          }
      }
      puts("YES");
  }
  int main(){
      scanf("%d", &n);
      for(int i = 1; i <= n; ++ i){
          scanf("%d", &a[i]);
      }
      scanf("%s",s + 1);
      solve();
      return 0;
  }
  ```

# [F.帮帮凯少保护他的羊](https://codeforces.com/problemset/problem/948/A)

* **解题思路**

  我们的策略自然是堵住所有的狼，让它无法吃掉羊。那么只有一种情况我们是无法保护羊的，即羊在狼的周围。所以我们只需要判断是否存在这种情况即可。如果不存在，那么直接在所有的空地放狼。

* **参考代码**

  ```c++
  #include <bits/stdc++.h>
  
  using namespace std;
  
  const int N = 500 + 5;
  
  int n,m;//n * m的矩阵。
  char s[N][N];
  bool check(int x,int y){
      if((x > 0 && s[x - 1][y] == 'S') || (y > 0 && s[x][y - 1] == 'S') || 
      (x < n - 1 && s[x + 1][y] == 'S') || (y < m - 1 && s[x][y + 1] == 'S')){
          return false;
      }
      return true; 
  }
  void solve(){
      for(int i = 0; i < n; ++ i){
          for(int j = 0; j < m; ++ j){
              if(s[i][j] == 'W'){
                  if(!check(i,j)){
                      puts("NO");
                      return;
                  }
              }
          }
      }
      puts("YES");
      for(int i = 0; i < n; ++ i){
          for(int j = 0; j < m; ++ j){
              if(s[i][j] == '.'){
                  s[i][j] = 'D';
              }
          }
          puts(s[i]);
      }
  }
  int main(){
      scanf("%d %d", &n, &m);
      for(int i = 0; i < n; ++ i){
          scanf("%s",s[i]);
      }
      solve();
      return 0;
  }
  ```

  



