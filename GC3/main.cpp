// Fie Ai (xi, yi) in R^2, i = {1, 2, 3, 4}, distincte doua cate doua.
// Sa se determine intersectia dintre segmentele [A1 A2] si [A3 A4].

#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

struct Punct
{
    int x, y, indice;
};

int cmp1 (const void* A, const void* B)
{
    Punct A1, B1;
    A1=*(Punct*)A;
    B1=*(Punct*)B;
    return A1.x-B1.x;
}
int cmp2 (const void* A, const void* B)
{
    Punct A1, B1;
    A1=*(Punct*)A;
    B1=*(Punct*)B;
    return A1.y-B1.y;
}

int Orientare_Segm (Punct A1, Punct A2, Punct A3)
{
    int x;
    x = ( A2.y - A1.y ) * ( A3.x - A2.x ) - ( A2.x - A1.x ) * ( A3.y - A2.y );
    if ( x == 0 )
        return 0;           // coliniare
    if ( x > 0 )
        return 1;           // in sensul acelor de ceasornic
    return 2;               // in sens invers
}

int main  ()
{
    int i, x, y;
    vector < Punct > P;

    // Citim cele 4 puncte
    P.resize(4);
    for ( i = 0; i < 4; i++ )
    {
        cout<<"A"<<i+1<<": ";
        cin>>P[i].x>>P[i].y;
        P[i].indice = i+1;
    }

    // Aflam ecuatiile dreptelor A1 A2 si A3 A4
    int a1, b1, c1, a2, b2, c2;
    a1 = P[0].y - P[1].y;
    b1 = P[1].x - P[0].x;
    c1 = P[0].x * P[1].y - P[0].y * P[1].x;

    a2 = P[2].y - P[3].y;
    b2 = P[3].x - P[2].x;
    c2 = P[2].x * P[3].y - P[2].y * P[3].x;

    int D;
    float X, Y;
    D = a1*b2 - b1*a2;

    if (D != 0)
    {
        X = (float)( (-c1) * b2 - (-c2) * b1 ) / (float)D;
        Y = (float)( a1 * (-c2) - a2 * (-c1) ) / (float)D;
        // (X, Y) e punctul de intersectie al DREPTELOR, trebuie sa verificam daca este si al SEGMENTELOR
        if ((Orientare_Segm(P[0], P[1], P[2]) == 1 && Orientare_Segm(P[0], P[1], P[3]) == 2 ) ||
            (Orientare_Segm(P[0], P[1], P[2]) == 2 && Orientare_Segm(P[0], P[1], P[3]) == 1 ))
            {
                cout<<"Intersectia segmentelor este in punctul ("<<X<<", "<<Y<<")"<<endl;
                return 0;
            }
        if ((Orientare_Segm(P[2], P[3], P[0]) == 1 && Orientare_Segm(P[2], P[3], P[1]) == 2 ) ||
            (Orientare_Segm(P[2], P[3], P[0]) == 2 && Orientare_Segm(P[2], P[3], P[1]) == 1 ))
            {
                cout<<"Intersectia segmentelor este in punctul ("<<X<<", "<<Y<<")"<<endl;
                return 0;
            }
    }
    else
    {
        // Aflam rangul matricei extinse
        int D1, D2;
        D1 = a1*c2 - c1*a2;
        D2 = b1*c2 - c1*b2;
        if (D1 != 0 || D2 != 0)
            // RANG = 2
        {
            cout<<"Segmentele nu se intersecteaza.";
            return 0;
        }
        else
        {
            // RANG = 1, dreptele coincid
                if (P[0].x == P[1].x && P[1].x == P[2].x && P[2].x == P[3].x)
                    qsort (&P[0], P.size(), sizeof(Punct), cmp2);
                else
                    qsort (&P[0], P.size(), sizeof(Punct), cmp1);
                if ( (P[0].indice == 1 && P[1].indice == 2 && P[2].indice == 3 && P[3].indice == 4) ||
                (P[0].indice == 2 && P[1].indice == 1 && P[2].indice == 3 && P[3].indice == 4) ||
                (P[0].indice == 1 && P[1].indice == 2 && P[2].indice == 4 && P[3].indice == 3) ||
                (P[0].indice == 2 && P[1].indice == 1 && P[2].indice == 4 && P[3].indice == 3) )
                {
                    cout<<"Segmentele nu se intersecteaza.";
                    return 0;
                }
                else
                {
                    cout<<"Intersectia segmentelor este segmentul cu capetele A"<<P[1].indice<<" si A"<<P[2].indice<<endl;
                    return 0;
                }
        }

    }
    cout<<"Segmentele nu se intersecteaza.";
    return 0;
}
