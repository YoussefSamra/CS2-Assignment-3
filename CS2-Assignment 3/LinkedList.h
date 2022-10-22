#pragma once
#include <iostream>
#include <vector>
using namespace std;


struct Node {
	int data;
	Node* next;
	int counter;

	Node();
	Node(int data);

};

class LinkedList {

private:
	Node* head;

public:
	
	LinkedList();
	void addNode(int x);	
	void removeNode(int x);
	void printlist();
	int sumOfNodes();
	LinkedList VectortoList(vector<int>& v);


};