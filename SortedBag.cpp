#include "SortedBag.h"
#include "SortedBagIterator.h"

SortedBag::SortedBag(Relation r) {
    this->capacity = 4;
    this->length = 0;
    this->rel = r;
    this->data = new TComp[this->capacity];
}

// tetha(size)
void SortedBag::add(TComp e) {
    bool done = false;
    this->length ++;
    for(int i = this->length-2; i >= 0 && done == false; i --) {
        if(this->rel(this->data[i], e) == false) {
            this->data[i+1] = this->data[i];
        } else {
            this->data[i+1] = e;
            done = true;
        }
    }
    if(done == false) {
        this->data[0] = e;
    }
    if(this->length == this->capacity) {
        this->capacity *= 2;
        TComp* newArray = new TComp[this->capacity];
        for(int i = 0; i < this->length; i ++)
            newArray[i] = this->data[i];
        delete[] this->data;
        this->data = newArray;
    }
}

// tetha(n)
bool SortedBag::remove(TComp e) {
    if(this->length == 0)
        return false;
//    if(search(e) == false)
//        return false;

	bool found = false;
    for(int i = 0; i < this->length - 1; i ++) {
        if(this->data[i] == e) {
            found = true;
        }
        if(found == true) {
            this->data[i] = this->data[i+1];
        }
    }
    if(this->data[this->length-1] == e && found == false) {
        found = true;
    }
    if(found == true) {
        this->length --;
    }
    return found;
}

// tetha(n)
bool SortedBag::search(TComp elem) const {
	for(int i = 0; i < this->length; i ++) {
        if(elem == this->data[i])
            return true;
    }
    return false;
}

// O(n)
int SortedBag::nrOccurrences(TComp elem) const {
    int number = 0;
    for(int i = 0; i < this->length; i ++) {
        if(elem == this->data[i])
            number ++;
        else if(this->rel(elem, this->data[i]) == true)
            break;
    }
    return number;
}


// tetha(1)
int SortedBag::size() const {
	return this->length;
}

// tetha(1)
bool SortedBag::isEmpty() const {
    return (this->length == 0);
}


SortedBagIterator SortedBag::iterator() const {
	return SortedBagIterator(*this);
}


SortedBag::~SortedBag() {
	delete[] this->data;
}

