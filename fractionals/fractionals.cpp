#include <iostream>
#include "fraction.h"


int main()
{
	int key;
	fraction dr1 = fraction();
	fraction dr2 = fraction();
	fraction drf = fraction();
	complex cpl = complex();
	fraction ckR;
	fraction ckI;
	do
	{
		cout << "1. Fractionals\n2. Complex's:" << endl;
		cin >> key;
	} while (key < 1 || key >2);
	switch (key)
	{
	case 1:
		do
		{
			cout << "Input the first fractional (Numerator Denomenator):" << endl;
			cin >> dr1;
		} while (dr1.GetDen() == 0);
		do
		{
			cout << "Input the second fractional (Numerator Denomenator):" << endl;
			cin >> dr2;
		} while (dr2.GetDen() == 0);
		drf = dr1 + dr2;
		cout << "\nThe sum = " << drf << endl;
		drf = dr1 - dr2;

		cout << "\nThe difference = " << drf << endl;


		drf = dr1 / dr2;
		if (drf.GetDen() == 0) cout << "\nThe qoution is impossible to calculate." << endl;
		else
		{
			cout << "\nThe qoution = " << drf << endl;
		}
		drf = dr1 * dr2;
		cout << "\nThe production =" << drf << endl;
		if (dr1 != dr2)
		{
			cout << "\nThe fractionals are not equal" << endl;
			if (dr1 > dr2) cout << dr1 << " is bigger than " << dr2 << endl;
			if (dr2 > dr1) cout << dr2 << " is bigger than " << dr1 << endl;
		}
		if (dr1 == dr2) cout << "\nThe fractionals are equal" << endl;
		break;
	case 2:
		do
		{
			cout << "Input the first complex (Re Im):" << endl;
			cin >> cpl;
			ckR = cpl.GetRe();
			ckI = cpl.GetIm();
		} while ((ckR.GetDen() == 0) || (ckI.GetDen() == 0));
		complex cpl2 = complex();
		do
		{
			cout << "Input the second complex (Re Im):" << endl;
			cin >> cpl2;
			ckR = cpl2.GetRe();
			ckI = cpl2.GetIm();
		} while ((ckR.GetDen() == 0) || (ckI.GetDen() == 0));
		complex cpl3 = complex();
		cpl3 = cpl + cpl2;
		cout << "\nThe sum is " << cpl3 << endl;
		cpl3 = cpl - cpl2;
		cout << "\nThe difference is " << cpl3 << endl;
		cpl3 = cpl * cpl2;
		cout << "\nThe quotion is " << cpl3 << endl;
		cpl3 = cpl / cpl2;
		cout << "\nThe production is " << cpl3 << endl;
		if (cpl == cpl2) cout << cpl << " is equal to " << cpl2 << endl;
		if (cpl != cpl2) cout << cpl << " is not equal to " << cpl2 << endl;
		break;
	}
}