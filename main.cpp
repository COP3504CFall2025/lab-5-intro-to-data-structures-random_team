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

    ABQ<int> test;
    std::cout << "Size: "<< test.getSize() << std::endl;
    std::cout << "Capacity: "<< test.getMaxCapacity() << std::endl;
    test.enqueue(3);
    std::cout << "Size: "<< test.getSize() << std::endl;
    test.printForward();
    test.enqueue(4);
    std::cout << "Next" << std::endl;
    test.printForward();
    test.enqueue(5);
    test.enqueue(7);
    std::cout << "Capacity: "<< test.getMaxCapacity() << std::endl;
    std::cout << "First: "<< test.peek() << std::endl;
    test.enqueue(10);
    std::cout << "Size: "<< test.getSize() << std::endl;
    std::cout << "Capacity: "<< test.getMaxCapacity() << std::endl;
    test.printForward();
    test.printReverse();
    std::cout << "First: "<< test.peek() << std::endl;
    int deleted = test.dequeue();
    std::cout << "Size: "<< test.getSize() << std::endl;
    
    std::cout << "Popped: "<< deleted << std::endl;
    std::cout << "First: "<< test.peek() << std::endl;
    test.printForward();
    return 0;
}


#endif