////不要从以顾客为广搜的起始点，会超时，因为每个顾客都要广搜一次
////以餐厅为起始点，碰到顾客就标记该顾客已经拿到货，后续不再需要货
//#include<iostream>
//#include<queue>
//#define MAX_N 1001
//#define ULLONG unsigned long long
//using namespace std;
//
//int N,M,K,D;
////地图上的点的信息
//class Node
//{
//public:
//    //是否不能走此点
//    bool prohibit;
//    //是否是客户
//    bool client;
//    //是否是餐厅
//    bool rest;
//    //如果是客户，该客户需要的货物数量
//    int count;
//    Node(){prohibit = false;client = false;rest = false;count = 0;}
//    Node(bool a,bool b,bool c,int d)
//    {
//        prohibit = a;
//        client = b;
//        rest = c;
//        count = d;
//    }
//};
////用矩阵存储
//Node graphic[MAX_N][MAX_N];
//
////餐厅位置数组
//class Start
//{
//public:
//    int x;
//    int y;
//    Start(int a,int b){x = a;y = b;}
//};
//vector<Start> vr;
//
////遍历时的结点信息
//class Pos
//{
//public:
//    //当前位置
//    int x;
//    int y;
//    //当前行走的长度
//    int length;
//    Pos(){};
//    Pos(int a,int b,int c)
//    {
//        x = a;
//        y = b;
//        length = c;
//    }
//};
//
////真正的客户数量，合并重复位置以后的
//int client = 0;
//
//ULLONG BFS();
//
//int main()
//{
//    cin >>N >>M >>K >>D;
//    //接受餐厅信息
//    for(int i=0;i < M;i++)
//    {
//        int x,y;
//        cin >>x >>y;
//        graphic[x][y].rest = true;
//        vr.push_back(Start(x,y));
//    }
//    //接受客户信息，并合并同一个位置的客户
//    for(int i=0;i < K;i++)
//    {
//        int x,y,z;
//        cin >>x >>y >>z;
//        if(!graphic[x][y].client) client++;
//        graphic[x][y].count += z;
//        graphic[x][y].client = true;
//    }
//    //接受不能走的位置
//    for(int i=0;i < D;i++)
//    {
//        int x,y;
//        cin >>x >>y;
//        graphic[x][y].prohibit = true;
//    }
//    cout <<BFS();
//    return 0;
//}
//
//ULLONG BFS()
//{
//    ULLONG sum = 0;
//    bool visit[MAX_N][MAX_N] = {false,};
//    queue<Pos> q;
//    //所有餐厅入队
//    for(int i=0;i < M;i++)
//    {
//        int x = vr[i].x;
//        int y = vr[i].y;
//        q.push(Pos(x,y,0));
//    }
//    //如果所有客户都接到货，也退出
//    while(!q.empty() && client)
//    {
//        Pos now = q.front();
//        q.pop();
//        //访问过的结点不再访问
//        if(visit[now.x][now.y]) continue;
//        visit[now.x][now.y] = true;
//
//        //因为首先到达某个客户的送餐者一定是从距该客户最近餐厅出发的
//        //当前结点是客户，标记已送餐，客户数量减1
//        if(graphic[now.x][now.y].client)
//        {
//            client--;
//            sum += now.length*graphic[now.x][now.y].count;
//            graphic[now.x][now.y].client = false;
//        }
//        //上下左右位置入队
//        if(now.x > 1 && !graphic[now.x-1][now.y].prohibit)
//            q.push(Pos(now.x-1,now.y,now.length+1));
//        if(now.x < N && !graphic[now.x+1][now.y].prohibit)
//            q.push(Pos(now.x+1,now.y,now.length+1));
//        if(now.y > 1 && !graphic[now.x][now.y-1].prohibit)
//            q.push(Pos(now.x,now.y-1,now.length+1));
//        if(now.y < N && !graphic[now.x][now.y+1].prohibit)
//            q.push(Pos(now.x,now.y+1,now.length+1));
//    }
//    return sum;
//}
