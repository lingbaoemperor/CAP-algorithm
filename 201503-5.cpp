////��ʱ����������30
////����˵�÷��Σ�����̫����û��ϸ�о�
//#include<iostream>
//#include<vector>
//#include<queue>
//#include<stack>
//#include<vector>
//#include<mem.h>
//using namespace std;
//#define MAX_LIMIT 100000
//#define MAX 0x7FFFFFFF
//#define ULONG unsigned long long
//class Info
//{
//public:
//    int p1;
//    ULONG p2;
//    Info(int p1,ULONG p2)
//    {
//        this ->p1 = p1;
//        this ->p2 = p2;
//    }
//    Info(){}
//};
//class Node
//{
//public:
//    int p1; //��ǰ�ڵ�
//    ULONG p2; //��ǰ�߹���·��
//    ULONG p3; //��ǰ����
//    ULONG p4; //�������е����ʳ��۸�
//    Node(int p1,ULONG p2,ULONG p3,ULONG p4)
//    {
//        this ->p1 = p1;
//        this ->p2 = p2;
//        this ->p3 = p3;
//        this ->p4 = p4;
//    }
//    Node(){}
//};
//int N,M;
//vector<Info> path[MAX_LIMIT];
//ULONG prices[MAX_LIMIT] = {0,};
//vector<Info> schedule;
////���ѣ���ʱ�������м�֦�İ취
//void BFS();
////���ѣ���ʱ
//void DFS();
//int main()
//{
//    //��������
//    cin >>N>>M;
//    for(int i=1;i <= N;i++)
//    {
//        cin >>prices[i];
//    }
//    for(int i=0;i < N-1;i++)
//    {
//        int u,v;
//        ULONG e;
//        cin >>u>>v>>e;
//        path[u].push_back(Info(v,e));
//        path[v].push_back(Info(u,e));
//    }
//    for(int i=0;i < M;i++)
//    {
//        int u,v;
//        cin >>u >>v;
//        schedule.push_back(Info(u,v));
//    }
//
//    BFS();
//    //DFS();
//    return 0;
//}
//
//void DFS()
//{
//    for(int index=0;index < schedule.size();index++)
//    {
//        int src = schedule[index].p1;
//        int des = schedule[index].p2;
//        ULONG total_cost = 0;
//        stack<Node> s;
//        s.push(Node(src,0,0,prices[src]));
//        bool visit[MAX_LIMIT] = {false,};
//        bool arrive = false;
//        while(!arrive && !s.empty())
//        {
//            Node now = s.top();
//            s.pop();
//            visit[now.p1] = true;
//            for(int i=0;i < path[now.p1].size();i++)
//            {
//                //��һ���ڵ�
//                int p1 = path[now.p1][i].p1;
//                //·��
//                ULONG p2 = path[now.p1][i].p2;
//                if(visit[p1]) continue;
//
//                //��ͼ�
//                ULONG price = prices[now.p1]<now.p4?prices[now.p1]:now.p4;
//                //����һ�ڵ����·�̺ͻ���
//                ULONG cost = now.p3+p2*price;
//                //����
//                if(p1 == des)
//                {
//                        total_cost = cost;
//                        arrive = true;
//                        break;
//                }
//                else
//                    s.push(Node(p1,0,cost,price));
//            }
//        }
//        cout <<total_cost <<endl;
//    }
//}
//void BFS()
//{
//    for(int index=0;index < schedule.size();index++)
//    {
//        int src = schedule[index].p1;
//        int des = schedule[index].p2;
//        queue<Node> q;
//        q.push(Node(src,0,0,prices[src]));
//        ULONG len[MAX_LIMIT];
//        memset(len,0xFF,MAX_LIMIT*sizeof(ULONG));
//        len[src] = 0;
//        ULONG cost[MAX_LIMIT] = {0,};
//        cost[src] = 0;
//        while(!q.empty())
//        {
//            Node now = q.front();
//            q.pop();
//            for(int i=0;i < path[now.p1].size();i++)
//            {
//                //��һ�����еı��
//                int p1 = path[now.p1][i].p1;
//                //��һ�����е�·��
//                ULONG p2 = path[now.p1][i].p2;
//                if((p2+now.p2) > len[p1]) continue;
//                //����Ҫ��֦
//                /******/
//                ULONG price = prices[now.p1]<now.p4?prices[now.p1]:now.p4;
//                //���֮ǰ�и��͵ļ۸�
//                ULONG pr = price*p2+now.p3;
//                cost[p1] = pr;
//                ULONG le = now.p2+p2;
//                len[p1] = le;
//                q.push(Node(p1,le,pr,price));
//            }
//        }
//        cout <<cost[des] <<endl;
//    }
//}
