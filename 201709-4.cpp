//#include<iostream>
//#include<mem.h>
//#include<queue>
//#include<vector>
//using namespace std;
//#define MAX 1001
//int N,M;
////这里如果用一个visit数组记录访问过的节点会出错，深坑，不知道为什么
////??????????????
//bool visit1[MAX] = {false,};
//bool visit2[MAX] = {false,};
//
////深搜依旧超时
//bool path[MAX][MAX]={false,};
//void DFS_NEXT(int);
//void DFS_PRE(int);
//void DFS();
//
////拓补
//void topology();
//queue<int> q;
//vector<int> in[MAX];
//vector<int> out[MAX];
//int main()
//{
//    cin >>N >>M;
//    for(int i=0;i < M;i++)
//    {
//        int x,y;
//        cin >>x >>y;
//        in[y].push_back(x);
//        out[x].push_back(y);
//    }
//    topology();
////    for(int i=0;i < M;i++)
////    {
////        int x,y;
////        cin >>x >>y;
////        path[x][y] = true;
////    }
////    DFS();
//    return 0;
//}
//void topology()
//{
//    int result = 0;
//    int c = 0;
//    for(int i=1;i <= N;i++)
//    {
//        memset(visit1,0,MAX);
//        memset(visit2,0,MAX);
//        visit1[i] = true;
//        q.push(i);
//        while(!q.empty())
//        {
//            int now = q.front();
//            q.pop();
//            for(int j=0;j < out[now].size();j++)
//            {
//                int a = out[now][j];
//                if(!visit1[out[now][j]])
//                {
//                    q.push(out[now][j]);
//                    visit1[out[now][j]] = true;
//                }
//            }
//        }
//        q.push(i);
//        visit2[i] = true;
//        while(!q.empty())
//        {
//            int now = q.front();
//            q.pop();
//            for(int j=0;j < in[now].size();j++)
//            {
//                if(!visit2[in[now][j]])
//                {
//                    q.push(in[now][j]);
//                    visit2[in[now][j]] = true;
//                }
//            }
//        }
//        c = 0;
//        for(int i=1;i <= N;i++)
//            if(visit1[i] || visit2[i])
//                c++;
//        if(c == N)
//            result++;
//    }
//    cout <<result;
//}
//void DFS()
//{
//    int result = 0;
//    for(int i =1;i <= N;i++)
//    {
//        memset(visit1,0,MAX);
//        visit1[i] = true;
//        DFS_NEXT(i);
//        memset(visit2,0,MAX);
//        visit2[i] = true;
//        DFS_PRE(i);
//        int c = 0;
//        for(int j=1;j <= N;j++)
//            if(visit1[j] || visit2[j])
//                c++;
//        if(c == N)
//            result++;
//    }
//    cout <<result;
//}
//void DFS_NEXT(int start)
//{
//    for(int i=1;i <= N;i++)
//    {
//        if(i != start && !visit1[i] && path[start][i])
//        {
//            visit1[i] = true;
//            DFS_NEXT(i);
//        }
//    }
//}
//void DFS_PRE(int start)
//{
//    for(int i=1;i <= N;i++)
//    {
//        if(i != start && !visit2[i] && path[i][start])
//        {
//            visit2[i] = true;
//            DFS_PRE(i);
//        }
//    }
//}
