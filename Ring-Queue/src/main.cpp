
#include "Ring_Queue.hpp"
#include "RQ_Iterator.hpp"

#include <iostream>
#include <iterator>


int main()
{
    Ring_Queue<int, 4> rq;

    for(int i = 0; i < 10; ++i)
        rq.push_back(i * i);

    std::cout << "Ring Queue size: " << rq.size() << "\n";


    // auto p = rq.begin();

    std::cout << "Ring Queue elements:\n";
    std::copy(rq.begin(), rq.end(), std::ostream_iterator<int>(std::cout, "\n"));
    std::cout << "Done\n";
    

    return 0;
}
