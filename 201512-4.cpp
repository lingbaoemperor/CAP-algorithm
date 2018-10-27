////��ô���Զ���80�֣����д��󣬿����ǲ�������������
////���ݺ��񲻻�����⣬���ᳬʱ
//#include<iostream>
//#include<vector>
//#include<algorithm>
//#include<stack>
//#include<mem.h>
//using namespace std;
//#define MAX_N 10001
//#define MAX_M 100001
//
//int N,M;
////�ڽӱ�
//vector<int> graph[MAX_N];
////�߷��ʱ��
//bool bgraph[MAX_N][MAX_N] = {false,};
////�������
//stack<int> result;
//
////��������
//bool input();
////����
//bool dfs(int);
//
////���鼯���ж��Ƿ���ͨ
//int f[MAX_N] = {0,};
////Ѱ�Ҹ����
//int find(int x){return f[x] == x?x:(f[x] = find(f[x]));}
////�Ƿ�����һ�������
//bool oneSet(int x,int y){return find(x) == find(y);}
////�ϲ��������
//void mer(int x,int y){if(!oneSet(x,y)) f[find(x)] = find(y);  return;}
//
////���鼯�ж��Ƿ���ͨ
//bool isConn();
////�Ƿ���ŷ��ͨ·
//bool isEG();
//
////�����ж��Ƿ���ͨ
//bool isConn_dfs();
//
//int main()
//{
//    if(!input())
//    {
//        cout <<-1;
//        return 0;
//    }
//    memset(bgraph,false,sizeof(bgraph));
//    dfs(1);
//    while(!result.empty())
//    {
//        cout <<result.top() <<" ";
//        result.pop();
//    }
//    return 0;
//}
//bool input()
//{
//    cin >>N >>M;
//    for(int i=1;i <= N;i++)
//        f[i] = i;
//    for(int i=0;i < M;i++)
//    {
//        int s,d;
//        cin >>s >>d;
//        graph[s].push_back(d);
//        graph[d].push_back(s);
//        //���ϲ�
//        mer(s,d);
//    }
//    //������ͨͼֱ�ӷ��أ����鼯�����ѻ������Ķ���
//    if(!isConn_dfs()) return false;
//    //����ͨͼ��û��ŷ��ͨ·������
//    if(!isEG()) return false;
//
//    //������򣬺����ѵ��ĵ�һ���������������
//    for(int i=1;i <= N;i++)
//        sort(graph[i].begin(),graph[i].end());
//    return true;
//}
//bool dfs(int s)
//{
//    //�ڽӱ�
//    for(int i=0; i < graph[s].size();i++)
//    {
//        int next = graph[s][i];
//        //�ڽӾ�������������ʹ��ı�
//        if(!bgraph[s][next])
//        {
//            bgraph[s][next] = true;
//            bgraph[next][s] = true;
//            //�Ѿ��ҵ��˳�
//            dfs(next);
//        }
//    }
//    result.push(s);
//    return false;
//}
//
////�����ж��Ƿ�����ͨ
//bool isConn_dfs()
//{
//    bool visit[MAX_N] = {false,};
//    stack<int> s;
//    s.push(1);
//    visit[1] = true;
//    while(!s.empty())
//    {
//        int now = s.top();
//        s.pop();
//        for(int i=0;i < graph[now].size();i++)
//        {
//            int next = graph[now][i];
//            if(!visit[next])
//            {
//                visit[next] = true;
//                s.push(next);
//            }
//        }
//    }
//    for(int i=1;i <= N;i++)
//    {
//        if(!visit[i]) return false;
//    }
//    return true;
//}
//bool isConn()
//{
//    int x = find(1);
//    for(int i=2;i <= N;i++)
//    {
//        if(find(i) != x)
//            return false;
//    }
//    return true;
//}
//
//bool isEG()
//{
//    int x = 0;
//    //������ŷ��ͨ·��ֱ�ӷ���
//    for(int i=1;i <= N;i++)
//    {
//        if(graph[i].size()%2 != 0)
//            x++;
//    }
//    //Ҫôû�������ȵĵ㣬Ҫô1�������ȵĵ���һ���һ�������ȵĵ�
//    if(!(x == 0 || (x == 2 && graph[1].size()%2 != 0)))
//        return false;
//    return true;
//}
