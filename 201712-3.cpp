////哈哈，超时了，25分，不要看这一题了
//#include<iostream>
//#include<vector>
//#include<string>
//#include<sstream>
//#include<cstdlib>
//#include<iomanip>
//using namespace std;
//#define MAX_N 20
//
//int N,S,T;
//
////时间端类
//class Period
//{
//public:
//    int S;
//    int E;
//    Period(){}
//    Period(int s,int e){S = s;E = e;}
//};
//
////任务计划类
//class Schedule
//{
//public:
//    //分 0-59
//    vector<Period> minute;
//    //时 0-23
//    vector<Period> hour;
//    //天 1-31
//    vector<Period> day;
//    //月 1-12
//    vector<Period> month;
//    //星期 0-6
//    vector<Period> week;
//    //命令
//    string command;
//    Schedule(){}
//    Schedule(string);
//private:
//    //分割类似1-3,4,-58,9,10这样的字段
//    //参分别为以类似上述的字符串、分割后存储的数组、最小时间和最大时间
//    void process_input(string,vector<Period>&,int,int);
//    void process_month(string);
//    void process_week(string);
//
//};
//
//class Process;
////全部任务计划
//class InputSchedule
//{
//public:
//    //任务计划列表
//    vector<Schedule> schedules;
//    //任务计划数量
//    int N;
//    InputSchedule(){}
//    InputSchedule(int);
//    void check();
//    //遍历一个时间进程
//    void traverse(Process);
//};
//
//
////时刻类
//class Time
//{
//public:
//    //分时天月周
//    int minute;
//    int hour;
//    int day;
//    int month;
//    int year;
//    int week;
//    Time(){}
//};
////时间进程
//class Process
//{
//public:
//    Time now;
//    Time start;
//    Time over;
//    Process(){}
//    Process(string,string);
//    void check();
//    //按分钟自增
//    bool increase();
//private:
//    //计算开始时间的星期数（星期几）
//    void calc_start_week();
//    //将201711171234分割
//    void split(string,Time&);
//};
//
////任务计划表
//InputSchedule g_schedules;
//
//int main()
//{
//    int n;
//    string s,t;
//    cin >>n >>s >>t;
//    cin.get();
//    //处理输入，转换成时间表类
//    g_schedules = InputSchedule(n);
//    //检查时间表
////    g_schedules.check();
//    //处理输入的时间段
//    Process process;
//    process = Process(s,t);
////    g_process.check();
//    g_schedules.traverse(process);
//    return 0;
//}
//
//void InputSchedule:: traverse(Process process)
//{
//    while(true)
//    {
//        for(int i=0;i < schedules.size();i++)
//        {
//            vector<Period> month = schedules[i].month;
//            vector<Period> day = schedules[i].day;
//            vector<Period> week = schedules[i].week;
//            vector<Period> hour = schedules[i].hour;
//            vector<Period> minute = schedules[i].minute;
//            bool flag = false;
//            for(int j=0;j < month.size();j++)
//            {
//                if(process.now.month >= month[j].S && process.now.month <= month[j].E)
//                    flag = true;
//            }
//            if(!flag) continue;
//            flag = false;
//            for(int j=0;j < day.size();j++)
//            {
//                if(process.now.day >= day[j].S && process.now.day <= day[j].E)
//                    flag = true;
//            }
//            if(!flag) continue;
//            flag = false;
//            for(int j=0;j < week.size();j++)
//            {
//                if(process.now.week >= week[j].S && process.now.week <= week[j].E)
//                    flag = true;
//            }
//            if(!flag) continue;
//            flag = false;
//            for(int j=0;j < hour.size();j++)
//            {
//                if(process.now.hour >= hour[j].S && process.now.hour <= hour[j].E)
//                    flag = true;
//            }
//            if(!flag) continue;
//            flag = false;
//            for(int j=0;j < minute.size();j++)
//            {
//                if(process.now.minute >= minute[j].S && process.now.minute <= minute[j].E)
//                    flag = true;
//            }
//            if(!flag) continue;
//            cout <<setw(4) <<process.now.year;
//            cout <<setw(2) <<setfill('0') <<process.now.month;
//            cout <<setw(2) <<setfill('0') << process.now.day;
//            cout <<setw(2) <<setfill('0') << process.now.hour;
//            cout <<setw(2) <<setfill('0') << process.now.minute;
//            cout <<" " <<schedules[i].command <<endl;
//        }
//        if(process.increase() == false)
//            break;
//    }
//}
//
//bool Process::increase()
//{
//    //如果到达借宿时间，退出
//    if(now.year == over.year && now.month == over.month && now.day == over.day && now.hour == over.hour && now.minute == over.minute)
//        return false;
//
//    int step;
//    step = (now.minute+1)/60;
//    now.minute = (now.minute+1)%60;
//
//    //如果有进位
//    if(step)
//    {
//        if(now.hour == 23)
//            now.hour = 0;
//        else
//        {
//            now.hour++;
//            step = 0;
//        }
//    }
//
//    int month_days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
//
//    //如果天数需要自增
//    if(step)
//    {
//        if(((now.year%400 == 0) || (now.year%4 == 0&& now.year%100 != 0))&&(now.month == 2)&&(now.day == 29))
//            now.day = 1;
//        else if(now.day == month_days[now.month])
//            now.day = 1;
//        else
//        {
//            now.day++;
//            step = 0;
//        }
//
//        //星期自增
//        now.week = (now.week+1)%7;
//    }
//    //如果月份需要自增
//    if(step)
//    {
//        if(now.month == 12)
//            now.month = 1;
//        else
//        {
//            now.month++;
//            step = 0;
//        }
//    }
//    //年份
//    now.year += step;
//    return true;
//}
//
//void Process::calc_start_week()
//{
//    int sum = 0;
//    for(int y=1970;y < start.year;y++)
//    {
//        if((y%400 == 0) || (y%4 == 0 && y% 100 != 0))
//            sum += 366;
//        else
//            sum += 365;
//    }
//    int month_days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
//    for(int m=1;m < start.month;m++)
//    {
//        if((m == 2) && ((start.year%400 == 0) || (start.year%4 == 0 && start.year%100 != 0)))
//            sum += 29;
//        else
//            sum += month_days[m];
//    }
//    sum += start.day;
//    start.week = (sum+3)%7;
//}
//
//void Process::check()
//{
//    cout <<start.year <<" " <<start.month <<" " <<start.day <<" " <<start.hour <<" " <<start.minute <<" " <<start.week <<endl;
//    cout <<over.year <<" " <<over.month <<" " <<over.day <<" " <<over.hour <<" " <<over.minute <<endl;
//    for(int i=0;i < 100000;i++)
//    {
//        if(increase() == false) break;
//        cout <<now.year <<" " <<now.month <<" " <<now.day <<" " <<now.hour <<" " <<now.minute <<" " <<now.week <<endl;
//    }
//}
//
//Process::Process(string s,string o)
//{
//    split(s,start);
//    split(o,over);
//    calc_start_week();
//    now = start;
//}
//
//void Process::split(string s,Time& t)
//{
//    string syear = s.substr(0,4);
//    string smonth = s.substr(4,2);
//    string sday = s.substr(6,2);
//    string shour = s.substr(8,2);
//    string sminute = s.substr(10,2);
//    t.year = atoi(syear.c_str());
//    t.month = atoi(smonth.c_str());
//    t.day = atoi(sday.c_str());
//    t.hour = atoi(shour.c_str());
//    t.minute = atoi(sminute.c_str());
//}
//
//void Schedule::process_month(string s)
//{
//    int MIN = 1,MAX = 12;
//    string ss[13] = {"","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
//    //如果是星号，任意时间，直接返回
//    if(s == "*")
//    {
//        month.push_back(Period(MIN,MAX));
//        return;
//    }
//    //否则
//    vector<string> vtip;
//    //以逗号分割
//    while(true)
//    {
//        int pos = s.find(",");
//        if(pos == string::npos)
//            break;
//        vtip.push_back(s.substr(0,pos));
//        s = s.substr(pos+1,s.length()-pos-1);
//    }
//    vtip.push_back(s);
//
//    //现在全部变成类似1-3或是5这种
//    for(int i=0;i < vtip.size();i++)
//    {
//        int pos = vtip[i].find("-");
//        string vts = vtip[i];
//        //如果没找到'-'，那么是某个时刻
//        if(pos == string::npos)
//        {
//            //转成数字
//            int x = atoi(vts.c_str());
//            //如果是字符串
//            if(x == 0)
//            {
//                int m = 1;
//                for(;ss[m] != vts;m++){}
//                month.push_back(Period(m,m));
//            }
//            //否则
//            else
//                month.push_back(Period(x,x));
//        }
//        //是时间范围
//        else
//        {
//            string pre = vts.substr(0,pos);
//            string next = vts.substr(pos+1,vts.length()-pos-1);
//            int s = atoi(pre.c_str());
//            int e = atoi(next.c_str());
//            //两个都是字符串
//            if(s == 0)
//                for(;ss[s] != pre;s++){}
//            if(e == 0)
//                for(;ss[e] != next;e++){}
//            month.push_back(Period(s,e));
//        }
//    }
//}
//void Schedule::process_week(string s)
//{
//    string ss[7] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
//    int MIN = 0,MAX = 6;
//    //如果是星号，任意时间，直接返回
//    if(s == "*")
//    {
//        week.push_back(Period(MIN,MAX));
//        return;
//    }
//    //否则
//    vector<string> vtip;
//    //以逗号分割
//    while(true)
//    {
//        int pos = s.find(",");
//        if(pos == string::npos)
//            break;
//        vtip.push_back(s.substr(0,pos));
//        s = s.substr(pos+1,s.length()-pos-1);
//    }
//    vtip.push_back(s);
//
//    //现在全部变成类似1-3或是5这种
//    for(int i=0;i < vtip.size();i++)
//    {
//        int pos = vtip[i].find("-");
//        string vts = vtip[i];
//        //如果没找到'-'，那么是某个时刻
//        if(pos == string::npos)
//        {
//            //转成数字
//            //如果是零就不转了
//            if(vts == "0")
//                week.push_back(Period(0,0));
//            else
//            {
//                int x = atoi(vts.c_str());
//                //如果是字符串
//                if(x == 0)
//                {
//                    int w = 0;
//                    for(;ss[w] != vts;w++){}
//                    week.push_back(Period(w,w));
//                }
//                else
//                    week.push_back(Period(x,x));
//            }
//        }
//        //是时间范围
//        else
//        {
//            string pre = vts.substr(0,pos);
//            string next = vts.substr(pos+1,vts.length()-pos-1);
//            int s = atoi(pre.c_str());
//            int e = atoi(next.c_str());
//            //如果是字符串
//            if(pre == "0")
//            {
//                for(;ss[s] != vts;s++){}
//                for(;ss[e] != vts;e++){}
//                week.push_back(Period(s,e));
//            }
//            else
//                week.push_back(Period(s,e));
//        }
//    }
//}
////分割类似1-3,4,6-7,8的字段
//void Schedule::process_input(string s,vector<Period>& v,int MIN,int MAX)
//{
//    //如果是星号，任意时间，直接返回
//    if(s == "*")
//    {
//        v.push_back(Period(MIN,MAX));
//        return;
//    }
//    //否则
//    vector<string> vtip;
//    //以逗号分割
//    while(true)
//    {
//        int pos = s.find(",");
//        if(pos == string::npos)
//            break;
//        vtip.push_back(s.substr(0,pos));
//        s = s.substr(pos+1,s.length()-pos-1);
//    }
//    vtip.push_back(s);
//
//    //现在全部变成类似1-3或是5这种
//    for(int i=0;i < vtip.size();i++)
//    {
//        int pos = vtip[i].find("-");
//        string vts = vtip[i];
//        //如果没找到'-'，那么是某个时刻
//        if(pos == string::npos)
//        {
//            //转成数字
//            //如果是零就不转了
//            if(vts == "0")
//                v.push_back(Period(0,0));
//            else
//            {
//                int x = atoi(vts.c_str());
//                v.push_back(Period(x,x));
//            }
//        }
//        //是时间范围
//        else
//        {
//            string pre = vts.substr(0,pos);
//            string next = vts.substr(pos+1,vts.length()-pos-1);
//            int ipre = atoi(pre.c_str());
//            int inext = atoi(next.c_str());
//            if(pre == "0")
//                v.push_back(Period(0,inext));
//            else
//                v.push_back(Period(ipre,inext));
//        }
//    }
//}
//
////分割输入的字符串
//Schedule::Schedule(string s)
//{
//    vector<string> v;
//    while(true)
//    {
//        int pos = s.find(" ");
//        if(pos == string::npos)
//            break;
//        v.push_back(s.substr(0,pos));
//        s = s.substr(pos+1,s.length()-pos-1);
//    }
//    v.push_back(s);
//    process_input(v[0],minute,0,59);
//    process_input(v[1],hour,0,23);
//    process_input(v[2],day,1,31);
//    process_month(v[3]);
//    process_week(v[4]);
//    command = v[5];
//}
//
//InputSchedule::InputSchedule(int n)
//{
//    N = n;
//    for(int i=0;i < N;i++)
//    {
//        string s;
//        getline(cin,s);
//        schedules.push_back(Schedule(s));
//    }
//}
//
//void InputSchedule::check()
//{
//    cout <<"时间表：" <<endl;
//    for(int i=0;i < schedules.size();i++)
//    {
//        for(int j=0;j < schedules[i].minute.size();j++)
//            cout <<schedules[i].minute[j].S <<"-" <<schedules[i].minute[j].E <<" ";
//        cout <<endl;
//        for(int j=0;j < schedules[i].hour.size();j++)
//            cout <<schedules[i].hour[j].S <<"-" <<schedules[i].hour[j].E <<" ";
//        cout <<endl;
//        for(int j=0;j < schedules[i].day.size();j++)
//            cout <<schedules[i].day[j].S <<"-" <<schedules[i].day[j].E <<" ";
//        cout <<endl;
//        for(int j=0;j < schedules[i].month.size();j++)
//            cout <<schedules[i].month[j].S <<"-" <<schedules[i].month[j].E <<" ";
//        cout <<endl;
//        for(int j=0;j < schedules[i].week.size();j++)
//            cout <<schedules[i].week[j].S <<"-" <<schedules[i].week[j].E <<" ";
//        cout <<endl;
//        cout <<schedules[i].command <<endl;
//    }
//}
