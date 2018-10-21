//#include<iostream>
//#include<vector>
//#include<queue>
//#include<stack>
//#include<mem.h>
//using namespace std;
//#define MAX_CITY 10001
//
//vector<int> path[MAX_CITY];
//int N,M;
////用来记录联通城市
//bool visit[MAX_CITY] = {false,};
////记录节点是否在栈中
//bool vins[MAX_CITY] = {false,};
////用来记录结果
//unsigned long long sum = 0;
////访问时间戳
//int dfn[MAX_CITY] = {0,};
////接下来能追溯到的所有顶点中的最小时间戳
//int low[MAX_CITY] = {0,};
//int time = 1;
//stack<int> s;
//
////深搜超时
////广搜也超时
////tarjan,这些衍生出来的算法太多，不太好记
//void DFS_TarJan(int);
//int main()
//{
//    cin >>N >>M;
//    for(int i=0;i < M;i++)
//    {
//        int s,e;
//        cin >>s >>e;
//        path[s].push_back(e);
//    }
//    //以每个顶点为起始
//    for(int i=1;i <= N;i++)
//    {
//        if(!visit[i])
//            DFS_TarJan(i);
//    }
//    cout << sum;
//    return 0;
//}
//void DFS_TarJan(int now)
//{
//    dfn[now] = time;
//    low[now] = time;
//    time++;
//    s.push(now);
//    vins[now] = true;
//    visit[now] = true;
//    for(int i=0;i < path[now].size();i++)
//    {
//        int next = path[now][i];
//        //如果未访问过
//        if(!visit[next])
//        {
//            //结点入栈
//            DFS_TarJan(next);
//            //退栈以后，更新当前结点的low
//            low[now] = low[now]<low[next]?low[now]:low[next];
//        }
//        //如果接下来的节点在栈中
//        else if(vins[next])
//        {
//            //更新当前结点的low
//            low[now] = low[now]<dfn[next]?low[now]:dfn[next];
//        }
//    }
//    //如果当前顶点是连通分量的跟，则出栈
//    //记录该连通分量中的顶点对
//    unsigned long long vt = 0;
//    if(low[now] == dfn[now])
//    {
//        while(true)
//        {
//            vt++;
//            int p = s.top();
//            vins[p] = false;
//            s.pop();
//            if(p == now)
//                break;
//        }
//        sum += vt*(vt-1)/2;
//    }
//}
