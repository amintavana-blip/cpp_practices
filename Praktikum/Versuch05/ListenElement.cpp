//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
//////////////////////////////////////////////////////////////////////////////

#include "ListenElement.h"

/**
 * @brief Konstruktor, der ein neues Listenelement mit allen Werten erstellt
 *
 * @param pData Ein Objekt der Klasse Student
 * @param pNext Zeiger auf das naechste Listenelement
 */
ListenElement::ListenElement(Student pData, ListenElement* pNext):
    data(pData), next(pNext), prev(nullptr) // NEU: prev wird standardmaessig auf nullptr gesetzt
{
}

/**
 * @brief Fuegt ein Objekt der Klasse Student ein
 *
 * @param pData Objekt der Klasse Student
 */
void ListenElement::setData(Student pData)
{
    data = pData;
}

/**
 * @brief Fuegt einen Zeiger auf das naechste Listenelement ein
 *
 * @param pNext Zeiger auf das naechste Listenelement
 */
void ListenElement::setNext(ListenElement* pNext)
{
    next = pNext;
}

// ==========================================
// NEU: Setter fuer den Vorgaenger-Zeiger
// ==========================================
/**
 * @brief Fuegt einen Zeiger auf das vorherige Listenelement ein
 *
 * @param pPrev Zeiger auf das vorherige Listenelement
 */
void ListenElement::setPrev(ListenElement* pPrev)
{
    prev = pPrev;
}

/**
 * @brief Gibt ein Objekt der Klasse Student zurueck
 *
 * @return Ein Objekt der Klasse Student
 */
Student ListenElement::getData() const
{
    return data;
}

/**
 * @brief Gibt einen Zeiger auf das naechste Listenelement zurueck
 *
 * @return Zeiger auf das naechste Listenelement
 */
ListenElement* ListenElement::getNext() const
{
    return next;
}

// ==========================================
// NEU: Getter fuer den Vorgaenger-Zeiger
// ==========================================
/**
 * @brief Gibt einen Zeiger auf das vorherige Listenelement zurueck
 *
 * @return Zeiger auf das vorherige Listenelement
 */
ListenElement* ListenElement::getPrev() const
{
    return prev;
}