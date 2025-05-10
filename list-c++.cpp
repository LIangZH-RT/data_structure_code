#include <iostream>

using std::cout;

template<typename T>
class Node {
public:

	T data;
	Node* next;
};


template<typename T>
class LinkedList {
public:

	Node<T>* createNode(T data);
	void insertHead(T data);
	void insertAny(T data, int pos);
	void pushBack(T data);
	void removeAny(int pos);
	void revers_iterative();
	void reverse_recursive(Node<T>* current);
private:
	Node<T>* head = nullptr;
};

template<typename T>
Node<T>* LinkedList<T>::createNode(T data) {
	Node<T>* temp = new Node<T>;
	temp->data = data;
	temp->next = nullptr;
	return temp;
}

template<typename T>
void LinkedList<T>::insertHead(T data) {
	Node<T>* temp = createNode(data);
	if (head == nullptr) {
		head = temp;
	}
	else {
		temp->next = head;
		head = temp;
	}
}

template<typename T>
void LinkedList<T>::pushBack(T data) {
	Node<T>* temp = createNode(data);
	if (head == nullptr) {
		head = temp;
	}
	else {
		Node<T>* current = head;
		while (current->next != nullptr) {
			current = current->next;
		}
		current->next = temp;
	}
}

template<typename T>
void LinkedList<T>::insertAny(T data, int pos) {
	if (pos == 1) {
		insertHead(data);
		return;
	}
	Node<T>* temp = createNode(data),*current = head;
	for (int i = 0; i < pos - 2; i++) {
		if (current == nullptr) { cout<<"out of length\n"; return; }
		current = current->next;
	}
	temp->next = current->next;
	current->next = temp;
}

template<typename T>
void LinkedList<T>::removeAny(int pos) {
	if (head == nullptr) return;
	if (pos == 1) {
		Node<T>* temp = head;
		head = temp->next;
		delete temp;
		return;
	}
	Node<T>* current = head;
	for (int i = 0; i < pos - 2; i++) {
		if (current->next == nullptr) {
			cout << "Position out of bounds\n";
			return; 
		}
		current = current->next;
	}
	Node<T>* temp = current->next;
	current->next = temp->next;
	delete temp;
}

template<typename T>
void LinkedList<T>::revers_iterative() {
	if (head == nullptr || head->next == nullptr) { cout << "Node less than 2\n"; return; }
	Node<T>* prev = nullptr;
	Node<T>* current = head;
	Node<T>* next;
	while (current != nullptr) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}

template<typename T>
void LinkedList<T>::reverse_recursive(Node<T>* current) {
	if (head == nullptr || head->next == nullptr) { cout<<"Node less than 2\n"; return; }
	if (current->next == nullptr) { head = current; return; }
	 
	reverse_recursive(current->next);
	Node<T>* temp = current->next;
	temp->next = current;
	current->next = nullptr;
}

int main() {
	return 0;
}
