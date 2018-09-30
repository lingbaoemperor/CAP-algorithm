//#include<iostream>
//using namespace std;
//
////abaab
//
//int next[100]={0,};
//string s;
//string ss;
//
//int main()
//{
//    //0 0 1 1 2
//    s = "Hello";
//    ss = "HELLOisNOTHello";
//    next[0] = -1;   //第一个字符不匹配，-(-1)
//    for(int i=1,k=0;i<s.length();i++)
//    {
//        while(s[i]!=s[k]&&k>0)
//            k = next[k];
//        if(s[i] == s[k])
//            k++;
//        next[i] = k;
//    }
////    for(int i=0;i<s.length();i++)cout <<next[i] <<" ";
//    int i=0,j=0;
//    while(i<ss.length())
//    {
//        while(j<s.length()&&ss[i+j] == s[j])j++;
//        if(j == s.length()) cout<<i;
//        i += j-next[j];
//        j=0;
//    }
//    return 0;
//}
