//#include<iostream>
//#include<vector>
//#include<queue>
//#include<stack>
//#include<mem.h>
//using namespace std;
//#define MAX_CITY 10001
//
//vector<int> path[MAX_CITY];
//int N,M;
////������¼��ͨ����
//bool visit[MAX_CITY] = {false,};
////��¼�ڵ��Ƿ���ջ��
//bool vins[MAX_CITY] = {false,};
////������¼���
//unsigned long long sum = 0;
////����ʱ���
//int dfn[MAX_CITY] = {0,};
////��������׷�ݵ������ж����е���Сʱ���
//int low[MAX_CITY] = {0,};
//int time = 1;
//stack<int> s;
//
////���ѳ�ʱ
////����Ҳ��ʱ
////tarjan,��Щ�����������㷨̫�࣬��̫�ü�
//void DFS_TarJan(int);
//int main()
//{
//    cin >>N >>M;
//    for(int i=0;i < M;i++)
//    {
//        int s,e;
//        cin >>s >>e;
//        path[s].push_back(e);
//    }
//    //��ÿ������Ϊ��ʼ
//    for(int i=1;i <= N;i++)
//    {
//        if(!visit[i])
//            DFS_TarJan(i);
//    }
//    cout << sum;
//    return 0;
//}
//void DFS_TarJan(int now)
//{
//    dfn[now] = time;
//    low[now] = time;
//    time++;
//    s.push(now);
//    vins[now] = true;
//    visit[now] = true;
//    for(int i=0;i < path[now].size();i++)
//    {
//        int next = path[now][i];
//        //���δ���ʹ�
//        if(!visit[next])
//        {
//            //�����ջ
//            DFS_TarJan(next);
//            //��ջ�Ժ󣬸��µ�ǰ����low
//            low[now] = low[now]<low[next]?low[now]:low[next];
//        }
//        //����������Ľڵ���ջ��
//        else if(vins[next])
//        {
//            //���µ�ǰ����low
//            low[now] = low[now]<dfn[next]?low[now]:dfn[next];
//        }
//    }
//    //�����ǰ��������ͨ�����ĸ������ջ
//    //��¼����ͨ�����еĶ����
//    unsigned long long vt = 0;
//    if(low[now] == dfn[now])
//    {
//        while(true)
//        {
//            vt++;
//            int p = s.top();
//            vins[p] = false;
//            s.pop();
//            if(p == now)
//                break;
//        }
//        sum += vt*(vt-1)/2;
//    }
//}
