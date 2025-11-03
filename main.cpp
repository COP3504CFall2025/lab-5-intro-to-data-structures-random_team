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
    LLS<int> test;
    test.push(2);
    test.push(3);
    test.push(4);
    test.printForward();
    test.pop();
    std::cout<<std::endl;
    std::cout<<test.peek() << std::endl;
    std::cout<<std::endl;
    test.printForward();
    test.pop();
    test.pop();
    test.pop();
    test.push(5);
    std::cout<<std::endl;
    test.printForward();
    

    return 0;
}


#endif