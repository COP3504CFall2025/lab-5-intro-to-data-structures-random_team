#pragma once

#include "Interfaces.hpp"
#include "LinkedList.hpp"
#include <stdlib.h>
#include <stdexcept>

template <typename T>
class LLS : public StackInterface<T> {
private:
    LinkedList<T> list;
public:
    // Constructor
    LLS(){
        list.clear();
    };

    // Insertion
    void push(const T& item) override{
        list.AddHead(item);
    };

    // Deletion
    T pop() override{
        T front = list.getHead()->data;
        list.RemoveHead();
        return front;
    };

    // Access
    T peek() const override{
        return list.getHead()->data;
    };

    //Getters
    std::size_t getSize() const noexcept override{
        return static_cast<std::size_t>(list.getCount());
    };

    void printForward(){
        list.printForward();
    };

    void printReverse(){
        list.printReverse();
    };
};