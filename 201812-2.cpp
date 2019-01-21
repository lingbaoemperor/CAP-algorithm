///*小明放学*/
//#include<iostream>
//#include<vector>
//using namespace std;
//#define ULLONG unsigned long long
////r、y、g持续时间
//int g_iR,g_iY,g_iG;
////道路数和红绿灯数
//int g_iN;
////
//struct Info
//{
//    int type;
//    int period;
//};
//vector<Info> g_vInfo;
//void input();
//void output();
//int main()
//{
//    input();
//    output();
//    return 0;
//}
//void input()
//{
//    cin >>g_iR >>g_iY >>g_iG;
//    cin >>g_iN;
//    //0代表路段，1、2、3代表r、y、g倒计时
//    for(int i=0;i < g_iN;i++)
//    {
//        Info info;
//        cin >>info.type >>info.period;
//        g_vInfo.push_back(info);
//    }
//}
////r、g、y轮替
//void output()
//{
//    //记录走到某个结点所用时间
//    ULLONG cost = 0;
//
//    //r、g、y一个轮回所用时间
//    int circle_cost = g_iR+g_iG+g_iY;
//
//    for(int i=0;i < g_iN;i++)
//    {
//        int type = g_vInfo[i].type;
//        int period = g_vInfo[i].period;
//        //路段
//        if(type == 0)
//            cost += period;
//        //灯
//        else
//        {
//            ULLONG x = 0;
//            if(type == 1)
//                x = (g_iR-period+cost)%circle_cost;
//            else if(type == 3)
//                x = (g_iG+g_iR-period+cost)%circle_cost;
//            else if(type == 2)
//                x = (circle_cost-period+cost)%circle_cost;
//            else{}
//            //当前状态
//            //红灯
//            if(x < g_iR)
//                cost += g_iR-x;
//            else if(x < (g_iR+g_iG))
//            {//do nothing
//            }
//            else
//                cost += g_iR+circle_cost-x;
//        }
//    }
//    cout <<cost <<endl;
//}
