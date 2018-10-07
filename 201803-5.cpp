////这个思路如下，对于一组操作来说：
////先找一个叶节点，以该叶节点为根，从根开始搜寻（广搜）以根结点为起始点而且满足长度的路径，过程中累加路径权值
////搜索完成后删除该结点，再次寻找一个叶结点当作根节点，如此反复直至生于结点数小于最小路径的长度
////可能很耗时，有其它的更好的方法
////20分，超时，可以优化，不想搞了，折腾了好久
//#include<iostream>
//#include<vector>
//#include<queue>
//#include<stack>
//#include<mem.h>
//using namespace std;
//#define ULLONG unsigned long long
//#define Q 1000000007
//#define MAX_LIMIT 100000
////10棵树
//int g_iT = 10;
////结点数、操作数、结点数量下限、上限
//int g_in,g_im,g_iL,g_iR;
////10棵树,一颗树最多多十万组操作，最大一百万
//ULLONG g_ullResult[MAX_LIMIT*10];
////当前组数记录，保存结果用
//int g_iNow = 0;
////单向边
//vector<int> g_vsLine[MAX_LIMIT+1];
////双向边
//vector<int> g_vdLine[MAX_LIMIT+1];
////结点权值
//ULLONG g_ullWeight[MAX_LIMIT+1] = {0,};
////开始结点
//int g_iRoot = -1;
////用过的叶子结点的标记
//bool g_bVisit[MAX_LIMIT+1] = {false,};
////因为一组操作中要不断删除结点，重新构造树，临时存放，单向边双向边
//vector<int> g_vssLine[MAX_LIMIT+1];
//vector<int> g_vsdLine[MAX_LIMIT+1];
////入队结点信息
//class Node
//{
//public:
//    //结点
//    int node;
//    //当前经过路径长度
//    int length;
//    //累积权值
//    ULLONG weight;
//    Node(int n,int l,int w){ node=n; length=l; weight=w;}
//};
//
//void get_result();
////求一组组操作后的结果
//void resolve(int,int,ULLONG);
////u,v之间加上权值d
//bool addWeight(int,int,ULLONG,bool*);
////重新构造树，以一个叶节点为根
//void restruct();
////完成一次以某个叶节点为根的树的搜寻，从树中删除该结点
//void remove_root();
////一组操作完成，删除相关信息，memset有点问题
//void clear_data()
//{
//    for(int i=1;i <= g_in;i++)
//    {
//        g_vdLine[i].clear();
//        g_vsLine[i].clear();
//        g_vssLine[i].clear();
//        g_vsdLine[i].clear();
//    }
//}
//int main()
//{
//    cin >>g_iT;
//    for(int i=0;i < g_iT;i++)
//    {
////        cout <<"第" <<i+1 <<"棵树" <<endl;
//        get_result();
//        clear_data();
//    }
//    for(int i=0;i < g_iNow;i++)
//        cout <<g_ullResult[i] <<endl;
//    return 0;
//}
//
//void resolve(int u,int v,ULLONG d)
//{
//    bool visit[MAX_LIMIT+1] = {false,};
//    visit[u] = true;
//    addWeight(u,v,d,visit);
//    //取余
//    for(int i=1;i <= g_in;i++)
//        g_ullWeight[i] = g_ullWeight[i]<Q?g_ullWeight[i]:g_ullWeight[i]%Q;
//
//    //输出u->v之间的结点权值
////    for(int i=1;i <= g_in;i++)
////        cout <<g_ullWeight[i] <<" ";
////    cout <<endl;
//
//    //这个用来保存一组操作的二次求和的结果
//    ULLONG result = 0;
//    //剩下总结点数小于L退出
//    int left = g_in;
//    while(left >= g_iL)
//    {
//    left--;
//    restruct();
//    //接下来从1结点（树根）开始广搜，路径使用从根向下的单项路径
//    //根结点先入队
//    queue<Node> q;
//    q.push(Node(g_iRoot,1,g_ullWeight[g_iRoot]));
//    memset(visit,false,MAX_LIMIT+1);
//    visit[g_iRoot] = true;
//    //每到一个满足条件的结点：计算并保存其经过长度l和累积权值w
//    while(!q.empty())
//    {
//        int node = q.front().node;
//        int length = q.front().length;
//        ULLONG weight = q.front().weight;
//        q.pop();
//        //如果某个结点是叶子结点：1、长度不够，删掉 2、长度够，出队，保存该结点累积权值
//        if(g_vssLine[node].size() == 0)
//        {
//            if(length < g_iL)
//                continue;
//            if(length >= g_iL && length <= g_iR)
//            {
//                result += weight;
//                result = ((result<Q)?result:result%Q);
////                cout <<node <<" " <<length <<" " <<weight <<endl;
//            }
//        }
//        //若果某个结点是不是叶子结点
//        //遍历其子结点：
//        else
//        {
//            //当前结点长度在范围内
//            if(length > g_iR) continue;
//            if(length ==  g_iR)
//            {
//                result += weight;
//                result = ((result<Q)?result:result%Q);
//                continue;
//            }
//            if(length >= g_iL && length < g_iR)
//            {
//                result += weight;
//                result = ((result<Q)?result:result%Q);
////                cout <<node <<" " <<length <<" " <<weight <<endl;
//            }
//            for(int i=0;i < g_vssLine[node].size();i++)
//            {
//                int next = g_vssLine[node][i];
//                if(length < g_iR)
//                {
//                    ULLONG wei = weight+g_ullWeight[next];
//                    wei = wei<Q?wei:wei%Q;
//                    q.push(Node(next,length+1,wei));
//                }
//            }
//        }
//    }
////    cout <<result <<endl;
//    //删除根节点
//    remove_root();
//    }
//
//    g_ullResult[g_iNow] = result%Q;
//    g_iNow ++;
////    cout <<result <<endl;
//
//}
////深搜，u,v之间结点加上权值d
//bool addWeight(int u,int v,ULLONG d,bool* visit)
//{
//    //结点加上d
//    g_ullWeight[u] += d;
//    bool arrive = false;
//    for(int i=0;i < g_vdLine[u].size();i++)
//    {
//        int u1 = g_vdLine[u][i];
//        if(visit[u1]) continue;
//        visit[u1] = true;
//        if(u1 == v)
//        {
//            g_ullWeight[v] += d;
//            return true;
//        }
//        //该结点没有到达目的结点，减去之前加上的d
//        if(addWeight(u1,v,d,visit) == false)
//            g_ullWeight[u1] -= d;
//        else
//            arrive = true;
//    }
//    //该结点无路可走，减去之前加上的d
//    return arrive;
//}
//
//void get_result()
//{
//    cin >>g_in >>g_im >>g_iL >>g_iR;
//    //n个权值
//    for(int i=1;i <= g_in;i++)
//        cin >>g_ullWeight[i];
//    //n-1条边
//    for(int i=1;i <= g_in-1;i++)
//    {
//        int src;
//        cin >>src;
//        g_vsLine[src].push_back(i+1);
//        g_vdLine[src].push_back(i+1);
//        g_vdLine[i+1].push_back(src);
//    }
//    //m组操作操作
//    for(int j=0;j < g_im;j++)
//    {
//        int u,v;
//        ULLONG d;
//        cin >>u >>v >>d;
//        //边界信息拷贝
//        for(int i=1;i <= g_in;i++)
//        {
//            g_vssLine[i] = g_vsLine[i];
//            g_vsdLine[i] = g_vdLine[i];
//        }
//        resolve(u,v,d);
//    }
//}
////深搜遍历树，找到深度最小的叶节点，重构树
//void restruct()
//{
//    //寻找叶结点
//    int root = -1;
//    stack<int> s;
//    for(int i=1;i <= g_in;i++)
//        if(!g_vsdLine[i].empty())
//        {
//            s.push(g_vsdLine[i][0]);
//            break;
//        }
//    while(!s.empty())
//    {
//        int now = s.top();
//        s.pop();
//        //叶节点
//        if(g_vssLine[now].empty())
//        {
//            root = now;
//            break;
//        }
//        for(int i=0;i < g_vssLine[now].size();i++)
//        {
//            int next = g_vssLine[now][i];
//            s.push(next);
//        }
//    }
//
//    g_iRoot = root;
//
//    //重构树,最浅叶节点为根
//    for(int i=1;i <= g_in;i++)
//        g_vssLine[i].clear();
//    queue<int> q;
//    q.push(root);
//    bool visit[g_in+1] = {false,};
//    visit[root] = true;
//    while(!q.empty())
//    {
//        int now = q.front();
//        q.pop();
//        for(int i=0;i < g_vsdLine[now].size();i++)
//        {
//            int next = g_vsdLine[now][i];
//            if(visit[next]) continue;
//            g_vssLine[now].push_back(next);
//            q.push(next);
//            visit[next] = true;
//        }
//    }
//    //输出重构的数枝
////    for(int i=1;i <= g_in;i++)
////    {
////        cout <<i <<"->" <<" ";
////        for(int j=0;j < g_vssLine[i].size();j++)
////            cout <<g_vssLine[i][j] <<" ";
////        cout <<endl;
////    }
//}
////删掉一个结点
//void remove_root()
//{
//    g_vssLine[g_iRoot].clear();
//    g_vsdLine[g_iRoot].clear();
//    for(int i=1;i <= g_in;i++)
//        for(int j=0;j < g_vsdLine[i].size();j++)
//        {
//            if(g_vsdLine[i][j] == g_iRoot)
//                g_vsdLine[i].erase(g_vsdLine[i].begin()+j,g_vsdLine[i].begin()+j+1);
//        }
//}
