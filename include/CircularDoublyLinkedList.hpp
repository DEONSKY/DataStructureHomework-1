
#ifndef CircularDoublyLinkedList_HPP
#define CircularDoublyLinkedList_HPP
#include <iostream>
#include "Iterator.hpp"
using namespace std;

class CircularDoublyLinkedList {
private:
	Node* middleOfList;
	int size;
	Iterator IterateFromPrevIndex(int index) const ;
	Iterator IterateFromNextIndex(int index) const ;
	Iterator IterateFromFirstNode() const ;
public:
	CircularDoublyLinkedList() ;
	bool IsEmpty() const ;
	int Count() const ;
	void AddMultiple(int size,const int* list) ;
	void InsertItr(Iterator itr, const int& obj) ;
	void InsertPrevItr(Iterator itr, const int& obj) ;
	void RemoveAt(int index) ;
	void RemoveAtPrev(int index) ;
	void RemoveAtItr(Iterator itr) ;
	void RemoveAtPrevItr(Iterator itr) ;
	friend ostream& operator<<(ostream& screen, CircularDoublyLinkedList& list) ;
	static void Capraz(CircularDoublyLinkedList* highestArr,CircularDoublyLinkedList* lowestArr);
	int getOneCDLLData(int targetIndex);
	void Clear() ;
	~CircularDoublyLinkedList();
};
#endif