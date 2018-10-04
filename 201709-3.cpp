////90分，不知道有什么问题
//#include<iostream>
//#include<vector>
//#include<map>
//#include<cstdlib>
//using namespace std;
//class Object
//{
//public:
//    map<string,string> m_str;
//    map<string,Object> m_ob;
//    Object(int r,int l);
//    Object(){}
//};
////输入
//string input_s;
//string check_s[100];
////顶层JSON
//Object g_ob;
//int N,M;
//string remove_sprit(string);
//void search(Object ,vector<string> ,int );
//void get_result(string);
//int main()
//{
//    cin >>N>>M;
//    cin.get();
//    //输入拼接成一行
//    for(int i=0; i < N; i++)
//    {
//        string s;
//        getline(cin,s);
//        input_s.append(s);
//    }
//    //构造字典
//    g_ob = Object(0,input_s.length()-1);
//    //接收输入
//    for(int i=0;i < M;i++)
//        cin >>check_s[i];
//    //查询
//    for(int i=0;i < M;i++)
//    {
//        get_result(check_s[i]);
//        if(i != M-1)
//             cout <<endl;
//    }
//    return 0;
//}
//void get_result(string s)
//{
//    vector<string> vs;
//    while(true)
//    {
//        int f = s.find(".");
//        if(f == string::npos)
//        {
//            vs.push_back(s);
//            break;
//        }
//        else
//        {
//            vs.push_back(s.substr(0,f));
//            s = s.substr(f+1,s.length()-f-1);
//        }
//    }
//    search(g_ob,vs,0);
//}
//void search(Object ob,vector<string> vs,int i)
//{
//    //查找尽头
//    if(i == vs.size())
//    {
//        cout <<"NOTEXIST";
//        return;
//    }
//    map<string,string>::iterator it_str = ob.m_str.find(vs[i]);
//    map<string,Object>::iterator it_ob = ob.m_ob.find(vs[i]);
//    if(it_str != ob.m_str.end())
//    {
//        cout <<"STRING" <<" " <<it_str ->second;
//    }
//    if(it_ob != ob.m_ob.end())
//    {
//        //不再向下查找
//        if(i == vs.size()-1)
//        {
//            cout <<"OBJECT";
//            return;
//        }
//        search(it_ob ->second,vs,i+1);
//    }
//    if(it_str == ob.m_str.end() && it_ob == ob.m_ob.end())
//        cout <<"NOTEXIST";
//}
//Object::Object(int r,int l)
//{
//    //括号栈
//    int bracket = 0;
//    //引号栈
//    int quotation = 0;
//    //前一个引号索引
//    int index_quotation = -1;
//    //key栈
//    string key = "";
//    for(int pointer=r+1;pointer <= l;pointer++)
//    {
//        //空格，继续向后
//        if(input_s[pointer] == ' ')
//            continue;
//        else if(input_s[pointer] == '\\')
//            pointer+=1;
//        //引号
//        else if(input_s[pointer] == '"')
//        {
//            //该引号是某个字符串的结束
//            if(quotation)
//            {
//                //之前的引号出栈
//                quotation = 0;
//                //该字符串是一个value，将该value与key对应起来
//                if(key != "")
//                {
//                    m_str[key] = remove_sprit(input_s.substr(index_quotation+1,pointer-index_quotation-1));
//                    key = "";
//                }
//                //该字符串是一个key，保存key，等待下一个value
//                else
//                    key = remove_sprit(input_s.substr(index_quotation+1,pointer-index_quotation-1));
//            }
//            //该引号是某个字符串的开始,引号入栈,等待下一个引号
//            else
//            {
//                quotation = 1;
//                index_quotation = pointer;
//            }
//        }
//        //左括号，该value是一个对象
//        else if(input_s[pointer] == '{')
//        {
//            int pointer2 = pointer;
//            while(true)
//            {
//                pointer2++;
//                if(input_s[pointer2] == '{') { bracket++; continue; }
//                if(input_s[pointer2] != '}')
//                    continue;
//                else
//                {
//                    if(bracket != 0)
//                    {
//                        bracket--;
//                        continue;
//                    }
//                    else
//                        break;
//                }
//            }
//            m_ob[key] = Object(pointer,pointer2);
//            key = "";
//            pointer = pointer2+1;
//        }
//        //右括号，该object解析结束,退出
//        else if(input_s[pointer] == '}')
//            break;
//        else
//        {
//        }
//    }
//}
////去除转义符号
//string remove_sprit(string s)
//{
//    int start = 0;
//    while(true)
//    {
//        int pos = s.substr(start,s.length()-start).find("\\");
//        if(pos == string::npos)
//            break;
//        else
//        {
//            s.erase(start+pos,1);
//            start = start+pos+1;
//        }
//    }
//    return s;
//}
