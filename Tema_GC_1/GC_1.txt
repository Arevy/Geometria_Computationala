// Tema_GC_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
struct punct {
	float x, y, z;
}A1, A2, A3;
int main()
{
	cout << "Introduceti coordonatele punctului A1: "; 
	cin >> A1.x >> A1.y >> A1.z; cout<< endl;
	cout << "Introduceti coordonatele punctului A2: ";
	cin >> A2.x >> A2.y >> A2.z; cout << endl;
	cout << "Introduceti coordonatele punctului A3: ";
	cin >> A3.x >> A3.y >> A3.z; cout << endl;

	int ok = 0, k1 = 0, k2 = 0, k3 = 0, c = 0;
	
	if (A1.x == A2.x && A1.y == A2.y && A1.z == A2.z)
	{
		cout << "A1 si A2 coincid" << endl;c = 1;
	}
	if (A1.x == A3.x && A1.y == A3.y && A1.z == A3.z)
	{
		cout << "A1 si A3 coincid" << endl;c = 2;
	}
	if (A2.x == A3.x && A2.y == A3.y && A2.z == A3.z)
	{
		cout << "A2 si A3 coincid" << endl;c = 3;
	}
	
//	if (A3.y != A1.y && A2.y != A1.y && A3.x != A1.x && A2.x != A1.x && A3.z != A1.z && A2.z != A1.z && c == 0)
	if (c == 0)
	{
		float a;
		
		if ((A1.x - A2.x) != 0 )
		{
			a = (A3.x - A1.x) / (A2.x - A1.x);
			
			if ((A3.y - A1.y) == a*(A2.y - A1.y) && ((A3.z - A1.z) == a*(A2.z - A1.z)))
			{
				ok = 1;k1 = 1;
			}
		}
		
		if ((A1.y - A2.y) != 0  )
		{
			a = (A3.y - A1.y) / (A2.y - A1.y);
			if ((A3.x - A1.x) == a*(A2.x - A1.x) && ((A3.z - A1.z) == a*(A2.z - A1.z)))
			{
				ok = 1;k2 = 1;
			}
		}
		
		if ((A1.z - A2.z) != 0 )
		{
			a = (A3.z - A1.z) / (A2.z - A1.z);
			if ((A3.y - A1.y) == a*(A2.y - A1.y) && ((A3.x - A1.x) == a*(A2.x - A1.x)))
			{
				ok = 1;k3 = 1;
			}
		}
		
		/* if(A1.x != A2.x || A1.y != A2.y || A1.z !=A2.z)
			 */
		//k1 = 1;
		//a = (A3.x - A1.x) / (A2.x - A1.x);cout << a << endl;
		if (k1 == 1 || k2 == 1 || k3 == 1)
		{
			cout << "sunt coliniare " << endl; ok = -1;
		}
		else
			cout << " nu sunt coliniareee ";
		if (ok == -1)
			if ((1 - a) > 0)
				cout << " A3 = " << a << " * A2 +" << 1 - a << " * A2";
			else
				cout << " A3 = " << a << " * A2 " <<  1 - a << " * A2";
	}
	else
	{
		if(c==1)
			cout << " punctele sunt coliniare: A1=1*A2+0*A3 " << endl;
		else
			if(c==2)
				cout << " punctele sunt coliniare: A1=0*A2+1*A3 " << endl;
			else
				if(c==3)
					cout << " punctele sunt coliniare: A3=1*A2+0*A1 " << endl;
				else
					cout << " nu sunt coliniare";
	
	}
	
	/* punct M;

	M.x=A3.x-A1.x;
	M.y=A3.y-A1.y;
	M.z=A3.z-A1.z;

	punct N;

	N.x=A2.x-A1.x;
	N.y=A2.y-A1.y;
	N.z=A2.z-A1.z;

	if(M.x == (N.x*a) && (M.y == (N.y *a)) && (M.z == (N.z *a)))
	cout<<"punctele sunt coliniare";
	else
	cout<<"punctele nu sunt coliniare";
	*/
	int pause = 0;
	cin >> pause;
	return 0;
}
