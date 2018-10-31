#include <iostream>

using namespace std;

//create self referential structure 
struct node {
	int data; //declare variable
	struct node*link; //self referential structure, then create another variable 
};

//create class name queue
class queue {
public:
	void append(struct node *&top, node *&tail); //insert
	void serve(struct node *&top, node *&tail); //delete
	void display(node *top); //display
};

//insert number into queue list 
void queue::append(struct node *&top, node *&tail) {
	struct node *newNode; //can declare typedef
	struct node *temp;
	int value;
	cout << "Enter number: ";
	cin >> value;
	newNode = (struct node*)malloc(sizeof(struct node)); //allocate new memory location
														 //insert the number into data
	newNode->data = value;
	newNode->link = NULL;

	//if list is empty
	if (tail == NULL) {
		top = newNode;
	}
	else
		tail->link = newNode;
	tail = newNode;
}

//display the queue list
void queue::display(node*top) {
	cout << "Queue list: \n";
	//if the queue is empty
	if (top == NULL) {
		cout << "Your queue is empty\n";
	}
	//display the data in the list
	while (top != NULL) {
		cout << top->data << "\n";
		top = top->link;
	}
}

//delete value in the end of the list
void queue::serve(struct node *&top, node *&tail) {

	struct node *Temp;
	int value = 0;
	//if the queue is empty
	if (top == NULL)
		cout << "Queue is empty";
	else
	{
		//delete the number in the end of the queue list
		value = top->data;
		Temp = top;
		top = top->link;
		if (top == NULL)
			tail = NULL;
		else
			free(Temp);
		cout << value << " is deleted from queue\n";
	}


}

int main() {
	int choice;
	node *Head = NULL;
	node *Tail = NULL;
	queue list;

	//loop the menu until user exit the program
	do {
		cout << "\n================================================\n";
		cout << "1. Insert\n2. Delete\n3. Display\n4. Exit\n\nEnter your choice: ";
		//allow user to insert choice
		cin >> choice;
		cout << "\n";
		switch (choice) {
		case 1:
			list.append(Head, Tail);
			break;
		case 2:
			list.serve(Head, Tail);
			break;
		case 3:
			list.display(Head);
			break;
		case 4:
			return 0;
			break;
		default:
			cout << "Wrong input, please enter choice 1-4 only.";
			break;
		}
	} while (choice != '4');


	return 0;
}