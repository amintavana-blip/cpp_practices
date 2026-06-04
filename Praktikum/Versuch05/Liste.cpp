//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
//////////////////////////////////////////////////////////////////////////////

#include "Liste.h"
#include <iostream> 

/**
 * @brief Standardkonstruktor, der eine leere Liste erstellt
 */
Liste::Liste(): front(nullptr), back(nullptr)
{
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Ende der Liste.
 *
 * @param pData Objekt der Klasse Student
 * @return void
 */
void Liste::pushBack(Student pData)
{
    ListenElement* neuesElement = new ListenElement(pData, nullptr);

    if (front == nullptr)                                      
    {
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
        back->setNext(neuesElement);
        neuesElement->setPrev(back); 
        back = neuesElement;
    }
}

/**
 * @brief Entfernen eines Listenelements am Anfang der Liste.
 *
 * @return void
 */
void Liste::popFront()
{
    if (front == nullptr) return; 

    ListenElement* cursor = front;

    if (front == back)                                       // Liste enthaelt nur ein Listenelement
    {
        front = nullptr;
        back = nullptr;
    }
    else
    {
        front = front->getNext();
        front->setPrev(nullptr); 
    }
    
    delete cursor; 
}

/**
 * @brief Pruefen, ob die Liste leer ist
 *
 * @return wenn leer true, sonst false
 */
bool Liste::empty()
{
    if(front == nullptr)
    {
        return true;
    }
    return false;
}

/**
 * @brief Gibt die Daten des ersten Listenelements in der Liste zurueck
 *
 * @return Objekt der Klasse Student
 */
Student Liste::dataFront()
{
    return front->getData();
}

/**
 * @brief Ausgabe der Liste vom ersten bis zum letzten Element.
 *
 * @return void
 */
void Liste::ausgabeVorwaerts() const
{
    ListenElement* cursor = front;

    while (cursor != nullptr)
    {
        cursor->getData().ausgabe();
        cursor = cursor->getNext();
    }
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Anfang der Liste.
 *
 * @param pData Objekt der Klasse Student
 * @return void
 */
void Liste::pushFront(Student pData)
{
    ListenElement* neuesElement = new ListenElement(pData, nullptr);

    if (front == nullptr) 
    {
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
        neuesElement->setNext(front); 
        front->setPrev(neuesElement); 
        front = neuesElement;         
    }
}

/**
 * @brief Ausgabe der Liste vom letzten bis zum ersten Element (rueckwaerts).
 *
 * @return void
 */
void Liste::ausgabeRueckwaerts() const
{
    ListenElement* cursor = back;

    while (cursor != nullptr)
    {
        cursor->getData().ausgabe();
        cursor = cursor->getPrev(); 
    }
}

/**
 * @brief Sucht und loescht einen Studenten anhand seiner Matrikelnummer.
 *
 * @param matNr Die Matrikelnummer des zu loeschenden Studenten
 * @return bool true wenn erfolgreich geloescht, false wenn nicht gefunden
 */
bool Liste::entferneStudent(unsigned int matNr)
{
    if (front == nullptr)
    {
        std::cout << "Die Liste ist leer!" << std::endl;
        return false;
    }

    ListenElement* cursor = front;

    while (cursor != nullptr)
    {
        if (cursor->getData().getMatNr() == matNr) 
        {
            std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
            cursor->getData().ausgabe();

            if (cursor == front && cursor == back)
            {
                front = nullptr;
                back = nullptr;
            }
            else if (cursor == front)
            {
                front = front->getNext();
                front->setPrev(nullptr);
            }
            else if (cursor == back)
            {
                back = back->getPrev();
                back->setNext(nullptr);
            }
            else
            {
                cursor->getPrev()->setNext(cursor->getNext());
                cursor->getNext()->setPrev(cursor->getPrev());
            }

            delete cursor;
            return true; 
        }
        cursor = cursor->getNext();
    }

    std::cout << "Ein Student mit der Matrikelnummer " << matNr << " wurde nicht gefunden." << std::endl;
    return false;
}