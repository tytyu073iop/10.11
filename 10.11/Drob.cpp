#include "Drob.h"
#include <iostream>

Drob::Drob(ll n, ll d) : n(n) {
	if (d < 0)
	{
		-n;
		-d;
		d = static_cast<ull>(d);
	}
	else {
		d = d;
	}
}

Drob Drob::operator+(Drob right) const {
	Drob result = Drob();
	try
	{
		result.n = right.d * n + d * right.n;
		result.d = d * right.d;
	}
	catch (...)
	{
		throw "Currently unavaliable";
	}
	return result;
}

Drob Drob::operator-(Drob right) const {
	Drob result = Drob();
	Drob result = Drob();
	try
	{
		result.n = right.d * n - d * right.n;
		result.d = d * right.d;
	}
	catch (...)
	{
		throw "Currently unavaliable";
	}
	return result;
}

Drob Drob::operator*(Drob right) const {
	Drob result = Drob();
	try
	{
		result.n = n * right.n;
		result.d = d * right.n;
	}
	catch (...)
	{
		throw "Too big numbers";
	}
}

Drob Drob::operator/(Drob right) const {
	Drob result
}