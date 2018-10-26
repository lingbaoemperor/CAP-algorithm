////��ַֽ�
////p1,p2,......,pn������Ĳ˼�
////��ôǰһ��Ĳ˼ۣ�x1,x2,.....,xn��Ӧ������
////2p1 <= x1+x2 <= 2p1+1 , 3p2 <= x1+x2+x3 <= 3p2+2 , ...... , 2p2 <= x(n-1)+xn <= 2pn+1.
////x1,x2,......,xn >= 1.
////��s0=0 , s1 = x1 , s2 = x1+x2 , ...... , sn = x1+...+xn.ת��Ϊ>=����ʽ
////s2 - s0 >= 2p1 , s0 - s2 >= -(2p1+1)
////s3 - s0 >= 3p2 , s0 - s3 >= -(3p2+2)
////......
////��s0ΪԴ�㣬���䵽������·����Bellman_Ford��spfa����
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
////���ʱ�·�������Բ�������Ȩ��·
//void Bell(int src)
//{
//    //��ʼ״̬0����Ϊ���·��������һ��ÿ��·����һ���Ǵ���0��
//    //��Ϊ�۸�϶��Ǵ�����
//    int dis[N+1] = {0,};
//    //N+1����㣬����N��
//    for(int i=1;i <= N;i++)
//    {
//        //�������б�
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
//    //�Ƿ�����Ȩ��·���������
//    for(int i=0;i <= N;i++)
//    {
//        for(int j=0;j < path[i].size();j++)
//        {
//            Edge e = path[i][j];
//            if(dis[e.next] < (dis[i]+e.weight))
//            {
//                cout <<"����" <<endl;
//                break;
//            }
//        }
//    }
//    //��ÿ��ļ۸�
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
