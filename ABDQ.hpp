#pragma once
#include <iostream>
#include <cstddef>
#include <stdexcept>
#include "Interfaces.hpp"
#include <utility>

template <typename T>
class ABDQ : public DequeInterface<T> {
private:
    T* data_;                 // underlying dynamic array
    std::size_t capacity_;    // total allocated capacity
    std::size_t size_;        // number of stored elements
    std::size_t front_;       // index of front element
    std::size_t back_;        // index after the last element (circular)

    static constexpr std::size_t SCALE_FACTOR = 2;

public:
    // Big 5
    ABDQ(){
        capacity_ = 4;
        size_ = 0;
        front_ = 0;
        back_ = 0;
        data_ = new T[capacity_];
    };
    explicit ABDQ(std::size_t capacity){
        capacity_ = capacity;
        size_ = 0;
        front_ = 0;
        back_ = 0;
        data_ = new T[capacity_];
    };
    ABDQ(const ABDQ& other):
        data_(new T[other.capacity_]), capacity_(other.capacity_), size_(other.size_),  
        front_(other.front_), back_(other.back_){
        for(size_t i = 0; i<other.size_; ++i){
            data_[i] = other.data_[i];
        }
    };
    ABDQ(ABDQ&& other) noexcept:
    data_(other.data_), capacity_(other.capacity_), size_(other.size_),
    front_(other.front_), back_(other.back_){
        other.data_ = nullptr;
        other.capacity_ = 0;
        other.size_ = 0;
        other.back_ = -1;
        other.front_ = -1;
    };
    ABDQ& operator=(const ABDQ& other){
        if(this == &other) return *this;
        T* new_data_ = new T[other.capacity_];
        delete[] this->data_;

        this->data_ = new_data_;
        this->capacity_ = other.capacity_;
        this->size_ = other.size_;
        this->front_ = other.front_;
        this->back_ = other.back_;

        for(size_t i = 0; i<other.size_; ++i){
            data_[i] = other.data_[i];
        }

        return *this;
    };
    ABDQ& operator=(ABDQ&& other) noexcept{
        if(this == &other) return *this;

        delete[] this->data_;
        this->data_ = other.data_;
        this->capacity_ = other.capacity_;
        this->size_ = other.size_;
        this->front_ = other.front_;
        this->back_ = other.back_;

        other.data_ = nullptr;
        other.size_ = 0;
        other.capacity_ = 0;
        other.back_ = -1;
        other.front_ = -1;

        return *this;
    };
    ~ABDQ() override{
        delete[] data_;
        data_ = nullptr;
        capacity_ = 0;
        size_ = 0;
        front_ = -1;
        back_ = -1;
    };

    // Insertion
    void pushFront(const T& item) override{
        ensureCapacity();
        size_t index =(front_-1+capacity_)%capacity_;
        data_[index] = item;
        front_ = index;
        ++size_;
    };
    void pushBack(const T& item) override{
        ensureCapacity();
        size_t index = (front_+size_)%capacity_;
        data_[index] = item;
        back_ = index;
        ++size_;
    };

    // Deletion
    T popFront() override{
        if(size_ == 0){
            throw std::runtime_error("Empty Dequeue");
        }
        T first = data_[front_];
        
        front_ = (front_+1)%capacity_;
        --size_;
        shrinkIfNeeded();
        return first;
    };
    T popBack() override{
        if(size_ == 0){
            throw std::runtime_error("Empty Dequeue");
        }
        T last = data_[back_];
        back_ = (back_-1+capacity_)%capacity_;
        --size_;
        shrinkIfNeeded();
        return last;
    };

    void shrinkIfNeeded(){
        if(capacity_ >4 && size_*4<=capacity_){
            std::size_t oldCap = capacity_;
            capacity_/=2;
            T* newData = new T[capacity_];
            for(size_t i = 0; i<size_; ++i){
                newData[i] = data_[(i+front_)%oldCap];
            }
            delete [] data_;
            data_ = newData;
            front_ = 0;
            back_ = size_-1;
        }
    }
    // Access
    const T& front() const override{
        if(size_ == 0){
            throw std::runtime_error("Empty Dequeue");
        }
        
        return data_[front_];
    };
    const T& back() const override{
        if(size_ == 0){
            throw std::runtime_error("Empty Dequeue");
        }
        
        return data_[back_];
    };

    // Getters
    std::size_t getSize() const noexcept override{
        return size_;
    };

        // Get the max size of the ABS
    [[nodiscard]] size_t getMaxCapacity() const noexcept{
        return capacity_;
    };
    
    void printForward(){
        for(size_t i = 0; i<size_; ++i){
            std::cout << data_[(front_+i)%capacity_] << std::endl;
        }
    };

    void printReverse(){
        for(size_t i = 0; i<size_; ++i){
            std::cout << data_[(back_-i+capacity_)%capacity_] << std::endl;
        }
    };

    void ensureCapacity(){
        if(size_>= capacity_){
            std::size_t oldCap = capacity_;
            capacity_ *=SCALE_FACTOR;
            T* newData = new T[capacity_];
            for(size_t i = 0; i<oldCap; ++i){
                newData[i] = data_[(i+front_)%oldCap];
            }
            delete [] data_;
            data_ = newData;
            front_ = 0;
            back_ = oldCap-1;
        }

    };

};
