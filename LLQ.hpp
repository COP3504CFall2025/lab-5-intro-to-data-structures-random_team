#pragma once

#include "Interfaces.hpp"
#include "LinkedList.hpp"
#include <stdlib.h>
#include <stdexcept>

template <typename T>
class LLQ : public QueueInterface<T> {
private:
    LinkedList<T> list;
public:
    // Constructor
    LLQ(){
        list.clear();
    };

    // Insertion
    void enqueue(const T& item) override{
        list.AddTail(item);
    };

    // Deletion
    T dequeue() override{
        T front = list.getHead()->data;
        list.removeHead();
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

    void PrintForward(){
        list.PrintForward();
    };

    void PrintReverse(){
        list.PrintReverse();
    };


};