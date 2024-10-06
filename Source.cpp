#include "Header.h"
#include <iostream>
#include<Windows.h>
using namespace std;

DynamicArray::DynamicArray() :ptr(nullptr), size(0)
{}
DynamicArray::DynamicArray(int S)
{
	//cout << "Construct by 1 param\n";
	size = S;
	ptr = new int[S];
}

DynamicArray::DynamicArray(const DynamicArray& a)
{
	//cout << "Copy construct\n";
	size = a.size;
	ptr = new int[size];
	for (int i = 0; i < size; i++)
	{
		ptr[i] = a.ptr[i];
	}
}
DynamicArray::~DynamicArray()
{
	//cout << "Destruct\n";
	delete[] ptr;


}
void DynamicArray::Input()
{
	for (int i = 0; i < size; i++)
	{
		ptr[i] = rand() % 20;
	}
}
void DynamicArray::Output() const
{
	for (int i = 0; i < size; i++)
	{
		cout << ptr[i] << "\t";
	}
	cout << "\n---------------------------------\n";
}
int* DynamicArray::GetPointer() const
{
	return ptr;
}
int DynamicArray::GetSize() const
{
	return size;
}

void DynamicArray::ReSize(int newSize)
{
	int* newPtr = new int[newSize];
	int minSize = (newSize < size) ? newSize : size;
	for (int i = 0; i < minSize; i++)
	{
		newPtr[i] = ptr[i];
	}
	delete[] ptr;
	ptr = newPtr;
	size = newSize;
}

void DynamicArray::Sort()
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (ptr[j] > ptr[j + 1])
			{
				int temp = ptr[j];
				ptr[j] = ptr[j + 1];
				ptr[j + 1] = temp;
			}
		}
	}
}

int DynamicArray::Search(int a)
{
	for (int i = 0; i < size; i++)
	{
		if (ptr[i] == a)
		{
			return i;
		}
	}
	return -1;
}

void DynamicArray::Reverse()
{
	for (int i = 0; i < size / 2; i++)
	{
		swap(ptr[i], ptr[size - i - 1]);
	}
}

DynamicArray DynamicArray::operator+(int addSize) {
    DynamicArray temp(size + addSize); 
    for (int i = 0; i < size; i++) {
        temp.ptr[i] = ptr[i];
    }
    return temp;
}

DynamicArray DynamicArray::operator-(int delSize) {
    if (size > delSize) {
        DynamicArray temp(size - delSize);  
        for (int i = 0; i < temp.size; i++) {
            temp.ptr[i] = ptr[i]; 
        }
        return temp;
    }
    return *this;  
}

DynamicArray DynamicArray::operator*(int multiplier) {
    DynamicArray temp(size);
    for (int i = 0; i < size; i++) {
        temp.ptr[i] = ptr[i] * multiplier; 
    }
    return temp;
}

DynamicArray DynamicArray::operator-(const DynamicArray& other) {
    int newSize = (size < other.size) ? size : other.size;  
    DynamicArray temp(newSize);
    for (int i = 0; i < newSize; i++) {
        temp.ptr[i] = ptr[i] - other.ptr[i]; 
    }
    return temp;
}

DynamicArray DynamicArray::operator+(const DynamicArray& other) {
    DynamicArray temp(size + other.size);  
    for (int i = 0; i < size; i++) {
        temp.ptr[i] = ptr[i]; 
    }
    for (int i = 0; i < other.size; i++) {
        temp.ptr[size + i] = other.ptr[i];
    }
    return temp;
}

DynamicArray& DynamicArray::operator++() {
    this->ReSize(size + 1);  
    return *this;
}

DynamicArray& DynamicArray::operator--() {
    if (size > 1) {
        this->ReSize(size - 1); 
    }
    return *this;
}

