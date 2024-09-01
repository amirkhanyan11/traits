#include "traits.hpp"
#include <iostream>

using std::cout, std::endl;

constexpr bool p(int x)
{
	return x >= 0;
}

int main()
{

	cocobolo::conditional_t<p(-9), int, double> c = 5.3;

	cout << typeid(c).name() << endl;

	return 0;
}
