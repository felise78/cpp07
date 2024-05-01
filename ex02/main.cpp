#include "Array.hpp"
#include <iostream>

# define GREY2  "\033[0;38;2;170;170;170m"
# define RESET	"\033[0m"
# define ITALIC "\033[3m"

int main() {
    try {

        // Test cases
        std::cout << "----------------------"  GREY2 ITALIC " Default constructor" RESET << std::endl;
        Array<double> arr1; // Default constructor
        std::cout << GREY2 "arr1 size: " << arr1.size() << RESET << std::endl; 
        
        std::cout << "\n----------------------"  GREY2 ITALIC " Constructor with param" RESET << std::endl;
        Array<double> arr2(5); // Constructor with size
        std::cout << GREY2 "arr2 size: " << arr2.size() << RESET << std::endl;
        std::cout << arr2 << std::endl;
        
        std::cout << "----------------------"  GREY2 ITALIC " Modified arr2 with subscript operator" RESET << std::endl;
        arr2[3] = 10.01; // Using subscript operator, does not compile if arr is const
        std::cout << arr2 << std::endl;

        std::cout << "\n----------------------"  GREY2 ITALIC " Copy constructor arr3(arr2)" RESET << std::endl;
        Array<double> arr3(arr2); // Copy constructor
        std::cout << GREY2 "arr3 size: " << arr3.size() << RESET << std::endl;
        std::cout << arr3 << std::endl;

        std::cout << "----------------------"  GREY2 ITALIC " Modify arr2" RESET << std::endl;
        arr2[3] = 42; // Using subscript operator, does not compile if arr is const
        std::cout << arr2 << std::endl;

        std::cout << "----------------------"  GREY2 ITALIC " Does not change arr3" RESET << std::endl;
        std::cout << arr3 << std::endl;
       
        std::cout << "\n----------------------"  GREY2 ITALIC " Assignement operator arr4 = arr2" RESET << std::endl;
        Array<double> arr4;
        arr4 = arr2; // Assignment operator
        std::cout << GREY2 "arr4 size: " << arr4.size() << RESET << std::endl;
        std::cout << arr4 << std::endl;

        std::cout << "----------------------"  GREY2 ITALIC " Modify arr4" RESET << std::endl;
        arr4[3] = 20.02; // Modifying arr3 using subscript operator , does not compile if arr is const
        std::cout << arr4 << std::endl;

        std::cout << "----------------------"  GREY2 ITALIC " Does not change arr2" RESET << std::endl;
        std::cout << arr2 << std::endl;

        // Trying to access out of bounds
        std::cout << "\n----------------------"  GREY2 ITALIC " Exception" RESET << std::endl;
        std::cout << arr2[10] << std::endl; // This line should throw an exception
    } catch (const std::exception& e) {
        std::cerr << ITALIC "Exception caught: " RESET << e.what() << std::endl;
    }

    return 0;
}