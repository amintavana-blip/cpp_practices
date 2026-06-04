/**
 * Praktikum Informatik 1
 *
 *
 * @file main.cpp
 *
 * Die Funktionen fuer das Spiel Othello
 */

/**
 * @mainpage Othello
 *
 * Dokumentation des Spiels Othello im Rahmen des Praktikums Informatik 1.
 *
 */

#include <iostream>
#include <string>
#include "config.h"
#include "test.h"
#include "othelloKI.h"

/**
 * @brief Funktion zur ersten Initialisierung eines neuen Spielfelds
 *
 * Diese Funktion fuellt ein existierendes Spielfeld mit Nullen und erzeugt die Startaufstellung.
 *
 * @param spielfeld Spielfeld, das initialisiert wird
 */
void initialisiereSpielfeld(int spielfeld[GROESSE_Y][GROESSE_X])
{
    for (int j = 0; j < GROESSE_Y; j++)
    {
        for (int i = 0; i < GROESSE_X; i++)
        {
            spielfeld[j][i] = 0;
        }
    }
    spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2 - 1] = 1;
    spielfeld[GROESSE_Y / 2][GROESSE_X / 2 - 1] = 2;
    spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2] = 2;
    spielfeld[GROESSE_Y / 2][GROESSE_X / 2] = 1;
}

/**
 * @brief Ausgabe des Spielfelds auf der Konsole
 *
 * Ausgabe des aktuellen Spielfelds, 0 bedeutet leeres Feld, 1 ist Spieler 1 und 2 ist Spieler2
 * Kreuze symbolisieren Spieler 1, waehrend Kreise Spieler 2 symbolisieren
 *
 *  @param spielfeld  Spielfeld, das ausgeben wird
 */
void zeigeSpielfeld(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    std::cout << "   | ";

    // Start bei ASCII 65 = A
    for (int i = 65; i < 65 + GROESSE_X; ++i)
        std::cout << ((char)i) << " | ";

    std::cout << std::endl;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for (int i = 0; i < GROESSE_X; ++i)
        {
            std::cout << "---+";
        }
        std::cout << "---+" << std::endl;

        std::cout << " " << j + 1 << " |";
        for (int i = 0; i < GROESSE_X; ++i)
        {
            switch (spielfeld[j][i])
            {
            case 0:
                std::cout << "   ";
                break;
            case 1:
                std::cout << " X ";
                break;
            case 2:
                std::cout << " O ";
                break;
            default:
                std::cout << "Unzulaessige Daten im Spielfeld!" << std::endl;
                std::cout << "Abbruch .... " << std::endl;
                exit(0);
                break;
            }
            std::cout << "|";
        }; // for i
        std::cout << std::endl;
    } // for j
}

/**
 * @brief Prueft, wer Gewinner ist
 *
 * Zaehlt alle Steine auf dem Feld
 *
 * @param spielfeld Aktuelles Spielfeld, fuer das der Gewinner ermittelt wird
 * @return winner
 */
int gewinner(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    int zaehlerSpieler1 = 0;
    int zaehlerSpieler2 = 0;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for (int i = 0; i < GROESSE_X; ++i)
        {
            if (spielfeld[j][i] == 1)
            {
                ++zaehlerSpieler1;
            }
            if (spielfeld[j][i] == 2)
            {
                ++zaehlerSpieler2;
            }
        }
    }

    if (zaehlerSpieler1 == zaehlerSpieler2)
    {
        return 0;
    }
    if (zaehlerSpieler1 < zaehlerSpieler2)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

/**
 * @brief Ueberprueft fuer zwei Indizes, ob sie auf dem Spielfeld sind
 *
 * @param posX Index fuer die Spalte
 * @param posY Index fuer die Zeile
 * @return true, wenn Spalte und Zeile innerhalb des Spielfelds sind, sonst false
 */
bool aufSpielfeld(const int posX, const int posY)
{
    // Überprüfen, ob die Koordinaten im gültigen Bereich [0, GROESSE-1] liegen
    return (posX >= 0 && posX < GROESSE_X && posY >= 0 && posY < GROESSE_Y);
}

/**
 * @brief Ueberprueft fuer zwei Indizes, ob der Zug gueltig ist
 *
 *  Ueberprueft, ob auf einem benachbarten Feld ein gegnerischer Stein liegt.
 *  Wenn ja, wird diese Richtung solange untersucht, bis ein eigener Stein
 *  gefunden wird. Wird vorher der Spielfeldrand erreicht oder ein leeres Feld
 *  gefunden, wird false zurueckgegeben, sonst true
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Zu ueberpruefende Spalte
 * @param posY Zu ueberpruefende Zeile
 * @return
 */
bool zugGueltig(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{
    int gegner = 3 - aktuellerSpieler; // dasselbe wie: if aktuellerSpieler == 1 -> gegner = 2
                                       //               if aktuellerSpieler == 2 -> gegner = 1

    // Vorbedingung: Das Feld selbst muss auf dem Spielfeld liegen und leer (0) sein
    if (!aufSpielfeld(posX, posY) || spielfeld[posY][posX] != 0)
    {
        return false;
    }

    // Alle 8 Richtungen ueberpruefen bis erster gueltiger Zug gefunden
    for (int j = -1; j <= 1; j++)
    {
        for (int i = -1; i <= 1; i++)
        {
            // Die Richtung (0,0) bedeutet kein Schritt, diese wird uebersprungen
            if (i == 0 && j == 0)
            {
                continue;
            }

            // Koordinaten des direkt benachbarten Feldes (erster Schritt)
            int x = posX + i;
            int y = posY + j;

            // Schritt 1: Das direkte Nachbarfeld muss einen gegnerischen Stein enthalten
            if (aufSpielfeld(x, y) && spielfeld[y][x] == gegner)
            {
                // Schritt 2: Weiter in diese Richtung laufen (Sondierung)
                while (true)
                {
                    x += i; // Naechster Schritt in dieselbe Richtung
                    y += j;

                    // Wenn wir das Spielfeld verlassen oder ein leeres Feld finden -> ungueltige Richtung
                    if (!aufSpielfeld(x, y) || spielfeld[y][x] == 0)
                    {
                        break; // Schleife abbrechen, naechste Richtung der for-Schleifen prüfen
                    }

                    // Wenn wir einen eigenen Stein finden -> der Zug ist insgesamt gueltig!
                    if (spielfeld[y][x] == aktuellerSpieler)
                    {
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

/**
 * @brief Funktion, die einen Zug ausfuehrt
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Die aktuelle Spalte
 * @param posY Die aktuelle Zeile
 */
void zugAusfuehren(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{
    int gegner = 3 - aktuellerSpieler;

    spielfeld[posY][posX] = aktuellerSpieler;

    // Alle Richtungen bearbeiten
    for (int j = -1; j <= 1; j++)
    {
        for (int i = -1; i <= 1; i++)
        {
            // aehnlich wie die Funktion zugGueltig(), aber stellen Sie sicher, das alle gegnerischen Steine in
            // allen Richtungen in Ihre eigenen Steine umgewandelt werden
            //
            // Die Richtung (0,0) ueberspringen
            if (i == 0 && j == 0)
            {
                continue;
            }

            int x = posX + i;
            int y = posY + j;
            bool richtungGueltig = false;

            // Schritt 1: Vorwaerts pruefen, ob in dieser Richtung Steine umgedreht werden koennen
            if (aufSpielfeld(x, y) && spielfeld[y][x] == gegner)
            {
                while (true)
                {
                    x += i;
                    y += j;

                    if (!aufSpielfeld(x, y) || spielfeld[y][x] == 0)
                    {
                        break; // Richtung ist nicht gueltig
                    }

                    if (spielfeld[y][x] == aktuellerSpieler)
                    {
                        richtungGueltig = true; // Ein eigener Stein wurde gefunden.
                        break;
                    }
                }
            }

            // Schritt 2: Wenn die Richtung gueltig war, laufen wir rueckwaerts zum Ausgangspunkt
            // und waehrenddessen drehen wir alle gegnerischen Steine um.
            if (richtungGueltig)
            {
                // Wir starten von dem zuletzt gefundenen eigenen Stein (x, y)
                // und gehen schrittweise zurueck, bis wir wieder bei (posX, posY) sind.
                x -= i;
                y -= j;

                while (x != posX || y != posY)
                {
                    spielfeld[y][x] = aktuellerSpieler; // Gegnerischen Stein umdrehen!
                    x -= i;                             // Weiter zurueckgehen
                    y -= j;
                }
            }
        }
    }
}

int moeglicheZuege(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    int anzahlZuege = 0;

    // Das gesamte Spielfeld Feld fuer Feld durchlaufen
    for (int y = 0; y < GROESSE_Y; y++)
    {
        for (int x = 0; x < GROESSE_X; x++)
        {
            // Pruefen, ob auf diesem konkreten Feld (x, y) ein Zug gueltig ist
            if (zugGueltig(spielfeld, aktuellerSpieler, x, y))
            {
                anzahlZuege++; // Wenn ja, erhoehe den Zaehler
            }
        }
    }

    return anzahlZuege; // Gibt die Gesamtzahl der gueltigen Zuege zurueck

    return 0;
}

bool menschlicherZug(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    if (moeglicheZuege(spielfeld, aktuellerSpieler) == 0)
    {
        return false;
    }

    int posX;
    int posY;
    std::string symbolSpieler;
    if (aktuellerSpieler == 1)
    {
        symbolSpieler = "X";
    }
    else
    {
        symbolSpieler = "O";
    }

    while (true)
    {
        std::string eingabe;
        std::cout << std::endl
                  << "Du bist " << symbolSpieler << ". Dein Zug (z.B. A1, a1): ";
        std::cin >> eingabe;
        posX = (int)eingabe[0] % 32 - 1;
        posY = (int)eingabe[1] - 49;

        if (zugGueltig(spielfeld, aktuellerSpieler, posX, posY))
        {
            // accept turn;
            break;
        }
        else
        {
            std::cout << std::endl
                      << "Ungueltige Eingabe !" << std::endl;
        }
    }

    zugAusfuehren(spielfeld, aktuellerSpieler, posX, posY);
    std::cout << std::endl
              << "Spieler " << aktuellerSpieler << " setzt auf " << (char)(posX + 65) << (posY + 1) << std::endl;

    return true;
}

void spielen(const int spielerTyp[2])
{
    int spielfeld[GROESSE_Y][GROESSE_X];

    // Erzeuge Startaufstellung
    initialisiereSpielfeld(spielfeld);

    int aktuellerSpieler = 1;
    zeigeSpielfeld(spielfeld);

    // solange noch Zuege bei einem der beiden Spieler moeglich sind
    //
    // Variablen, um zu zaehlen, wie oft hintereinander gepasst wurde
    int aufeinanderfolgendePässe = 0;

    // Hauptspielschleife (Game Loop)
    // Das Spiel laeuft so lange, bis beide Spieler direkt hintereinander passen muessen
    while (aufeinanderfolgendePässe < 2)
    {
        // Pruefen, ob der aktuelle Spieler ueberhaupt Zuege machen kann
        if (moeglicheZuege(spielfeld, aktuellerSpieler) > 0)
        {
            // Zuruecksetzen des Pass-Zaehlers, da ein Zug moeglich ist
            aufeinanderfolgendePässe = 0;

            // Welcher Typ ist der aktuelle Spieler? (Index 0 fuer Spieler 1, Index 1 fuer Spieler 2)
            int typ = spielerTyp[aktuellerSpieler - 1];

            if (typ == 1)
            {
                // Menschlicher Spieler am Zug
                menschlicherZug(spielfeld, aktuellerSpieler);
            }
            else
            {
                // KI am Zug
                std::cout << std::endl << "KI (Spieler " << aktuellerSpieler << ") denkt nach..." << std::endl;
                computerZug(spielfeld, aktuellerSpieler); 
            }

            // Nach dem Zug das neue Spielfeld anzeigen
            zeigeSpielfeld(spielfeld);
        }
        else
        {
            // Spieler hat keine Zuege -> Er muss passen!
            aufeinanderfolgendePässe++;
            std::cout << std::endl << "Spieler " << aktuellerSpieler << " hat keine Zuege und muss PASSEN!" << std::endl;
        }

        // Spielerwechsel (Wechselt zwischen 1 und 2)
        aktuellerSpieler = 3 - aktuellerSpieler;
    }

    std::cout << std::endl << "=== SPIEL ENDE ===" << std::endl;

    // Spielerauswertung und Verkündung des Gewinners
    switch (gewinner(spielfeld))
    {
        case 0:
            std::cout << "Das Spiel endet unentschieden (Remis)!" << std::endl;
            break;
        case 1:
            std::cout << "Herzlichen Glueckwunsch! Spieler 1 (X) hat gewonnen!" << std::endl;
            break;
        case 2:
            std::cout << "Herzlichen Glueckwunsch! Spieler 2 (O) hat gewonnen!" << std::endl;
            break;
        default:
            std::cout << "Fehler bei der Gewinnerermittlung!" << std::endl;
            break;
    }
}

int main()
{
    if (TEST == 1)
    {
        bool gesamtErgebnis = ganzenTestAusfuehren();
        if (gesamtErgebnis == true)
        {
            std::cout << "ALLE TESTS BESTANDEN!" << std::endl;
        }
        else
        {
            std::cout << "MINDESTENS EIN TEST IST FEHLGESCHLAGEN!" << std::endl;
            exit(1);
        }
        std::cout << std::endl
                  << std::endl;
    }

    // Die folgenden drei Zeilen werden auskommentiert oder geloescht, nachdem Sie die Funktion spielen()
    // implementiert haben (waeren sonst doppelt)
    int spielfeld[GROESSE_Y][GROESSE_X];

    initialisiereSpielfeld(spielfeld);

    zeigeSpielfeld(spielfeld);

    // int spielerTyp[2] = { COMPUTER, COMPUTER };  // Feld, das Informationen ueber den Typ des Spielers enthaelt. MENSCH(=1) oder COPMUTER(=2)
    // spielen(spielerTyp);
    //
    int spielerTyp[2] = { COMPUTER, COMPUTER };
    spielen(spielerTyp);

    return 0;
}
