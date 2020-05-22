#ifndef SINGLYLINKEDLIST_H_INCLUDED             //��������� �������������: ������������ �������� ���������� ��� ��������������� ������������� ���������.
#define SINGLYLINKEDLIST_H_INCLUDED             //��������� �������������: ����� ���������������� (������) ��� ������������� ���������.

using namespace std;                            //������������ ����������� ���.

#include <iostream>                             //������������ ���� � ��������, ��������� � ����������� ��� ����������� �����-������ � ����� ���������������� C++.

template<typename T>                            //�������� ����� template ������������ ��� �������� ��������� (����������) ������� � �������.
class SinglyLinkedList                          //���������� ���������� ������ SinglyLinkedList.
{
private:                                        //����������� ������� private: ������ ������ ������ ������ (�.�. ��������-������ ������� ������) � ������� (friend) ������� ������ - ��� ��������, ��� � �������.
    size_t size;                                //���������� ����� ������.
    size_t count;
    T * data;                                   //����, �������������� ������������ ������ ���� ������, ������� ����� �������������� ��������� ���������� ������.
public:                                         //����������� ������� public: ������ ������ ����, ��� ����� ����������� ������� ������.
    SinglyLinkedList();                         //���������� ������������ ��� ����������.
    SinglyLinkedList(size_t size);              //���������� ������������ � �����������.
    SinglyLinkedList(const SinglyLinkedList &mc);   //���������� ������������ �����������.
    ~SinglyLinkedList();                        //���������� �����������.

    SinglyLinkedList<T> & operator=(const SinglyLinkedList<T> &mc);         //���������� ���������� ��������� ������������ (=).

    void setsize(size_t Size);                  //���������� ������ setsize.
    bool insertLast(T value);                   //���������� ������ insertLast.
    bool insertFirst(T value);                  //���������� ������ insertFirst.
    bool insertAtPos(size_t pos,T value);       //���������� ������ insertAtPos.
    void Delete(T value);                       //���������� ������ Delete.
    void DeleteLast();                          //���������� ������ DeleteLast.
    void DeleteFirst();                         //���������� ������ DeleteFirst.
    void DeleteAtPos(size_t pos);               //���������� ������ DeleteAtPos.
    void clear();                               //���������� ������ clear.
    T getLast()const;                           //���������� ������ getLast.
    T getFirst()const;                          //���������� ������ getFirst.
    void isContains(size_t pos)const;           //���������� ������ isContains.
    void isEmpty()const;                        //���������� ������ isEmpty.
    size_t Size()const;                         //���������� ������ Size.
    void print() const;                         //���������� ������ print.
};

#endif // SINGLYLINKEDLIST_H_INCLUDED           //��������� �������������: ����� ����� �������� ����������.
