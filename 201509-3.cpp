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
////这个只有80分，没处理嵌套模板
//void get_flag_version1();
////这个100分
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
//            //寻找第一个'}'
//            if(g_sTemplate[i][j] != '}') continue;
//            //'}'前一个不是'}'或者字符串已结束，下一轮
//            if(j > 0&&g_sTemplate[i][j-1] != '}') continue;
//            //'}}'前一个不是' '或者字符串已结束，下一轮
//            if(j > 1&&g_sTemplate[i][j-2] != ' ') continue;
//            //寻找' }}'前面的' '，没找到跳出
//            int k = j-3;
//            for(;k>0&&g_sTemplate[i][k]!=' ';k--){}
//            //' '前面不是'{'跳出
//            if(k > 0&& g_sTemplate[i][k-1] != '{') continue;
//            //'{ '前面不是'{'跳出
//            if(k > 1&& g_sTemplate[i][k-2] != '{') continue;
//            //现在从k-2开始到j是要替换的，即从k-2开始后面j-(k-2)+1个
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
//            //找到一个变量后j直接变成k-3
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
//            //入栈 -3
//            if(j>2 && g_sTemplate[i].substr(j,3) == " }}")
//            {
//                g_stack.push(" }}");
//                g_pos.push(j);
//                j -= 3;
//                continue;
//            }
//            //有配对的
//            else if(!g_stack.empty() && g_stack.top() == " }}" && g_sTemplate[i].substr(j,3) == "{{ ")
//            {
//                g_stack.pop();
//                int pos = g_pos.top();
//                g_pos.pop();
//                //如果是嵌套的，不进行任何操作, 出栈 }},-1
//                //不是嵌套的
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
