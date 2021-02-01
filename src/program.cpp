
#include <MainList.hpp>
#include <fstream>

int main() {
	MainList* listOfList = new MainList();
	
	/*		//Eger Sayilar.txt in parametrelere göre otomatik olusturulmasını istiyorsanız yorumdan cikarin//
	#pragma region CreateAndWrite
	int maxValue = 150, minValue = 1;
	int colMaxCount = 21,colMinCount = 3,rowCount=5;
	ofstream DocWrite("doc/Sayilar.txt");
	for(int row=0; row<rowCount;row++){
		int colNum=rand()% (colMaxCount - colMinCount + 1 ) + colMinCount ;
		(colNum % 2 == 0) ? colNum++:colNum;
		for(int col = 0; col <colNum; col++ ){
			DocWrite << to_string(rand()% (maxValue - minValue + 1 ) + minValue)+" " ;
		}
		DocWrite << endl;
	}
	DocWrite.close();
	#pragma endregion
	*/
	
	#pragma region Read
	ifstream DocRead("doc/Sayilar.txt");
  	string row = "";
  	if ( DocRead.is_open() ){
    	while ( getline(DocRead, row) ){
			//Satirin bosluk ile bitmediği durumda okuma hatalarının önüne gecer.
			if(row.back()!=' '){
				row+=' ';
			}
			int rowSize = 0;
			for (auto x : row) {
        	if (x == ' ')
            	rowSize++;
    		}
			string num = "";
			int *rowNums = new int[rowSize];
			CircularDoublyLinkedList* CDLList = new CircularDoublyLinkedList();
			
			int i = 0;
    		for (auto x : row) {
        		if (x == ' '){
        	    	rowNums[i]=stoi(num);
					//CDLList ->Add(stoi(num));
        	    	num = "";
					i++;
        		}
        		else {
        		    num = num + x;
        		}

    		}
			CDLList->AddMultiple(rowSize,rowNums);
			//cout<<*CDLList<<endl;
			listOfList->Add(CDLList);
			//cout<<endl;
    	}
    	DocRead.close();
	}
	#pragma endregion
	//cout << *listOfList << endl;
	listOfList->Caprazla();
	//cout << *listOfList << endl;
	cin.ignore();
	delete listOfList;
	return 0;
}