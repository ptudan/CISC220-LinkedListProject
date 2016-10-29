/*
 * SLL.cpp
 *
 *  Created on: Sep 26, 2016
 *      Author: Paul Tudan
 */

#include "SLL.hpp"
#include "SNode.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

SLL::SLL(){
	first = NULL;
	last = NULL;
	size = 0;
}
SLL::~SLL(){
	SNode *tmp = first;
	while (first != NULL) {
		tmp = first->next;
		delete first;
		first = tmp;
		size --;
	}
	first = NULL;
	last = NULL;
}
void SLL::printSLL() {
	SNode *tmp = first;
	while (tmp != NULL) {
		cout << tmp->data << "->";
		tmp = tmp->next;
	}
	cout << endl;
}

void SLL::addFirst(int x) { // 3 pts
//make a new list of only one node, data is x
	first = new SNode(x);
	last = first;
	size++;
}
void SLL::addAtFront(int x) {  //3 pts
//add a new node to the front of the list with data being x
	SNode *temp = first;
	first = new SNode(x); //creates new node
	first->next = temp; //makes new node next value
	size++;
	if(size == 2){//if new node is the second node added, changes last value to original first
		last = first->next;
	}//if
}

void SLL::push(int x) { //6 pts
//add a new node to the end of the list, with data x
	last->next = new SNode(x); //creates new node in last->next
	last = last->next; //sets last to new node
	last->next = NULL; //assures new last->next is NULL
	size++;
}

void SLL::addAtK(int x, int k){
	SNode *tmp = first;
	if (k==0) {
		addAtFront(x);
	}//if
	else if (k < size  && k >= 0) {
		for (int i = 0; i < k-1; i++) {
			tmp = tmp->next;
		}//for
		SNode *tmp2 = tmp->next;
		tmp->next = new SNode(x);
		tmp->next->next = tmp2;
		size++;
	}//else if
}
void SLL::join(SLL *list2){ //3 pts
//join the list with list2, making the current list one longer list
	last->next = list2->first; //concatenates lists
	size += list2->size; //increases size
	last = list2->last; //sets last
}

int SLL::pop() {
	//lastSet();
	//getVals();
	if (size > 0) {
		int x = last->data;
		if (first != last){ //COULD NOT DEBUG HER PROGRAM, DON'T UNDERSTAND ERRORS
			SNode *tmp = first;
			for (int i = 0; i < size-1;i++) {
				tmp = tmp->next;
			}
			delete last;
			last = tmp;
			last->next = NULL;
		}
		else {
			delete last;
			first = NULL;
			last = NULL;
		}
		size --;
		//lastSet();
		return x;
	}
	else {
		return -1;
	}
}
SNode *SLL::findKth(int k) { //4 pts
// find the node at the kth location and return it
	SNode *temp = first;
	for(int i = 0; i<size; i++){
		if(k == 0){
			return first;
		}//if
		else if(i == k){
			return temp;
		}//else if
		else{
			temp = temp->next;
		}//else
	}//for
	return NULL;
	
}
int SLL::findK(int k) {
	SNode *tmp = first;
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
int SLL::remFirst() { //3 pts
//remove the first node from the list, returning its data
	int x = first->data;
	SNode *temp = first->next;//saves location of 2nd node
	//cout<<"first next: "<<first->next->data<<endl;
	first->next = NULL; //sets pointer to null to avoid error message 
	delete first; //bug HERE, don't understand why it happens on second iteration
	first = temp; //sets first to stored value (originally 2nd)
	size--; 
	return x;
}
void SLL::reverseList(){ //10 pts
//Reverses the list, after completed, the last should be the first
//in the list and the first should be the last
//Challenge - I did this with one pass across the list
//my code works like this:
//original list: 12345
//after add first for loop: 5432112345
//then pops off the last 5 nodes with pop loop leaving 54321
	int origSize = size; //saves original size of list
	SNode *temp = first;
	for(int i = 0; i<origSize; i++){
		addAtFront(temp->data);//adds each value at front of list
		if(temp->next != NULL){//iterates through list
			temp = temp->next;
		}//if
		else{
			last = temp;
			break;
		}//else
	}//for
	//cout<<"got here"<<endl;
	printSLL();
	temp = first;
	for(int i = 0; i<origSize; i++){
		pop();//pops all the original values off of list
		temp = temp->next;
		if(i == origSize - 1){
			last = temp;//gets new last node
		}
	}//for
}

int SLL::remKth(int k) {
	int x = -2147000000; 
	if (k < size && k > 0) {
		SNode *tmp = first;
		for (int i = 0; i < k -1; i++) {//again, errors
			tmp = tmp->next;
		}
		x = tmp->next->data;
		SNode *tmp2= tmp->next;
		tmp->next = tmp->next->next;
		tmp2->next = NULL;
		delete tmp2;
		return x;
		size--;
	}
	return x;
}

void SLL::getVals(){//for debugging purposes only
	cout<<"First: "<< first->data<< " Last: " <<last->data<< " size: " << size<<endl;
}

void SLL::lastSet(){//for debugging purposes only
	SNode *temp = first;
	for(int i = 0; i<size-1; i++){
		if(temp->next->data >1000){
			temp->next = NULL;
			last = temp;
		}
		temp = temp->next;
	}
}
