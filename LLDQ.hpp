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
        list.clear();
    };

    // Core Insertion Operations
    void pushFront(const T& item) override{
        list.addHead(item);
    };
    void pushBack(const T& item) override{
        list.addTail(item);
    };

    // Core Removal Operations
    T popFront() override{
        
        if(list.getCount() == 0){
            throw std::runtime_error("Empty Dequeue");
        }
        T front = list.getHead()->data;
        list.removeHead();
        return front;
        
    };
    T popBack() override{

        if(list.getCount() == 0){
                throw std::runtime_error("Empty Dequeue");
        }
        T back = list.getTail()->data;
        list.removeTail();
        return back;
        
        
    };

    // Element Accessors
    const T& front() const override{
    
        if(list.getCount() == 0){
            throw std::runtime_error("Empty Dequeue");
        }
        return list.getHead()->data;
        
        
    };
    const T& back() const override{

        if(list.getCount() == 0){
            throw std::runtime_error("Empty Dequeue");
        }
        return list.getTail()->data;
        
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






