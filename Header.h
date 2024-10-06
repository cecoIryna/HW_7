#pragma once
#include <iostream>
using namespace std;

class DynamicArray {
    int* ptr;  // указатель на динам. массив
    int size;  // размер массива 
public:
    DynamicArray();
    DynamicArray(int);
    DynamicArray(const DynamicArray&);  // copy constructor
    ~DynamicArray();

    void Input();  // rand
    void Output() const;  // вывод на консоль
    int* GetPointer() const;
    int GetSize() const;

    void ReSize(int newSize);  // изменение размера массива
    void Sort();  // сортировка(любой алгоритм сортировки)
    int Search(int a);  // поиск элемента в массиве, возвращает индекс найденного элемента, либо -1
    void Reverse();  // перезаписывает последовательность элементов в обратном порядке

    // Перегрузки операторов
    DynamicArray operator+(int addSize);  // увеличиваем кол-во элементов на 10
    DynamicArray operator-(int delSize);  // удаляем последние элементы
    DynamicArray operator*(int multiplier);  // умножаем каждый элемент на 2
    DynamicArray operator-(const DynamicArray& other);  // разность массивов
    DynamicArray operator+(const DynamicArray& other);  // конкатенация массивов

    DynamicArray& operator++();  // увеличиваем кол-во элементов на 1
    DynamicArray& operator--();  // уменьшаем кол-во элементов на 1
};
