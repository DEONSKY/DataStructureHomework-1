
#include "CircularDoublyLinkedList.hpp"

	Iterator CircularDoublyLinkedList::IterateFromPrevIndex(int index) const {
		if (!(index < 0 || index > Count())) {
			int i = 0;
			Iterator itr(middleOfList);
			while ( index != i++)
				itr.StepNext();
			return itr;
		}
		return NULL;
	}
		Iterator CircularDoublyLinkedList::IterateFromNextIndex(int index) const {
		if (!(index < 0 || index > Count())) {
			int i = 0;
			Iterator itr(middleOfList);
			while ( index != i++){
				itr.StepBack();
			}
			return itr;
		}
		return NULL;
	}
	Iterator CircularDoublyLinkedList::IterateFromFirstNode() const {
		return Iterator(middleOfList);
	}

	//template<typename> friend class MainList;
	CircularDoublyLinkedList::CircularDoublyLinkedList() {
		middleOfList = new Node(int(),NULL,NULL);
		size = 0;
	}
	bool CircularDoublyLinkedList::IsEmpty() const {
		return middleOfList->next == NULL;
	}
	int CircularDoublyLinkedList::Count() const {
		return size;
	}
	void CircularDoublyLinkedList::AddMultiple(int size,const int* list) {
			int index = 0;
			Iterator itr;
			itr = IterateFromPrevIndex(0);
			InsertPrevItr(itr,list[0]);
			int i = 1;
			for (int j = i; i<(size+1)/2 ;i++){
				InsertPrevItr(itr,list[i]);
				itr.StepBack();
			}
			itr = IterateFromNextIndex(0);
			for (int z = i; z < size; z++)
			{
				InsertItr(itr,list[z]);
				itr.StepNext();
			}
			
	}
	void CircularDoublyLinkedList::InsertItr(Iterator itr, const int& obj) {

		if (size == 0) {
			//cout<< " - " <<middleOfList->next->next<< " - ";
			middleOfList->next = middleOfList;
			middleOfList->prev = middleOfList;
			middleOfList->data = obj;
		}else{
			Node* newNext = itr.current->next;
			itr.current->next = new Node(obj, newNext, itr.current);
			//cout<< " InsertNext : "<<itr.current->data<<" "<<itr.current->next->data<<endl;
			if (newNext != NULL) {
				newNext->prev = itr.current->next;
			}
		}
		size++;
	}
	void CircularDoublyLinkedList::InsertPrevItr(Iterator itr, const int& obj) {

		if (size == 0) {
			//middleOfList->next = itr.current->prev;
			//cout<< " - " <<middleOfList->prev<< " - ";
			middleOfList->prev = middleOfList;
			middleOfList->next = middleOfList;
			middleOfList->data = obj;
		}else{
			Node* newPrev = itr.current->prev;
			itr.current->prev = new Node(obj,itr.current,newPrev);
			//cout<< " InsertPrev : "<<itr.current->data<<" "<<itr.current->prev->data<<endl;
			if (newPrev != NULL) {
				newPrev->next = itr.current->prev;
			}
		}
		size++;
	}
	/*
	void Remove(const int& obj) {
		int index = IndexOf(obj);
		RemoveAt(index);
	}*/
	void CircularDoublyLinkedList::RemoveAt(int index) {
		Iterator itr;
		itr = IterateFromPrevIndex(index);
		if (itr.current->next != NULL) {
			Node* oldNode = itr.current->next;
			itr.current->next = itr.current->next->next;
			oldNode->next->prev = oldNode->prev;
			delete oldNode;
			if (index == 0)
				middleOfList->next->prev->next = middleOfList->next;
			size--;
			if (size == 0)
				itr.current->next = NULL;
		}
	}
	void CircularDoublyLinkedList::RemoveAtPrev(int index) {
		Iterator itr;
		itr = IterateFromNextIndex(index);
		if (itr.current->prev != NULL) {
			Node* oldNode = itr.current->prev;
			itr.current->prev = itr.current->prev->prev;
			oldNode->prev->next = oldNode->next;
			delete oldNode;
			if (index == 0)
				middleOfList->next->next->prev = middleOfList->next;
			size--;
			if (size == 0)
				itr.current->prev = NULL;
		}
	}
	void CircularDoublyLinkedList::RemoveAtItr(Iterator itr) {
		if (itr.current->next != NULL) {
			Node* oldNode = itr.current->next;
			//cout<<"RemoveNext : "<<oldNode->data<<endl;
			itr.current->next = itr.current->next->next;
			oldNode->next->prev = oldNode->prev;
			delete oldNode;
			size--;
			if (size == 0)
				itr.current->next = NULL;
		}
	}
	void CircularDoublyLinkedList::RemoveAtPrevItr(Iterator itr) {
		if (itr.current->prev != NULL) {
			Node* oldNode = itr.current->prev;
			//cout<<"RemovePrev : "<<oldNode->data<<endl;
			itr.current->prev = itr.current->prev->prev;
			oldNode->prev->next = oldNode->next;
			delete oldNode;
			size--;
			if (size == 0)
				itr.current->prev = NULL;
		}
	}
	ostream& operator<<(ostream& screen, CircularDoublyLinkedList& list) {
		if (list.IsEmpty())
			screen << "Liste bos";
		else {
			Iterator itr = list.IterateFromFirstNode();
			for(int i = 0;i<(list.size-1)/2; i++){
				itr.StepBack();
			}
			for (int index = 0; index < list.size; itr.StepNext(), index++)
				screen << to_string(itr.GetCurrentData()) << " ";
		}
		return screen;
	}
	void CircularDoublyLinkedList::Capraz(CircularDoublyLinkedList* highestArr,CircularDoublyLinkedList* lowestArr){
		
		int longLoop;
		int shortLoop;
		int lowestArrCount=lowestArr->Count();
		int highestArrCount=highestArr->Count();
		int lowestArrPossLoop=(lowestArrCount-1)/2;
		int highestArrPossLoop=(highestArrCount-1)/2;
		if(highestArrCount>lowestArrCount){
			longLoop=highestArrPossLoop;
			shortLoop=lowestArrPossLoop;
		}else{
			longLoop=lowestArrPossLoop;
			shortLoop=highestArrPossLoop;
		}
		#pragma region FirstHalf
		Iterator itrHigh= highestArr->IterateFromFirstNode();
		Iterator itrLow = lowestArr->IterateFromFirstNode();

		for(int i=0 ; i < longLoop ; i++){
			//cout<<shortLoop<<endl;
			if( i<shortLoop ){
				itrHigh.StepBack() , itrLow.StepNext();
				//cout<<itrHigh.current->data<<" : "<<itrLow.current->data<<endl;
				int tempHigh=itrHigh.current->data;
				itrHigh.current->data=itrLow.current->data;
				itrLow.current->data=tempHigh;
				
			}else{
				if(highestArrCount>lowestArrCount){

					int temp = itrHigh.current->prev->data;
					//cout<<" "<<temp<< " ";
					highestArr->RemoveAtPrevItr(itrHigh);
					lowestArr->InsertItr(itrLow,temp);
					itrLow.StepNext();
				}else{
					int temp = itrLow.current->next->data;
					lowestArr->RemoveAtItr(itrLow);
					highestArr->InsertPrevItr(itrHigh,temp);
					itrHigh.StepBack();
				}
			}
		}
		#pragma endregion

		#pragma region SecondHalf

		itrHigh= highestArr->IterateFromFirstNode();
		itrLow = lowestArr->IterateFromFirstNode();
		for(int i=0 ; i < longLoop ; i++){
			if( i<shortLoop ){
				itrLow.StepBack() , itrHigh.StepNext();
				//cout<<itrLow.current->data<<" : "<<itrHigh.current->data<<endl;
				int tempLow=itrLow.current->data;
				itrLow.current->data=itrHigh.current->data;
				itrHigh.current->data=tempLow;
				
			}else{
				if(highestArrCount<lowestArrCount){
					int tempi = itrLow.current->prev->data;
					//cout<<" "<<tempi<< " ";
					lowestArr->RemoveAtPrevItr(itrLow);
					highestArr->InsertItr(itrHigh,tempi);
					itrHigh.StepNext();
				}else{
					int temp = itrHigh.current->next->data;
					//cout<<" "<<temp<< " ";
					highestArr->RemoveAtItr(itrHigh);
					lowestArr->InsertPrevItr(itrLow,temp);
					itrLow.StepBack();
				}
			}
		}
		#pragma endregion
		cout<<"En Buyuk Liste Ort Deger Adresi :"<<highestArr->middleOfList->next<<endl;
		//cout<<highestArr->middleOfList->data<<endl;
		cout<<"En Buyuk Liste Degerler :"<<endl;
		cout<<*highestArr<<endl;
		cout<<"En Kucuk Liste Ort Deger Adresi :"<< lowestArr->middleOfList->next<<endl;
		//cout<<lowestArr->middleOfList->data<<endl;
		cout<<"En Kucuk Liste Degerler :"<<endl;
		cout<<*lowestArr<<endl;
	}
	int CircularDoublyLinkedList::getOneCDLLData(int targetIndex){
		int data;
		if (targetIndex<=size){
			int index = 0;
			for (Iterator itr = IterateFromFirstNode(); index < targetIndex; itr.StepNext(), index++)
				data = itr.GetCurrentData();
		}
		else {
			data = 0;
		}
		return data;
	}
	/*
	int getOneCDLLDataPrev(int targetIndex){
		targetIndex++;
		int data;
		if (targetIndex<=size){
			int index = 0;
			for (Iterator<Object> itr = IterateFromFirstNode(); index < targetIndex; itr.StepBack(), index++)
				data = itr.GetCurrentData();
		}
		else {
			data = 0;
		}
		return data;
	}*/
	void CircularDoublyLinkedList::Clear() {
		while (!IsEmpty()) {
			RemoveAt(0);
		}
	}
	CircularDoublyLinkedList::~CircularDoublyLinkedList() {
		Clear();
		delete middleOfList;
	}
