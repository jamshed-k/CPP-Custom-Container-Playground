
#include "Doubly_Linked_List.hpp"

#include <string>
#include <iostream>


int main()
{
    Doubly_Linked_List<int> lst;


    // Test `push_front`
    for(int i = 0; i < 10; ++i)
        lst.push_front(i);

    lst.print_forward();

    
    // Test `pop_front`
    while(!lst.empty())
        lst.pop_front();

    lst.print_forward();


    // Test `push_back`
    for(int i = 0; i < 10; ++i)
        lst.push_back(i);

    lst.print_forward();

    
    // Test `pop_back`
    while(!lst.empty())
        lst.pop_back();

    lst.print_forward();


    // Test `insert`
    for(int i = 0; i < 10; i += 2)
        lst.push_back(i);

    lst.print_forward();

    std::cout << "Inserted: " << *(lst.insert(lst.begin(), 3)) << "\n";
    std::cout << "Inserted: " << *(lst.insert(lst.begin(), 1)) << "\n";
    lst.print_forward();

    auto p = lst.begin();
    for(int  i = 0; i < 4; ++i)
        ++p;

    std::cout << "Inserted: " << *(lst.insert(p, 5)) << "\n";
    lst.print_forward();

    std::cout << "Inserted: " << *(lst.insert(lst.end(), 7)) << "\n";
    std::cout << "Inserted: " << *(lst.insert(lst.end(), 9)) << "\n";
    lst.print_forward();


    // Test `erase`
    auto q = lst.begin();
    q = q + 2;

    for(int i = 0; i < 2; ++i)
    {
        std::cout << "Deleting: " << *q << "\n";
        q = lst.erase(q);
        std::cout << "Next val: " << *q << "\n";
        lst.print_forward();
    }

    ++q;
    for(int i = 0; i < 3; ++i)
    {
        std::cout << "Deleting: " << *q << "\n";
        q = lst.erase(q);
        std::cout << "Next val: " << *q << "\n";
        lst.print_forward();
    }


    // Test `operator-`
    auto r = lst.begin();
    r = r + 4;
    std::cout << "Current val: " << *r << "\n";

    r = r - 4;
    std::cout << "Current val: " << *r << "\n";


    return 0;
}
