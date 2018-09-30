//#include<iostream>
//using namespace std;
//int get_score(int*,int);
//int main()
//{
//    int a[40]={0,};
//    int i=0;
//    do
//    {
//        cin>>a[i];
//        i++;
//    }while(cin.get()!='\n');
//    cout <<get_score(a,i);
//    return 0;
//}
//
//int get_score(int* a,int i)
//{
//    int j = 0;
//    int score = 0;
//    int iter = 2;
//    while(j<i)
//    {
//        if(a[j] == 1){score++;iter =2;}
//        else if(a[j] == 2)
//        {
//            score += iter;
//            iter += 2;
//        }
//        else break;
//        j++;
//    }
//    return score;
//}
