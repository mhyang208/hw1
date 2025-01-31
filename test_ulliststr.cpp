#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite


int main(int argc, char* argv[])
{

    // test pushing to an empty list
    ULListStr test_ulliststr1;
    test_ulliststr1.push_front("0");

    // std::cout << "test";
    std::cout << test_ulliststr1.front() << std::endl;
    std::cout << test_ulliststr1.back() << std::endl;
    std::cout << test_ulliststr1.size() << std::endl;

    test_ulliststr1.clear();

    // test pushing to a list with space
    ULListStr test_ulliststr2;
    for (int i = 0; i < 5; i++)
        test_ulliststr2.push_front("0");

    std::cout << test_ulliststr2.size() << std::endl;
    // testing size of list
    std::cout << "get" << std::endl;
    std::cout << test_ulliststr2.get(4) << std::endl;
    // std::cout << test_ulliststr2.back() << std::endl;

    test_ulliststr2.clear();

    for (int i = 0; i < 5; i++)
        test_ulliststr2.push_back("0");


    std::cout << "Back" << std::endl;
    std::cout << test_ulliststr2.size() << std::endl;
    // testing size of list
    std::cout << "get" << std::endl;
    std::cout << test_ulliststr2.get(4) << std::endl;

    // test pushing to a list without space
    ULListStr test_ulliststr3;
    for (int i = 0; i < 10; i++)
        test_ulliststr3.push_front("0");

    std::cout << "get" << std::endl;
    std::cout << test_ulliststr3.get(9) << std::endl;
    std::cout << test_ulliststr3.size() << std::endl;

    test_ulliststr3.push_front("1");
    std::cout << "get" << std::endl;
    std::cout << test_ulliststr3.get(10) << std::endl;
    std::cout << test_ulliststr3.size() << std::endl;

    test_ulliststr3.clear();
    

    for (int i = 0; i < 10; i++)
        test_ulliststr3.push_back("0");

    std::cout << "Back" << std::endl;
    std::cout << "get" << std::endl;
    std::cout << test_ulliststr3.get(9) << std::endl;
    std::cout << test_ulliststr3.size() << std::endl;

    test_ulliststr3.push_back("1");
    std::cout << "get" << std::endl;
    std::cout << test_ulliststr3.get(10) << std::endl;
    std::cout << test_ulliststr3.size() << std::endl;

    // test front then back
    ULListStr test_ulliststr4;
    test_ulliststr4.push_front("0");
    test_ulliststr4.push_back("1");

    std::cout << std::endl;
    std::cout << "FrontBack" << std::endl;
    std::cout << "get" << std::endl;
    std::cout << test_ulliststr4.get(0) << std::endl;
    std::cout << "get" << std::endl;
    std::cout << test_ulliststr4.get(1) << std::endl;


}
