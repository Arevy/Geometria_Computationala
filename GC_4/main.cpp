#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>


using namespace std;

struct punct
{
    int x;
    int y;
};

int produs_scalar(punct a, punct b,punct c, punct d)
{
    int p,x1,y1,x2,y2;
    x1=b.x-a.x;
    y1=b.y-a.y;
    x2=d.x-c.x;
    y2=d.y-c.y;
    p=x1*x2+y1*y2;
    //cout<<"x1="<<x1<<endl;
    //cout<<"x2="<<x2<<endl;
    return p;
}
double norma(punct a, punct b)
{
    int x,y;
    double n;
    x=b.x-a.x;
    y=b.y-a.y;
    n=sqrt(x*x+y*y);
    return n;

}

int main()
{   ifstream f("date.in");
    vector<punct> a;
    punct q;
    int i,w;
    double b1,unghi1,b2,unghi2;
    for(i=0;i<4;i++)
    {
        f>>q.x;
        f>>q.y;
        a.push_back(q);
    }
    //cout<<"Caca="<<norma(a[1],a[2])*norma(a[1],a[0])<<endl;
    //cout<<"chestie="<<(produs_scalar(a[1],a[2],a[1],a[0]))<<endl;
    b1=(produs_scalar(a[1],a[2],a[1],a[0]))/(norma(a[1],a[2])*norma(a[1],a[0]));
    unghi1=acos(b1);
    //cout<<"u1="<<unghi1<<endl;

    b2=(produs_scalar(a[3],a[2],a[3],a[0]))/(norma(a[3],a[2])*norma(a[3],a[0]));
    unghi2=acos(b2);
    //cout<<"u2="<<unghi2<<endl;
    cout<<"pi="<<M_PI<<endl;
    cout<<"unghi="<<unghi1+unghi2<<endl;
    if(unghi1+unghi2==M_PI) cout<<"Punctul ("<<a[3].x<<","<<a[3].y<<") se afla pe cerc"<<endl;
    else if(unghi1+unghi2>M_PI) cout<<"Punctul ("<<a[3].x<<","<<a[3].y<<") se afla in interiorul cercului"<<endl;
    else cout<<"Punctul ("<<a[3].x<<","<<a[3].y<<") se afla in exteriorul cercului"<<endl;

    int d1=norma(a[0],a[1])+norma(a[2],a[3]);
    int d2=norma(a[1],a[2])+norma(a[0],a[3]);
    if(d1==d2) cout<<"Patrulaterul este circumscriptibil";
    else cout<<"nu este";

    return 0;
}
