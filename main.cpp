#include "traits.hpp"
#include <iostream>

using std::cout, std::endl;


class A
{
	virtual ~A();
};

int main()
{

	cout << og::is_polymorphic_v<A> << endl;

	return 0;
}
