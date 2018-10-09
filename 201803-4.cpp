//#include<iostream>
//#include<mem.h>
//#define MAX 100
//using namespace std;
//int g_iResult[5];
//int g_iChess[4][4];
//int g_iLeft = 9;
//bool isWin(int,int);
//int DFS(int turn);
//int main()
//{
//    int T;
//    cin >>T;
//    for(int i=0;i < T;i++)
//    {
//        for(int j=1;j < 4;j++)
//        {
//            for(int k=1;k < 4;k++)
//            {
//                cin >>g_iChess[j][k];
//                if(g_iChess[j][k] != 0)
//                    g_iLeft--;
//            }
//        }
//        g_iResult[i] = DFS(1);
//        g_iLeft = 9;
//    }
//    for(int i=0;i < T;i++)
//        cout <<g_iResult[i] <<endl;
//    return 0;
//}
//
//int DFS(int turn)
//{
//    //某一方胜利或者平局
//    //平局标志
//    bool tie = true;
//    for(int r=1;r < 4;r++)
//    {
//        for(int c=1;c < 4;c++)
//        {
//            //胜利，返回当前局得分
//            if(g_iChess[r][c] != 0)
//            {
//                if(isWin(r,c))
//                    return (g_iChess[r][c] == 1)?g_iLeft+1:-(g_iLeft+1);
//            }
//            else
//                tie = false;
//        }
//    }
//    //平局
//    if(tie) return 0;
//
//    //这个地方不能设为0，因为对于一个节点来说（加入是轮到1下棋），若果子树的分数全是负的，0就会出问题
//    int score = turn==1?-MAX:MAX;
//    //棋局未结束，寻找空位下棋
//    for(int r=1;r < 4;r++)
//    {
//        for(int c=1;c < 4;c++)
//        {
//            if(g_iChess[r][c] != 0) continue;
//            g_iChess[r][c] = turn;
//            g_iLeft--;
//            //一个子树的评分
//            int child = DFS(3-turn);
//            //需按照子树中的最大评分当作该结点的评分
//            if(turn == 1)
//                score = score>child?score:child;
//            //需按照子树中的最小评分当作该结点的评分
//            if(turn == 2)
//                score = score>child?child:score;
//            g_iLeft++;
//            g_iChess[r][c] = 0;
//        }
//    }
//    //遍历完成，返回最佳评分
//    return score;
//}
////判断第r行第c列的一方是否胜利
//bool isWin(int r,int c)
//{
//    int turn = g_iChess[r][c];
//    int length = -1;
//    //竖
//    for(int i=r;i > 0;i--) if(g_iChess[i][c] == turn) length++;
//    for(int i=r;i < 4;i++) if(g_iChess[i][c] == turn) length++;
//    if(length == 3)
//        return true;
//    length = -1;
//    //横
//    for(int j=c;j > 0;j--) if(g_iChess[r][j] == turn) length++;
//    for(int j=c;j < 4;j++) if(g_iChess[r][j] == turn) length++;
//    if(length == 3)
//        return true;
//    length = -1;
//    //左斜
//    for(int i=r,j=c;i > 0&&j > 0;i--,j--) if(g_iChess[i][j] == turn) length++;
//    for(int i=r,j=c;i < 4&&j < 4;i++,j++) if(g_iChess[i][j] == turn) length++;
//    if(length == 3)
//        return true;
//    length = -1;
//    //右斜
//    for(int i=r,j=c;i > 0&&j < 4;i--,j++) if(g_iChess[i][j] == turn) length++;
//    for(int i=r,j=c;i < 4&&j > 0;i++,j--) if(g_iChess[i][j] == turn) length++;
//    if(length == 3)
//        return true;
//    return false;
//}
