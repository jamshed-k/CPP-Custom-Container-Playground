
#include "Singly_Linked_List.hpp"
#include "List_Iterator.hpp"

#include <string>
#include <iostream>


int main()
{
    Singly_Linked_List<std::string> linked_list;


    linked_list.push_back("List of preliminary Bloodborne bosses:");
    linked_list.push_back("Cleric Beast");
    linked_list.push_back("Father Gascoigne");
    linked_list.push_back("Blood Starved Beast");

    linked_list.pop_front();


    List_Iterator<std::string> it = linked_list.begin();
    while(it != linked_list.end())
    {
        std::cout << *it << "\n";
        ++it;
    }

    linked_list.clear();

    linked_list.push_back("New list:");
    linked_list.push_back("Gibberish");

    it = linked_list.begin();
    while(it != linked_list.end())
    {
        std::cout << *it << "\n";
        ++it;
    }



    Singly_Linked_List<uint8_t> nums;
    for(uint8_t i = 0; i < 10; ++i)
        nums.push_front(i);

    auto it2 = nums.begin();
    while(it2 != nums.end())
    {
        std::cout << (int)*it2 << "\n";
        ++it2;
    }


    return 0;
}
