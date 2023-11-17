#pragma once

#include "MyMacros.h"
#include <compare>
#include <iostream>

class Drob
{
    public:
     Drob();
	Drob(ll n, ll d);
	Drob operator+(const Drob& right) const;
	Drob operator-(const Drob& right) const;
	Drob operator*(const Drob& right) const;
	Drob operator/(const Drob& right) const;
        bool operator==(const Drob& right) const;
	int operator<=>(const Drob& right) const;
	Drob& operator++();
        Drob operator++(int d);
	Drob& operator--();
        Drob operator--(int d);
	Drob& operator+=(const Drob& right);
	Drob& operator-=(const Drob& right);
	Drob& operator*=(const Drob& right);
	Drob& operator/=(const Drob& right);
	Drob operator-() const;
	Drob operator!() const;
	// std::istream& operator>>(std::istream& stream);
	// std::ostream& operator<<(std::ostream& stream) const;
        friend std::istream& operator>>(std::istream& stream, Drob& right);
        friend std::ostream& operator<<(std::ostream& stream, const Drob& right);
	[[nodiscard]] double ToDouble() const;
        [[nodiscard]] ll GetN() const;
        [[nodiscard]] ull GetD() const;
        void SetN(ll a);
        void SetD(ll d);
    private:
     void MakeBeaty();
     ll n_; //Числитель(Верх)
     ll d_; //Знаминатель(низ)
};


