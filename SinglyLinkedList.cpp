using namespace std;                                    //������������ ����������� ���.

#include "SinglyLinkedList.h"                           //��������� ����� � �������� � �����������, ������� �� ������� ��� ������ � ����.

template<typename T>                                    //�������� ����� template ������������ ��� �������� ��������� (����������) ������� � �������.
SinglyLinkedList<T>::SinglyLinkedList()                 //����������� ��� ����������.
{
    size = 1;
    count = 0;
    data = new T[size];
}

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList(size_t size)      //����������� � �����������.
{
    if(size < 1)
    {
        size = 1;
    }
    this->size = size;
    this->count = 0;
    this->data = new T[size];
}

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList &mc)       //����������� �����������.
{
    this->size = mc.size;
    this->count = mc.count;
    this->data = new T[mc.size];
    for(size_t i=0;i<mc.count;i++)
    {
        this->data[i]=mc.data[i];
    }
}

template<typename T>
SinglyLinkedList<T>::~SinglyLinkedList()                //����������.
{
    delete [] data;
}

template<typename T>
SinglyLinkedList<T> & SinglyLinkedList<T>::operator=(const SinglyLinkedList<T> &mc)     //���������� ��������� ������������.
{
    delete [] this->data;
    this->size = mc.size;
    this->count = mc.count;
    this->data = new T[mc.size];
    for(size_t i=0;i<mc.count;i++)
    {
        this->data[i]=mc.data[i];
    }
}

template<typename T>
void SinglyLinkedList<T>::setsize(size_t Size)          //���������� ������ setsize.
    {
        this->size = Size;
    }

template<typename T>
bool SinglyLinkedList<T>::insertLast(T value)           //���������� ������ insertLast.
{
    if(count < size)
    {
        data[count] = value;
        ++count;
        return true;
    }   return false;
}

template<typename T>
bool SinglyLinkedList<T>::insertFirst(T value)          //���������� ������ insertFirst.
{
    if(count < size)
    {
        for(int i=size;i>=0;i--)
            data[i]=data[i-1];
        ++count;
        data[0] = value;
        return true;
    }   return false;
}

template<typename T>
bool SinglyLinkedList<T>::insertAtPos(size_t pos, T value)          //���������� ������ insertAtPos.
{
    if(pos < count && pos >= 0)
    {
        for(int i=size;i> pos;i--)
            data[i]=data[i-1];
        ++count;
        data[pos] = value;
        return true;
    }   return false;
}

template<typename T>
void SinglyLinkedList<T>::Delete(T value)           //���������� ������ Delete.
{
    int m=0;
    int pos=0;
    for(int i=0;i<count;i++)
    {
        if(data[i]==value)
            {
                pos = i;
                for (int i = pos; i < count; ++i)
                    data[i] = data[i + 1];
                --count;
                break;
            }
        m++;
    }
    if(m==count && pos!=count)
        cout << "������ ������� ����������� � ������." << endl;
}

template<typename T>
void SinglyLinkedList<T>::DeleteLast()              //���������� ������ DeleteLast.
{
    for (int i = 0; i < count; ++i)
        data[count] = data[count - 1];
    --count;
}

template<typename T>
void SinglyLinkedList<T>::DeleteFirst()             //���������� ������ DeleteFirst.
{
    for (int i = 0; i < count; ++i)
        data[i] = data[i + 1];
    --count;
}

template<typename T>
void SinglyLinkedList<T>::DeleteAtPos(size_t pos)           //���������� ������ DeleteAtPos.
{
    if(pos<count && pos >=0)
    {
        for (int i = pos; i < count; ++i)
            data[i] = data[i + 1];
        --count;
    }
}

template<typename T>
void SinglyLinkedList<T>::clear()                           //���������� ������ clear.
{
    this->count = 0;
    delete [] this->data;
    this->data = new T[this->count];
}

template<typename T>
T SinglyLinkedList<T>::getLast() const                      //���������� ������ getLast.
{
    return data[count-1];
}

template<typename T>
T SinglyLinkedList<T>::getFirst() const                     //���������� ������ getFirst.
{
    return data[0];
}

template<typename T>
void SinglyLinkedList<T>::isContains(size_t pos)const       //���������� ������ isContains.
{
    if (count > pos)
        cout << "������ ����� �������: " << data[pos] << "." << endl;
    else
        cout << "������ ����� ��� �� ����������� ������." << endl;
}

template<typename T>
void SinglyLinkedList<T>::isEmpty()const                    //���������� ������ isEmpty.
{
    if (count == 0)
        cout << "������ ����." << endl;
    else
        cout << "������ �������� ��������." << endl;
}

template<typename T>
size_t SinglyLinkedList<T>::Size()const                     //���������� ������ Size.
{
    cout << "���������� ����� � ������ (size): " << size << "." << endl;
    cout << "��������� ����� (count): " << count << "." << endl;
}

template<typename T>
void SinglyLinkedList<T>::print() const                     //���������� ������ print.
{
    for(size_t i=0;i<count;i++)
    {
        cout << data[i] << ", ";
    }
    cout << "\b\b.";
    if (count == 0)
        cout << "\b \b�����.";
    cout << endl;
}
