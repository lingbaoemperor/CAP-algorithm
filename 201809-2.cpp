////想不到有什么好办法，只有用笨方法了
//#include<iostream>
//#include<queue>
//using namespace std;
//int N;
//
////时间段信息，开始和结束时刻
//class Time
//{
//public:
//    int s,e;
//    Time(){}
//    Time(int a,int b)
//    {
//        s = a;
//        e = b;
//    }
//};
////两个人的输入信息
//queue<Time> q1;
//queue<Time> q2;
////输出结果
//void output();
//int main()
//{
//    //接受输入
//    cin >>N;
//    for(int i=0;i < N;i++)
//    {
//        int s,e;
//        cin >>s >>e;
//        q1.push(Time(s,e));
//    }
//    for(int i=0;i < N;i++)
//    {
//        int s,e;
//        cin >>s >>e;
//        q2.push(Time(s,e));
//    }
//    //输出结果
//    output();
//    return 0;
//}
//
//void output()
//{
//    //最终结果记录
//    int sum = 0;
//    Time t1 = q1.front();
//    Time t2 = q2.front();
//    //记录当前遍历中，哪一个人的结束时间最晚
//    int now = t1.e > t2.e?1:2;
//    q1.pop();
//    q2.pop();
//    while(true)
//    {
//        //这里是第一个人的某个时间段的结束时间比第二个人晚
//        //以第一个人某个时间段的结束时间为基准
//        if(now == 1)
//        {
//            //有重合，则加上重合时间
//            if(t1.s < t2.e)
//            {
//                int s1 = t1.s>t2.s?t1.s:t2.s;
//                sum += t2.e-s1;
//            }
//            if(q2.empty()) break;
//            //没有重合，遍历第二个人的下一个时间段
//            t2 = q2.front();
//            q2.pop();
//            //如果第二个人这个时间段的结束时间比第一个人晚，那么开始遍历第一个人的时间段，直到第一个人有一个时间段的结束时间超过该结束时间
//            if(t2.e > t1.e)
//                now = 2;
//        }
//        //同上，这里是第二个人,now == 2
//        else
//        {
//            if(t2.s < t1.e)
//            {
//                int s2 = t1.s>t2.s?t1.s:t2.s;
//                sum += t1.e-s2;
//            }
//            if(q1.empty()) break;
//            t1 = q1.front();
//            q1.pop();
//            if(t1.e > t2.e)
//                now = 1;
//        }
//    }
//    cout << sum;
//}
