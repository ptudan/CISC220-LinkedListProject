/*
 * lab3main.cpp
 *
 *  Created on: Feb 26, 2015
 *      Author: Paul Tudan
 */

//#include <iostream>
//#include <stdlib.h>

#include "SLL.hpp"
#include "SNode.hpp"
#include "DLL.hpp"
#include "DNode.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
	srand(time(NULL));
	
	/*cout << "SLL" << endl;
// Testing SLL
	SLL *list = new SLL;
	cout<<"Testing addFirst"<<endl;
	list->addFirst(rand()%50);
	list->printSLL();
	
	cout<<" "<<endl;
	cout<<"Testing push"<<endl;
	for (int i = 0; i < 10; i++) {
		if (i == 5) {
			cout<<" "<<endl;
			cout<<"Adding 42 at position 5"<<endl;
			list->push(42);
			i++;
		}
		else {
			list->push(rand()%50);
		}
		list->printSLL();
	}
	
	cout<<"Testing findKth and findK"<<endl;
	SNode *s = list->findKth(6);
	int y = s->getData();
	cout << y << endl;
	int x = list->findK(42);
	cout << x << endl;
	
	cout<<" "<<endl;
	cout<<"Testing addAtK"<<endl;
	list->addAtK(55,4);
	list->printSLL();
	list->addAtK(60,0);
	list->printSLL();
	
	cout<<" "<<endl;
	cout<<"Testing pop"<<endl;
	x = list->pop();
	cout << x << endl;
	list->printSLL();
	x = list->pop();
	cout << x << endl;
	list->printSLL();
	
	cout<<" "<<endl;
	cout<<"Testing rem first"<<endl;
	x = list->remFirst();
	cout << x << endl;
	list->printSLL();
	//list->getVals();
	x = list->remFirst();
	cout << x << endl;
	list->printSLL();
	
	cout<<" "<<endl;
	cout<<"Testing remKth"<<endl;
	x = list->remKth(3);
	cout << x << endl;
	list->printSLL();
	x = list->remKth(4);
	cout << x << endl;
	list->printSLL();

	cout<<" "<<endl;
	cout<<"Creates new list with addFirst and push"<<endl;
	SLL *l2 = new SLL;
	l2->addFirst(rand()%50);
	for (int i = 0; i < 10; i++) {
		l2->push(rand()%50);
	}
	l2->printSLL();
	cout << endl;
	cout<<"joins to list1"<<endl;
	list->join(l2);
	list->printSLL();

	cout<<" "<<endl;
	cout<<"Testing reverse list"<<endl;
	list->reverseList();
	list->printSLL();
	*/
//Testing DLL

	cout << "DLL" << endl << endl;
	DLL *listd = new DLL;
	cout<<" "<<endl;
	cout<<"Testing addFirst: "<<endl;
	listd->addFirst(rand()%50);
	listd->printDLL();
	cout<<" "<<endl;
	cout<<"Testing push: "<<endl;
	for (int i = 0; i < 8; i++) {
		if (i == 4) {
			listd->push(42);
			i++;
		}
		else {
			listd->push(rand()%50);
		}
		listd->printDLL();
	}
	
	cout<<" "<<endl;
	cout<<"Testing findKth: "<<endl;
	DNode *s2 = listd->findKth(6);
	int y2 = s2->getData();
	cout <<"data at index 6 : "<< y2 << endl;
	
	cout<<" "<<endl;
	cout<<"Testing findK: "<<endl;
	int x2 = listd->findK(42);
	cout <<"Index: "<< x2 << endl;
	
	cout<<" "<<endl;
	cout<<"Testing addAtK: "<<endl;
	listd->addAtK(55,4);
	listd->printDLL();
	listd->addAtK(60,0);
	listd->printDLL();
	
	cout<<" "<<endl;
	cout<<"Testing pop: "<<endl;
	x2 = listd->pop();
	cout <<"popped: "<< x2 << endl;
	listd->printDLL();
	x2 = listd->pop();
	cout<<"popped: "<< x2 << endl;
	listd->printDLL();
	
	cout<<" "<<endl;
	cout<<"Testing remFirst: "<<endl;
	x2 = listd->remFirst();
	cout<<"Data removed from first value: " << x2 << endl;
	listd->printDLL();
	x2 = listd->remFirst();
	cout<<"Data removed from first value: " << x2 << endl;
	listd->printDLL();
	
	cout<<" "<<endl;
	cout<<"Testing remKth: "<<endl;
	x2 = listd->remKth(3);
	cout<<"Removed value from index 3: " << x2 << endl;
	listd->printDLL();
	x2 = listd->remKth(4);
	cout<<"Removed value from index 4: " << x2 << endl;
	listd->printDLL();
	

	DLL *ld2 = new DLL;
	cout<<" "<<endl;
	cout<<"Creating list 2 for joining: "<<endl;
	ld2->addFirst(rand()%50);
	for (int i = 0; i < 8; i++) {
		ld2->push(rand()%50);
	}
	ld2->printDLL();
	cout << endl;
	
	cout<<" "<<endl;
	cout<<"Joining Lists: "<<endl;
	listd->join(ld2);
	listd->printDLL(); 
	
	//cout<<" "<<endl;
	//cout<<"Reversing Lists: "<<endl;
	//listd->printRevDLL();

	cout<<" "<<endl;
	cout<<"Creating list for merging: "<<endl;
	DLL *list1 = new DLL;
	list1->addFirst(rand()%250);
	list1->printDLL();
	for (int i = 0; i < 8; i++) {
		list1->push(rand()%250);
	}
	//list1->printDLL();
	cout<<"Sorting list: "<<endl;
	list1->sortDLL();
	list1->printDLL();

	cout<<" "<<endl;
	cout<<"Creating new list for merging: "<<endl;
	DLL *list2 = new DLL;
	list2->addFirst(1);
	list2->printDLL();
	for (int i = 0; i < 8; i++) {
		list2->push(i*2 + 1);
	}
	//list2->printDLL();
	//list2->sortDLL();
	cout<<"list 2: "<<endl;
	list2->printDLL();
	cout<<"list 1: "<<endl;
	list1->printDLL();
	cout<<"Merged lists 1&2"<<endl;
	list1->Merge2(list2);
	
	cout<<endl;
	cout<<"Delete duplicates of merged list: "<<endl;
	list1->RemoveDuplicates();
	list1->printDLL();
	
	/*cout<<endl;
	cout<<"Testing reverse list: "<<endl;
	list1->RecursiveReverse();
	list1->printDLL();*/
}

