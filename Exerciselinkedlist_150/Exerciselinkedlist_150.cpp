#include <iostream>
using namespace std;

class Node {
public :
	int rollnumber;
	string name;
	Node* next;
	Node* prev;
};

class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollnumber, Node** previous, Node** current);
	bool listEmpty();
	bool delNode(int rollnumber);
	void traverse();
};

void CircularLinkedList::addNode() {
	int nim;
	string nm;
	cout << "\nEnter the roll number of the student : ";
	cin >> nim;
	cout << "\nEnter the name of the student : ";
	cin >> nm;
	Node* newNode = new Node(); //step 1
	newNode->rollnumber = nim; //step 2
	newNode->name = nm;// step 2
	
	/*insert a node in the begining of a doubly - linked list*/
	if (LAST == NULL || nim <= LAST->rollnumber) {
		if (LAST != NULL && nim == LAST->rollnumber) {
			cout << "\nDuplicated number of allowed" << endl;
			return;
		}
		newNode->next = LAST; //step 3
		if (LAST != NULL)
			LAST->prev = newNode;//Step 4
		newNode->prev = NULL; //Step 5
		LAST = newNode; //Step 6
		return;
	}

	/*inserting a Node Between Two Nodes in the List*/
	Node* Rangga = LAST; //step1 a.
	Node* Fadillah = NULL;
	while (Rangga->next != NULL && Rangga->next->rollnumber < nim) //step1.c
	{
		Fadillah = Rangga; // 1.d
		Rangga = Rangga->next; //1.e
	}

	if (Rangga->next != NULL && nim == Rangga->next->rollnumber) {
		cout << "\nDuplicate roll Numbers not allowed" << endl;
		return;
	}

	newNode->next = Rangga->next; //step 4
	newNode->prev = Rangga; //step 5
	if (Rangga->next != NULL)
		Rangga->next->prev = newNode; //step 6
	Rangga->next = newNode;//step 7
}


bool CircularLinkedList::search(int rollnumber, Node** Fadillah, Node**Rangga) {

	*Fadillah = LAST->next;
	*Rangga = LAST->next;

	while (*Rangga != LAST) {
		if (rollnumber == (*Rangga)->rollnumber) {
			return true;
		}
		*Fadillah = *Rangga;
		*Rangga = (*Rangga)->next;
	}

	if (rollnumber == LAST->rollnumber) {
		return true;
	}
	else {
		return false;
	}
}

bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}

bool CircularLinkedList::delNode(int rollnumber) {
	Node* Fadillah, * Rangga;
	Fadillah = Rangga = NULL;
	if (search(rollnumber, &Fadillah, &Rangga) == false)
		return false;
	if (Rangga->next != NULL)
		Rangga->next->prev = Fadillah;
	if (Fadillah != NULL)
		Fadillah->next = Rangga->next;
	else
		LAST = Rangga->next;

	delete Rangga;
	return true;
}

void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList empty\n";
	}
	else {
		cout << "\nRecords in the list are: \n";
		Node* currentNode = LAST->next;
		while (currentNode != LAST) {
			cout << currentNode->rollnumber << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
		cout << LAST->rollnumber << " " << LAST->name << endl;
	}
}
	
int main() {
	CircularLinkedList obj;
	int ch, rollnumber;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View a;; the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case'1': {
				obj.addNode();
				break;
			}
			case '2': {
				obj.delNode(rollnumber);
				break;
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "invalid option" << endl;
				break;
			}

		}
	}
		catch (exception& e) {
			cout << e.what() << endl;
		}
		return 0;
}