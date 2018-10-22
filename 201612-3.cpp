////最坑的地方是，输入的权限可能有重复的，要保留最大的
//#include<iostream>
//#include<map>
//#include<vector>
//#include<string>
//#include<sstream>
//using namespace std;
//#define MAX_QUERY 10001
//
//int P,R,U,Q;
//
//map<string,int> auth;
//map<string,map<string,int> > role;
//map<string,vector<string> > user;
//class QINFO
//{
//public:
//    string user;
//    string auth;
//    int level;
//    QINFO(){}
//    QINFO(string u,string a,int l)
//    {
//        user = u;
//        auth = a;
//        level = l;
//    }
//};
////查询信息
//vector<QINFO> query;
//void Auth();
//void Role();
//void User();
//void Query();
//
//void output(QINFO);
//
//int main()
//{
//    //接受权限信息
//    Auth();
//    //接受角色信息
//    Role();
//    //接受用户信息
//    User();
//    //接受查询信息
//    Query();
//
//    for(vector<QINFO>::iterator it = query.begin();it != query.end();it++)
//        output((*it));
//    return 0;
//}
//void output(QINFO info)
//{
//    //最终信息保存
//    bool result = false;
//    int level = -1;
//
//    //获取该用户的角色列表
//    map<string,vector<string> >::iterator user_it = user.find(info.user);
//    //用户是否定义
//    if(user_it != user.end())
//    {
//        //获取角色列表
//        vector<string> vrole = user_it ->second;
//        //遍历角色
//        for(vector<string>::iterator vrole_it = vrole.begin();vrole_it != vrole.end();vrole_it++)
//        {
//            //获取角色名
//            string srole = (*vrole_it);
//            //获取一个角色拥有的权限列表
//            map<string,map<string,int> >::iterator role_it = role.find(srole);
//            //如果在角色信息表中找到角色
//            if(role_it != role.end())
//            {
//                //获取该角色的权限列表
//                map<string,int> authlist = role_it ->second;
//                //获取要查询的权限在该角色中的信息，按权限名字来查
//                map<string,int>::iterator iit = authlist.find(info.auth);
//                //如果权限存在
//                if(iit != authlist.end())
//                {
//                    map<string,int>::iterator it = auth.find(info.auth);
//                    //输入的权限不一定在权限列表中，即权限未定义,所以要有一个判断
//                    if(it != auth.end())
//                    {
//                        //如果查询不带等级
//                        if(info.level == -1)
//                        {
//                            //如果该权限不分等级，直接查询成功
//                            if(it ->second == -1)
//                                result = true;
//                            //如果分等级，则输出拥有的最高等级
//                            else
//                            {
//                                result = true;
//                                level = (level > iit ->second?level:iit ->second);
//                            }
//                        }
//                        //查询带等级
//                        else
//                        {
//                            //如果该权限不分等级，直接查询成功
//                            if(it ->second == -1)
//                                result = true;
//                            //是否有达到相应权限等级，而且未超出最高等级，则记录该角色最高的权限等级
//                            else if(iit ->second >= info.level && info.level <= it ->second)
//                                result = true;
//                            //没有达到则失败
//                            else{}
//                        }
//                    }
//                }
//            }
//        }
//    }
//    if(level != -1)
//        cout <<level <<endl;
//    else
//    {
//        cout <<boolalpha <<result <<endl;
//    }
//}
//
//void Query()
//{
//    cin >>Q;
//    for(int i=0;i < Q;i++)
//    {
//        string u,l;
//        cin >>u >>l;
//        int pos = l.find(":");
//        if(pos == string::npos)
//            query.push_back(QINFO(u,l,-1));
//        else
//        {
//            string au;
//            int level;
//            au = l.substr(0,pos);
//            stringstream sstr;
//            sstr.str("");
//            sstr.clear();
//            sstr.str(l.substr(pos+1,l.length()-pos-1));
//            sstr >> level;
//            query.push_back(QINFO(u,au,level));
//        }
//    }
//}
//void User()
//{
//    cin >>U;
//    for(int i=0;i < U;i++)
//    {
//        vector<string> v;
//        string u;
//        int c;
//        cin >>u >>c;
//        for(int j=0;j < c;j++)
//        {
//            string s;
//            cin >>s;
//            v.push_back(s);
//        }
//        user[u] = v;
//    }
//}
//void Role()
//{
//    cin >>R;
//    for(int i=0;i < R;i++)
//    {
//        map<string,int> mp;
//        string r;
//        int c;
//        cin >>r >>c;
//        for(int j=0;j < c;j++)
//        {
//            string s;
//            cin >>s;
//            int pos = s.find(":");
//            if(pos == string::npos)
//                mp[s] = -1;
//            else
//            {
//                int level;
//                stringstream sstr;
//                sstr.str("");
//                sstr.clear();
//                sstr.str(s.substr(pos+1,s.length()-pos-1));
//                sstr >> level;
//                //这里要注意，输入的权限可能有重复的，同样保留最大等级的
//                string sb = s.substr(0,pos);
//                map<string,int>::iterator it = mp.find(sb);
//                if(it != mp.end() && it ->second > level)
//                    continue;
//                else
//                    mp[sb] = level;
//            }
//        }
//        role[r] = mp;
//    }
//}
//
//void Auth()
//{
//    cin >> P;
//    for(int i=0;i < P;i++)
//    {
//        string s;
//        cin >>s;
//        int pos = s.find(":");
//        if(pos == string::npos)
//            auth[s] = -1;
//        else
//        {
//            stringstream sstr;
//            int level;
//            sstr.str("");
//            sstr.clear();
//            sstr.str(s.substr(pos+1,s.length()-pos-1));
//            sstr >>level;
//            //这里要注意，输入的权限可能有重复的，只保留最大等级的
//            string sb = s.substr(0,pos);
//            map<string,int>::iterator it = auth.find(sb);
//            if(it != auth.end() && it ->second > level)
//                continue;
//            else
//                auth[sb] = level;
//        }
//    }
//}
