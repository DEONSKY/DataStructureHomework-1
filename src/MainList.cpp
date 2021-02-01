
#include "MainList.hpp"
		
		void MainList::Reserve(int newCapacity){
			if(capacity>=newCapacity)
				return;
			CircularDoublyLinkedList** temp = new CircularDoublyLinkedList*[newCapacity];
			for(int i=0;i<length;i++)
				temp[i]=items[i];
			if(items!=NULL)
				delete[] items;
			items=temp;
			capacity=newCapacity;
		}

		MainList::MainList(){
			length=0;
			capacity=0;
			items=NULL;
		}
		int MainList::Size() const{
			return length;
		}
		bool MainList::IsEmpty() const{
			return Size()==0;
		}
		void MainList::Add( CircularDoublyLinkedList* yeni){
			Insert(length,yeni);
		}
		void MainList::Insert(int i,  CircularDoublyLinkedList* yeni){
			if(i<0 || i>length)
				return;
			if(length >= capacity)
				Reserve(max(1,2*capacity));
			for(int j=length-1;j>=i;j--)
				items[j+1]=items[j];
			//items[i]=yeni;
			items[i]=yeni;
			length++;
		}
		void MainList::Clear(){
			length=0;
		}
		ostream& operator<<(ostream& screen, MainList& right){
			screen<<endl;
			string row = "";
			for(int i=0;i<right.Size();i++){
				screen << *right.items[i];
				if(i+1!=right.length)
					screen<<endl;
			}
			return screen;
		}
		/*
		string getData(){
		string data = "";
			string row = "";
			for(int i=0;i<length;i++){
				row+= items[i]->getOneCDLLData(1);
				if(i+1!=length)
					row+="\n";
			}
			return row;
		}*/
		CircularDoublyLinkedList* MainList::findMin(){
			CircularDoublyLinkedList* arMin = items[0];
			for(int i=0;i<length;i++){
				int data = items[i]->getOneCDLLData(1);
				if(arMin->getOneCDLLData(1) > data){
					arMin = items[i];
				}
			}
			
			return arMin;
		}
		CircularDoublyLinkedList* MainList::findMax(){
			CircularDoublyLinkedList* arMax = items[0] ;
			for(int i=0;i<length;i++){
				int data = items[i]->getOneCDLLData(1);
				if(arMax->getOneCDLLData(1) < data){
					arMax = items[i];
				}
			}
			return arMax;
		}
		void MainList::Caprazla(){
			CircularDoublyLinkedList* highestArr = findMax();
			CircularDoublyLinkedList* lowestArr = findMin();
			//int a=highestArr->getOneCDLLDataPrev(2);
			//cout<<a<<endl;
			highestArr->Capraz(highestArr,lowestArr);
			
		}
		MainList::~MainList(){
			if(items != NULL)
				delete[] items;
		}
