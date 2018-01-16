//有趣的数 2013-12 question 4
#include <iostream>
using namespace std;
#define X 1000000007

int main()
{
    int n ;
    cin >>n;
    long long**s = new long long*[n+1];
    for(int i=0;i <= n;i++)
        s[i] = new long long[6];

    for(int i=0;i < 6;i++)
        s[0][i] = 0;
    for(int i=1;i <= n;i++)
    {
        s[i][0]=1;
        s[i][1]=(s[i-1][0]+s[i-1][1]*2)%X;
        s[i][2]=(s[i-1][1]+s[i-1][2]*2)%X;
        s[i][3]=(s[i-1][1]+s[i-1][3]*2+s[i-1][4])%X;
        s[i][4]=(s[i-1][0]+s[i-1][4])%X;
        s[i][5]=(s[i-1][2]+s[i-1][3]+s[i-1][5]*2)%X;
    }
    cout <<s[n][5];
    for(int i=0;i <= n;i++)
        delete [] s[i];
    delete s;
    return 0;
}
