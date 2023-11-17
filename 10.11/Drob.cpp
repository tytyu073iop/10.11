#include "Drob.h"
#include <algorithm>
#include <iostream>
#include <numeric>

void Drob::MakeBeaty() {
	ll const g = std::gcd(n_, d_);
	n_ /= g;
	d_ /= g;
}

Drob::Drob() = default; //NOLINT: I dont' give a fuck

Drob::Drob(ll n, ll d) : n_(n), d_(d) {
	if (d < 0)
	{
		n_ = -n_;
		d = -d;
		//d = (d);
	}
	MakeBeaty();
}

bool Drob::operator==(const Drob &right) const {
    return ((*this - right).n_ == 0);
}

Drob Drob::operator+(const Drob& right) const {
	Drob result = Drob();
	try
	{
		result.n_ = right.d_ * n_ + d_ * right.n_;
		result.d_ = d_ * right.d_;
	}
	catch (...)
	{
		throw "Currently unavaliable";
        }
        result.MakeBeaty();
        return result;
}

Drob Drob::operator-(const Drob& right) const {
	Drob result = Drob();
	try
	{
		result.n_ = right.d_ * n_ - d_ * right.n_;
		result.d_ = d_ * right.d_;
	}
	catch (...)
	{
		throw "Currently unavaliable";
	}
	result.MakeBeaty();
	return result;
}

Drob Drob::operator*(const Drob& right) const {
	Drob result = Drob();
	try
	{
		result.n_ = n_ * right.n_;
		result.d_ = d_ * right.d_;
	}
	catch (...)
	{
		throw "Too big numbers";
	}
	result.MakeBeaty();
	return result;
}

Drob Drob::operator/(const Drob& right) const {
	Drob result = Drob();
	try
	{
		result.n_ = n_ * right.d_;
		result.d_ = d_ * right.n_;
	}
	catch (...)
	{
		throw "Too big numbers";
	}
	result.MakeBeaty();
	return result;
}

Drob& Drob::operator++() {
	n_++;
	MakeBeaty();
	return *this;
}

Drob& Drob::operator--() {
	n_--;
	MakeBeaty();
	return *this;
}

Drob& Drob::operator+=(const Drob& right) {
	try
	{
		n_ = right.d_ * n_ + d_ * right.n_;
		d_ = d_ * right.d_;
	}
	catch (...)
	{
		throw "Currently unavaliable";
	}
	MakeBeaty();
	return *this;
}

Drob& Drob::operator-=(const Drob& right) {
	try
	{
		n_ = right.d_ * n_ - d_ * right.n_;
		d_ = d_ * right.d_;
	}
	catch (...)
	{
		throw "Currently unavaliable";
	}
	MakeBeaty();
	return *this;
}

Drob& Drob::operator*=(const Drob& right) {
	try
	{
		n_ = n_ * right.n_;
		d_ = d_ * right.d_;
	}
	catch (...)
	{
		throw "Too big numbers";
	}
	MakeBeaty();
	return *this;
}

Drob& Drob::operator/=(const Drob& right) {
	try
	{
		n_ = n_ * right.d_;
		d_ = d_ * right.n_;
	}
	catch (...)
	{
		throw "Too big numbers";
	}
	MakeBeaty();
	return *this;
}

std::ostream& operator<<(std::ostream& stream, const Drob& right) {
	stream << right.n_ << "/" << right.d_;
        return stream;
}

std::istream& operator>>(std::istream& stream, Drob& right) {
	stream >> right.n_ >> right.d_;
	right.MakeBeaty();
        return stream;
}

int Drob::operator<=>(const Drob& right) const {
    Drob const temp = *this - right;
    return static_cast<int>(temp.n_);
}

double Drob::ToDouble() const {
    return static_cast<double>(n_)/static_cast<double>(d_);
}

Drob Drob::operator!() const {
    return {d_, n_};
}
