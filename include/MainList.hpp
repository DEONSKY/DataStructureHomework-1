
#ifndef MAINLIST_HPP
#define MAINLIST_HPP
#include "CircularDoublyLinkedList.hpp"

class MainList{
	private:
		CircularDoublyLinkedList** items;
		int length;
		int capacity;
		
		void Reserve(int newCapacity);
	public:
		MainList();
		int Size() const;
		bool IsEmpty() const;
		void Add( CircularDoublyLinkedList* yeni);
		void Insert(int i,  CircularDoublyLinkedList* yeni);
		const int& First();
		void Clear();
		friend ostream& operator<<(ostream& screen, MainList& right);
		CircularDoublyLinkedList* findMin();
		CircularDoublyLinkedList* findMax();
		void Caprazla();
		~MainList();
};
#endif