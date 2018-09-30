//#include<iostream>
//#include<iomanip>
//using namespace std;
//#define SY 1850
//#define SW 2
//int a,b,c,y1,y2;
//int g_days[13] = {0,31,59,90,120,151,181,212,243,273,304,334,365};
//int g_day[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
//void get_flag();
//bool is_leap(int);
//int main()
//{
//    cin >>a>>b>>c>>y1>>y2;
//    get_flag();
//    return 0;
//}
//void get_flag()
//{
//    int days = 0;
//    for(int y=1850;y<y1;y++)
//    {
//        if((y%400 == 0) || (y%4==0&&y%100!=0))
//        days += 366;
//        else
//        days += 365;
//    }
//    for(int y=y1;y <= y2;y++)
//    {
//        int tmp = days;
//
//        //加今年的天数
//        if(is_leap(y))
//            days += 366;
//        else
//            days += 365;
//
//        tmp += g_days[a-1];
////        cout <<days <<endl;
//        //如果是闰年
//        if(a > 2 && is_leap(y)) tmp += 1;
//        //该月一号的星期数
//        int weeks = (tmp)%7+2;
////        cout <<weeks <<endl;
//        int day = 0;
//        if(c>=weeks)
//            day = 7*(b-1)+c-weeks+1;
//        else
//            day = 7*(b-1)+c+7-weeks+1;
//
//        if(a == 2 && is_leap(y) && day > 29) {cout<<"none"; if(y != y2) cout<<endl; continue;}
//        if(a == 2 && !is_leap(y) && day > 28) {cout<<"none"; if(y != y2) cout<<endl; continue;}
//        if(a != 2 && day > g_day[a]) {cout<<"none"; if(y != y2) cout<<endl; continue;}
//
//        //卧槽啊，这里是深坑啊，玛德，我服了
//        cout <<y<<"/"<<setw(2)<<setfill('0')<<a<<"/"<<setw(2)<<setfill('0')<<day;
//        if(y != y2) cout<<endl;
//    }
//}
//bool is_leap(int y)
//{
//    if(y%400 == 0) return true;
//    if(y%4 == 0)
//    {
//        if(y%100 != 0) return true;
//    }
//    return false;
//}
