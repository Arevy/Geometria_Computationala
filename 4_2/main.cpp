#include <iostream>
#include<fstream>
#include<math.h>
#include<tgmath.h>
#define PI 3.14
using namespace std;
ifstream f("date.in");
ofstream g("date.out");
struct pct
{
    float x,y;
} v[5];
float arccosinus(struct pct a, struct pct b,struct pct c)
{
    float aux23x,aux23y,aux21x,aux21y;
    aux21x=a.x-b.x;
    aux21y=a.y-b.y;
    aux23x=c.x-b.x;
    aux23y=c.y-b.y;
    float rez,dist23,dist21;
    rez=aux21x*aux23x+aux23y*aux21y;
    dist21=sqrt(aux21x*aux21x+aux21y*aux21y);
    dist23=sqrt(aux23x*aux23x+aux23y*aux23y);
    float cosinus;
    cosinus=rez/(dist21*dist23);
    return acos(cosinus);

}
int circumscriptibil(struct pct a, struct pct b, struct pct c, struct pct d)
{
float d12,d34,d23,d14;
d12=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
d34=sqrt((c.x-d.x)*(c.x-d.x)+(c.y-d.y)*(c.y-d.y));
d23=sqrt((b.x-c.x)*(b.x-c.x)+(b.y-c.y)*(b.y-c.y));
d14=sqrt((a.x-d.x)*(a.x-d.x)+(a.y-d.y)*(a.y-d.y));
float rez1,rez2;
rez1=d12+d34;
rez2=d23+d14;
if(rez1==rez2)
return 1; else return 0;
}
int main()
{int i,n;
    cin>>n;
    for(i=1; i<=n; i++)

        cin>>v[i].x>>v[i].y;

float ceva1,ceva2;
ceva1=arccosinus(v[1],v[2],v[3]);
ceva1=ceva1*180/PI;
ceva2=arccosinus(v[3],v[4],v[1]);
ceva2=ceva2*180/PI;
cout<<ceva1<<" "<<ceva2<<endl;
if((int)ceva1+(int)ceva2<180)
    cout<<"Se afla in exteriorul cercului";
else if((int)ceva1+(int)ceva2==180)
        cout<<"Se afla pe cerc";
else g<<"Se afla in interiorul cercului";
cout<<endl<<endl;
if(circumscriptibil(v[1],v[2],v[3],v[4])==1)
    cout<<"Patrulaterul este circumscriptibil.";
else cout<<"Patrulaterul nu este circumscriptibil.";
    return 0;
}
