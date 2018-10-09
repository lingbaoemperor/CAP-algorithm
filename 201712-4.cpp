////��������������Ϊ�ǹ��ѣ���
////Dijkstra
//#include<iostream>
//#include<vector>
//#include<queue>
//#include<mem.h>
//#define ULLONG unsigned long long
//#define MAX_LIMIT 1001
//using namespace std;
//ULLONG N,M;
//
//class Path
//{
//public:
//    ULLONG next;
//    ULLONG length;
//    ULLONG type;
//    Path(ULLONG t,ULLONG n,ULLONG len){type = t;next = n;length = len;}
//};
////·��
//vector<Path> path[MAX_LIMIT];
//ULLONG get_result();
//int main()
//{
//    cin >>N >>M;
//    for(ULLONG i=0;i < M;i++)
//    {
//        ULLONG t,a,b;
//        ULLONG c;
//        cin >>t >>a >>b >>c;
//        path[a].push_back(Path(t,b,c));
//        path[b].push_back(Path(t,a,c));
//    }
//    cout <<get_result();
//    return 0;
//}
//ULLONG get_result()
//{
//    //distance��һ�д����ý��֮ǰ������С·�ܳ���
//    //�ڶ��д����õ����ƣ��
//    ULLONG distance[N+1][3];
//    bool visit[N+1] = {false,};
//
//    //��1��ʼ
//    ULLONG key = 1;
//    memset(distance,0xff,8*3*(N+1));
//    visit[key] = true;
//    distance[1][2] = 0;
//    distance[1][1] = 0;
//
//    //1������ľ��룺1����βΪ1����С·�ܳ� 2����ƣ��
//    for(ULLONG i=0;i < path[key].size();i++)
//    {
//        ULLONG next = path[key][i].next;
//        ULLONG len = path[key][i].length;
//        ULLONG type = path[key][i].type;
//        if(type == 1)
//        {
//            distance[next][2] = len*len;
//            distance[next][1] = len;
//        }
//        else
//        {
//            distance[next][2] = len;
//            distance[next][1] = 0;
//        }
//    }
//    //���¡����е���ʹ��Ժ����
//    while(true)
//    {
//        ULLONG Max = 0xFFFFFFFFFFFFFFFF;
//        key = 0;
//        //Ѱ��ƣ����С�ĵ�
//        for(ULLONG i=1;i <= N;i++)
//        {
//            if(i == key || visit[i]) continue;
//            if(distance[i][2] < Max)
//            {
//                key = i; Max = distance[i][2];
//            }
//        }
//        if(key == 0) break;
//        visit[key] = true;
//        //�Ըõ�Ϊ�м�㣬����1�������ƣ��
//        for(ULLONG i=0;i < path[key].size();i++)
//        {
//            ULLONG next = path[key][i].next;
//            ULLONG len = path[key][i].length;
//            ULLONG type = path[key][i].type;
//            if(visit[next]) continue;
//            ULLONG new_distance = 0;
//            //��·��ֱ�ӼӾ��룬֮ǰ��С·���˶��ˣ�����С·������Ϊ0
//            if(type == 0)
//            {
//                new_distance = len+distance[key][2];
//                if(new_distance < distance[next][2])
//                {
//                    distance[next][2] = new_distance;
//                    distance[next][1] = 0;
//                }
//            }
//            //С·
//            else
//            {
//                //֮ǰ��������С·�����������С·������ƣ���ټ��ϣ��ܵ�ƣ�ͼ�ȥ֮ǰС·��ƣ�ͣ���Ϊ�ظ���
//                if(distance[key][1] != 0)
//                    new_distance = (distance[key][1]+len)*(distance[key][1]+len)+distance[key][2]-distance[key][1]*distance[key][1];
//                //֮ǰû��С·����ֱ�Ӽӵ�ǰС·��ƽ��
//                else
//                    new_distance = len*len+distance[key][2];
//                if(new_distance < distance[next][2])
//                {
//                    distance[next][2] = new_distance;
//                    //С·��������
//                    distance[next][1] = len+distance[key][1];
//                }
//            }
//        }
//    }
//    return distance[N][2];
//}
