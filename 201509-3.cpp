//#include<iostream>
//#include<stack>
//#include<cstdlib>
//#include<string>
//using namespace std;
//int m,n;
//string g_sTemplate[100];
//stack<string> g_stack;
//stack<int> g_pos;
//struct
//{
//    string name;
//    string value;
//}g_vVar[100];
//
////���ֻ��80�֣�û����Ƕ��ģ��
//void get_flag_version1();
////���100��
//void get_flag_version2();
//int main()
//{
//    cin >>m >>n;
//    cin.get();
//    for(int i=0;i < m;i++)
//        getline(cin,g_sTemplate[i]);
//    for(int i=0;i < n;i++)
//    {
//        cin >>g_vVar[i].name;
//        cin.get();
//        getline(cin,g_vVar[i].value);
//    }
//    get_flag_version2();
//    return 0;
//}
//void get_flag_version1()
//{
//    for(int i=0;i < m;i++)
//    {
//        for(int j=g_sTemplate[i].length()-1;j > 0;j--)
//        {
//            int s = 0,e = 0;
//            //Ѱ�ҵ�һ��'}'
//            if(g_sTemplate[i][j] != '}') continue;
//            //'}'ǰһ������'}'�����ַ����ѽ�������һ��
//            if(j > 0&&g_sTemplate[i][j-1] != '}') continue;
//            //'}}'ǰһ������' '�����ַ����ѽ�������һ��
//            if(j > 1&&g_sTemplate[i][j-2] != ' ') continue;
//            //Ѱ��' }}'ǰ���' '��û�ҵ�����
//            int k = j-3;
//            for(;k>0&&g_sTemplate[i][k]!=' ';k--){}
//            //' 'ǰ�治��'{'����
//            if(k > 0&& g_sTemplate[i][k-1] != '{') continue;
//            //'{ 'ǰ�治��'{'����
//            if(k > 1&& g_sTemplate[i][k-2] != '{') continue;
//            //���ڴ�k-2��ʼ��j��Ҫ�滻�ģ�����k-2��ʼ����j-(k-2)+1��
//            string name = g_sTemplate[i].substr(k+1,j-k-3);
//            int index = -1;
//            for(int l=0;l < n;l++)
//            {
//                if(name == g_vVar[l].name)
//                    index = l;
//            }
//            if(index != -1)
//                g_sTemplate[i].replace(k-2,j-k+3,g_vVar[index].value.substr(1,g_vVar[index].value.length()-2));
//            else
//                g_sTemplate[i].erase(k-2,j-k+3);
//            //�ҵ�һ��������jֱ�ӱ��k-3
//            j = k -3;
//
//        }
//        cout <<g_sTemplate[i] <<endl;
//    }
//}
//
//void get_flag_version2()
//{
//    for(int i=0;i < m;i++)
//    {
//        while(!g_stack.empty())
//        {
//            g_stack.pop();
//            g_pos.pop();
//        }
//        int len = g_sTemplate[i].length();
//        int j = len-3;
//        int pre = -1;
//        while(j >= 0)
//        {
//            //��ջ -3
//            if(j>2 && g_sTemplate[i].substr(j,3) == " }}")
//            {
//                g_stack.push(" }}");
//                g_pos.push(j);
//                j -= 3;
//                continue;
//            }
//            //����Ե�
//            else if(!g_stack.empty() && g_stack.top() == " }}" && g_sTemplate[i].substr(j,3) == "{{ ")
//            {
//                g_stack.pop();
//                int pos = g_pos.top();
//                g_pos.pop();
//                //�����Ƕ�׵ģ��������κβ���, ��ջ }},-1
//                //����Ƕ�׵�
//                if(g_stack.empty())
//                {
//                    string name = g_sTemplate[i].substr(j+3,pos-j-3);
//                    int index = -1;
//                    for(int k=0;k < n;k++)
//                    {
//                        if(name == g_vVar[k].name)
//                            index = k;
//                    }
//                    if(index != -1)
//                        g_sTemplate[i].replace(j,pos+3-j,g_vVar[index].value.substr(1,g_vVar[index].value.length()-2));
//                    else
//                        g_sTemplate[i].erase(j,pos+3-j);
//                }
//            }
//            j--;
//        }
//        cout <<g_sTemplate[i] <<endl;
//    }
//}
