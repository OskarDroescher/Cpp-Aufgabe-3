#include <iostream>
#include "Matrix.h"
#include "MyExceptions.h"
using namespace std;

/*
Bearbeiten Sie die Aufgaben der Reihe nach direkt im Quellcode.
Sie koennen die Beschreibungen zur Aufgabenstellung loeschen, aber bitte
lassen Sie die Markierungen, wo welche Aufgabe beginnt im Quellcode!

Hinweis: Bitte geben Sie nur die Quelldateien ohne das Visual Studio Projekt ab!
*/

int main()
{
    bool change = false;
    int newValue = 0;
    // ------------------------------------------------------------------------
    // 1. Aufgabe (Referenzen)
    // ------------------------------------------------------------------------
    
    std::cout<<"\n\nAufgabe 1\n=========\n" <<std::endl;
    
	// Wo steckt der eigentliche Konstruktoraufruf bei der folgenden Anweisung?
    // ==> Der Konstruktoraufruf steckt in der Funktion
	// Wieso kann die Funktion ones() mit dem Scope-Operator, ohne Objekt aufgerufen werden? ==> Existiert kein Objekt und ein Objekt wird benötigt, wird das Objekt über einen Konstruktor definiert.
	Matrix33 mat1 = Matrix33::ones();
	
    // Ueber die Funktion Matrix33::get koennen sie einen Wert in der Matrix abfragen:
    string update = "0";
    do
    {
        std::cout << "Moechten Sie einen Wert in der Matrix anpassen? -> Ja = '1', Nein = '2':";
        int a, b;
        std::cin >> update;
        if (update == "1")
        {
            std::cout << "Neue Spalte eingeben:";
            std::cin >> a;
            std::cout << "Neue Zeile eingeben:";
            std::cin >> b;
            std::cout << "Neuen Wert eingeben:";
            std::cin >> newValue;
            change = true;
            std::cout << "Wert in Matrix (" + to_string(a) + ","  + to_string(b) + "):" << mat1.get(a-1, b-1, newValue, change) << std::endl;
            //Da ein Mensch bei eins anfängt zu zählen, der Computer bei Arrays jedoch mit 0 wird bei der Eingabe der Spalten und Zeilen der Wert um -1 verringert.
            //Dadurch muss der Mensch nicht anfangen plötzlich mit 0 beim Zählen anzufangen.
            change = false;
        }
    } while (update != "2");

    // veraendern Sie die Funktion Matrix33::get so, 
    // dass Sie ueber diese Funktion auch Werte verändern koennen:
	// Hinweis: Rueckgabewert als Referenz
    // mat1.get(1, 1) = 5;

    std::cout<<mat1.toString() <<std::endl; 

	
    // ------------------------------------------------------------------------
    // 2. Aufgabe (Operatoren)
    // ------------------------------------------------------------------------
    
    std::cout<<"\n\nAufgabe 2\n=========\n" <<std::endl;
    
    Matrix33 matA(-1,0,3,  2,-2.5,1,  -4,1.5,-1);
    Matrix33 matB(1,0,1,  1.5,0,0,  2.5,-1.5,-2);
    
    // Implementieren Sie die noetigen Operatoren in der Klasse, damit folgende
    // Ausdruecke richtig funktionieren und geben Sie nach jeder Rechnung die Ergebnisse aus:
    
    //Matrix33 matResult1 = matA + matB;
    //Matrix33 matResult2 = matA * matB;
    //Matrix33 matResult3 = matA * 5;
    //matResult1 += matB;
    //Matrix33 matC = matResult2 += matB;

    
    // ------------------------------------------------------------------------
    // 3. Aufgabe (Operatoren)
    // ------------------------------------------------------------------------
    
    std::cout<<"\n\nAufgabe 3\n=========\n" <<std::endl;
    
    // Testen Sie folgende Anweisung:
    //Matrix33 matResult4 = 5 * matA;
    
    // Warum funktioniert die Anweisung nicht? aendern Sie den '*' Operator so,
    // dass der Ausdruck funktioniert!
    

    
    // ------------------------------------------------------------------------
    // 4. Aufgabe (Konvertierungsoperator)
    // ------------------------------------------------------------------------
    
    std::cout<<"\n\nAufgabe 4\n=========\n" <<std::endl;
    
    Matrix33 matZ(1,3,5,  1,-2,1, 1.5, 3.5, -4);
    // Erzeugen Sie einen Konvertierungsoperator, so dass folgender Ausdruck klappt.
    double det;
    det = matZ.get(0,0,0,false)*matZ.get(1,1,0,false)*matZ.get(2,2,0,false)+matZ.get(0,1,0,false)*matZ.get(1,2,0,false)*matZ.get(2,0,0,false)+matZ.get(0,2,0,false)*matZ.get(1,0,0,false)*matZ.get(2,1,0,false)
        -(matZ.get(2,0,0,false)*matZ.get(1,1,0,false)*matZ.get(0,2,0,false)+matZ.get(2,1,0,false)*matZ.get(1,2,0,false)*matZ.get(0,0,0,false)+matZ.get(2,2,0,false)*matZ.get(1,0,0,false)*matZ.get(0,1,0,false));
    
    std::cout << "Die Determinante der folgenden 3x3 Matrix " << endl;
    std::cout << matZ.toString() << std::endl;
    std::cout << "ist: " + to_string(det) << endl;

    // Der Konvertierungsoperator soll die Determinante der Matrix zurueckgeben.
    // Hinweis: http://de.wikipedia.org/wiki/Determinante#Berechnung
    

    //double det = matZ;
    // ------------------------------------------------------------------------
    // 5. Aufgabe (Exception)
    // ------------------------------------------------------------------------
    
    std::cout<<"\n\nAufgabe 5\n=========\n" <<std::endl;
    Matrix33 matX(1, 3, 5, 1, -2, 1, 1.5, 3.5, -4);
    //string update = "0";
    do
    {
        std::cout << "Moechten Sie einen Wert in der Matrix anpassen? -> Ja = '1', Nein = '2':";
        int a, b;
        std::cin >> update;
        if (update == "1")
        {
            std::cout << "Neue Spalte eingeben:";
            std::cin >> a;
            std::cout << "Neue Zeile eingeben:";
            std::cin >> b;
            try {
                if (a > 3 || b > 3 || a < 1 || b < 1)
                    throw MatrixDimensionError();
                std::cout << "Neuen Wert eingeben:";
                std::cin >> newValue;
                change = true;
                std::cout << "Wert in Matrix (" + to_string(a) + "," + to_string(b) + "):" << matX.get(a - 1, b - 1, newValue, change) << std::endl;
                //Da ein Mensch bei eins anfängt zu zählen, der Computer bei Arrays jedoch mit 0 wird bei der Eingabe der Spalten und Zeilen der Wert um -1 verringert.
                //Dadurch muss der Mensch nicht anfangen plötzlich mit 0 beim Zählen anzufangen.
            }
            catch (const MatrixDimensionError e) {
                std::cout << "Exception:\n" << e.getError() << std::endl;
            }
            change = false;
        }
    } while (update != "2");
    std::cout << matX.toString() << std::endl;
    // Implementieren Sie ein Exceptionhandling mit einer extra definierten
	// Exceptionklasse. Ein Objekt dieser Klasse soll geworfen werden, wenn 
    // bei der Verwendung der get-Funktion fehlerhafte Indizes eingegeben werden
	// z.B.
    
    return 0;
}
