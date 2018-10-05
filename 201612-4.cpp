//¶¯Ì¬¹æ»®
//#include<iostream>
//#define MAX_LIMIT 1000
//#define MAX 9999999
//using namespace std;
//int N;
////int chance[MAX_LIMIT] = {0,};
//int dp[MAX_LIMIT][MAX_LIMIT];
//int value[MAX_LIMIT][MAX_LIMIT] = {0,};
//int result();
//int main()
//{
//    cin >>N;
//    for(int i=1;i <= N;i++)
//        cin >>value[i][i];
//    for(int i=1;i <= N;i++)
//        dp[i][i] = 0;
//    for(int i=N-1;i > 0;i--)
//    {
//        for(int j=N;j > i;j--)
//            value[i][j] = value[i][i]+value[i+1][j];
//    }
//    cout<< result();
//    return 0;
//}
//int result()
//{
//    //step 1->N-1
//    for(int step=1;step < N;step++)
//    {
//        //i 1->N
//        for(int i=1;i <= N;i++)
//        {
//            int j = i+step;
//            dp[i][j] = dp[i][i]+dp[i+1][j];
//            //j i 1 ->2
//            for(int k=i+1;k < j;k++)
//            {
//                int tmp = dp[i][k]+dp[k+1][j];
//                if(dp[i][j] > tmp)
//                    dp[i][j] = tmp;
//            }
//            dp[i][j] += value[i][j];
//        }
//    }
//    return dp[1][N];
//}
