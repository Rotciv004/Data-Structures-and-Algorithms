#include "MultiMap.h"
#include "MultiMapIterator.h"
#include <exception>
#include <iostream>

using namespace std;


void MultiMap::add(TKey c, TValue v) {
	TElem elem = make_pair(c, v);
	Node* newNode = new Node(elem);
	if (this->head == nullptr) {
		this->head = newNode;
	}
	else {
		newNode->next = this->head;
		this->head = newNode;
	}
	this->length++;
}


bool MultiMap::remove(TKey c, TValue v) {
	Node* current = this->head;
	Node* prev = nullptr;

	while (current != nullptr) {
		if (current->data.first == c && current->data.second == v) {
			if (prev == nullptr) {
				this->head = current->next;
			}
			else {
				prev->next = current->next;
			}
			delete current;
			this->length--;
			return true;
		}
		prev = current;
		current = current->next;
	}

	return false;
}


vector<TValue> MultiMap::search(TKey c) const {
	vector<TValue> values;
	Node* current = this->head;
	while (current != nullptr) {
		if (current->data.first == c) {
			values.push_back(current->data.second);
		}
		current = current->next;
	}
	return values;
}


int MultiMap::size() const {
	return this->length;
}


bool MultiMap::isEmpty() const {
	return this->length == 0;
}

MultiMapIterator MultiMap::iterator() const {
	return MultiMapIterator(*this);
}


MultiMap::~MultiMap() {
	while (this->head != nullptr) {
		Node* temp = this->head;
		this->head = this->head->next;
		delete temp;
	}
}

vector<TValue> MultiMap::removeKey(TKey key) {
	std::vector<TValue> removedValues;
	Node* current = this->head;
	Node* prev = nullptr;

	while (current != nullptr) {
		if (current->data.first == key) {
			removedValues.push_back(current->data.second);
			if (prev == nullptr) {
				this->head = current->next;
				delete current;
				current = this->head;
			}
			else {
				prev->next = current->next;
				Node* temp = current;
				current = current->next;
				delete temp;
			}
			this->length--;
		}
		else {
			prev = current;
			current = current->next;
		}
	}

	return removedValues;
}
