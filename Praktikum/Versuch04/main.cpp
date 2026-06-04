//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
// Versuch 04: Einf�hrung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

/**
 * @file main.cpp
 * @brief Hauptprogramm zur iterativen Berechnung der Sichtweite zum Horizont.
 */

#include "Vektor.h"
#include <iostream>
#include <iomanip> // Zwingend erforderlich fuer std::fixed und std::setprecision

/**
 * @brief Hauptfunktion des Programms.
 * * Berechnet iterativ die Entfernung, die ein Beobachter auf einer Plattform
 * auf einer ideal runden Erde sehen kann, bis der Horizont erreicht ist.
 * * @return int Gibt 0 zurueck, wenn das Programm erfolgreich beendet wurde.
 */
int main()
{
    // 1. Initialisierung der gegebenen Werte aus der Aufgabe
    double radiusErde = 6371000.0;           // 6371 km in Metern
    double plattformHoehe = 555.7;           // Plattform in Metern
    double menschHoehe = 1.70;               // Mensch in Metern
    
    // Die Gesamthoehe des Beobachters (Augenhoehe)
    double gesamtHoehe = plattformHoehe + menschHoehe; 

    // 2. Vektoren aufsetzen (Start auf der Y-Achse)
    // Beobachter befindet sich ueber der Erdoberflaeche
    Vektor beobachter(0.0, radiusErde + gesamtHoehe, 0.0);
    
    // Der Punkt auf der Oberflaeche startet direkt unter dem Beobachter
    Vektor horizont(0.0, radiusErde, 0.0);
    
    // 3. Iterations-Parameter
    // Eine Schrittweite von 10^-8 Radiant fuehrt exakt zu den geforderten 1.322.751 Schritten.
    double schrittweite = 0.00000001; 
    int schritte = 0;

    // Der Sichtvektor verlaeuft VOM Beobachter ZUM Punkt auf der Erdoberflaeche
    Vektor sicht = horizont.sub(beobachter);

    // 4. Iterative Berechnung (ohne Pythagoras!)
    // Wir drehen den Erd-Punkt so lange, bis die Sichtlinie tangential zur Erde liegt 
    // (Winkel genau 90 Grad, Skalarprodukt erreicht 0 oder wird minimal positiv).
    while (horizont.skalarProd(sicht) < 0.0)
    {
        horizont.rotiereUmZ(schrittweite); // Funktion aus Aufgabe 4.6.1
        sicht = horizont.sub(beobachter);  // Sichtvektor aktualisieren
        schritte++;                        // Schleifenzaehler erhoehen
    }

    // 5. Ergebnisse formatieren (wie in der Aufgabenstellung vorgegeben)
    // Gleitkommazahlen nicht als Exponent, sondern mit 4 Nachkommastellen anzeigen
    std::cout << std::fixed << std::setprecision(4);
    
    std::cout << "Sie koennen " << (sicht.laenge() / 1000.0) << " Km weit sehen.\n";
    std::cout << "Sie sind " << gesamtHoehe << " Meter hoch.\n";
    
    // Winkel Beta berechnen (Winkel zwischen Beobachter-Vektor und Horizont-Vektor am Erdmittelpunkt)
    // Da die winkel()-Funktion Radiant zurueckgibt, rechnen wir in Grad um (* 180 / Pi).
    double pi = 3.14159265358979323846;
    double winkelGrad = beobachter.winkel(horizont) * (180.0 / pi);
    
    std::cout << "Der Winkel betraegt " << winkelGrad << " Grad.\n";
    
    // Den Zaehler ausgeben
    std::cout << "Anzahl Schritte: " << schritte << "\n";

    return 0;
}