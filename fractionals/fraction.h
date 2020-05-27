#pragma once

#include <iostream>
using namespace std;

class fraction

{
private:
	int num;
	int den;
public:
	fraction();
	fraction(int a, int b);
	int GetNum() const;
	void SetNum(int a);
	int GetDen() const;
	void SetDen(int a);

	fraction Simplify();
	fraction operator=(const fraction& tmp);
	fraction operator+(const fraction& tmp) const;
	fraction operator-(const fraction& tmp) const;
	fraction operator/(const fraction& tmp) const;
	fraction operator*(const fraction& tmp) const;
	bool operator!=(const fraction& tmp) const;
	bool operator==(const fraction& tmp) const;
	bool operator<(const fraction& tmp) const;
	bool operator>(const fraction& tmp) const;

	friend std::ostream& operator<< (std::ostream& out, const fraction& fraction);
	friend std::istream& operator>> (std::istream& in, fraction& fraction);
};
class complex : public fraction
{
private:
	fraction Re;
	fraction Im;
public:
	complex();
	void SetRe(fraction _Re);
	void SetIm(fraction _Im);

	fraction GetRe() const;
	fraction GetIm() const;

	complex Simplify();
	complex operator=(const complex& tmp);
	complex operator-(const complex& tmp) const;
	complex operator*(const complex& tmp) const;
	complex operator/(const complex& tmp) const;
	complex operator+(const complex& tmp) const;
	bool operator==(const complex& tmp) const;
	bool operator!=(const complex& tmp) const;

	complex(fraction _first, fraction _second);
	~complex();

	friend std::ostream& operator<< (std::ostream& out, const complex& complex);
	friend std::istream& operator>> (std::istream& in, complex& complex);
};