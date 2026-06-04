//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
//////////////////////////////////////////////////////////////////////////////

#ifndef _LISTENELEMENT_H_
#define _LISTENELEMENT_H_

#include "Student.h"

class ListenElement
{
private:
    Student data;
    ListenElement* next;
    ListenElement* prev; // NEU: Zeiger auf das vorherige Element

public:
    ListenElement(Student pData, ListenElement* pNext);

    void setData(Student pData);
    void setNext(ListenElement* pNext);
    void setPrev(ListenElement* pPrev); // NEU: Setter fuer den Vorgänger

    Student getData() const;
    ListenElement* getNext() const;
    ListenElement* getPrev() const;     // NEU: Getter fuer den Vorgänger
};

#endif
