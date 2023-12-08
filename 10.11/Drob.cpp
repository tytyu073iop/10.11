#include "Drob.h"
#include <algorithm>
#include <iostream>
#include <numeric>

void Drob::MakeBeaty() {
        if (d_ == 0) {
            throw "zero in n"; //NOLINT: Don't care
        }
        if (d_ < 0)
	{
		n_ = -n_;
		d_ = -d_;
		//d = (d);
	}
	ll const g = std::gcd(n_, d_);
	n_ /= g;
	d_ /= g;
}

Drob::Drob() = default; //NOLINT: I dont' give a fuck

Drob::Drob(ll n, ll d) : n_(n), d_(d) {
	MakeBeaty();
}

bool Drob::operator==(const Drob &right) const {
    return ((*this - right).n_ == 0);
}

Drob Drob::operator+(const Drob& right) const {
	Drob result = Drob();
        ll const lcm = std::lcm(d_, right.d_);
        ll const d1 = lcm / d_;
        ll const d2 = lcm / right.d_;
	result.n_ = d1 * n_ + d2 * right.n_;
	result.d_ = lcm;
        result.MakeBeaty();
        return result;
}

Drob Drob::operator-(const Drob& right) const {
	Drob result = Drob();
        ll const lcm = std::lcm(d_, right.d_);
        ll const d1 = lcm / d_;
        ll const d2 = lcm / right.d_;
	result.n_ = d1 * n_ - d2 * right.n_;
	result.d_ = lcm;
	result.MakeBeaty();
	return result;
}

Drob Drob::operator*(const Drob& right) const {
	Drob result = Drob();
        ll const gcd = std::gcd(n_, right.d_);
        ll nc = n_ / gcd;
        ll nd = right.d_ / gcd;
        ll const gcd2 = std::gcd(right.n_, d_);
        nc *= (right.n_ / gcd2);
        nd *= (d_ / gcd2);
	result.n_ = nc;
	result.d_ = nd;
	result.MakeBeaty();
	return result;
}

Drob Drob::operator/(const Drob& right) const {
	Drob result = Drob();
        ll const gcdn = std::gcd(n_, right.n_);
        ll const gcdd = std::gcd(d_, right.d_);
	result.n_ = (n_ / gcdn) * (right.d_ / gcdd);
	result.d_ = (d_ / gcdd) * (right.n_ / gcdn);
	result.MakeBeaty();
	return result;
}

Drob& Drob::operator++() {
	n_++;
	MakeBeaty();
	return *this;
}

Drob Drob::operator++(int d) { //NOLINT: Dummy int
    Drob temp(*this);
    ++*this;
    return temp;
}

Drob& Drob::operator--() {
	n_--;
	MakeBeaty();
	return *this;
}

Drob Drob::operator--(int d) { //NOLINT: dum int
    Drob temp(*this);
    --*this;
    return temp;
}

Drob& Drob::operator+=(const Drob& right) {
	*this = *this + right;
	return *this;
}

Drob& Drob::operator-=(const Drob& right) {
	*this = *this - right;
	return *this;
}

Drob& Drob::operator*=(const Drob& right) {
        *this = *this * right;
	return *this;
}

Drob& Drob::operator/=(const Drob& right) {
        *this = *this / right;
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

Drob Drob::operator-() const {
    return {-n_, d_};
}

ll Drob::GetD() const {
    return d_;
}

ll Drob::GetN() const {
    return n_;
}
