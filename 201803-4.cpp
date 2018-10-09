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
//    //ĳһ��ʤ������ƽ��
//    //ƽ�ֱ�־
//    bool tie = true;
//    for(int r=1;r < 4;r++)
//    {
//        for(int c=1;c < 4;c++)
//        {
//            //ʤ�������ص�ǰ�ֵ÷�
//            if(g_iChess[r][c] != 0)
//            {
//                if(isWin(r,c))
//                    return (g_iChess[r][c] == 1)?g_iLeft+1:-(g_iLeft+1);
//            }
//            else
//                tie = false;
//        }
//    }
//    //ƽ��
//    if(tie) return 0;
//
//    //����ط�������Ϊ0����Ϊ����һ���ڵ���˵���������ֵ�1���壩�����������ķ���ȫ�Ǹ��ģ�0�ͻ������
//    int score = turn==1?-MAX:MAX;
//    //���δ������Ѱ�ҿ�λ����
//    for(int r=1;r < 4;r++)
//    {
//        for(int c=1;c < 4;c++)
//        {
//            if(g_iChess[r][c] != 0) continue;
//            g_iChess[r][c] = turn;
//            g_iLeft--;
//            //һ������������
//            int child = DFS(3-turn);
//            //�谴�������е�������ֵ����ý�������
//            if(turn == 1)
//                score = score>child?score:child;
//            //�谴�������е���С���ֵ����ý�������
//            if(turn == 2)
//                score = score>child?child:score;
//            g_iLeft++;
//            g_iChess[r][c] = 0;
//        }
//    }
//    //������ɣ������������
//    return score;
//}
////�жϵ�r�е�c�е�һ���Ƿ�ʤ��
//bool isWin(int r,int c)
//{
//    int turn = g_iChess[r][c];
//    int length = -1;
//    //��
//    for(int i=r;i > 0;i--) if(g_iChess[i][c] == turn) length++;
//    for(int i=r;i < 4;i++) if(g_iChess[i][c] == turn) length++;
//    if(length == 3)
//        return true;
//    length = -1;
//    //��
//    for(int j=c;j > 0;j--) if(g_iChess[r][j] == turn) length++;
//    for(int j=c;j < 4;j++) if(g_iChess[r][j] == turn) length++;
//    if(length == 3)
//        return true;
//    length = -1;
//    //��б
//    for(int i=r,j=c;i > 0&&j > 0;i--,j--) if(g_iChess[i][j] == turn) length++;
//    for(int i=r,j=c;i < 4&&j < 4;i++,j++) if(g_iChess[i][j] == turn) length++;
//    if(length == 3)
//        return true;
//    length = -1;
//    //��б
//    for(int i=r,j=c;i > 0&&j < 4;i--,j++) if(g_iChess[i][j] == turn) length++;
//    for(int i=r,j=c;i < 4&&j > 0;i++,j--) if(g_iChess[i][j] == turn) length++;
//    if(length == 3)
//        return true;
//    return false;
//}
