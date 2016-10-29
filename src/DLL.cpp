/*
 * DLL.cpp
 *
 *  Created on: Sep 28, 2016
 *      Author: Paul Tudan
 */

#include "DLL.hpp"
#include "DNode.hpp"
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <direct.h>
#include <windows.h>
using namespace std;

DLL::DLL(){
	first = NULL;
	last = NULL;
	size = 0;
}
DLL::~DLL(){
	DNode *tmp = first;
	while (first != NULL) {
		tmp = first->next;
		delete first;
		first = tmp;
		size --;
	}
	first = NULL;
	last = NULL;
}
void DLL::printDLL() {
	DNode *tmp = first;
	//int printCount = 0;
	while (tmp != NULL) {
		//printCount++; && printCount<size
		cout << tmp->data << "->";
		tmp = tmp->next;
	}
	cout << endl;
}
void DLL::printRevDLL() {
	DNode *tmp = last;
	while (tmp != NULL) {
		cout << tmp->data << "->";
		tmp = tmp->prev;
	}
	cout << endl;
}

void DLL::addFirst(int x) { //2 pts
//add very first element to list
	first = new DNode(x);
	last = first;
	size++;
}
void DLL::addAtFront(int x) { //2 pts
//	add a new node to the beginning of the list
	DNode *temp = new DNode(x);//creates new node
	first->prev = temp; //links first back to new
	temp->next = first; //links new to first
	first = temp;//sets first
	size++;
	if(size == 2){
		last = first->next;//if new node is second nodes, sets last
	}//if
}

void DLL::push(int x) { //2 pts
// add a new node to the end of the list
	DNode *temp = new DNode(x);//creates new node
	last->next = temp;//links last node to new
	temp->prev = last;//links new node to last
	last = temp; //sets last to new node
	size++;
}

void DLL::addAtK(int x, int k){ //4 pts
//add at position k a new node with x as the data
	DNode *temp = first;
	for(int i = 0; i<size; i++){//iterates to k
		if(k == 0){//if at 0
			addAtFront(x);
			return;
		}//if
		else if(i == k){
			DNode *temp2 = new DNode(x);//creates new node
			temp->prev->next = temp2;//attaches nodes to new node
			temp2->prev = temp->prev;
			temp->prev = temp2;
			temp2->next = temp;
			size++;//increments size
			return;
		}//else if
		else{
			temp = temp->next;
		}//else
	}//for
}
void DLL::join(DLL *list2){ //2 pts
// join list 2 to the end of the list, modifying the size of the list
	DNode *temp = list2->first;
	last->next = temp;//points last of original list to first of second
	temp->prev = last;//points first of new list back to last of orig
	last = list2->last;//sets last to new last
	size += list2->size;//adds size
	cout<<"first: "<<first->data<<" last: "<< last->data<<" size: "<<size<<endl;//prints debug
}

int DLL::pop() { //5 pts
//popping the last node off the end of the list and returning that data
	int x = last->data;//saves data of final node
	DNode *temp = last->prev;//saves prev of final node
	last->prev->next = NULL;
	last->prev = NULL;//nulls all unneeded pointers
	last->next = NULL;
	delete last;//deletes final node
	last = temp;//resets final node
	size--;
	return x;
}
DNode *DLL::findKth(int k) { 
//find the element at the kth position and returning a pointer to that node
	DNode *temp = first;
	for(int i = 0; i<size; i++){//iterates to k
		if(k == 0){
			return first;
		}
		else if(i == k){
			return temp;
		}
		else{
			temp = temp->next;//increments list
		}
	}
	cout<<"There is no element at "<<k<<endl;//debugging return
	return NULL;
}
int DLL::findK(int k) {
	DNode *tmp = first;
	int ind = 0;
	while (tmp != NULL && tmp->data != k) {
		tmp = tmp->next;
		ind++;
	}
	if (ind < size) {
		return ind;
	}
	else {
		return -1;
	}
}
int DLL::remFirst() { //2 pts
//remove the first node from the list, returning its data
	if(size == 1){//base case
		int x = first->data;
		DNode *temp = first;
		first = NULL;
		last = NULL;
		size--;
		delete temp;
		return x;
	}
	DNode *temp = first;
	int x = first->data;//saves data
	first->next->prev = NULL;
	first = first->next;//resets first
	temp->next = NULL;
	delete temp;//deletes old first
	size--;
	return x;
}
int DLL::remKth(int k) { //4 pts
//remove the kth element of the list, returning its data
	DNode *temp = first;
	int x = -2147000000;
	for(int i = 0; i<size; i++){//iterates to k
		if(k == 0){
			return remFirst();
		}//if
		else if(i == k){
			if(k<size-1){
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;//switches prev/nexts of adj nodes
				x = temp->data;//saves data
				temp->next = NULL;
				temp->prev = NULL;
				delete temp;
				size--;
				return x;
			}//if
			else{//need to change last variable
				temp->prev->next = NULL;
				x = temp->data;
				last = temp->prev;
				temp->prev = NULL;
				delete temp;
				size--;
				return x;
			}//else
		}//else if
		else{
			temp = temp->next;
		}//else
	}//for
	cout<<"remKth failed with a value of "<<k<<endl;
	return x;
}
void DLL::RecursiveReverse() { //6 pts
// RECURSIVELY reverses the list
	DNode *temp = first;
	for(int i = 0; i<size; i++){
		if(i==0){
			DNode *temp2 = temp->next;
			temp->prev = temp2;
			temp->next = NULL;
			temp = temp2;
			DNode *temp4 = first;
			first = last;
			last = temp4;
		}//if
		else if(i == size-1){
			break;
			DNode *temp2 = temp->prev;
			temp->next = temp2;
			temp->prev = NULL;
		}//else if
		else{
			DNode *temp2 = temp->next;
			DNode *temp3 = temp->prev;
			temp->prev = temp2;
			temp->next = temp3;
			temp = temp2;
		}//else
	}//for
	
}
void DLL::sortDLL() { //10 pts
//sort the list from smallest to largest
	DNode *temp;
	bool isSorted;
	for(int i = 0; i<size; i++){
		isSorted = true;
		temp = first;
		cout<<"loop number: "<<i+1<<endl;
		for(int j = 0; j<size-1; j++){
			cout<<"first: " <<first->data<<" last: "<<last->data<<" size: "<<size<<" temp: "<< temp->data<<endl;
			printDLL();
			if(temp==first && temp->data > temp->next->data){
				isSorted = false;
				DNode *temp2 = temp->next;
				temp2->prev = NULL;
				temp->prev = temp2;
				temp->next = temp2->next;
				temp2->next->prev = temp;
				temp2->next = temp;
				first = temp2;
			}
			else if(temp->data > temp->next->data){
				isSorted = false;
				DNode *temp2 = temp->next;
				if(temp2->next == NULL){
					cout<<"changin last"<<endl;
					temp->next = NULL;
					last = temp;
					cout<<"last: "<<last->data<<endl;
				}
				else{
					temp->next = temp2->next;
					temp2->next->prev = temp;
				}
				temp2->prev = temp->prev;
				temp->prev->next = temp2;
				temp->prev = temp2;
				temp2->next = temp;
			}
			else{
				temp = temp->next;
			}
		}
		if(isSorted){
			return;
		}
		cout<<endl;
	}
}

void DLL::Merge2(DLL *l2) { //10 pts
//Merge two sorted lists into one longer sorted list, and setting
//the current list to the longer sorted list
// Note that I sorted both lists before I called this.
//also note that joining the two lists and then sorting is NOT what I want
//here - I want this function to start at the beginning of each list,
//and pull the smallest of the 2 values into the new list, then move up
//one in that particular list.  
// e.g., 
// l1 = 3,7,12,15,22,23,24,29    l2=4,8,12,13,27
// n=3
// l1 = 7,12,15,22,23,24,29    l2=4,8,12,13,27
// n=3,4
// l1 = 7,12,15,22,23,24,29    l2=8,12,13,27
// n=3,4,7
// l1 = 12,15,22,23,24,29    l2=8,12,13,27
// n=3,4,7,8
// l1 = 12,15,22,23,24,29    l2=12,13,27
// n=3,4,7,8,12
// l1 = 15,22,23,24,29    l2=12,13,27
// n=3,4,7,8,12,12
// l1 = 15,22,23,24,29    l2=13,27
// n=3,4,7,8,12,12,13
// l1 = 15,22,23,24,29    l2=27
// n=3,4,7,8,12,12,13
// l1 = 15,22,23,24,29    l2=27
// n=3,4,7,8,12,12,13,15
// l1 = 22,23,24,29    l2=27
// n=3,4,7,8,12,12,13,15,22
// l1 = 23,24,29    l2=27
// n=3,4,7,8,12,12,13,15,22,23
// l1 = 24,29    l2=27
// n=3,4,7,8,12,12,13,15,22,23,24
// l1 = 29    l2=27
// n=3,4,7,8,12,12,13,15,22,23,24,27
// l1 = 29    l2
// n=3,4,7,8,12,12,13,15,22,23,24,27,29
	
	DLL *newList = new DLL;
	if(first->data > l2->first->data){//appends lower of the two firsts
		newList->addFirst(l2->remFirst());
	}//if
	else{
		newList->addFirst(remFirst());
	}//else
	newList->printDLL();
	
	while((size > 0) && (l2->size > 0)){//while there are nodes remaining in each list
		//cout<<"here"<<endl;
		if(first->data > l2->first->data){//pushes lower of two current firsts
			newList->push(l2->remFirst());
		}//if
		else{
			newList->push(remFirst());
		}//else
		newList->printDLL();
	}//while
	
	if(size == 0){//when no nodes are in list 1
		while(l2->size > 0){//while nodes are still in list 2
			newList->push(l2->remFirst());//pushes remaining list 2 nodes
		}//while
	}//if
	else{//when no nodes are in list 2
		while(size > 0){//while nodes remain in list 1
			newList->push(remFirst());//pushes remaining list 1 nodes
		}//while
	}//else
	
	newList->printDLL();
	
	first = newList->first;//sets list to new list
	last = newList->last;
	size = newList->size;
}
void DLL::RemoveDuplicates() { //12pts
// assumes the list is unsorted, removes all duplicates from the list
//Note how massively easier this would be if we just sorted the list first...
// Note also that you can use a helper function if you like
	//sortDLL();
	
	DNode *temp = first;
	while(temp->next != NULL){
		if(temp->next->data == temp->data){//if nodes are dupes
			DNode *temp2 = temp->next->next;//saves jump node
			temp->next->prev = NULL;
			temp->next->next = NULL;
			delete temp->next;//deletes dupe node
			temp->next = temp2;//sets next up
		}//if
		else{
			temp = temp->next;
		}//else
	}//while
}




