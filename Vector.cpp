#include "Vector.h"
#include <stdlib.h>

const int INCREASE = 2;

template <class T> LolVector<T> :: LolVector(int kek){
    array = new std::shared_ptr<T> [kek];
    size = 0;
    capacity = kek;
}

template <class T> TAlloccationBlock LolVector<T>::vector_allocator(sizeof(LolVector<T>), 100);

template <class T> void LolVector<T>::ResizeVector(std::shared_ptr<T> *&array){
    capacity *= INCREASE;
    std::shared_ptr<T> *tmp = new std::shared_ptr<T> [capacity];
    for(int i = 0; i < size; ++i){
        tmp[i] = array[i];
        array[i] = nullptr;
    }
    delete [] array;
    array = nullptr;
    array = tmp;
    tmp = nullptr;
}

template <class T> void * LolVector<T>::operator new (size_t size){
    return vector_allocator.allocate();
}

template <class T> void LolVector<T>::operator delete (void *p){
    vector_allocator.deallocate(p);
}

template <class T> void LolVector<T>::Push(std::shared_ptr<T> &temp){
    if (size == capacity){
        ResizeVector(array);
    }
    array[size] = temp;
    ++size;
}

template <class T> void LolVector<T>::Get(int lol){
    array[lol]->Print();
}

template <class T> void LolVector<T>::Delete(){
    array[size] = nullptr;
    size--;
}

template <class T> std::ostream& operator<<(std::ostream& os, const LolVector<T>& vector){
    for(int i = 0; i < vector.size; ++i){
        vector.array[i]->Print();
    }
    return os;
}

template <class T> int LolVector<T>::GetSize(){
    return size;
}

template <class T> void LolVector<T>::DeleteAll(){
    for(int i = 0; i < GetSize(); i++){
        array[i] = nullptr;
    }
    delete [] array;
    array = nullptr;
    capacity = size = 0;
}

template <class T> LolVector<T>::~LolVector(){
    DeleteAll();
}

template <class T> TIterator<T> LolVector<T>::begin(){
    return TIterator<T>(array);
}

template <class T> TIterator<T> LolVector<T>::end(){
    return TIterator<T>(array +  size);
}

#include "Figure.h"
template class LolVector<Figure>;
template std::ostream& operator<<(std::ostream& os, const LolVector<Figure> &vector);