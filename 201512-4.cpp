////怎么尝试都是80分，运行错误，可能是测试数据有问题
////回溯好像不会出问题，但会超时
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<stack>
//#include<mem.h>
//using namespace std;
//#define MAX_N 10001
//#define MAX_M 100001
//
//int N,M;
////邻接表
//vector<int> graph[MAX_N];
////边访问标记
//bool bgraph[MAX_N][MAX_N] = {false,};
////结果保存
//stack<int> result;
//
////接受输入
//bool input();
////深搜
//bool dfs(int);
//
////并查集，判断是否联通
//int f[MAX_N] = {0,};
////寻找根结点
//int find(int x){return f[x] == x?x:(f[x] = find(f[x]));}
////是否属于一个根结点
//bool oneSet(int x,int y){return find(x) == find(y);}
////合并两个结点
//void mer(int x,int y){if(!oneSet(x,y)) f[find(x)] = find(y);  return;}
//
////并查集判断是否联通
//bool isConn();
////是否有欧拉通路
//bool isEG();
//
////深搜判断是否连通
//bool isConn_dfs();
//
//int main()
//{
//    if(!input())
//    {
//        cout <<-1;
//        return 0;
//    }
//    memset(bgraph,false,sizeof(bgraph));
//    dfs(1);
//    while(!result.empty())
//    {
//        cout <<result.top() <<" ";
//        result.pop();
//    }
//    return 0;
//}
//bool input()
//{
//    cin >>N >>M;
//    for(int i=1;i <= N;i++)
//        f[i] = i;
//    for(int i=0;i < M;i++)
//    {
//        int s,d;
//        cin >>s >>d;
//        graph[s].push_back(d);
//        graph[d].push_back(s);
//        //结点合并
//        mer(s,d);
//    }
//    //不是连通图直接返回，并查集和深搜或其他的都行
//    if(!isConn_dfs()) return false;
//    //是连通图但没有欧拉通路，返回
//    if(!isEG()) return false;
//
//    //结点排序，后面搜到的第一个结果就是所求结果
//    for(int i=1;i <= N;i++)
//        sort(graph[i].begin(),graph[i].end());
//    return true;
//}
//bool dfs(int s)
//{
//    //邻接表
//    for(int i=0; i < graph[s].size();i++)
//    {
//        int next = graph[s][i];
//        //邻接矩阵用来保存访问过的边
//        if(!bgraph[s][next])
//        {
//            bgraph[s][next] = true;
//            bgraph[next][s] = true;
//            //已经找到退出
//            dfs(next);
//        }
//    }
//    result.push(s);
//    return false;
//}
//
////深搜判断是否来联通
//bool isConn_dfs()
//{
//    bool visit[MAX_N] = {false,};
//    stack<int> s;
//    s.push(1);
//    visit[1] = true;
//    while(!s.empty())
//    {
//        int now = s.top();
//        s.pop();
//        for(int i=0;i < graph[now].size();i++)
//        {
//            int next = graph[now][i];
//            if(!visit[next])
//            {
//                visit[next] = true;
//                s.push(next);
//            }
//        }
//    }
//    for(int i=1;i <= N;i++)
//    {
//        if(!visit[i]) return false;
//    }
//    return true;
//}
//bool isConn()
//{
//    int x = find(1);
//    for(int i=2;i <= N;i++)
//    {
//        if(find(i) != x)
//            return false;
//    }
//    return true;
//}
//
//bool isEG()
//{
//    int x = 0;
//    //不存在欧拉通路，直接返回
//    for(int i=1;i <= N;i++)
//    {
//        if(graph[i].size()%2 != 0)
//            x++;
//    }
//    //要么没有奇数度的点，要么1是奇数度的点而且还有一个奇数度的点
//    if(!(x == 0 || (x == 2 && graph[1].size()%2 != 0)))
//        return false;
//    return true;
//}
