#include "traits/traits.hpp"
#include "fold/fold.hpp"
#include <iostream>
#include <algorithm>
#include <ranges>
#include <vector>

using std::cout, std::endl, std::vector;


int main()
{

	vector<int> vec {1, 2, 3, 4, 5, 6};

	cout << og::fold_left_first(vec, std::multiplies<int>()) << endl;

	return 0;
}
