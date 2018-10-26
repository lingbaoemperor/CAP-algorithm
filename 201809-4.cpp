////差分分解
////p1,p2,......,pn是输入的菜价
////那么前一天的菜价（x1,x2,.....,xn）应该满足
////2p1 <= x1+x2 <= 2p1+1 , 3p2 <= x1+x2+x3 <= 3p2+2 , ...... , 2p2 <= x(n-1)+xn <= 2pn+1.
////x1,x2,......,xn >= 1.
////令s0=0 , s1 = x1 , s2 = x1+x2 , ...... , sn = x1+...+xn.转换为>=的形式
////s2 - s0 >= 2p1 , s0 - s2 >= -(2p1+1)
////s3 - s0 >= 3p2 , s0 - s3 >= -(3p2+2)
////......
////以s0为源点，求其到各点的最长路径，Bellman_Ford和spfa都行
//#include<iostream>
//#include<vector>
//#include<mem.h>
//#define MAX_N 1001
//using namespace std;
//
//int N;
//class Edge
//{
//public:
//    int weight;
//    int next;
//    Edge(){}
//    Edge(int w,int n)
//    {
//        weight = w;
//        next = n;
//    }
//};
//vector<Edge> path[MAX_N];
//void input();
//void check();
//void Bell(int);
//
//int main()
//{
//    input();
//    Bell(0);
//    return 0;
//}
//
////Bellman_Ford
////求的时最长路径，所以不能有正权回路
//void Bell(int src)
//{
//    //初始状态0，因为求最长路径，最终一定每个路径会一定是大于0的
//    //因为价格肯定是大于零
//    int dis[N+1] = {0,};
//    //N+1个结点，遍历N次
//    for(int i=1;i <= N;i++)
//    {
//        //遍历所有边
//        for(int j=0;j <= N;j++)
//        {
//            for(int k=0;k < path[j].size();k++)
//            {
//                Edge e = path[j][k];
//                if(dis[e.next] < (dis[j]+e.weight))
//                    dis[e.next] = dis[j]+e.weight;
//            }
//        }
//    }
//    //是否有正权回路，有则错误
//    for(int i=0;i <= N;i++)
//    {
//        for(int j=0;j < path[i].size();j++)
//        {
//            Edge e = path[i][j];
//            if(dis[e.next] < (dis[i]+e.weight))
//            {
//                cout <<"错误" <<endl;
//                break;
//            }
//        }
//    }
//    //求每天的价格
//    dis[0] = 0;
//    for(int i=1;i <= N;i++)
//        cout <<dis[i] - dis[i-1] <<" ";
//}
//
//void input()
//{
//    cin >>N;
//    for(int i=1;i <= N;i++)
//    {
//        int price;
//        cin >>price;
//        if(i == 1)
//        {
//            path[0].push_back(Edge(price*2,2));
//            path[2].push_back(Edge(-price*2-1,0));
//            continue;
//        }
//        else if(i == N)
//        {
//            path[N-2].push_back(Edge(price*2,N));
//            path[N].push_back(Edge(-price*2-1,N-2));
//            continue;
//        }
//        path[i-2].push_back(Edge(price*3,i+1));
//        path[i+1].push_back(Edge(-price*3-2,i-2));
//    }
//    for(int i=0;i < N;i++)
//        path[i].push_back(Edge(1,i+1));
////    check();
//}
//
//void check()
//{
//    for(int i=0;i <= N;i++)
//    {
//        cout <<i <<":" <<endl;
//        for(int j=0;j < path[i].size();j++)
//        {
//            cout <<path[i][j].next <<" " <<path[i][j].weight <<endl;
//        }
//    }
//}
