#pragma once

#include <cstddef>
#include <stdexcept>
#include "Interfaces.hpp"
#include "LinkedList.hpp"
#include <utility>



template <typename T>
class LLDQ : public DequeInterface<T> {
private:
    LinkedList<T> list;

public:
    // Constructor
    LLDQ(){
        list.Clear();
    };

    // Core Insertion Operations
    void pushFront(const T& item) override{
        list.AddHead(item);
    };
    void pushBack(const T& item) override{
        list.AddTail(item);
    };

    // Core Removal Operations
    T popFront() override{
        try{
            if(list.getCount() == 0){
                throw std::runtime_error();
            }
            T front = list.getHead()->data;
            list.RemoveHead();
            return front;
        }
    };
    T popBack() override{
        try{
            if(list.getCount() == 0){
                throw std::runtime_error();
            }
            T back = list.getTail()->data;
            list.RemoveTail();
            return back;
        }
        
    };

    // Element Accessors
    const T& front() const override{
        try{
            if(list.getCount() == 0){
                throw std::runtime_error();
            }
            return list.getHead()->data;
        }
        
    };
    const T& back() const override{
        try{
            if(list.getCount() == 0){
                throw std::runtime_error();
            }
            return list.getTail()->data;
        }
    };

     //Getters
    std::size_t getSize() const noexcept override{
        return static_cast<std::size_t>(list.getCount());
    };

    void printForward(){
        list.PrintForward();
    };

    void printReverse(){
        list.PrintReverse();
    };
};






