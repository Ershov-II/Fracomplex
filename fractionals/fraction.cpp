#include "fraction.h"

fraction::fraction()
{
	this->SetNum(0);
	this->SetDen(1);
}

fraction::fraction(int a, int b)
{
	this->SetNum(a);
	this->SetDen(b);
}

int fraction::GetNum() const
{
	return this->num;
}




void fraction::SetNum(int a)
{
	this->num = a;

}

int fraction::GetDen() const
{
	return this->den;
}


void fraction::SetDen(int a)
{
	this->den = a;
}

fraction fraction::Simplify()
{
	int a = this->GetNum();
	int b = this->GetDen();
	if (a == 0) b = 1;
	if (a != 0)
	{
		if (a < 0)
		{
			a = a - (2 * a);
			b = b - (2 * b);
		}
		int checker = 2;
		while (checker < a)
		{
			if ((a % checker == 0) && (b % checker == 0))
			{
				a = a / checker;
				b = b / checker;
				checker = 1;
			}
			checker++;
		}
		if (b % a == 0)
		{
			b = b / a;
			a = 1;
		}
	}
	if ((a >= 0) && (b < 0))
	{
		a = a - 2 * a;
		b = b - 2 * b;
	}
	this->fraction::fraction(a, b);
	return*this;
}



fraction fraction::operator+(const fraction& tmp) const
{
	fraction f = fraction();
	int a1 = this->GetNum();
	int a2 = this->GetDen();
	int b1 = tmp.GetNum();
	int b2 = tmp.GetDen();
	int af = 0, bf = 0;

	if (a1 == 0)
	{
		af = b1;
		bf = b2;
	}
	else
	{
		if (b1 == 0)
		{
			af = a1;
			bf = a2;
		}
		else
		{
			af = (a1 * b2) + (a2 * b1);
			bf = a2 * b2;
		}
	}
	f.fraction::fraction(af, bf);
	f.Simplify();
	return f;
}
fraction fraction::operator-(const fraction& tmp) const
{
	fraction f = fraction();
	int a1 = this->GetNum();
	int a2 = this->GetDen();
	int b1 = tmp.GetNum();
	int b2 = tmp.GetDen();
	int af = 0, bf = 0;

	if (a1 == 0)
	{
		af = b1;
		bf = b2;
	}
	else
	{
		if (b1 == 0)
		{
			af = a1;
			bf = a2;
		}
		else
		{
			af = (a1 * b2) - (a2 * b1);
			bf = a2 * b2;
		}
	}
	f.fraction::fraction(af, bf);
	f.Simplify();
	return f;
}
fraction fraction::operator/(const fraction& tmp) const
{
	fraction f = fraction();
	int a1 = this->GetNum();
	int a2 = this->GetDen();
	int b1 = tmp.GetNum();
	int b2 = tmp.GetDen();
	int af, bf;
	if (a1 == 0)
	{
		af = 0;
		bf = 1;
	}
	else
	{
		af = a1 * b2;
		bf = a2 * b1;
	}

	f.fraction::fraction(af, bf);
	f.Simplify();
	return f;
}

fraction fraction::operator*(const fraction& tmp) const
{
	fraction f = fraction();
	int a1 = this->GetNum();
	int a2 = this->GetDen();
	int b1 = tmp.GetNum();
	int b2 = tmp.GetDen();
	int af, bf;
	if ((a1 == 0) || (b1 == 0))
	{
		af = 0;
		bf = 1;
	}
	else
	{
		af = a1 * b1;
		bf = a2 * b2;
	}

	f.fraction::fraction(af, bf);
	f.Simplify();
	return f;
}

bool fraction::operator!=(const fraction& tmp) const
{
	bool checker;
	fraction f1 = fraction(this->GetNum(), this->GetDen());
	f1.Simplify();
	fraction f2 = fraction(tmp.GetNum(), tmp.GetDen());
	f2.Simplify();
	if ((f1.GetNum() == f2.GetNum()) && (f1.GetDen() == f2.GetDen())) checker = false;
	else checker = true;
	return checker;
}

bool fraction::operator==(const fraction& tmp) const
{
	bool checker;
	fraction f1 = fraction(this->GetNum(), this->GetDen());
	f1.Simplify();
	fraction f2 = fraction(tmp.GetNum(), tmp.GetDen());
	f2.Simplify();
	if ((f1.GetNum() == f2.GetNum()) && (f1.GetDen() == f2.GetDen())) checker = true;
	else checker = false;
	return checker;
}

bool fraction::operator<(const fraction& tmp) const
{
	bool checker = NULL;
	int a1 = this->GetNum();
	int b1 = this->GetDen();
	int a2 = tmp.GetNum();
	int b2 = tmp.GetDen();
	a1 = a1 * b2;
	a2 = a2 * b1;
	b1 = b1 * b2;
	b2 = b1;
	if (a1 < a2) checker = true;
	if (a1 >= a2) checker = false;
	return checker;
}

bool fraction::operator>(const fraction& tmp) const
{
	bool checker = NULL;
	fraction f1 = fraction(this->GetNum(), this->GetDen());
	f1.Simplify();
	fraction f2 = fraction(tmp.GetNum(), tmp.GetDen());
	f2.Simplify();
	int a1 = f1.GetNum();
	int b1 = f1.GetDen();
	int a2 = f2.GetNum();
	int b2 = f2.GetDen();
	a1 = a1 * b2;
	a2 = a2 * b1;
	b1 = b1 * b2;
	b2 = b1;
	if (a1 > a2) checker = true;
	if (a1 <= a2) checker = false;
	return checker;
}

fraction fraction::operator=(const fraction& tmp)
{
	this->SetNum(tmp.GetNum());
	this->SetDen(tmp.GetDen());
	return*this;
}

complex::complex()
{
	this->Re = fraction(0, 1);
	this->Im = fraction(0, 1);
}

void complex::SetRe(fraction _Re)
{
	this->Re = _Re;
}

void complex::SetIm(fraction _Im)
{
	this->Im = _Im;
}

fraction complex::GetRe() const
{
	return this->Re;
}

fraction complex::GetIm() const
{
	return this->Im;
}

complex complex::Simplify()
{
	fraction a = this->GetRe();
	fraction b = this->GetIm();
	a.Simplify();
	b.Simplify();
	this->complex::complex(a, b);
	return*this;
}

complex complex::operator=(const complex& tmp)
{
	this->SetRe(tmp.GetRe());
	this->SetIm(tmp.GetIm());
	return*this;
}

complex complex::operator-(const complex& tmp) const
{
	fraction Re1 = fraction();
	fraction Re2 = fraction();
	fraction Im1 = fraction();
	fraction Im2 = fraction();
	fraction Ref = fraction();
	fraction Imf = fraction();
	Re1 = this->GetRe();
	Re2 = tmp.GetRe();
	Im1 = this->GetIm();
	Im2 = tmp.GetIm();
	Imf = Im1 - Im2;
	Ref = Re1 - Re2;
	complex end = complex(Ref, Imf);
	return end;
}

complex complex::operator*(const complex& tmp) const
{
	fraction Re1 = fraction();
	fraction Re2 = fraction();
	fraction Im1 = fraction();
	fraction Im2 = fraction();
	fraction Ref = fraction();
	fraction Imf = fraction();
	Re1 = this->GetRe();
	Re2 = tmp.GetRe();
	Im1 = this->GetIm();
	Im2 = tmp.GetIm();
	Ref = (Re1 * Re2) - (Im1 * Im2);
	Imf = (Im1 * Re2) + (Im2 * Re1);
	complex end = complex(Ref, Imf);
	return end;
}

complex complex::operator/(const complex& tmp) const
{
	fraction Re1 = fraction();
	fraction Re2 = fraction();
	fraction Im1 = fraction();
	fraction Im2 = fraction();
	fraction Ref = fraction();
	fraction Imf = fraction();
	Re1 = this->GetRe();
	Re2 = tmp.GetRe();
	Im1 = this->GetIm();
	Im2 = tmp.GetIm();
	Imf = ((Re1 * Re2) - (Im1 * Im2)) / ((Re2 * Re2) + (Im2 * Im2));
	Ref = ((Im1 * Re2) - (Re1 * Im2)) / ((Re2 * Re2) + (Im2 * Im2));
	complex end = complex(Ref, Imf);
	return end;
}

complex complex::operator+(const complex& tmp) const
{
	fraction Re1 = fraction();
	fraction Re2 = fraction();
	fraction Im1 = fraction();
	fraction Im2 = fraction();
	fraction Ref = fraction();
	fraction Imf = fraction();
	Re1 = this->GetRe();
	Re2 = tmp.GetRe();
	Im1 = this->GetIm();
	Im2 = tmp.GetIm();
	Imf = Im1 + Im2;
	Ref = Re1 + Re2;
	complex end = complex(Ref, Imf);
	return end;
}

bool complex::operator==(const complex& tmp) const
{
	complex cpl1 = complex(this->GetRe(), this->GetIm());
	complex cpl2 = complex(tmp.GetRe(), tmp.GetIm());
	bool checker = NULL;
	if ((cpl1.GetRe() == cpl2.GetRe()) && (cpl1.GetIm() == cpl2.GetIm()))
	{
		checker = true;
	}
	else checker = false;
	return checker;
}

bool complex::operator!=(const complex& tmp) const
{
	complex cpl1 = complex(this->GetRe(), this->GetIm());
	complex cpl2 = complex(tmp.GetRe(), tmp.GetIm());
	bool checker = NULL;
	if ((cpl1.GetRe() == cpl2.GetRe()) && (cpl1.GetIm() == cpl2.GetIm()))
	{
		checker = false;
	}
	else checker = true;
	return checker;
}

complex::complex(fraction _first, fraction _second)
{
	this->Re = _first;
	this->Im = _second;
}

complex::~complex()
{
	this->Re = fraction(0, 1);
	this->Im = fraction(0, 1);
}

std::ostream& operator<<(std::ostream& out, const fraction& fraction)
{
	out << fraction.num << "/" << fraction.den;
	return out;
}

std::istream& operator>>(std::istream& in, fraction& fraction)
{
	in >> fraction.num;
	in >> fraction.den;
	return in;
}

std::ostream& operator<<(std::ostream& out, const complex& complex)
{
	out << complex.Re << "+(" << complex.Im << "xi)";
	return out;
}

std::istream& operator>>(std::istream& in, complex& complex)
{
	in >> complex.Re;
	in >> complex.Im;
	return in;
}
