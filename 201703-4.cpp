//地铁修建	2017-03 question4
//最蠢的方法，没有超时
#include <iostream>
#include <algorithm>
#define MAX 300000

using namespace std;

class Node
{
public:
    int head;
    int tail;
    int weight;
    friend bool operator <(const Node& x,const Node& y)
    {
        return x.weight < y.weight;
    }
};
Node node[MAX];
int relation[MAX];
int root(int n);
int main()
{
    int n,m;
    int fin = 0;
    cin >>n >>m;
    for(int i=0;i <= n;i++)
        relation[i] = i;
    for(int i=0;i < m;i++)
        cin >>node[i].head >>node[i].tail >>node[i].weight;
    sort(node,node+m);
    for(int i=0;i < m;i++)
    {
        int a = root(node[i].head);
        int b = root(node[i].tail);
        if(a == b) continue;
        if(a > b)
            relation[a] = b;
        else
            relation[b] = a;
        fin = max(fin,node[i].weight);
        if(root(n) == 1) break;
    }
    cout <<fin <<endl;
    return 0;
}

int root(int n)
{
    if(relation[n] == n ) return n;
    else return root(relation[n]);
}
