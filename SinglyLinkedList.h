#ifndef SINGLYLINKEDLIST_H_INCLUDED             //директива препроцессора: осуществл€ет условную компил€цию при неопределЄнности символической константы.
#define SINGLYLINKEDLIST_H_INCLUDED             //директива препроцессора: задаЄт макроопределение (макрос) или символическую константу.

using namespace std;                            //пространство стандартных имЄн.

#include <iostream>                             //заголовочный файл с классами, функци€ми и переменными дл€ организации ввода-вывода в €зыке программировани€ C++.

template<typename T>                            // лючевое слово template используетс€ дл€ создани€ шаблонных (обобщЄнных) функций и классов.
class SinglyLinkedList                          //ќбъ€вление шаблонного класса SinglyLinkedList.
{
private:                                        //модификатор доступа private: доступ открыт самому классу (т.е. функци€м-членам данного класса) и друзь€м (friend) данного класса - как функци€м, так и классам.
    size_t size;                                //объ€вление полей класса.
    size_t count;
    T * data;                                   //поле, представл€ющее динамический массив типа данных, который можно переопределить благодар€ шаблонному классу.
public:                                         //модификатор доступа public: доступ открыт всем, кто видит определение данного класса.
    SinglyLinkedList();                         //объ€вление конструктора без параметров.
    SinglyLinkedList(size_t size);              //объ€вление конструктора с параметрами.
    SinglyLinkedList(const SinglyLinkedList &mc);   //объ€вление конструктора копировани€.
    ~SinglyLinkedList();                        //объ€вление деструктора.

    SinglyLinkedList<T> & operator=(const SinglyLinkedList<T> &mc);         //объ€вление перегрузки оператора присваивани€ (=).

    void setsize(size_t Size);                  //объ€вление метода setsize.
    bool insertLast(T value);                   //объ€вление метода insertLast.
    bool insertFirst(T value);                  //объ€вление метода insertFirst.
    bool insertAtPos(size_t pos,T value);       //объ€вление метода insertAtPos.
    void Delete(T value);                       //объ€вление метода Delete.
    void DeleteLast();                          //объ€вление метода DeleteLast.
    void DeleteFirst();                         //объ€вление метода DeleteFirst.
    void DeleteAtPos(size_t pos);               //объ€вление метода DeleteAtPos.
    void clear();                               //объ€вление метода clear.
    T getLast()const;                           //объ€вление метода getLast.
    T getFirst()const;                          //объ€вление метода getFirst.
    void isContains(size_t pos)const;           //объ€вление метода isContains.
    void isEmpty()const;                        //объ€вление метода isEmpty.
    size_t Size()const;                         //объ€вление метода Size.
    void print() const;                         //объ€вление метода print.
};

#endif // SINGLYLINKEDLIST_H_INCLUDED           //директива препроцессора: конец ветки условной компил€ции.
