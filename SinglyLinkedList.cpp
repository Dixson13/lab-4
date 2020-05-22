using namespace std;                                    //пространство стандартных имён.

#include "SinglyLinkedList.h"                           //шаблонный класс с методами и переменными, который мы создали для работы с ними.

template<typename T>                                    //Ключевое слово template используется для создания шаблонных (обобщённых) функций и классов.
SinglyLinkedList<T>::SinglyLinkedList()                 //конструктор без параметров.
{
    size = 1;
    count = 0;
    data = new T[size];
}

template<typename T>
SinglyLinkedList<T>::SinglyLinkedList(size_t size)      //конструктор с параметрами.
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
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList &mc)       //конструктор копирования.
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
SinglyLinkedList<T>::~SinglyLinkedList()                //деструктор.
{
    delete [] data;
}

template<typename T>
SinglyLinkedList<T> & SinglyLinkedList<T>::operator=(const SinglyLinkedList<T> &mc)     //перегрузка оператора присваивания.
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
void SinglyLinkedList<T>::setsize(size_t Size)          //реализация метода setsize.
    {
        this->size = Size;
    }

template<typename T>
bool SinglyLinkedList<T>::insertLast(T value)           //реализация метода insertLast.
{
    if(count < size)
    {
        data[count] = value;
        ++count;
        return true;
    }   return false;
}

template<typename T>
bool SinglyLinkedList<T>::insertFirst(T value)          //реализация метода insertFirst.
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
bool SinglyLinkedList<T>::insertAtPos(size_t pos, T value)          //реализация метода insertAtPos.
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
void SinglyLinkedList<T>::Delete(T value)           //реализация метода Delete.
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
        cout << "Данный элемент отсутствует в списке." << endl;
}

template<typename T>
void SinglyLinkedList<T>::DeleteLast()              //реализация метода DeleteLast.
{
    for (int i = 0; i < count; ++i)
        data[count] = data[count - 1];
    --count;
}

template<typename T>
void SinglyLinkedList<T>::DeleteFirst()             //реализация метода DeleteFirst.
{
    for (int i = 0; i < count; ++i)
        data[i] = data[i + 1];
    --count;
}

template<typename T>
void SinglyLinkedList<T>::DeleteAtPos(size_t pos)           //реализация метода DeleteAtPos.
{
    if(pos<count && pos >=0)
    {
        for (int i = pos; i < count; ++i)
            data[i] = data[i + 1];
        --count;
    }
}

template<typename T>
void SinglyLinkedList<T>::clear()                           //реализация метода clear.
{
    this->count = 0;
    delete [] this->data;
    this->data = new T[this->count];
}

template<typename T>
T SinglyLinkedList<T>::getLast() const                      //реализация метода getLast.
{
    return data[count-1];
}

template<typename T>
T SinglyLinkedList<T>::getFirst() const                     //реализация метода getFirst.
{
    return data[0];
}

template<typename T>
void SinglyLinkedList<T>::isContains(size_t pos)const       //реализация метода isContains.
{
    if (count > pos)
        cout << "Ячейка имеет элемент: " << data[pos] << "." << endl;
    else
        cout << "Ячейка пуста или не принадлежит списку." << endl;
}

template<typename T>
void SinglyLinkedList<T>::isEmpty()const                    //реализация метода isEmpty.
{
    if (count == 0)
        cout << "Список пуст." << endl;
    else
        cout << "Список содержит элементы." << endl;
}

template<typename T>
size_t SinglyLinkedList<T>::Size()const                     //реализация метода Size.
{
    cout << "Количество ячеек в списке (size): " << size << "." << endl;
    cout << "Заполнено ячеек (count): " << count << "." << endl;
}

template<typename T>
void SinglyLinkedList<T>::print() const                     //реализация метода print.
{
    for(size_t i=0;i<count;i++)
    {
        cout << data[i] << ", ";
    }
    cout << "\b\b.";
    if (count == 0)
        cout << "\b \bПусто.";
    cout << endl;
}
