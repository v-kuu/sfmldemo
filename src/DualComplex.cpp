#include "DualComplex.hpp"

DualComplex::DualComplex(std::complex<float> r, std::complex<float> d)
	: real(r), dual(d)
{
}

DualComplex::DualComplex(double angleDeg, sf::Vector2<float> translation)
	: real(std::polar(1.0, (angleDeg * M_PI / 180))),
	dual(std::complex<float>(translation.x, translation.y) * real)
{
}

DualComplex DualComplex::operator+(const DualComplex &other) const
{
	return {real + other.real, dual + other.dual};
}

DualComplex DualComplex::operator-(const DualComplex &other) const
{
	return {real - other.real, dual - other.dual};
}

DualComplex DualComplex::operator*(const DualComplex &other) const
{
	return {real * other.real, real * other.dual + dual * other.real};
}

DualComplex DualComplex::operator*(float scalar) const
{
	return {real * scalar, dual * scalar};
}

bool DualComplex::operator==(const DualComplex &other) const
{
	return (real == other.real && dual == other.dual);
}

bool DualComplex::operator!=(const DualComplex &other) const
{
	return (real != other.real || dual != other.dual);
}

DualComplex DualComplex::normalize(void) const
{
	float norm = std::abs(real);
	if (norm != 0)
		return {real / norm, dual / norm};
	return (*this);
}

sf::Transform DualComplex::toMat3(void) const
{
	return {real.real(), -real.imag(), dual.real(),
			real.imag(), real.real(), dual.imag(),
			0.0, 0.0, 1.0};
}

std::ostream &operator<<(std::ostream &os, const DualComplex &dc)
{
	os << "{(" << dc.real.real() << " + " << dc.real.imag() << "ε) + ("
		<< dc.dual.real() << " + " << dc.dual.imag() << "ε)i";
	return (os);
}
