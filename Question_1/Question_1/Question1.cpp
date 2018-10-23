#include <iostream>
#include <string>
#include <stdlib.h> //library needed for clear console screen function
using namespace std;

struct Node {
	int data;
	struct Node* next;//self-referential structure
};

int num[5];

int Display(Node* head) {
	if (head == NULL) {
		cout << "Your list is empty\n";
		return 0;
	}
	cout << "The numbers in the list: ";
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << "\n\n";
	return 0;
}

void Insert(Node* &head, int num[]) {
	for (int x = 0; x < 5; x++) {
		Node* temp;
		Node* NewNode = (Node*)malloc(sizeof(struct Node));
		NewNode->data = num[x];
		NewNode->next = NULL;
		if (head == NULL)
			head = NewNode;
		else {
			temp = head;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = NewNode;
		}
	}
}

int Search(Node* &head, int target) {
	struct Node* temp;
	temp = head;
	while (temp != NULL)
	{
		if (temp->data == target) {
			cout << "Found it! Good Job!\n\n";
			Display(head);
			return 0;
		}
		else {
			temp = temp->next;
		}
	}
	cout << "Ops! The number is not in the list\n\n";
	return 0;
}


int main() {
	struct Node* head = NULL;

	cout << "Please enter 5 integer numbers:-\n";
	string counter = "";
	
	int guessNum;
	for (int x = 0; x < 5; x++) {
		switch(x){
		case 0:
			counter = "first";
			break;
		case 1:
			counter = "second";
			break;
		case 2:
			counter = "third";
			break;
		case 3:
			counter = "forth";
			break;
		case 4:
			counter = "fifth";
			break;
		}
		cout << "Enter the " << counter << " number: ";
		cin >> num[x];
	}

	system("CLS");//clear console screen

	cout << "Please enter another one number: ";
	cin >> guessNum;

	cout << "\n----------------------------------\n\n";

	Insert(head, num);//call insert function
	Search(head, guessNum);//call search function

	return 0;
}