//#include<iostream>
//#include<cmath>
//using namespace std;
////kmp
//
//string s;
//int next[100]={0,};
//int sensitive;
//int N;
//string ss[100];
//
//void get_next();
//void get_flag1();
//void get_flag2();
//int main()
//{
//    cin >>s>>sensitive>>N;
//    for(int i=0;i < N;i++)
//        cin >>ss[i];
//    get_next();
//    if(sensitive)
//        get_flag1();
//    else
//        get_flag2();
//    return 0;
//}
//void get_flag1()
//{
//    for(int x=0;x<N;x++)
//    {
//        string all = ss[x];
//        int i = 0;
//        while(i < all.length())
//        {
//            int j = 0;
//            while(j < s.length() && s[j] == all[i+j])   j++;
//            if(j == s.length()) {cout <<all;if(x != N-1) cout<<endl; break;}
//            else
//                i += j-next[j];
//        }
//    }
//}
//void get_flag2()
//{
//    for(int x=0;x<N;x++)
//    {
//        string all = ss[x];
//        int i = 0;
//        while(i < all.length())
//        {
//            int j = 0;
//            while(j < s.length() && (s[j] == all[i+j] || (abs(s[j]-all[i+j])==32))) j++;
//            if(j == s.length()){cout <<all;if(x != N-1) cout<<endl;break;}
//            else
//                i += j-next[j];
//        }
//    }
//}
//void get_next()
//{
//    next[0] = -1;
//    for(int i=1,j=0;i < s.length();i++)
//    {
//        while(j>0&&s[i] != s[j])
//            j = next[j-1];
//        if(s[i] == s[j])
//            j++;
//        next[i] = j;
//    }
//}
