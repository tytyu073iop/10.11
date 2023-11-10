#include "Drob.h"
#include <iostream>
#include <numeric>
#include <algorithm>

void Drob::make_beaty() {
	ll g = std::gcd(n, d);
	n /= g;
	d /= g;
}

Drob::Drob() {
	
}

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
	make_beaty();
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
	result.make_beaty();
	return result;
}

Drob Drob::operator-(Drob right) const {
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
	result.make_beaty();
	return result;
}

Drob Drob::operator*(Drob right) const {
	Drob result = Drob();
	try
	{
		result.n = n * right.n;
		result.d = d * right.d;
	}
	catch (...)
	{
		throw "Too big numbers";
	}
	result.make_beaty();
	return result;
}

Drob Drob::operator/(Drob right) const {
	Drob result = Drob();
	try
	{
		result.n = n * right.d;
		result.d = d * right.n;
	}
	catch (...)
	{
		throw "Too big numbers";
	}
	result.make_beaty();
	return result;
}

Drob& Drob::operator++() {
	n++;
	make_beaty();
	return *this;
}

Drob& Drob::operator--() {
	n--;
	make_beaty();
	return *this;
}

Drob& Drob::operator+=(Drob right) {
	try
	{
		n = right.d * n + d * right.n;
		d = d * right.d;
	}
	catch (...)
	{
		throw "Currently unavaliable";
	}
	make_beaty();
	return *this;
}

Drob& Drob::operator-=(Drob right) {
	try
	{
		n = right.d * n - d * right.n;
		d = d * right.d;
	}
	catch (...)
	{
		throw "Currently unavaliable";
	}
	make_beaty();
	return *this;
}

Drob& Drob::operator*=(Drob right) {
	try
	{
		n = n * right.n;
		d = d * right.d;
	}
	catch (...)
	{
		throw "Too big numbers";
	}
	make_beaty();
	return *this;
}

Drob& Drob::operator/=(Drob right) {
	try
	{
		n = n * right.d;
		d = d * right.n;
	}
	catch (...)
	{
		throw "Too big numbers";
	}
	make_beaty();
	return *this;
}

std::ostream& Drob::operator<<(std::ostream& stream) const {
	stream << n << "/" << d;
}

std::istream& Drob::operator>>(std::istream& stream) {
	stream >> n >> d;
	make_beaty();
}

Drob operator!() const{

}