//#include<iostream>
//#include<algorithm>
//#include<queue>
//using namespace std;
//class Action
//{
//public:
//    int key,action,time,related;
//    Action(){}
//    Action(int k,int a,int t)
//    {
//        key = k;action = a;time = t;
//    }
//    bool operator < (const Action& t)const
//    {
//        //还钥匙优先、小编号优先
//        if(time>t.time) return true;
//        if(time<t.time) return false;
//        if(action>t.action) return true;
//        if(action<t.action) return false;
//        if(key>t.key) return true;
//        return false;
//    }
//};
//
//void get_flag(int);
//int find_key(int*,int,int);
//priority_queue<Action> q;
//int main()
//{
//    int N = 0;
//    int K = 0;
//    cin >>N>>K;
//    Action actions[1001];
//    for(int i=1;i<=2*K;i+=2)
//    {
//        int w,s,c;
//        cin >>w>>s>>c;
//        q.push(Action(w,1,s));
//        q.push(Action(w,0,s+c));
//    }
//    get_flag(N);
////    for(int i=1;i<=K;i++)
////    {
////        cout<<info[i].w<<" "<<info[i].s<<" "<<info[i].c<<endl;
////    }
//    return 0;
//}
//
//void get_flag(int N)
//{
//    int keys[1001] = {0,};
//    int flag = 0;
//    for(int i=1;i<=N;i++) {keys[i] = i;}
//    while(!q.empty()){
//            Action a = q.top();
//            if(a.action == 1)
//            {
//                int index = find_key(keys,a.key,N);
//                if(index == 0) continue;
//                else
//                {
//                    keys[index] = 0;q.pop();
//                }
//            }
//            else
//            {
//                int index = find_key(keys,0,N);
//                keys[index] = a.key;
//                q.pop();
//            }
////            cout <<q.size();
//    }
//    for(int i=1;i<=N;i++)
//        cout <<keys[i] <<" ";
//}
//
//int find_key(int* keys,int key,int N)
//{
//    for(int i=1;i<=N;i++)
//    {
//        if(keys[i] == key)
//            return i;
//    }
//    return 0;
//}
