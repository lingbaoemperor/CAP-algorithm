////���˼·���£�����һ�������˵��
////����һ��Ҷ�ڵ㣬�Ը�Ҷ�ڵ�Ϊ�����Ӹ���ʼ��Ѱ�����ѣ��Ը����Ϊ��ʼ��������㳤�ȵ�·�����������ۼ�·��Ȩֵ
////������ɺ�ɾ���ý�㣬�ٴ�Ѱ��һ��Ҷ��㵱�����ڵ㣬��˷���ֱ�����ڽ����С����С·���ĳ���
////���ܺܺ�ʱ���������ĸ��õķ���
////20�֣���ʱ�������Ż���������ˣ������˺þ�
//#include<iostream>
//#include<vector>
//#include<queue>
//#include<stack>
//#include<mem.h>
//using namespace std;
//#define ULLONG unsigned long long
//#define Q 1000000007
//#define MAX_LIMIT 100000
////10����
//int g_iT = 10;
////�������������������������ޡ�����
//int g_in,g_im,g_iL,g_iR;
////10����,һ��������ʮ������������һ����
//ULLONG g_ullResult[MAX_LIMIT*10];
////��ǰ������¼����������
//int g_iNow = 0;
////�����
//vector<int> g_vsLine[MAX_LIMIT+1];
////˫���
//vector<int> g_vdLine[MAX_LIMIT+1];
////���Ȩֵ
//ULLONG g_ullWeight[MAX_LIMIT+1] = {0,};
////��ʼ���
//int g_iRoot = -1;
////�ù���Ҷ�ӽ��ı��
//bool g_bVisit[MAX_LIMIT+1] = {false,};
////��Ϊһ�������Ҫ����ɾ����㣬���¹���������ʱ��ţ������˫���
//vector<int> g_vssLine[MAX_LIMIT+1];
//vector<int> g_vsdLine[MAX_LIMIT+1];
////��ӽ����Ϣ
//class Node
//{
//public:
//    //���
//    int node;
//    //��ǰ����·������
//    int length;
//    //�ۻ�Ȩֵ
//    ULLONG weight;
//    Node(int n,int l,int w){ node=n; length=l; weight=w;}
//};
//
//void get_result();
////��һ���������Ľ��
//void resolve(int,int,ULLONG);
////u,v֮�����Ȩֵd
//bool addWeight(int,int,ULLONG,bool*);
////���¹���������һ��Ҷ�ڵ�Ϊ��
//void restruct();
////���һ����ĳ��Ҷ�ڵ�Ϊ����������Ѱ��������ɾ���ý��
//void remove_root();
////һ�������ɣ�ɾ�������Ϣ��memset�е�����
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
////        cout <<"��" <<i+1 <<"����" <<endl;
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
//    //ȡ��
//    for(int i=1;i <= g_in;i++)
//        g_ullWeight[i] = g_ullWeight[i]<Q?g_ullWeight[i]:g_ullWeight[i]%Q;
//
//    //���u->v֮��Ľ��Ȩֵ
////    for(int i=1;i <= g_in;i++)
////        cout <<g_ullWeight[i] <<" ";
////    cout <<endl;
//
//    //�����������һ������Ķ�����͵Ľ��
//    ULLONG result = 0;
//    //ʣ���ܽ����С��L�˳�
//    int left = g_in;
//    while(left >= g_iL)
//    {
//    left--;
//    restruct();
//    //��������1��㣨��������ʼ���ѣ�·��ʹ�ôӸ����µĵ���·��
//    //����������
//    queue<Node> q;
//    q.push(Node(g_iRoot,1,g_ullWeight[g_iRoot]));
//    memset(visit,false,MAX_LIMIT+1);
//    visit[g_iRoot] = true;
//    //ÿ��һ�����������Ľ�㣺���㲢�����侭������l���ۻ�Ȩֵw
//    while(!q.empty())
//    {
//        int node = q.front().node;
//        int length = q.front().length;
//        ULLONG weight = q.front().weight;
//        q.pop();
//        //���ĳ�������Ҷ�ӽ�㣺1�����Ȳ�����ɾ�� 2�����ȹ������ӣ�����ý���ۻ�Ȩֵ
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
//        //����ĳ������ǲ���Ҷ�ӽ��
//        //�������ӽ�㣺
//        else
//        {
//            //��ǰ��㳤���ڷ�Χ��
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
//    //ɾ�����ڵ�
//    remove_root();
//    }
//
//    g_ullResult[g_iNow] = result%Q;
//    g_iNow ++;
////    cout <<result <<endl;
//
//}
////���ѣ�u,v֮�������Ȩֵd
//bool addWeight(int u,int v,ULLONG d,bool* visit)
//{
//    //������d
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
//        //�ý��û�е���Ŀ�Ľ�㣬��ȥ֮ǰ���ϵ�d
//        if(addWeight(u1,v,d,visit) == false)
//            g_ullWeight[u1] -= d;
//        else
//            arrive = true;
//    }
//    //�ý����·���ߣ���ȥ֮ǰ���ϵ�d
//    return arrive;
//}
//
//void get_result()
//{
//    cin >>g_in >>g_im >>g_iL >>g_iR;
//    //n��Ȩֵ
//    for(int i=1;i <= g_in;i++)
//        cin >>g_ullWeight[i];
//    //n-1����
//    for(int i=1;i <= g_in-1;i++)
//    {
//        int src;
//        cin >>src;
//        g_vsLine[src].push_back(i+1);
//        g_vdLine[src].push_back(i+1);
//        g_vdLine[i+1].push_back(src);
//    }
//    //m���������
//    for(int j=0;j < g_im;j++)
//    {
//        int u,v;
//        ULLONG d;
//        cin >>u >>v >>d;
//        //�߽���Ϣ����
//        for(int i=1;i <= g_in;i++)
//        {
//            g_vssLine[i] = g_vsLine[i];
//            g_vsdLine[i] = g_vdLine[i];
//        }
//        resolve(u,v,d);
//    }
//}
////���ѱ��������ҵ������С��Ҷ�ڵ㣬�ع���
//void restruct()
//{
//    //Ѱ��Ҷ���
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
//        //Ҷ�ڵ�
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
//    //�ع���,��ǳҶ�ڵ�Ϊ��
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
//    //����ع�����֦
////    for(int i=1;i <= g_in;i++)
////    {
////        cout <<i <<"->" <<" ";
////        for(int j=0;j < g_vssLine[i].size();j++)
////            cout <<g_vssLine[i][j] <<" ";
////        cout <<endl;
////    }
//}
////ɾ��һ�����
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
