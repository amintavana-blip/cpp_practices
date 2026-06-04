//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 04: Einf�hrung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"

Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{

}

Vektor::~Vektor()
{

}

/**
 * @brief Function printing the components of the vector 
 */
void Vektor::ausgabe() const
{
    std::cout << "X-Komponente: " << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}

/**
 * @brief Subtrahiert einen gegebenen Vektor von diesem Vektor
 * * @param input Der zu subtrahierende Vektor
 * @return Vektor Ein neuer Vektor, der das Ergebnis der Subtraktion darstellt
 */
Vektor Vektor::sub(const Vektor& input) const
{
    // Die Komponenten des uebergebenen Vektors werden von den aktuellen Komponenten abgezogen
    return Vektor(x - input.x, y - input.y, z - input.z);
}

/**
 * @brief Berechnet die Laenge (den Betrag) des aktuellen Vektors
 * * Formel: Euklidische Norm im 3D-Raum (Wurzel aus der Summe der Quadrate)
 * * @return double Die Laenge des Vektors
 */
double Vektor::laenge() const
{
    return std::sqrt(x * x + y * y + z * z);
}

/**
 * @brief Berechnet das Skalarprodukt dieses Vektors mit einem anderen Vektor
 * * Formel: (x1 * x2) + (y1 * y2) + (z1 * z2)
 * * @param input Der andere Vektor fuer das Skalarprodukt
 * @return double Das resultierende Skalarprodukt
 */
double Vektor::skalarProd(const Vektor& input) const
{
    return (x * input.x) + (y * input.y) + (z * input.z);
}

/**
 * @brief Berechnet den Winkel zwischen diesem Vektor und einem anderen Vektor (in Radiant)
 * * Formel: cos(alpha) = (A . B) / (|A| * |B|)  ->  alpha = acos(...)
 * * @param input Der Vektor, zu dem der Winkel berechnet werden soll
 * @return double Der Winkel in Radiant (0 bis Pi). Liefert 0.0 bei Division durch Null.
 */
double Vektor::winkel(const Vektor& input) const
{
    double zaehler = skalarProd(input);       // Skalarprodukt der beiden Vektoren
    double nenner = laenge() * input.laenge(); // Produkt der Laengen beider Vektoren

    // Schutz vor Division durch Null, falls einer der Vektoren ein Nullvektor ist
    if (nenner == 0.0) 
    {
        return 0.0; 
    }

    // Berechnet den Arkuskosinus des Verhaeltnisses, um den Winkel zu bestimmen
    return std::acos(zaehler / nenner);
}

/**
 * @brief Rotiert den Vektor um die Z-Achse um einen gegebenen Winkel (in Radiant)
 * * Bei einer Rotation um die Z-Achse bleibt die Z-Komponente unveraendert.
 * Die X- und Y-Komponenten werden mithilfe der Rotationsmatrix transformiert:
 * x_neu = x * cos(rad) - y * sin(rad)
 * y_new = x * sin(rad) + y * cos(rad)
 * * @param rad Der Rotationswinkel in Radiant
 */
void Vektor::rotiereUmZ(const double rad)
{
    // Die alten Werte muessen zwischengespeichert werden, da sie sich gegenseitig beeinflussen
    double alteX = x;
    double alteY = y;

    x = alteX * std::cos(rad) - alteY * std::sin(rad);
    y = alteX * std::sin(rad) + alteY * std::cos(rad);
    // Die Z-Komponente bleibt bei einer Rotation um die Z-Achse konstant
}
