///*С����ѧ*/
//#include<iostream>
//#include<vector>
//using namespace std;
//#define ULLONG unsigned long long
////r��y��g����ʱ��
//int g_iR,g_iY,g_iG;
////��·���ͺ��̵���
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
//    //0����·�Σ�1��2��3����r��y��g����ʱ
//    for(int i=0;i < g_iN;i++)
//    {
//        Info info;
//        cin >>info.type >>info.period;
//        g_vInfo.push_back(info);
//    }
//}
////r��g��y����
//void output()
//{
//    //��¼�ߵ�ĳ���������ʱ��
//    ULLONG cost = 0;
//
//    //r��g��yһ���ֻ�����ʱ��
//    int circle_cost = g_iR+g_iG+g_iY;
//
//    for(int i=0;i < g_iN;i++)
//    {
//        int type = g_vInfo[i].type;
//        int period = g_vInfo[i].period;
//        //·��
//        if(type == 0)
//            cost += period;
//        //��
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
//            //��ǰ״̬
//            //���
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
