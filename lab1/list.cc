#include <iostream>
#include "list.h"

using namespace std;

List::List() : first(nullptr) {}

List::~List() {
	while(first != nullptr) {
		Node* tmp = first;
		first = first->next;
		delete tmp;
	}
}

bool List::exists(int d) const {
	Node* current = first;
	while(current != nullptr) {
		if(current->value == d) {
			return true;
		}
		current = current->next;
	}
	return false;
}

int List::size() const {
	int size = 0;
	Node* current = first;
	while(current != nullptr) {
		++size;
		current = current->next;
	}
	return size;
}

bool List::empty() const {
	return first == nullptr;
}

void List::insertFirst(int d) {
	if(first == nullptr) {
		first = new Node(d, nullptr);
	} else {
		first = new Node(d, first);
	}
}

void List::remove(int d, DeleteFlag df) {
	Node* prev = nullptr;
	Node* current = first;
	bool foundValue = false;
	while(current != nullptr && !foundValue) {
		switch(df) {
			case List::DeleteFlag::LESS:
				if(current->value < d) {
					foundValue = true;
				}
			break;
			case List::DeleteFlag::EQUAL:
				if(current->value == d) {
					foundValue = true;
				}
			break;
			case List::DeleteFlag::GREATER:
				if(current->value > d) {
					foundValue = true;
				}
			break;
		}
		if(!foundValue) {
			prev = current;
			current = current->next;
		}
	}

	if(foundValue) {
		if(prev == nullptr) {
			first = first->next;
		} else {
			prev->next = current->next;
			delete current;
		}
	}
}

void List::print() const {
	Node* current = first;
	while(current != nullptr) {
		cout << current->value << " ";
		current = current->next;
	}
}
