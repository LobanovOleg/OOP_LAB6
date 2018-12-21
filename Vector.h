#ifndef VECTOR_H
#define VECTOR_H



#include "Figure.h"
#include "Pentagon.h"
#include "Trapeze.h"
#include "Rhombus.h"
#include "Iterator.h"
#include "TAlloccationBlock.h"


template <class T> class LolVector{
public:
    LolVector(int kek); //конструктор класса
    void Push(std::shared_ptr<T> &temp); //добавление элемента в класс
    void Get(int lol); //получение элемента класса
    void Delete(); //удаление поледнего элемента
    template <class A> friend std::ostream& operator<<(std::ostream& os, const LolVector<A>& vector); //вывод в стандартный поток
    void DeleteAll();
    ~LolVector(); //деструктор класса
    TIterator<T> begin(); // Установка итератора на начало
    TIterator<T> end(); // Установка итератора на конец
    int GetSize(); // получение размера класса
    void * operator new (size_t size); // переопределенный оператор выделения памяти из кучи
    void operator delete (void *p); // возвращение памяти в кучу
private:
    void ResizeVector(std::shared_ptr<T> *&array); //изменение размера вектора
    int size; //текущее количество элементов
    int capacity; // выделенное место
    std::shared_ptr<T> *array; //массив

    static TAlloccationBlock vector_allocator;
};

#endif