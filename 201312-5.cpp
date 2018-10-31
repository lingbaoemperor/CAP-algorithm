//I'm stuck!!! 2013-12 question 5
//深搜
#include <iostream>
using namespace std;

typedef struct Grid
{
    char c;
    int s;
}Grid;
int si,sj,ei,ej;
void init(Grid**&,int r,int c);
void scan(Grid**&,Grid**&,int r,int c);
void opt(Grid**&,int,int);
void optchar(Grid**&,int,int);
void DPS(Grid**&,int,int,int,int);
int Count(Grid**&,Grid**&,int,int);
int main()
{
    int r,c;
    cin >>r >>c;
    Grid** p = new Grid*[r];
    Grid** q = new Grid*[r];
    for(int i=0;i < r;i++)
    {
        p[i] = new Grid[c];
        q[i] = new Grid[c];
    }

    init(p,r,c);
    init(q,r,c);
    scan(p,q,r,c);
    DPS(p,si,sj,r,c);
    if(p[ei][ej].s == 0)
    {
        cout <<"I'm stuck!";
        return 0;
    }
    cout <<Count(p,q,r,c);
    for(int i=0;i < r;i++)
    {
        delete [] p[i];
        delete [] q[i];
    }
    delete p;
    delete q;
    return 0;
}
void init(Grid**& p,int r,int c)
{
    for(int i=0;i < r;i++)
        for(int j=0;j < c;j++)
            p[i][j].s = 0;
}
void scan(Grid**& p,Grid**& q,int r,int c)
{
    string s;
    getline(cin,s);
    for(int i=0;i < r;i++)
    {

        getline(cin,s);
        for(int j=0;j < c;j++)
        {
            if(s[j] == 'S')
            {
                si = i;
                sj = j;
            }
            if(s[j] == 'T')
            {
                ei = i;
                ej = j;
            }
            p[i][j].c = s[j];
            q[i][j].c = s[j];
        }
    }
}
void opt(Grid**& p,int r,int c)
{
    for(int i=0;i < r;i++)
    {
        for(int j=0;j < c;j++)
            cout <<p[i][j].s <<" ";
        cout <<endl;
    }
}
void optchar(Grid**& p,int r,int c)
{
    for(int i=0;i < r;i++)
    {
        for(int j=0;j < c;j++)
            cout <<p[i][j].c;
        cout <<endl;
    }
}
void DPS(Grid**& p,int i,int j,int r,int c)
{
    if(p[i][j].c == '#' || p[i][j].s == 1) return;
    p[i][j].s = 1;
    switch(p[i][j].c)
    {
    case '-':
        {
            if(j != 0)
                DPS(p,i,j-1,r,c);
            if(j != (c-1))
                DPS(p,i,j+1,r,c);
            break;
        }
    case '|':
        {
            if(i != 0)
                DPS(p,i-1,j,r,c);
            if(i != (r-1))
                DPS(p,i+1,j,r,c);
            break;
        }
    case '.':
        {
            if(i != (r-1))
                DPS(p,i+1,j,r,c);
            break;
        }
    default:
        {
            if(j != 0)
                DPS(p,i,j-1,r,c);
            if(j != (c-1))
                DPS(p,i,j+1,r,c);
            if(i != 0)
                DPS(p,i-1,j,r,c);
            if(i != (r-1))
                DPS(p,i+1,j,r,c);
            break;
        }
    }
}
int Count(Grid**& p,Grid**& q,int r,int c)
{
    int sum = 0;
    for(int i=0;i < r;i++)
        for(int j=0;j < c;j++)
        {
            init(q,r,c);
            if(p[i][j].s == 1 && q[i][j].c != 'T' && q[i][j].c != 'S')
            {
                DPS(q,i,j,r,c);
                if(q[ei][ej].s == 0)
                    sum++;
            }
        }
    return sum;
}
