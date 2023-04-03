#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>

using namespace std;

SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) {
    this->index = 0;
}

TComp SortedBagIterator::getCurrent() {
    if(valid())
        return this->bag.data[index];
    else
	    throw exception();
}

bool SortedBagIterator::valid() {
    if(this->index >= 0 && this->index < this->bag.size())
        return true;
    else
	    return false;
}

void SortedBagIterator::next() {
    if(valid())
        this->index ++;
    else
        throw exception();
}

void SortedBagIterator::first() {
    this->index = 0;
}

