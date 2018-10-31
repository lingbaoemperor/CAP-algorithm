////��������ʱ�ˣ�25�֣���Ҫ����һ����
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
////ʱ�����
//class Period
//{
//public:
//    int S;
//    int E;
//    Period(){}
//    Period(int s,int e){S = s;E = e;}
//};
//
////����ƻ���
//class Schedule
//{
//public:
//    //�� 0-59
//    vector<Period> minute;
//    //ʱ 0-23
//    vector<Period> hour;
//    //�� 1-31
//    vector<Period> day;
//    //�� 1-12
//    vector<Period> month;
//    //���� 0-6
//    vector<Period> week;
//    //����
//    string command;
//    Schedule(){}
//    Schedule(string);
//private:
//    //�ָ�����1-3,4,-58,9,10�������ֶ�
//    //�ηֱ�Ϊ�������������ַ������ָ��洢�����顢��Сʱ������ʱ��
//    void process_input(string,vector<Period>&,int,int);
//    void process_month(string);
//    void process_week(string);
//
//};
//
//class Process;
////ȫ������ƻ�
//class InputSchedule
//{
//public:
//    //����ƻ��б�
//    vector<Schedule> schedules;
//    //����ƻ�����
//    int N;
//    InputSchedule(){}
//    InputSchedule(int);
//    void check();
//    //����һ��ʱ�����
//    void traverse(Process);
//};
//
//
////ʱ����
//class Time
//{
//public:
//    //��ʱ������
//    int minute;
//    int hour;
//    int day;
//    int month;
//    int year;
//    int week;
//    Time(){}
//};
////ʱ�����
//class Process
//{
//public:
//    Time now;
//    Time start;
//    Time over;
//    Process(){}
//    Process(string,string);
//    void check();
//    //����������
//    bool increase();
//private:
//    //���㿪ʼʱ��������������ڼ���
//    void calc_start_week();
//    //��201711171234�ָ�
//    void split(string,Time&);
//};
//
////����ƻ���
//InputSchedule g_schedules;
//
//int main()
//{
//    int n;
//    string s,t;
//    cin >>n >>s >>t;
//    cin.get();
//    //�������룬ת����ʱ�����
//    g_schedules = InputSchedule(n);
//    //���ʱ���
////    g_schedules.check();
//    //���������ʱ���
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
//    //����������ʱ�䣬�˳�
//    if(now.year == over.year && now.month == over.month && now.day == over.day && now.hour == over.hour && now.minute == over.minute)
//        return false;
//
//    int step;
//    step = (now.minute+1)/60;
//    now.minute = (now.minute+1)%60;
//
//    //����н�λ
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
//    //���������Ҫ����
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
//        //��������
//        now.week = (now.week+1)%7;
//    }
//    //����·���Ҫ����
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
//    //���
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
//    //������Ǻţ�����ʱ�䣬ֱ�ӷ���
//    if(s == "*")
//    {
//        month.push_back(Period(MIN,MAX));
//        return;
//    }
//    //����
//    vector<string> vtip;
//    //�Զ��ŷָ�
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
//    //����ȫ���������1-3����5����
//    for(int i=0;i < vtip.size();i++)
//    {
//        int pos = vtip[i].find("-");
//        string vts = vtip[i];
//        //���û�ҵ�'-'����ô��ĳ��ʱ��
//        if(pos == string::npos)
//        {
//            //ת������
//            int x = atoi(vts.c_str());
//            //������ַ���
//            if(x == 0)
//            {
//                int m = 1;
//                for(;ss[m] != vts;m++){}
//                month.push_back(Period(m,m));
//            }
//            //����
//            else
//                month.push_back(Period(x,x));
//        }
//        //��ʱ�䷶Χ
//        else
//        {
//            string pre = vts.substr(0,pos);
//            string next = vts.substr(pos+1,vts.length()-pos-1);
//            int s = atoi(pre.c_str());
//            int e = atoi(next.c_str());
//            //���������ַ���
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
//    //������Ǻţ�����ʱ�䣬ֱ�ӷ���
//    if(s == "*")
//    {
//        week.push_back(Period(MIN,MAX));
//        return;
//    }
//    //����
//    vector<string> vtip;
//    //�Զ��ŷָ�
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
//    //����ȫ���������1-3����5����
//    for(int i=0;i < vtip.size();i++)
//    {
//        int pos = vtip[i].find("-");
//        string vts = vtip[i];
//        //���û�ҵ�'-'����ô��ĳ��ʱ��
//        if(pos == string::npos)
//        {
//            //ת������
//            //�������Ͳ�ת��
//            if(vts == "0")
//                week.push_back(Period(0,0));
//            else
//            {
//                int x = atoi(vts.c_str());
//                //������ַ���
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
//        //��ʱ�䷶Χ
//        else
//        {
//            string pre = vts.substr(0,pos);
//            string next = vts.substr(pos+1,vts.length()-pos-1);
//            int s = atoi(pre.c_str());
//            int e = atoi(next.c_str());
//            //������ַ���
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
////�ָ�����1-3,4,6-7,8���ֶ�
//void Schedule::process_input(string s,vector<Period>& v,int MIN,int MAX)
//{
//    //������Ǻţ�����ʱ�䣬ֱ�ӷ���
//    if(s == "*")
//    {
//        v.push_back(Period(MIN,MAX));
//        return;
//    }
//    //����
//    vector<string> vtip;
//    //�Զ��ŷָ�
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
//    //����ȫ���������1-3����5����
//    for(int i=0;i < vtip.size();i++)
//    {
//        int pos = vtip[i].find("-");
//        string vts = vtip[i];
//        //���û�ҵ�'-'����ô��ĳ��ʱ��
//        if(pos == string::npos)
//        {
//            //ת������
//            //�������Ͳ�ת��
//            if(vts == "0")
//                v.push_back(Period(0,0));
//            else
//            {
//                int x = atoi(vts.c_str());
//                v.push_back(Period(x,x));
//            }
//        }
//        //��ʱ�䷶Χ
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
////�ָ�������ַ���
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
//    cout <<"ʱ���" <<endl;
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
