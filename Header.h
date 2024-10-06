#pragma once
#include <iostream>
using namespace std;

class DynamicArray {
    int* ptr;  // ��������� �� �����. ������
    int size;  // ������ ������� 
public:
    DynamicArray();
    DynamicArray(int);
    DynamicArray(const DynamicArray&);  // copy constructor
    ~DynamicArray();

    void Input();  // rand
    void Output() const;  // ����� �� �������
    int* GetPointer() const;
    int GetSize() const;

    void ReSize(int newSize);  // ��������� ������� �������
    void Sort();  // ����������(����� �������� ����������)
    int Search(int a);  // ����� �������� � �������, ���������� ������ ���������� ��������, ���� -1
    void Reverse();  // �������������� ������������������ ��������� � �������� �������

    // ���������� ����������
    DynamicArray operator+(int addSize);  // ����������� ���-�� ��������� �� 10
    DynamicArray operator-(int delSize);  // ������� ��������� ��������
    DynamicArray operator*(int multiplier);  // �������� ������ ������� �� 2
    DynamicArray operator-(const DynamicArray& other);  // �������� ��������
    DynamicArray operator+(const DynamicArray& other);  // ������������ ��������

    DynamicArray& operator++();  // ����������� ���-�� ��������� �� 1
    DynamicArray& operator--();  // ��������� ���-�� ��������� �� 1
};
