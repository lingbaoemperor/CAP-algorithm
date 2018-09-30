//#include<iostream>
//#include<cmath>
//using namespace std;
//
//int get_flag(int*,int);
//void QuickSort(int*,int,int);
//int main()
//{
//    int n = 0;
//    cin >>n;
//    int* a = new int[n];
//    for(int i=0;i<n;i++)
//        cin >>a[i];
//    QuickSort(a,0,n-1);
//    cout <<get_flag(a,n);
//    return 0;
//}
//int get_flag(int*a,int n)
//{
//    int flag = 999999;
//    for(int i=0;i<n-1;i++)
//        if(flag>abs(a[i+1]-a[i]))
//            flag = abs(a[i+1]-a[i]);
//    return flag;
//}
//void QuickSort(int* a,int f,int e)
//{
//    if(f>=e) return;
//    int l = f,r = e;
//    int k=a[l];
//    while(l!=r)
//    {
//        while(k<=a[r]&&l<r)
//            r--;
//        a[l] =a[r];
//        while(k>=a[l]&&l<r)
//            l++;
//        a[r] = a[l];
//    }
//    a[l] = k;
//    QuickSort(a,f,l-1);
//    QuickSort(a,l+1,e);
//}
