////90�֣���֪����ʲô����
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
////����
//string input_s;
//string check_s[100];
////����JSON
//Object g_ob;
//int N,M;
//string remove_sprit(string);
//void search(Object ,vector<string> ,int );
//void get_result(string);
//int main()
//{
//    cin >>N>>M;
//    cin.get();
//    //����ƴ�ӳ�һ��
//    for(int i=0; i < N; i++)
//    {
//        string s;
//        getline(cin,s);
//        input_s.append(s);
//    }
//    //�����ֵ�
//    g_ob = Object(0,input_s.length()-1);
//    //��������
//    for(int i=0;i < M;i++)
//        cin >>check_s[i];
//    //��ѯ
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
//    //���Ҿ�ͷ
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
//        //�������²���
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
//    //����ջ
//    int bracket = 0;
//    //����ջ
//    int quotation = 0;
//    //ǰһ����������
//    int index_quotation = -1;
//    //keyջ
//    string key = "";
//    for(int pointer=r+1;pointer <= l;pointer++)
//    {
//        //�ո񣬼������
//        if(input_s[pointer] == ' ')
//            continue;
//        else if(input_s[pointer] == '\\')
//            pointer+=1;
//        //����
//        else if(input_s[pointer] == '"')
//        {
//            //��������ĳ���ַ����Ľ���
//            if(quotation)
//            {
//                //֮ǰ�����ų�ջ
//                quotation = 0;
//                //���ַ�����һ��value������value��key��Ӧ����
//                if(key != "")
//                {
//                    m_str[key] = remove_sprit(input_s.substr(index_quotation+1,pointer-index_quotation-1));
//                    key = "";
//                }
//                //���ַ�����һ��key������key���ȴ���һ��value
//                else
//                    key = remove_sprit(input_s.substr(index_quotation+1,pointer-index_quotation-1));
//            }
//            //��������ĳ���ַ����Ŀ�ʼ,������ջ,�ȴ���һ������
//            else
//            {
//                quotation = 1;
//                index_quotation = pointer;
//            }
//        }
//        //�����ţ���value��һ������
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
//        //�����ţ���object��������,�˳�
//        else if(input_s[pointer] == '}')
//            break;
//        else
//        {
//        }
//    }
//}
////ȥ��ת�����
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
