#pragma once
#include <iostream>
using namespace std;



template <typename T>
class LinkedList {
	struct Node {
		T data;
		Node* prev;
		Node* next;
	};
public:

	// Behaviors
	void printForward() const{
		Node* current = head;
		while(current != nullptr){
			std::cout<< current->data << std::endl;
			current = current->next;
		}
	};
	void printReverse() const{
		Node* current = tail;
		while(current != nullptr){
			std::cout<< current->data << std::endl;
			current = current->prev;
		}
	};

	// Accessors
	[[nodiscard]] unsigned int getCount() const{
		return count;
	};

	Node* getHead(){
		return head;
	};
	const Node* getHead() const{
		return head;
	};
	Node* getTail(){
		return tail;
	};
	const Node* getTail() const{
		return tail;
	};

	// Insertion
	void AddHead(const T& data){
		Node* h = new Node{data, nullptr, head};
		if(head != nullptr){
			head->prev = h;
		}else{
			tail = h;
		}
		head= h;
		++count;
	};
	void AddTail(const T& data){
		Node* t = new Node{data, tail, nullptr};
		if(tail != nullptr){
			tail->next = t;
		}else{
			head = t;
		}
		tail = t;
		++count;
	};

	// Removal
	bool RemoveHead(){
		if(head == nullptr){
			return false;
		}
		Node* second = head->next;
		if(second == nullptr){
			tail = nullptr;
			delete head;
			head = nullptr;
		}else{
			second->prev = nullptr;
			delete head;
			head = second;

		}
		--count;
		return true;
	};
	bool RemoveTail(){
		if(tail == nullptr){
			return false;
		}
		Node* second = tail->prev;
		if(second == nullptr){
			head = nullptr;
			delete tail;
			tail = nullptr;
		}else{
			second->next = nullptr;
			delete tail;
			tail = second;

		}
		--count;
		return true;
	};
	void clear(){
		
		while(count > 0){
			RemoveHead();
		}
		count = 0;
	};

	// Operators
	LinkedList<T>& operator=(LinkedList<T>&& other) noexcept{
		if(this == &other) return *this;
		clear();

		this->head = other.head;
		this->tail = other.tail;
		this->count = other.count;

		other.head = nullptr;
		other.tail = nullptr;
		other.count = 0;

		return *this;

	};
	LinkedList<T>& operator=(const LinkedList<T>& rhs){
		if(this == &rhs) return *this;
		clear();

		Node* current = rhs.head;
		while(current != nullptr){
			AddTail(current->data);
			current = current->next;
		}

		return *this;
	};

	// Construction/Destruction
	LinkedList():head(nullptr), tail(nullptr), count(0){};
	
	LinkedList(const LinkedList<T>& list)
	:head(nullptr), tail(nullptr), count(0){
		if(list.head == nullptr){
			return;
		}
		Node* current = list.head;
		while(current != nullptr){
			AddTail(current->data);
			current = current->next;
		}

	};
	LinkedList(LinkedList<T>&& other) noexcept:
	head(other.head), tail(other.tail), count(other.count){
		other.head = nullptr;
		other.tail = nullptr;
		other.count = 0;
	};
	~LinkedList(){
		clear();
	};

private:
	// Stores pointers to first and last nodes and count
	Node* head;
	Node* tail;
	unsigned int count;

};