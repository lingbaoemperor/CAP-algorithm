////注意一点，后画的线段可能覆盖前面画的内容，好像只会覆盖符号，不覆盖线段
//#include<iostream>
//#include<mem.h>
//using namespace std;
//#define MAX_LOC 100
//
//char canvas[MAX_LOC][MAX_LOC];
//bool visit[MAX_LOC][MAX_LOC];
//int M,N,Q;
//
//void init();
//void draw();
//void output();
//void DFS(int,int,char);
//int main()
//{
//    init();
//    draw();
//    output();
//    return 0;
//}
//void draw()
//{
//    for(int q=0;q < Q;q++)
//    {
//        int op;
//        int x1,y1,x2,y2;
//        int x,y;
//        char c;
//        cin >>op;
//        if(op == 1)
//        {
//            cin >>x >>y >>c;
//            memset(visit,false,MAX_LOC*MAX_LOC);
//            DFS(N-y-1,x,c);
//        }
//        else
//        {
//            cin >>x1 >>y1 >>x2 >>y2;
//            if(x1 == x2)
//            {
//                y1 = N-y1-1;
//                y2 = N-y2-1;
//                int s = y1<y2?y1:y2;
//                int e = y1<y2?y2:y1;
//                //填充竖线
//                for(int j=s;j <= e;j++)
//                {
//                    if(canvas[j][x1] == '-')
//                        canvas[j][x1] = '+';
//                    else if(canvas[j][x1] != '+')
//                        canvas[j][x1] = '|';
//                }
//            }
//            else
//            {
//                y1 = N-y1-1;
//                y2 = N-y2-1;
//                int s = x1<x2?x1:x2;
//                int e = x1<x2?x2:x1;
//                for(int j=s;j <= e;j++)
//                {
//                    if(canvas[y1][j] == '|')
//                        canvas[y1][j] = '+';
//                    else if(canvas[y1][j] != '+')
//                        canvas[y1][j] = '-';
//                }
//            }
//        }
//    }
//}
//void DFS(int x,int y,char c)
//{
//    if(x >= 0 && y >= 0 && x < N && y < M && canvas[x][y] != '-' && canvas[x][y] != '|' && canvas[x][y] != '+')
//    {
//        canvas[x][y] = c;
//        visit[x][y] = true;
//        if(!visit[x-1][y])
//            DFS(x-1,y,c);
//        if(!visit[x+1][y])
//            DFS(x+1,y,c);
//        if(!visit[x][y-1])
//            DFS(x,y-1,c);
//        if(!visit[x][y+1])
//            DFS(x,y+1,c);
//    }
//}
//
//void init()
//{
//    cin >>M >>N >>Q;
//    for(int x=0;x < N;x++)
//    {
//        for(int y=M-1;y >= 0;y--)
//            canvas[x][y] = '.';
//    }
//}
//
//void output()
//{
//    for(int i=0;i < N;i++)
//    {
//        for(int j=0;j < M;j++)
//            cout <<canvas[i][j];
//        cout <<endl;
//    }
//}
