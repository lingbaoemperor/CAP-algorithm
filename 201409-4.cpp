////��Ҫ���Թ˿�Ϊ���ѵ���ʼ�㣬�ᳬʱ����Ϊÿ���˿Ͷ�Ҫ����һ��
////�Բ���Ϊ��ʼ�㣬�����˿;ͱ�Ǹù˿��Ѿ��õ���������������Ҫ��
//#include<iostream>
//#include<queue>
//#define MAX_N 1001
//#define ULLONG unsigned long long
//using namespace std;
//
//int N,M,K,D;
////��ͼ�ϵĵ����Ϣ
//class Node
//{
//public:
//    //�Ƿ����ߴ˵�
//    bool prohibit;
//    //�Ƿ��ǿͻ�
//    bool client;
//    //�Ƿ��ǲ���
//    bool rest;
//    //����ǿͻ����ÿͻ���Ҫ�Ļ�������
//    int count;
//    Node(){prohibit = false;client = false;rest = false;count = 0;}
//    Node(bool a,bool b,bool c,int d)
//    {
//        prohibit = a;
//        client = b;
//        rest = c;
//        count = d;
//    }
//};
////�þ���洢
//Node graphic[MAX_N][MAX_N];
//
////����λ������
//class Start
//{
//public:
//    int x;
//    int y;
//    Start(int a,int b){x = a;y = b;}
//};
//vector<Start> vr;
//
////����ʱ�Ľ����Ϣ
//class Pos
//{
//public:
//    //��ǰλ��
//    int x;
//    int y;
//    //��ǰ���ߵĳ���
//    int length;
//    Pos(){};
//    Pos(int a,int b,int c)
//    {
//        x = a;
//        y = b;
//        length = c;
//    }
//};
//
////�����Ŀͻ��������ϲ��ظ�λ���Ժ��
//int client = 0;
//
//ULLONG BFS();
//
//int main()
//{
//    cin >>N >>M >>K >>D;
//    //���ܲ�����Ϣ
//    for(int i=0;i < M;i++)
//    {
//        int x,y;
//        cin >>x >>y;
//        graphic[x][y].rest = true;
//        vr.push_back(Start(x,y));
//    }
//    //���ܿͻ���Ϣ�����ϲ�ͬһ��λ�õĿͻ�
//    for(int i=0;i < K;i++)
//    {
//        int x,y,z;
//        cin >>x >>y >>z;
//        if(!graphic[x][y].client) client++;
//        graphic[x][y].count += z;
//        graphic[x][y].client = true;
//    }
//    //���ܲ����ߵ�λ��
//    for(int i=0;i < D;i++)
//    {
//        int x,y;
//        cin >>x >>y;
//        graphic[x][y].prohibit = true;
//    }
//    cout <<BFS();
//    return 0;
//}
//
//ULLONG BFS()
//{
//    ULLONG sum = 0;
//    bool visit[MAX_N][MAX_N] = {false,};
//    queue<Pos> q;
//    //���в������
//    for(int i=0;i < M;i++)
//    {
//        int x = vr[i].x;
//        int y = vr[i].y;
//        q.push(Pos(x,y,0));
//    }
//    //������пͻ����ӵ�����Ҳ�˳�
//    while(!q.empty() && client)
//    {
//        Pos now = q.front();
//        q.pop();
//        //���ʹ��Ľ�㲻�ٷ���
//        if(visit[now.x][now.y]) continue;
//        visit[now.x][now.y] = true;
//
//        //��Ϊ���ȵ���ĳ���ͻ����Ͳ���һ���ǴӾ�ÿͻ��������������
//        //��ǰ����ǿͻ���������Ͳͣ��ͻ�������1
//        if(graphic[now.x][now.y].client)
//        {
//            client--;
//            sum += now.length*graphic[now.x][now.y].count;
//            graphic[now.x][now.y].client = false;
//        }
//        //��������λ�����
//        if(now.x > 1 && !graphic[now.x-1][now.y].prohibit)
//            q.push(Pos(now.x-1,now.y,now.length+1));
//        if(now.x < N && !graphic[now.x+1][now.y].prohibit)
//            q.push(Pos(now.x+1,now.y,now.length+1));
//        if(now.y > 1 && !graphic[now.x][now.y-1].prohibit)
//            q.push(Pos(now.x,now.y-1,now.length+1));
//        if(now.y < N && !graphic[now.x][now.y+1].prohibit)
//            q.push(Pos(now.x,now.y+1,now.length+1));
//    }
//    return sum;
//}
