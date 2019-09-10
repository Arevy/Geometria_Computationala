#include <iostream>
#include <vector>

using namespace std;

struct Punct
{
    int x, y;
};

int puncte_identice (Punct A, Punct B)
{
    if (A.x == B.x && A.y == B.y)
        return 1;
    return 0;
}

float arie_triunghi (Punct A, Punct B, Punct C)
{
    float arie;
    arie = ( (A.x - C.x) * (B.y - A.y) - (A.x - B.x) * (C.y - A.y) );
    if (arie > 0)
        return arie;
    return -arie;
}


int interiorul_triunghiului (Punct P, Punct A, Punct B, Punct C)
{
    if (arie_triunghi(A, B, C) == arie_triunghi (P, A, B) + arie_triunghi (P, B, C) + arie_triunghi (P, A, C))
        return 1;
    return 0;
}


int Pozitie_FataDeDreapta (Punct P, Punct A, Punct B)
{
    int d;
    d = (P.x - A.x) * (B.y - A.y) - (P.y - A.y) * (B.x - A.x);
    return d;
}

int main ()
{
    Punct A1, A2, A3, A4;
    vector <Punct> P, M, I, J;
    int i;

    cout<<"Coordonate A1: ";
    cin>>A1.x>>A1.y;
    cout<<"Coordonate A2: ";
    cin>>A2.x>>A2.y;
    cout<<"Coordonate A3: ";
    cin>>A3.x>>A3.y;
    cout<<"Coordonate A4: ";
    cin>>A4.x>>A4.y;
    P.push_back(A1);
    P.push_back(A2);
    P.push_back(A3);
    P.push_back(A4);

    // Cazul I: TR(A1, A2, A3)
    if (!( interiorul_triunghiului(A4, A1, A2, A3) == 1))
        M.push_back(A4);
    // Cazul II: TR(A1, A2, A4)
    if (!( interiorul_triunghiului(A3, A1, A2, A4) == 1))
        M.push_back(A3);
    // Cazul III: TR(A2, A3, A4)
    if (!( interiorul_triunghiului(A1, A2, A3, A4) == 1))
        M.push_back(A1);
    // Cazul IV: TR(A1, A3, A4)
    if (!( interiorul_triunghiului(A2, A1, A3, A4) == 1))
        M.push_back(A2);

    if ( M.size() == 0 ) // daca NICIUN PUNCT NU E IN EXTERIOR --> segment
    {
        Punct Pmin, Pmax;
        int ind_min, ind_max;
        ind_min = 0;
        ind_max = 0;
        Pmin = A1;
        Pmax = A1;
        if ( A1.x == A2.x == A3.x == A4.x )
        {
            for (i=1; i<4; i++)
            {
                if (P[i].y < Pmin.y)
                {
                    ind_min = i;
                    Pmin.y = P[i].y;
                }
                if (P[i].y > Pmax.y)
                {
                    ind_max = i;
                    Pmax.y = P[i].y;
                }
            }
//        cout<<ind_min<<" "<<ind_max;
            for (i=0; i<4; i++)
                if ( i == ind_min || i == ind_max )
                    I.push_back (P[i]);
                else
                    J.push_back (P[i]);
        }
        else
        {
            for (i=1; i<4; i++)
            {
                if (P[i].x < Pmin.x)
                {
                    ind_min = i;
                    Pmin.x = P[i].x;
                }
                if (P[i].x > Pmax.x)
                {
                    ind_max = i;
                    Pmax.x = P[i].x;
                }
            }
       // cout<<ind_min<<" "<<ind_max;
            for (i=0; i<4; i++)
                if ( i == ind_min || i == ind_max )
                    I.push_back (P[i]);
                else
                    J.push_back (P[i]);
        }
    }

    else
        if ( M.size() == 3 ) // daca TREI PUNCTE sunt in EXTERIOR --> triunghi
        {
            for ( i=0; i<4; i++ )
                if ( puncte_identice( P[i], M[0] ) || puncte_identice( P[i], M[1] ) || puncte_identice( P[i], M[2] ) )
                        I.push_back (P[i]);
                    else
                        J.push_back (P[i]);
        }
        else
        {
            // P0 P1    P0 P2   P0 P3   P1 P2   P1 P3   P2 P3
            if ( ((Pozitie_FataDeDreapta(P[2], P[0], P[1]) > 0) && (Pozitie_FataDeDreapta(P[3], P[0], P[1]) < 0))
            || ((Pozitie_FataDeDreapta(P[2], P[0], P[1]) < 0) && (Pozitie_FataDeDreapta(P[3], P[0], P[1]) > 0)) )
            {
                I.push_back (P[2]);
                I.push_back (P[3]);
                J.push_back (P[0]);
                J.push_back (P[1]);
            }
            else
                if ( ((Pozitie_FataDeDreapta(P[1], P[0], P[2]) > 0) && (Pozitie_FataDeDreapta(P[3], P[0], P[2]) < 0))
                || ((Pozitie_FataDeDreapta(P[1], P[0], P[2]) < 0) && (Pozitie_FataDeDreapta(P[3], P[0], P[2]) > 0)) )
                {
                    I.push_back (P[1]);
                    I.push_back (P[3]);
                    J.push_back (P[0]);
                    J.push_back (P[2]);
                }
                else
                    if ( ((Pozitie_FataDeDreapta(P[1], P[0], P[3]) > 0) && (Pozitie_FataDeDreapta(P[2], P[0], P[3]) < 0))
                    || ((Pozitie_FataDeDreapta(P[1], P[0], P[3]) < 0) && (Pozitie_FataDeDreapta(P[2], P[0], P[3]) > 0)) )
                    {
                        I.push_back (P[1]);
                        I.push_back (P[2]);
                        J.push_back (P[0]);
                        J.push_back (P[3]);
                    }
                    else
                        if ( ((Pozitie_FataDeDreapta(P[0], P[1], P[2]) > 0) && (Pozitie_FataDeDreapta(P[3], P[1], P[2]) < 0))
                        || ((Pozitie_FataDeDreapta(P[0], P[1], P[2]) < 0) && (Pozitie_FataDeDreapta(P[3], P[1], P[2]) > 0)) )
                        {
                            I.push_back (P[0]);
                            I.push_back (P[3]);
                            J.push_back (P[1]);
                            J.push_back (P[2]);
                        }
                        else
                            if ( ((Pozitie_FataDeDreapta(P[0], P[1], P[3]) > 0) && (Pozitie_FataDeDreapta(P[2], P[1], P[3]) < 0))
                            || ((Pozitie_FataDeDreapta(P[0], P[1], P[3]) < 0) && (Pozitie_FataDeDreapta(P[2], P[1], P[3]) > 0)) )
                            {
                                I.push_back (P[0]);
                                I.push_back (P[2]);
                                J.push_back (P[1]);
                                J.push_back (P[3]);
                            }
                            else
                                if ( ((Pozitie_FataDeDreapta(P[0], P[2], P[3]) > 0) && (Pozitie_FataDeDreapta(P[1], P[2], P[3]) < 0))
                                || ((Pozitie_FataDeDreapta(P[0], P[2], P[3]) < 0) && (Pozitie_FataDeDreapta(P[1], P[2], P[3]) > 0)) )
                                {
                                    I.push_back (P[0]);
                                    I.push_back (P[1]);
                                    J.push_back (P[2]);
                                    J.push_back (P[3]);
                                }
        }

    cout << "I = { ";
    for (i=0; i<I.size(); i++)
        cout<<"("<<I[i].x<<", "<<I[i].y<<" ) ";
    cout << "}"<<endl;
    cout << "J = { ";
    for (i=0; i<J.size(); i++)
        cout<<"("<<J[i].x<<", "<<J[i].y<<" ) ";
    cout << "}"<<endl;

    return 0;
}
