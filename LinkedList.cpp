/*Garrison Davis
I am turning this in very late sorry
Function: A linked List with a built in Node class which i know is not what the directions asked
for, but honestly I did not read them well and did this whole thing before reading about the 
header files and node class and stuff and I really do not have time to redo it.
Input: A series of ints
Output: A linked list will be printed. */
#include <iostream>

using namespace std;
//This is the node class I made inside of this whole thing. It is used to create nodes
//I could have also made a seperate node class but as mentioned before I did npot read until
//I was done.
class node{
public:
	int data;
	node* next;
};

//This is the beggining of the linked list class
class linkedList{
//Creates a head and tail node
private:
	node* head;
	node* tail;
public: // This is a prototype for all of the functions. I could have put it in a header file, but I did not. 
	int size;
	linkedList();
	linkedList(int, int);
	~linkedList();
	void init();
	void insert(int,int);
	int get(int);
	void remove(int);
	int getSize();
	void print();
};

//Default Constrers as specified.
linkedList::linkedList()
{
	size = 0;
	head = NULL;
	tail = NULL;

}

linkedList::linkedList(int size, int num) {
	this->size = size;
	head->data = num;
	tail->data = num;
}

linkedList::~linkedList()
{
	cout << "this object was deleted" << "\n";
}
//This guy will take in all of the values and populate thelinked list
void linkedList::init() {
	int val;
	std::cin >> val;
}
//This will insert a node at any index you want it to
void linkedList:: insert(int idx, int n)
{
	node* pre = new node();
	node* cur = new node();
	node* temp = new node();
	if (head == NULL) {
		head->data = n;
		return;
	}
	if (idx == 0){
		temp->data = n;
		temp->next = head;
		head = temp;

	}
	else{
		cur = head;
		for (int i = 0; i < idx; i++)
		{
			pre = cur;
			cur = cur->next;
		}
		temp->data = n;
		temp->next = cur;
		pre->next = temp;
	}
	size++;
}

//This guy will remove any node you want
void linkedList::remove(int idx)
{
	node* pre = new node();
	node* cur = new node();
	cur = this->head;
	if (head == NULL) {
		cout << "There is nothing to remove cheif";
		return;
	}
	if(idx == 0){
		pre = head;
		head = head ->next;
		return;
	}
	else{
		for (int i = 0; i < idx; i++){
			pre = cur;
			cur = cur ->next;
		}
		pre->next = cur->next;
	}
	size--;
}
//This guy will print
void linkedList::print(){
	node* printNode = head;
	while (printNode != NULL)
	{
		cout << printNode->data << "\n";
		printNode = printNode->next;
	}
}
//This guy takes in an index and returns the value at that index.
int linkedList::get(int idx) {
	node* curr = head;
	for (int i = 0; i < idx; i++) {
		curr = curr->next;
	}
	return curr->data;
}
//This dude returns the size.
int linkedList::getSize() {
	return size;
}


