#include "MultiMapIterator.h"
#include "MultiMap.h"
#include <stdexcept>

MultiMapIterator::MultiMapIterator(const MultiMap& c): col(c), current(c.head) {}

TElem MultiMapIterator::getCurrent() const{
	if (!valid()) {
		throw std::runtime_error("Iterator not valid");
	}
	return current->data;
}

bool MultiMapIterator::valid() const {
	return current != nullptr;
}

void MultiMapIterator::next() {
	if (valid()) {
		current = current->next;
	}
	else {
		throw std::runtime_error("Iterator not valid");
	}
}

void MultiMapIterator::first() {
	current = col.head;
}

