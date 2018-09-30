//#include<iostream>
//#include<cstdlib>
//using namespace std;
///*
//    输入n手操作
//    summon <position> <attack> <health>
//    attack <attacker> <defender>
//    end
//*/
//class Servant
//{
//public:
//    int blood;
//    int strength;
//    Servant(){blood = -1;strength = -1;}
//    Servant(int blood,int strength){this->blood=blood;this->strength=strength;}
//};
//class Hero:Servant
//{
//public:
//    Servant servants[8];
//    int count_of_servant;
//    Hero(){servants[0].blood = 30;servants[0].strength = 0;count_of_servant=0;}
//    void add_servant(Servant servant,int pos)
//    {
//        count_of_servant += 1;
//        int i = count_of_servant;
//        for(;i>pos;i--) servants[i] = servants[i-1];
//        servants[pos] = servant;
//    }
//    void sub_servant(int pos)
//    {
//        int i=pos;
//        for(;i<count_of_servant;i++)    servants[i] = servants[i+1];
//        count_of_servant -= 1;
//    }
//};
//void get_flag();
//void summon();
//bool attack();
//void next();
//void output();
////global
//Hero heros[3];
//int now = 1;
////平局
//bool b;
//int main()
//{
//    b = true;
//    get_flag();
//    output();
//    return 0;
//}
//
//void get_flag()
//{
//    int N;
//    cin >>N;
//    for(int i=0;i<N;i++)
//    {
//        string op;
//        cin >>op;
//        if(op == "summon")
//            summon();
//        else if(op == "attack")
//        {
//            if((b=attack()) == false)
//                break;
//        }
//        else
//            next();
//    }
//}
//
//void summon()
//{
//    int pos,attack,health;
//    cin >>pos >>attack >>health;
//    Servant s(health,attack);
//    heros[now].add_servant(s,pos);
//}
//bool attack()
//{
//    int attacker,defender;
//    cin >>attacker>>defender;
//    //减血
//    heros[now].servants[attacker].blood -= heros[3-now].servants[defender].strength;
//    heros[3-now].servants[defender].blood -= heros[now].servants[attacker].strength;
//    //随从死亡,移动随从
//    if(heros[now].servants[attacker].blood <= 0)
//        heros[now].sub_servant(attacker);
//    if(defender != 0)
//    {
//        if(heros[3-now].servants[defender].blood <= 0)
//            heros[3-now].sub_servant(defender);
//    }
//    if(heros[now].servants[0].blood <= 0 || heros[3-now].servants[0].blood <= 0)
//        return false;
//    return true;
//}
//void next()
//{
//    now = 3-now;
//}
//
//void output()
//{
//    if(b) cout<<0 <<endl;
//    else
//    {
//        if(heros[1].servants[0].blood <= 0)
//            cout <<-1 <<endl;
//        else if(heros[2].servants[0].blood <= 0)
//            cout <<1 <<endl;
//    }
//    cout <<heros[1].servants[0].blood <<endl;
//    cout <<heros[1].count_of_servant<<" ";
//    for(int i=1;i<=heros[1].count_of_servant;i++)
//        cout <<heros[1].servants[i].blood <<" ";
//
//    cout <<endl;
//
//    cout <<heros[2].servants[0].blood <<endl;
//    cout <<heros[2].count_of_servant<<" ";
//    for(int i=1;i<=heros[2].count_of_servant;i++)
//        cout <<heros[2].servants[i].blood <<" ";
//    cout <<endl;
//}
