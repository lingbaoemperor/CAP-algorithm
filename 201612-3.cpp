////��ӵĵط��ǣ������Ȩ�޿������ظ��ģ�Ҫ��������
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
////��ѯ��Ϣ
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
//    //����Ȩ����Ϣ
//    Auth();
//    //���ܽ�ɫ��Ϣ
//    Role();
//    //�����û���Ϣ
//    User();
//    //���ܲ�ѯ��Ϣ
//    Query();
//
//    for(vector<QINFO>::iterator it = query.begin();it != query.end();it++)
//        output((*it));
//    return 0;
//}
//void output(QINFO info)
//{
//    //������Ϣ����
//    bool result = false;
//    int level = -1;
//
//    //��ȡ���û��Ľ�ɫ�б�
//    map<string,vector<string> >::iterator user_it = user.find(info.user);
//    //�û��Ƿ���
//    if(user_it != user.end())
//    {
//        //��ȡ��ɫ�б�
//        vector<string> vrole = user_it ->second;
//        //������ɫ
//        for(vector<string>::iterator vrole_it = vrole.begin();vrole_it != vrole.end();vrole_it++)
//        {
//            //��ȡ��ɫ��
//            string srole = (*vrole_it);
//            //��ȡһ����ɫӵ�е�Ȩ���б�
//            map<string,map<string,int> >::iterator role_it = role.find(srole);
//            //����ڽ�ɫ��Ϣ�����ҵ���ɫ
//            if(role_it != role.end())
//            {
//                //��ȡ�ý�ɫ��Ȩ���б�
//                map<string,int> authlist = role_it ->second;
//                //��ȡҪ��ѯ��Ȩ���ڸý�ɫ�е���Ϣ����Ȩ����������
//                map<string,int>::iterator iit = authlist.find(info.auth);
//                //���Ȩ�޴���
//                if(iit != authlist.end())
//                {
//                    map<string,int>::iterator it = auth.find(info.auth);
//                    //�����Ȩ�޲�һ����Ȩ���б��У���Ȩ��δ����,����Ҫ��һ���ж�
//                    if(it != auth.end())
//                    {
//                        //�����ѯ�����ȼ�
//                        if(info.level == -1)
//                        {
//                            //�����Ȩ�޲��ֵȼ���ֱ�Ӳ�ѯ�ɹ�
//                            if(it ->second == -1)
//                                result = true;
//                            //����ֵȼ��������ӵ�е���ߵȼ�
//                            else
//                            {
//                                result = true;
//                                level = (level > iit ->second?level:iit ->second);
//                            }
//                        }
//                        //��ѯ���ȼ�
//                        else
//                        {
//                            //�����Ȩ�޲��ֵȼ���ֱ�Ӳ�ѯ�ɹ�
//                            if(it ->second == -1)
//                                result = true;
//                            //�Ƿ��дﵽ��ӦȨ�޵ȼ�������δ������ߵȼ������¼�ý�ɫ��ߵ�Ȩ�޵ȼ�
//                            else if(iit ->second >= info.level && info.level <= it ->second)
//                                result = true;
//                            //û�дﵽ��ʧ��
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
//                //����Ҫע�⣬�����Ȩ�޿������ظ��ģ�ͬ���������ȼ���
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
//            //����Ҫע�⣬�����Ȩ�޿������ظ��ģ�ֻ�������ȼ���
//            string sb = s.substr(0,pos);
//            map<string,int>::iterator it = auth.find(sb);
//            if(it != auth.end() && it ->second > level)
//                continue;
//            else
//                auth[sb] = level;
//        }
//    }
//}
