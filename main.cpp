#include "traits.hpp"
#include <iostream>

using std::cout, std::endl;


template <bool val>
typename cocobolo::enable_if<val, int>::type
foo ()
{
	cout << "a" << endl;

	return 0;
}

constexpr bool p(int x)
{
	return x >= 0;
}

int main()
{
	cocobolo::conditional_t<p(-9), int, double> c = 5.3;

	foo<true>();

	return 0;
}
