#include "LinkedList.h"
	

void insertAfter(vector<int>& v, int firstValue, int secondValue) {   
    int x;
    for (int i = 0; i < v.size(); i++) {
        x = v.at(i);
        if (x == firstValue) {
            v.insert(v.begin() + i + 1, secondValue);
        }
    }
}

LinkedList::LinkedList() {

    head = NULL;
};

Node::Node() {

    data = 0;
    next = NULL;
    counter = 0;
};
Node::Node(int data) {

    this->data = data;
    this->next = NULL;
    counter = 0;


};

int LinkedList::sumOfNodes() {
    int sum = 0;
    Node* temp = head;
    if (head == NULL) {
        return 0;
    }

    while (temp != NULL) {
        sum += temp->data;
        temp = temp->next;
    }


    return sum;

}


void LinkedList::addNode(int data) {

    Node* Nnode = new Node(data);

    if (head == NULL) {
        head = Nnode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {        // To go thorugh the whole list

        temp = temp->next;
    }

    temp->next = Nnode;

}

void LinkedList::removeNode(int data) {

    Node* temp = head, * t = NULL;
    int size = 0;

    if (head == NULL) {
        cout << "List Is Empty" << endl;
        return;
    }

    while (temp != NULL) { // To get the size of the linked list
        temp = temp->next;
        size++;
    }

    if (size < data) {
        cout << "index Out Of Range" << endl;
        return;
    }

    temp = head;

    if (data == 1) {
        head = head->next;
        delete temp;
        return;
    }
    
    while (data-- > 1) {
        t = temp;
        temp = temp->next;
    }

    t->next = temp->next;

    delete temp;




}

void LinkedList::printlist() {
    Node* temp = head;
    
    if (head == NULL) {
        cout << "List Is Empty" << endl;
        return;
    }

    while (temp != NULL)
    {
        cout << endl << temp->data << " ";
        temp = temp->next;

    }


}

LinkedList LinkedList::VectortoList(vector<int>& v) {
    Node* temp = head;
    LinkedList list;

    for (int i = 0; i < v.size(); i++) {
       list.addNode(v[i]);
    }

    while (temp != NULL) {

        for (int i = 0; i < v.size(); i++) {
            if (temp->data == v[i]) {

                temp->counter++;
            }
            temp = temp->next;
        }
    }

    return list;

}



int main() {
	int x;
	const int size = 6;
	vector<int>integers(size);
    for (int i = 0; i < size; i++) {
        cout << "Pleae Input Integer Value: ";
        cin >> x;
        integers.push_back(x); 
        cout << endl;
    }
    LinkedList list = list.VectortoList(integers);
    cout << "Sum Of Nodes: " << list.sumOfNodes();

	return 0;
}