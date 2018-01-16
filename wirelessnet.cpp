//无线网络 2014-03 question 4
//分支限界
#include <iostream>
#include <cmath>
#include <queue>
using namespace std;
#define INF 8000000

class Graph{
public:
    Graph(int n,int m,int k,int r)
    {
        this ->n = n;
        this ->m = m;
        this ->k = k;
        this ->r = r;
        c = new bool*[n+m];
        for(int i=0;i < n+m;i++)
        {
            c[i] = new bool[n+m];
        }
        dist = new int[n+m];
    }
    ~Graph()
    {
        for(int i=0;i < n+m;i++)
        {
            delete [] c[i];
        }
        delete [] dist;
        delete [] c;
    }
    void scan();
    void shortestPath(int);
    void print(int v){ cout <<dist[v]-1;}
    void DJ(int v);
    void trace()
    {
        for(int i=0;i < n+m;i++)
        {
            for(int j=0;j < n+m;j++)
                cout <<c[i][j] <<" ";
            cout <<endl;
        }
    }
    void input()
    {
        for(int i=0;i < m+n;i++)
        {
            for(int j=0;j < m+n;j++)
                cin >>c[i][j];
            dist[i] = INF;
        }
    }
private:
    bool** c;
    int* dist;
    int n,m,k;
    long long r;
};
class Point
{
    friend class Graph;
private:
    long long x;
    long long y;
};
class Node
{
public:
    bool operator<(const Node& x) const
    {
        return length > x.length;
    }
    int i;     //顶点
    int length; //路径长度, 到原点的路径长
    int nk;     //用了多少新增路由器
};

int main()
{
    int n,m,k,r;
    cin >>n >>m >>k >>r;
    Graph G(n,m,k,r);
    G.scan();
//    G.input();
    G.shortestPath(0);
    G.print(1);
    return 0;
}

 void Graph::scan()
{
    Point* p = new Point[n+m];
    for(int i=0;i < n+m;i++)
        cin >>p[i].x >>p[i].y;
    for(int i=0;i < n+m;i++)
    {
        for(int j=i;j < n+m;j++)
        {
            long long xx = (p[i].x- p[j].x)*(p[i].x-p[j].x);
            long long yy = (p[i].y-p[j].y)*(p[i].y-p[j].y);
            if(r*r >= (xx+yy))
                c[i][j] =1;
            else
                c[i][j] = 0;
            c[j][i] = c[i][j];
        }
        dist[i] = INF;
    }
    delete [] p;
}
void Graph::shortestPath(int v)
{
    priority_queue<Node> q;
    Node E;
    E.length = 0;
    E.i = v;
    E.nk = 0;
    dist[v] = 0;
    while(true)
    {
        for(int j=0;j < n+m;j++)
        {
            if(c[E.i][j] && (1+E.length) < dist[j])
            {
                dist[j] = 1+E.length;
                Node N;
                N.i = j;
                N.length = dist[j];
                N.nk =E.nk;
                if(j >= n) N.nk++;
                if(N.nk <= k)
                    q.push(N);
            }
        }
        if(q.empty()) break;
        E = q.top();
        q.pop();
    }
}
