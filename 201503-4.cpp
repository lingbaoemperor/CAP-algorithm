////先找到最深的叶子节点，在从该结点往回搜索，记录最大长度
//#include<iostream>
//#include<vector>
//#include<queue>
//#include<mem.h>
//using namespace std;
////交换机和电脑同等对待，题目说n和m最大都是10000，那么加起来应该是100000001，这么大肯定卡死了
////但是不知道为什么小一点也能通过
//#define MAX_NODE 100001
//
////交换机和电脑数量
//int N,M;
//
//class Node
//{
//public:
//    //编号和设备类型
//    int number;
//    int depth;
//    Node(){}
//    Node(int num,int dp)
//    {
//        number = num;
//        depth = dp;
//    }
//};
////树结构
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
//    //最深的结点深度和编号
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
//        //访问标记
//        visit[now] = true;
//        //更新最深结点
//        if(depth < dp)
//        {
//            depth = dp;
//            md = now;
//        }
//        //下面的结点入队
//        for(int i=0;i < tree[now].size();i++)
//        {
//            int next = tree[now][i];
//            q.push(Node(next,dp+1));
//        }
//    }
//    //以最深结点为起始点，搜索
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
//    //交换机
//    for(int i=2;i <= N;i++)
//    {
//        int father;
//        cin >>father;
//        tree[father].push_back(i);
//        tree[i].push_back(father);
//    }
//    //电脑
//    for(int i=N+1;i <= N+M;i++)
//    {
//        int father;
//        cin >>father;
//        tree[father].push_back(i);
//        tree[i].push_back(father);
//    }
//}
