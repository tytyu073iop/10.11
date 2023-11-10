#pragma once

#include "MyMacros.h"
#include <compare>
#include <iostream>

class Drob
{
public:
	Drob();
	Drob(ll n, ll d);
	Drob operator+(Drob right) const;
	Drob operator-(Drob right) const;
	Drob operator*(Drob right) const;
	Drob operator/(Drob right) const;
	// auto operator<=>(Drob right) const;
	Drob& operator++();
	Drob& operator--();
	Drob& operator+=(Drob right);
	Drob& operator-=(Drob right);
	Drob& operator*=(Drob right);
	Drob& operator/=(Drob right);
	Drob& operator-();
	Drob operator!() const;
	std::istream& operator>>(std::istream& stream);
	std::ostream& operator<<(std::ostream& stream) const;
	ll n; //Числитель(Верх)
	ull d; //Знаминатель(низ)
	double to_double() const;
	void make_beaty();
private:
	
};