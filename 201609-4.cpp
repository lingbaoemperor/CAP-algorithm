////Dijkstra，每次更新到某个点的最短路径的时候，记录下更新连接到这个点的边的最小权值
//#include<iostream>
//#include<vector>
//#include<queue>
//#include<mem.h>
//#define MAX_CITY 10001
//#define ULLONG unsigned long long
//using namespace std;
//
//class Node
//{
//public:
//    int next;
//    int weight;
//    Node(){}
//    Node(int n,int w){next = n;weight = w;}
//};
//vector<Node> path[MAX_CITY];
//int N,M;
//
//void Dijkstra();
//int main()
//{
//    cin >>N >>M;
//    for(int i=0;i < M;i++)
//    {
//        int s,e,w;
//        cin >>s >>e >>w;
//        path[s].push_back(Node(e,w));
//        path[e].push_back(Node(s,w));
//    }
//    Dijkstra();
//    return 0;
//}
//
//void Dijkstra()
//{
//    //访问标志
//    bool visit[N+1] = {false,};
//    //中间距离
//    ULLONG dis[N+1];
//    ULLONG cost[N+1];
//    //前驱结点，因为求总路径的时候需要用
//    memset(dis,0xff,8*(N+1));
//    memset(cost,0xff,8*(N+1));
//    visit[1] = true;
//    dis[1] = 0;
//    for(int i=0;i < path[1].size();i++)
//    {
//        int next = path[1][i].next;
//        int weight = path[1][i].weight;
//        if(!visit[next])
//        {
//            dis[next] = weight;
//            cost[next] = weight;
//        }
//    }
//    while(true)
//    {
//        int k = -1;
//        ULLONG MAX = 0Xffffffffffffffff;
//        for(int i=1;i <= N;i++)
//        {
//            if(!visit[i] && dis[i] < MAX)
//            {
//                k = i;
//                MAX = dis[i];
//            }
//        }
//        if(k == -1) break;
//        visit[k] = true;
//        for(int i=0;i < path[k].size();i++)
//        {
//            int next = path[k][i].next;
//            int weight = path[k][i].weight;
//            if(!visit[next] && (dis[k]+weight) < dis[next])
//            {
//                dis[next] = dis[k]+weight;
//                cost[next] = weight;
//            }
//            if(!visit[next] && (dis[k]+weight) == dis[next])
//            {
//                cost[next] = (weight<cost[next]?weight:cost[next]);
//            }
//        }
//    }
//    ULLONG sum = 0;
//    for(int i=2;i <= N;i++)
//        sum += cost[i];
//    cout <<sum <<endl;
//}
