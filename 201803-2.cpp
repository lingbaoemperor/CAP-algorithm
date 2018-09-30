//#include<iostream>
//using namespace std;
//
//class Ball
//{
//    public:
//        int direction;
//        int position;
//        bool changed;
//        Ball(){};
//        Ball(int d,int p){direction=d;position=p;changed = false;}
//        void move(){position+=direction;}
//        void change_direction(){direction=-direction;};
//};
//void get_flag(int,int,int,Ball*);
//int main()
//{
//    int n,l,t;
//    cin >>n>>l>>t;
//    Ball init[100];
//    for(int i=0;i<n;i++)
//    {
//        int p;
//        cin>>p;
//        init[i] = Ball(1,p);
//    }
//    get_flag(n,l,t,init);
//    for(int i=0;i<n;i++)
//        cout<<init[i].position<<" ";
//    return 0;
//}
//
//void get_flag(int n,int l,int t,Ball* balls)
//{
//    for(int i=0;i<t;i++)
//    {
//        for(int j=0;j<n;j++)
//        {
//            if(balls[j].position == l || balls[j].position == 0) balls[j].change_direction();
//            for(int k=j+1;k<n;k++)
//            {
//                if(balls[k].changed) continue;
//                if(balls[j].position == balls[k].position)
//                {
//                    balls[j].change_direction();
//                    balls[k].change_direction();
//                    balls[k].changed = true;
//                }
//            }
//            balls[j].move();
//        }
//        for(int j=0;j<n;j++)
//            balls[j].changed = false;
//    }
//}
