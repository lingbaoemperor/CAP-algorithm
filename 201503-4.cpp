////���ҵ������Ҷ�ӽڵ㣬�ڴӸý��������������¼��󳤶�
//#include<iostream>
//#include<vector>
//#include<queue>
//#include<mem.h>
//using namespace std;
////�������͵���ͬ�ȶԴ�����Ŀ˵n��m�����10000����ô������Ӧ����100000001����ô��϶�������
////���ǲ�֪��ΪʲôСһ��Ҳ��ͨ��
//#define MAX_NODE 100001
//
////�������͵�������
//int N,M;
//
//class Node
//{
//public:
//    //��ź��豸����
//    int number;
//    int depth;
//    Node(){}
//    Node(int num,int dp)
//    {
//        number = num;
//        depth = dp;
//    }
//};
////���ṹ
////vector<Device> tree[];
//vector<int> tree[MAX_NODE];
//void init();
//void BFS_TWICE(int);
//
//int main()
//{
//    init();
//    BFS_TWICE(1);
//    return 0;
//}
//
//void BFS_TWICE(int root)
//{
//    //����Ľ����Ⱥͱ��
//    int depth = 0;
//    int md = 0;
//
//    queue<Node> q;
//    bool visit[MAX_NODE] = {false,};
//    q.push(Node(1,0));
//    while(!q.empty())
//    {
//        Node nd = q.front();
//        q.pop();
//        int now = nd.number;
//        int dp = nd.depth;
//        if(visit[now]) continue;
//        //���ʱ��
//        visit[now] = true;
//        //����������
//        if(depth < dp)
//        {
//            depth = dp;
//            md = now;
//        }
//        //����Ľ�����
//        for(int i=0;i < tree[now].size();i++)
//        {
//            int next = tree[now][i];
//            q.push(Node(next,dp+1));
//        }
//    }
//    //��������Ϊ��ʼ�㣬����
//    q.push(Node(md,0));
//    depth = 0;
//    memset(visit,false,MAX_NODE);
//    while(!q.empty())
//    {
//        Node nd = q.front();
//        q.pop();
//        int now = nd.number;
//        int dp = nd.depth;
//        if(visit[now]) continue;
//        visit[now] = true;
//        if(dp > depth) depth = dp;
//        for(int i=0;i < tree[now].size();i++)
//        {
//            int next = tree[now][i];
//            q.push(Node(next,dp+1));
//        }
//    }
//    cout <<depth;
//}
//
//void init()
//{
//    cin >>N >>M;
//    //������
//    for(int i=2;i <= N;i++)
//    {
//        int father;
//        cin >>father;
//        tree[father].push_back(i);
//        tree[i].push_back(father);
//    }
//    //����
//    for(int i=N+1;i <= N+M;i++)
//    {
//        int father;
//        cin >>father;
//        tree[father].push_back(i);
//        tree[i].push_back(father);
//    }
//}
