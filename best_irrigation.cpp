//最优灌溉	2014-12 question 4
//ci有可能是0，问题输入条件的bug
#include <iostream>
using namespace std;
#define INF 999999
class Area
{
public:
    Area(int,int);
    ~Area();
    void PM(int);
    void print();
private:
    int** area;
    int n;
    int m;
    int weigh;
    int* dis;
    int* b;
};

int main()
{
    int n,m;
    cin >>n >>m;
    Area a(n,m);
    a.PM(1);
    a.print();
    return 0;
}

void Area::print()
{
    cout <<weigh;
}

void Area::PM(int v)
{
    weigh = 0;
    dis[v] = 0;
    for(int i=1;i <= n;i++)
    {
        int k;
        int min = INF;
        for(int j=1;j <= n;j++)
        {
            if(!b[j] && dis[j] < min)
            {
                min = dis[j];
                k = j;
            }
        }
        b[k] = 1;
        weigh += min;
        for(int j=1;j <= n;j++)
        {
            if(!b[j] && area[k][j] != -1 && area[k][j] < dis[j])
            {
                dis[j] = area[k][j];
            }
        }
    }
}

Area::Area(int x,int y)
{
    n = x;
    m = y;
    dis = new int[n+1];
    b = new int[n+1];
    area = new int*[n+1];
    for(int i=1;i <= n;i++)
    {
        area[i] = new int[n+1];
        dis[i] = INF;
        b[i] = 0;
    }

    for(int i=1;i <= n;i++)
    {
        for(int j=1;j <= n;j++)
            area[i][j] = -1;
    }

    for(int i=1;i <= m;i++)
    {
        int x,y;
        int z;
        cin >>x >>y >>z;
        area[x][y] = z;
        area[y][x] = z;
    }
}
Area::~Area()
{
    for(int i=1;i <= n;i++)
        delete [] area[i];
    delete [] area;
    delete [] dis;
    delete [] b;
}
