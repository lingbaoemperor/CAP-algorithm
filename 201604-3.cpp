//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//int N;
//vector<string> g_vNow;
////��������
//void result();
////����ĳ��·���Ľ��
//void process(string);
//int main()
//{
//    result();
//    return 0;
//}
//
//void process(string s_raw)
//{
//    //��·����ֱ�������ǰĿ¼
//    if(s_raw == "")
//    {
//        for(int j=0;j < g_vNow.size();j++)
//            cout <<"/" <<g_vNow[j];
//        cout <<endl;
//        return;
//    }
//    //��������·��
//    vector<string> v;
//    //�����Ը�·��Ϊ��ʼ���Ե�ǰĿ¼Ϊ��ʼ��
//    if(s_raw[0] != '/')
//        v = g_vNow;
//    while(true)
//    {
//        string s;
//        int pos = s_raw.find("/");
//        if(pos == string::npos)
//            break;
//        //������б�ܲ�Ҫ
//        else if(pos == 0)
//        {
//            s_raw = s_raw.substr(1,s_raw.length()-1);
//            continue;
//        }
//        //ĳ���м�Ŀ¼������
//        else
//        {
//            s = s_raw.substr(0,pos);
//            s_raw = s_raw.substr(pos+1,s_raw.length()-pos-1);
//        }
//        //��Ŀ¼�����֣��ϼ�Ŀ¼���ջ
//        if(s == "..")
//        {
//            if(!v.empty())
//                v.pop_back();
//        }
//        //��ǰĿ¼����
//        else if(s == ".")
//            continue;
//        //ĳ��Ŀ¼����ջ
//        else
//            v.push_back(s);
//    }
//    //���һ�����ļ����ļ�����ջ
//    if(s_raw != "")
//        v.push_back(s_raw);
//    //�������ȫ��б�ܣ�ֻ�����Ŀ¼/
//    if(v.empty()){ cout <<"/" <<endl; return;}
//    //���·��
//    for(int j=0;j < v.size();j++)
//        cout <<"/" <<v[j];
//    cout <<endl;
//}
//void result()
//{
//    cin >>N;
//    string s;
//    cin >>s;
//    cin.get();
//    s = s.substr(1,s.length()-1).append("/");
//    while(true)
//    {
//        int pos = s.find("/");
//        if(pos == string::npos)
//            break;
//        g_vNow.push_back(s.substr(0,pos));
//        s = s.substr(pos+1,s.length()-pos-1);
//    }
//    string s1;
//    while(N && getline(cin,s1))
//    {
//        process(s1);
//        N--;
//    }
//}
