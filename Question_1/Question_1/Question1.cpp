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
	cout << "\n";
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

int Search(Node* &head, int target, bool correct) {
	struct Node* temp;
	temp = head;
	while (temp != NULL)
	{
		if (temp->data == target) {
			cout << "\n----------------------------------\n\nFound it! Good Job!\n\n";
			Display(head);
			correct = true;
			return correct;
		}
		else {
			temp = temp->next;
		}
	}
	cout << "\n----------------------------------\nOps! The number is not in the list\n\nPlease try again...\n\n";
	return correct;
}


int main() {
	struct Node* head = NULL;
	bool correct = false;

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
	
	Insert(head, num);//call insert function
	
	do{
		cout << "Please enter another one number: ";
		cin >> guessNum;
		correct = Search(head, guessNum, correct);//call search function
	} while (!correct);
	
	cout << "\n----------------------------------\n\n";

	

	return 0;
}