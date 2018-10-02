//#include<iostream>
//#include<queue>
//using namespace std;
//#define MAX 99999999
//class Pos
//{
//public:
//    int r;
//    int c;
//    int t;
//    Pos() {}
//    Pos(int row,int col,int time){r=row;c=col;t=time;}
//};
//int N,M,T;
//bool board[9999][100][100]={false,};
////深搜超时
////int get_flag_dfs(int,int,int);
////广搜
//int get_flag_bfs();
//int main()
//{
//    cin >>N>>M>>T;
//    int n = 1,m = 1,t = 0;
//    for(int i=0;i < T;i++)
//    {
//        int r,c,a,b;
//        cin >>r>>c>>a>>b;
//        for(int time=a;time <= b;time++)
//            board[time][r][c] = true;
//    }
//    cout <<get_flag_bfs();
//    return 0;
//}
////广搜
//int get_flag_bfs()
//{
//    queue<Pos> q;
//    Pos first(1,1,0);
//    q.push(first);
//    while(!q.empty())
//    {
//        Pos now = q.front();
//        q.pop();
//        if(now.r < 1 || now.c < 1 || now.r > N || now.c > M)
//            continue;
//        if(now.r == N && now.c == M) return now.t;
//        int r = now.r;
//        int c = now.c;
//        int t = now.t;
//        if(board[t][r][c])
//            continue;
//        board[t][r][c] = true;
//        q.push(Pos(r,c+1,t+1));
//        q.push(Pos(r+1,c,t+1));
//        q.push(Pos(r,c-1,t+1));
//        q.push(Pos(r-1,c,t+1));
//    }
//    return 0;
//}
////深搜超时
////int get_flag_dfs(int n,int m,int t)
////{
////    //深搜结束，返回终点的步数
////    if(n == N && m == M)
////        return t;
////    //从当前节点，右方和下方搜索
////    int r1 = MAX,r2 = MAX;
////    if(m < M && !board[t+1][n][m+1])
////        r1 = get_flag_dfs(n,m+1,t+1);
////    if(n < N && !board[t+1][n+1][m])
////        r2 = get_flag_dfs(n+1,m,t+1);
////    if(!board[t+1][n][m+1] || !board[t+1][n+1][m])
////        return (r1<r2?r1:r2);
////    //从当前节点左边和上边
////    if(m > 1 && !board[t+1][n][m-1])
////        r1 = get_flag_dfs(n,m-1,t+1);
////    if(n > 1 && !board[t+1][n-1][m])
////        r2 = get_flag_dfs(n-1,m,t+1);
////    return (r1<r2?r1:r2);
////}
