//#include<iostream>
//#include<string>
//#include<vector>
//using namespace std;
//
//int N;
//vector<string> g_vNow;
////接受输入
//void result();
////计算某个路径的结果
//void process(string);
//int main()
//{
//    result();
//    return 0;
//}
//
//void process(string s_raw)
//{
//    //空路径，直接输出当前目录
//    if(s_raw == "")
//    {
//        for(int j=0;j < g_vNow.size();j++)
//            cout <<"/" <<g_vNow[j];
//        cout <<endl;
//        return;
//    }
//    //用来保存路径
//    vector<string> v;
//    //不是以根路径为起始（以当前目录为起始）
//    if(s_raw[0] != '/')
//        v = g_vNow;
//    while(true)
//    {
//        string s;
//        int pos = s_raw.find("/");
//        if(pos == string::npos)
//            break;
//        //连续的斜杠不要
//        else if(pos == 0)
//        {
//            s_raw = s_raw.substr(1,s_raw.length()-1);
//            continue;
//        }
//        //某个中间目录的名称
//        else
//        {
//            s = s_raw.substr(0,pos);
//            s_raw = s_raw.substr(pos+1,s_raw.length()-pos-1);
//        }
//        //该目录的名字，上级目录则出栈
//        if(s == "..")
//        {
//            if(!v.empty())
//                v.pop_back();
//        }
//        //当前目录不管
//        else if(s == ".")
//            continue;
//        //某个目录的入栈
//        else
//            v.push_back(s);
//    }
//    //最后一级是文件，文件名入栈
//    if(s_raw != "")
//        v.push_back(s_raw);
//    //输入如果全是斜杠，只输出根目录/
//    if(v.empty()){ cout <<"/" <<endl; return;}
//    //输出路径
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
