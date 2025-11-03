#ifdef MAIN

#include "ABDQ.hpp"
#include "ABQ.hpp"
#include "ABS.hpp"
#include "Interfaces.hpp"
#include "LinkedList.hpp"
#include "LLDQ.hpp"
#include "LLQ.hpp"
#include "LLS.hpp"
#include <iostream>

/*
    - LEAVE THE IFDEF GUARDS TO KEEP YOUR MAIN WITHOUT CONFLICTING WITH GRADESCOPE!
    - Test your code in this main and run locally with the RunMain configuration in CLion, or
    through your own command line compilation. Make sure to add flag "-DMAIN" to your compilation so this
    main function can compile.

*/

int main() {
    ABDQ<int> test;
    for (int i = 1; i < 10; i++)
        if (i % 2 == 0)
            test.pushBack(i);
        else
            test.pushFront(i);
    test.printForward();
    std::cout << "Capacity: " << test.getMaxCapacity() << std::endl;
    std::cout << "Size:" << test.getSize() << std::endl;
    std::cout << "Front: " << test.front() << " Back: " << test.back()  << std::endl;
    test.popFront();
    test.popBack();
    test.printForward();
    
    std::cout << "Capacity: " << test.getMaxCapacity() << std::endl;
    std::cout << "Size:" << test.getSize() << std::endl;

    std::cout << "Front: " << test.front() << " Back: " << test.back()  << std::endl;

    test.popFront();
    test.popFront();
    test.popFront();
    test.popFront();

    test.printForward();
    std::cout << "Capacity: " << test.getMaxCapacity() << std::endl;
    std::cout << "Size:" << test.getSize() << std::endl;
    std::cout << "Front: " << test.front() << " Back: " << test.back()  << std::endl;
    
    test.popFront();
    test.popBack();
    test.printForward();
    std::cout << "Capacity: " << test.getMaxCapacity() << std::endl;
    std::cout << "Size:" << test.getSize() << std::endl;
    std::cout << "Front: " << test.front() << " Back: " << test.back()  << std::endl;
    return 0;
}


#endif