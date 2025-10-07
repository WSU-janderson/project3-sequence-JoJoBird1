#include "Sequence.h"
#include <cstdlib>
#include <iostream>

using namespace std;

Sequence::Sequence(size_t sz = 0) 
    : 
{

}

size_t Sequence::size() const {
    return numElts;
}

bool Sequence::empty() const {
    return numElts == 0;
}