////�벻����ʲô�ð취��ֻ���ñ�������
//#include<iostream>
//#include<queue>
//using namespace std;
//int N;
//
////ʱ�����Ϣ����ʼ�ͽ���ʱ��
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
////�����˵�������Ϣ
//queue<Time> q1;
//queue<Time> q2;
////������
//void output();
//int main()
//{
//    //��������
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
//    //������
//    output();
//    return 0;
//}
//
//void output()
//{
//    //���ս����¼
//    int sum = 0;
//    Time t1 = q1.front();
//    Time t2 = q2.front();
//    //��¼��ǰ�����У���һ���˵Ľ���ʱ������
//    int now = t1.e > t2.e?1:2;
//    q1.pop();
//    q2.pop();
//    while(true)
//    {
//        //�����ǵ�һ���˵�ĳ��ʱ��εĽ���ʱ��ȵڶ�������
//        //�Ե�һ����ĳ��ʱ��εĽ���ʱ��Ϊ��׼
//        if(now == 1)
//        {
//            //���غϣ�������غ�ʱ��
//            if(t1.s < t2.e)
//            {
//                int s1 = t1.s>t2.s?t1.s:t2.s;
//                sum += t2.e-s1;
//            }
//            if(q2.empty()) break;
//            //û���غϣ������ڶ����˵���һ��ʱ���
//            t2 = q2.front();
//            q2.pop();
//            //����ڶ��������ʱ��εĽ���ʱ��ȵ�һ��������ô��ʼ������һ���˵�ʱ��Σ�ֱ����һ������һ��ʱ��εĽ���ʱ�䳬���ý���ʱ��
//            if(t2.e > t1.e)
//                now = 2;
//        }
//        //ͬ�ϣ������ǵڶ�����,now == 2
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
