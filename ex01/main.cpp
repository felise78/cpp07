#include <iostream>
#include "iter.hpp"

int main ()
{
	// test with int
	int intArray[] = {1, 2, 3, 4, 5};
    iter(intArray, 5, print<int>);
    std::cout << std::endl;

    // test with double
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    iter(doubleArray, 5, print<double>);
    std::cout << std::endl;

    // test with string
    std::string strArray[] = {"Hello", "world", "from", "42"};
    iter(strArray, 4, print<std::string>);
    std::cout << std::endl;

	return 0;
}
