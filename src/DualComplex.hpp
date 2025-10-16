#include <SFML/Graphics/Transform.hpp>
#include <complex>
#include <iostream>

struct	DualComplex
{
	std::complex<float> real;
	std::complex<float> dual;

	DualComplex(std::complex<float> r = {}, std::complex<float> d = {});
	DualComplex(double angleDeg, sf::Vector2<float> translation);

	DualComplex operator+(const DualComplex &other) const;
	DualComplex operator-(const DualComplex &other) const;
	DualComplex operator*(const DualComplex &other) const;
	DualComplex operator*(float scalar) const;
	bool operator==(const DualComplex &other) const;
	bool operator!=(const DualComplex &other) const;

	DualComplex normalize(void) const;
	sf::Transform toMat3(void) const;
};

std::ostream &operator<<(std::ostream &os, const DualComplex &dc);
