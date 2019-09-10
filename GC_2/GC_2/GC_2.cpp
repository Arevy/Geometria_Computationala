// GC_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
struct puncte {
	float x, y;
}A1,A2,A3,A4, I, J;
int main()
{
	int n, n1, ok=0;
	cout << "Introduceti coordonatele punctului A1: ";
	cin >> A1.x >> A1.y; cout << endl;
	cout << "Introduceti coordonatele punctului A2: ";
	cin >> A2.x >> A2.y; cout << endl;
	cout << "Introduceti coordonatele punctului A3: ";
	cin >> A3.x >> A3.y; cout << endl;
	cout << "Introduceti coordonatele punctului A4: ";
	cin >> A4.x >> A4.y; cout << endl;
	cout << "Care vrei sa fie I? A1,A2, A3, A4: ";cin >> n;cout << endl;
	if (n == 1)
	{
		I.x = A1.x;
		I.y = A1.y;
		ok = n;
	}
	else
		if (n == 2)
		{
			I.x = A2.x;
			I.y = A2.y;
			ok = n;
		}
		else
			if (n == 3)
			{
				I.x = A3.x;
				I.y = A3.y;
				ok = n;
			}
			else
				if (n == 4)
				{
					I.x = A4.x;
					I.y = A4.y;
					ok = n;
				}
				else
					cout << "nu ai ales corect" << endl;
	cout << "Acum sa-l alegem pe J, alege din cele ramase:";cin >> n1;cout << endl;
	if (n1 == n)
		cout << "L-ai ales pe I=J din greseala, alege altul" << endl;
	else
		if (n1 > 4)
			cout << "ai ales gresit" << endl;
		else
		{
			cout << "ai ales corect" << endl;ok = 1;
		}
	/*if (ok == 1)
	{

	}
	*/
	int pause;
	cin >> pause;
    return 0;
}

