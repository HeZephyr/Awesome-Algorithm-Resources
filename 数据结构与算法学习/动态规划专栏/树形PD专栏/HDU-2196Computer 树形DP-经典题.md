* **题面**

  >A school bought the first computer some time ago(so this computer's id is 1). During the recent years the school bought N-1 new computers. Each new computer was connected to one of settled earlier. Managers of school are anxious about slow functioning of the net and want to know the maximum distance Si for which i-th computer needs to send signal (i.e. length of cable to the most distant computer). You need to provide this information.
  >![img](https://raw.githubusercontent.com/unique-pure/PicLibrary/main/img/C128-1005-1.JPG)
  >
  >Hint: the example input is corrsponding to this graph. And from the graph, you can see that the computer 4 is farthest one from 1, so S1 = 3. Computer 4 and 5 are the farthest ones from 2, so S2 = 2. Computer 5 is the farthest one from 3, so S3 = 3. we also get S4 = 4, S5 = 4.
  >
  >Input
  >
  >Input file contains multiple test cases.In each case there is natural number N (N<=10000) in the first line, followed by (N-1) lines with descriptions of computers. i-th line contains two natural numbers - number of computer, to which i-th computer is connected and length of cable used for connection. Total length of cable does not exceed 10^9. Numbers in lines of input are separated by a space.
  >
  >Output
  >
  >For each case output N lines. i-th line must contain number Si for i-th computer (1<=i<=N).
  >
  >Sample Input
  >
  >```
  >5
  >1 1
  >2 1
  >3 1
  >1 1
  >```
  >
  >Sample Output
  >
  >```
  >3
  >2
  >3
  >4
  >4
  >```

* **题目大意**

  > 给出一棵树，求离每个节点最远的点的距离

* **解题思路**

  这种问题我们很容易想到树形DP，而对于这种无根树，我们必须要知道节点$u$的最远距离是怎么来的:

  * ==来自它的孩子部。==
  * ==来自它的父亲部。==

  如下图所示：

  ![image-20210524203516576](https://raw.githubusercontent.com/unique-pure/PicLibrary/main/img/image-20210524203516576.png)

  求孩子部的最远距离好求，我们利用树形$DP$递归从下到上求解即可。而来自父亲部的最远距离我们怎么求呢？那么我们就需要知道父亲部的最远距离怎么求？有两种情况。

  * ==父节点的父亲部。==
  * ==父节点的孩子部。==

  由上可知，父节点的孩子部可能包含了我们这蓝色的部分，即我们要求的$u$的孩子部，这显然是不合理的，我们需要排除这种情况。则我们就可以判断一下：我们需要判断一下，**假如fu的最远点路径经过了u，那么我们就不继承他，改为继承fu子树的次远点距离**。那么也就是说，我们是先求出来自孩子部的最远距离和次远距离，这需要我们利用一次树形$DP$跑$dfs$解决，而如果需要求来自父亲部的最远距离的话，我们需要通过继承我们的父节点的最远距离和次远距离，这样才能求解。而第二遍的树形$DP$方程如下：

  设$f[u][0]$为节点$u$孩子部的最远距离，$f[u][1]$为节点$u$孩子部的次远距离，而$f[u][2]$则为节点$u$父亲部的次元距离。

  当$u$在$fu$的最远点路径上，那么$f[u][2]=max(f[u][1],f[u][2])+w[u][v]$

  当$u$不在$fu$的最远点路径上，那么$f[u][2]=max(f[u][0],f[u][2])+w[u][v]$

  跑完两边之后易知每个节点$i$的最远距离为$max(f[i][0],f[i][2])$

* **AC代码**

  