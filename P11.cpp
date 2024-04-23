/**********************************************************/
/* Autor: Kasim Mermer                                    */
/* Datum: 28.12.2016									  */
/* Projekt: P11A1										  */
/* Beschreibung: Matrizen- Rechnung.					  */
/**********************************************************/

// Bibliotheken
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

// Definitionen
#define Groesse 20

// Funktionen
int pruefen(char[Groesse]);
int pruefen2(char[Groesse]);
int zahl_eingabe(void);
int zahl_eingabe_ohne_fehler(void);
int** array_setzen(int**, int, int);
int** eingabe_der_Zahlen(int**, int, int);
void array_ausgeben(int**, int, int);

/*---- Hauptfunktionen für das Programm ----*/
int** rechnung_minus(int**, int**, int**, int, int);
int** rechnung_plus(int**, int**, int**, int, int);
void multiplikation(int, int, int, int, int**, int**, int**);
int** Skalar_multiplikation(int**, int**, int, int, int);
int** Transponierte(int**, int**, int, int);

int main(void)
{	// Deklarationen/ Initialisierungen.
	int wahl = 0, rechenwert = 0;
	char eingabe[Groesse] = { 0 };
	int zeile = 0, spalte = 0, aufhalten = 0;
	int **feld = 0;
	int **feld2 = 0;
	int **erg = 0;
	int index = 0, index2 = 0, dimension_s = 0, dimension_z = 0, dim2_s = 0, dim2_z = 0;

	while (wahl != 6)
	{
		// menue
		printf("Was moechten sie tun?\n (1) Subtraktion zweier Matrizen.\n (2) Addition zweier Matrizen.\n (3) Multiplikation zweier Matrizen.\n");
		printf(" (4) Multiplikation einer Mtrize mit einem Skalar.\n (5) Erstellen der Transponierten Matrize.\n");
		printf(" (6) Programm beenden.\n\nIhre Wahl:\t");
		fgets(eingabe, Groesse, stdin);
		wahl = pruefen(eingabe);
		// Alle Variablen auf 0 setzen damit man sie wieder verwenden kann
		dimension_s = 0;
		dim2_s = 0;
		dimension_z = 0;
		dim2_z = 0;
		printf("\n");
		// Switch- Case wahl wird gewählt
		switch (wahl)
		{
		case 1:
			while (dimension_z == 0)
			{
				printf("Geben sie die Anzahl der Zeilen fuer die erste Matrize ein:\t");
				dimension_z = zahl_eingabe();
			}
			while (dimension_s == 0)
			{
				printf("Geben sie die Anzahl der Spalten fuer die erste Matrize ein:\t");
				dimension_s = zahl_eingabe();
			}
			while (dim2_z == 0)
			{
				printf("Geben sie die Anzahl der Zeilen fuer die zweite Matrize ein:\t");
				dim2_z = zahl_eingabe();
			}
			while (dim2_s == 0)
			{
				printf("Geben sie die Anzahl der Spalten fuer die zweite Matrize ein:\t");
				dim2_s = zahl_eingabe();
			}
			// kontrolliert ob die Bedingung für +/- gilt
			if (dimension_s == dim2_s && dimension_z == dim2_z && wahl != 3)
			{
				// Funktionsaufrufe mit Rückgabeparameter
				feld = array_setzen(feld, dimension_z, dimension_s);
				feld2 = array_setzen(feld2, dimension_z, dimension_s);
				erg = array_setzen(erg, dimension_z, dimension_s);
				printf("\nGeben sie die Zahlen fuer die erste Matrize ein:\n");
				feld = eingabe_der_Zahlen(feld, dimension_z, dimension_s);
				printf("\nGeben sie die Zahlen fuer die zweite Matrize ein:\n");
				feld2 = eingabe_der_Zahlen(feld2, dimension_z, dimension_s);
				// Löscht Commando
				system("cls");
				printf("\nIhre erste Matrize:\n\n");
				array_ausgeben(feld, dimension_z, dimension_s);
				printf("\nIhre zweite Matrize:\n\n");
				array_ausgeben(feld2, dimension_z, dimension_s);
				printf("\nIhr Ergebnis Matrize fuer Subtraktion lautet:\n");
				erg = rechnung_minus(feld, feld2, erg, dimension_z, dimension_s);
				array_ausgeben(erg, dimension_z, dimension_s);
				// löscht die Addressen, welche reserviert wurde und macht auch den Speicher frei
				free(feld);
				free(feld2);
				free(erg);
			}
			else
			{
				// Fehlermeldung
				printf("\n\nSie haben einen Fehler gemacht\n\n");
			}
			// Damit das Programm zum stehen kommt
			fgets(eingabe, Groesse, stdin);
			system("cls");
			// springt aus switch- case raus
			break;
		case 2:
			while (dimension_z == 0)
			{
				printf("Geben sie die Anzahl der Zeilen fuer die erste Matrize ein:\t");
				dimension_z = zahl_eingabe();
			}
			while (dimension_s == 0)
			{
				printf("Geben sie die Anzahl der Spalten fuer die erste Matrize ein:\t");
				dimension_s = zahl_eingabe();
			}
			while (dim2_z == 0)
			{
				printf("Geben sie die Anzahl der Zeilen fuer die zweite Matrize ein:\t");
				dim2_z = zahl_eingabe();
			}
			while (dim2_s == 0)
			{
				printf("Geben sie die Anzahl der Spalten fuer die zweite Matrize ein:\t");
				dim2_s = zahl_eingabe();
			}
			// kontrolliert ob die Bedingung für +/- gilt
			if (dimension_s == dim2_s && dimension_z == dim2_z && wahl != 3)
			{
				// Funktionsaufrufe mit Rückgabeparameter
				feld = array_setzen(feld, dimension_z, dimension_s);
				feld2 = array_setzen(feld2, dimension_z, dimension_s);
				erg = array_setzen(erg, dimension_z, dimension_s);
				printf("\nGeben sie die Zahlen fuer die erste Matrize ein:\n");
				feld = eingabe_der_Zahlen(feld, dimension_z, dimension_s);
				printf("\nGeben sie die Zahlen fuer die zweite Matrize ein:\n");
				feld2 = eingabe_der_Zahlen(feld2, dimension_z, dimension_s);
				// Löscht Commando
				system("cls");
				printf("\nIhre erste Matrize:\n\n");
				array_ausgeben(feld, dimension_z, dimension_s);
				printf("\nIhre zweite Matrize:\n\n");
				array_ausgeben(feld2, dimension_z, dimension_s);
				printf("\nIhr Ergebnis Matrize fuer Addition lautet:\n");
				erg = rechnung_plus(feld, feld2, erg, dimension_z, dimension_s);
				array_ausgeben(erg, dimension_z, dimension_s);
				// löscht die Addressen, welche reserviert wurde und macht auch den Speicher frei
				free(feld);
				free(feld2);
				free(erg);
			}
			else
			{
				// Fehlermeldung
				printf("\n\nSie haben einen Fehler gemacht\n\n");
			}
			// Damit das Programm zum stehen kommt
			fgets(eingabe, Groesse, stdin);
			system("cls");
			// springt aus switch- case raus
			break;
		case 3:
			while (dimension_z == 0)
			{
				printf("Geben sie die Anzahl der Zeilen fuer die erste Matrize ein:\t");
				dimension_z = zahl_eingabe();
			}
			while (dimension_s == 0)
			{
				printf("Geben sie die Anzahl der Spalten fuer die erste Matrize ein:\t");
				dimension_s = zahl_eingabe();
			}
			while (dim2_z == 0)
			{
				printf("Geben sie die Anzahl der Zeilen fuer die zweite Matrize ein:\t");
				dim2_z = zahl_eingabe();
			}
			while (dim2_s == 0)
			{
				printf("Geben sie die Anzahl der Spalten fuer die zweite Matrize ein:\t");
				dim2_s = zahl_eingabe();
			}
			if (dimension_s == dim2_z)
			{
				// Funktionsaufrufe mit Rückgabeparameter
				feld = array_setzen(feld, dimension_z, dimension_s);
				feld2 = array_setzen(feld2, dim2_z, dim2_s);
				erg = array_setzen(erg, dimension_z, dim2_s);
				printf("\nGeben sie die Zahlen fuer die erste Matrize ein:\n");
				feld = eingabe_der_Zahlen(feld, dimension_z, dimension_s);
				printf("\nGeben sie die Zahlen fuer die zweite Matrize ein:\n");
				feld2 = eingabe_der_Zahlen(feld2, dim2_z, dim2_s);
				// Löscht Commando
				system("cls");
				printf("\nIhre erste Matrize:\n\n");
				array_ausgeben(feld, dimension_z, dimension_s);
				printf("\nIhre zweite Matrize:\n\n");
				array_ausgeben(feld2, dim2_z, dim2_s);
				printf("\nIhr Ergebnis Matrize fuer Multiplikation lautet:\n");
				multiplikation(dimension_z, dimension_s, dim2_z, dim2_s, feld, feld2, erg);
				array_ausgeben(erg, dimension_z, dim2_s);
				// löscht die Addressen, welche reserviert wurde und macht auch den Speicher frei
				free(feld);
				free(feld2);
				free(erg);
			}
			else
			{
				// Fehlermeldung
				printf("\n\n\nRechnung nicht moeglich,\nweil die Spalten der ersten Matrize nciht mit den\nZeilen der zweiten Matrize uebereinstimmen.\n\n");
			}
			// Damit das Programm zum stehen kommt
			fgets(eingabe, Groesse, stdin);
			system("cls");
			// springt aus switch- case raus
			break;
		case 4:
			while (dimension_z == 0)
			{
				printf("Geben sie die Anzahl der Zeilen fuer die erste Matrize ein:\t");
				dimension_z = zahl_eingabe();
			}
			while (dimension_s == 0)
			{
				printf("Geben sie die Anzahl der Spalten fuer die erste Matrize ein:\t");
				dimension_s = zahl_eingabe();
			}
			// Funktionsaufrufe mit Rückgabeparameter
			printf("\n\nGeben sie den Wert fuer die Rechnung ein:");
			rechenwert = zahl_eingabe_ohne_fehler();
			feld = array_setzen(feld, dimension_z, dimension_s);
			// erg[][] größen von zeilen und spalten von der ersten Matrize wird gleich gesetzt
			erg = array_setzen(erg, dimension_z, dimension_s);
			printf("\nGeben sie die Zahlen fuer die Matrize ein:\n");
			feld = eingabe_der_Zahlen(feld, dimension_z, dimension_s);
			// Löscht Commando
			system("cls");
			printf("\nIhre Matrize:\n\n");
			array_ausgeben(feld, dimension_z, dimension_s);
			printf("Die Skalarrechnung mit dem Wert \"%i\" fuer die Matrize ergibt:\n\n", rechenwert);
			erg = Skalar_multiplikation(feld, erg, dimension_z, dimension_s, rechenwert);
			array_ausgeben(erg, dimension_z, dimension_s);
			// löscht die Addressen, welche reserviert wurde und macht auch den Speicher frei
			free(feld);
			free(erg);
			// Damit das Programm zum stehen kommt
			fgets(eingabe, Groesse, stdin);
			system("cls");
			// springt aus switch- case raus
			break;
		case 5:
			while (dimension_z == 0)
			{
				printf("Geben sie die Anzahl der Zeilen fuer die erste Matrize ein:\t");
				dimension_z = zahl_eingabe();
			}
			while (dimension_s == 0)
			{
				printf("Geben sie die Anzahl der Spalten fuer die erste Matrize ein:\t");
				dimension_s = zahl_eingabe();
			}
			// Funktionsaufrufe mit Rückgabeparameter
			feld = array_setzen(feld, dimension_z, dimension_s);
			// erg[][] größen von zeilen und spalten von der ersten Matrize wird vertauscht gesetzt
			erg = array_setzen(erg, dimension_s, dimension_z);
			printf("\nGeben sie die Zahlen fuer die Matrize ein:\n");
			feld = eingabe_der_Zahlen(feld, dimension_z, dimension_s);
			// Löscht Commando
			system("cls");
			printf("\nIhre Matrize:\n\n");
			array_ausgeben(feld, dimension_z, dimension_s);
			printf("Die Transponierte Matrize daraus:\n");
			erg = Transponierte(feld, erg, dimension_z, dimension_s);
			array_ausgeben(erg, dimension_s, dimension_z);
			// löscht die Addressen, welche reserviert wurde und macht auch den Speicher frei
			free(feld);
			free(erg);
			// Damit das Programm zum stehen kommt
			fgets(eingabe, Groesse, stdin);
			// Löscht Commando
			system("cls");
			// springt aus switch- case raus
			break;
		case 6:
			// Programm end bedingung
			printf("Das Programm wird nun beendet.");
			fgets(eingabe, Groesse, stdin);
			// springt aus switch- case raus
			break;
		default:
			// Für Fehleingaben
			printf("Sie haben etwas falsches eingeben.");
			// damit das Programm zum stehen kommt
			fgets(eingabe, Groesse, stdin);
			// löscht commando
			system("cls");
			// springt aus switch- case raus
			break;
		}
	}
	// rückgabewert
	return 0;
}

// Funktion
int** Skalar_multiplikation(int **feld, int **erg, int dimension_z, int dimension_s, int rechenwert)
{
	// Initialisierungen/ Deklarationen
	int index, index2, index3, wert;
	for (index = 0; index < dimension_z; index++)
	{
		for (index2 = 0; index2 < dimension_s; index2++)
		{
			// Skalarrechnung. alle Werte von der Matrize die der User eingab, wird mit dem wert, welches der User eingab, berechnet
			erg[index][index2] = feld[index][index2] * rechenwert;
		}
	}
	// Gibt feld zurück 
	return erg;
}

// Funktion
int** Transponierte(int **feld, int **erg, int dimension_z, int dimension_s)
{
	// Initialisierungen/ Deklarationen
	int index, index2, index3;
	
	// hier wird die Matrize, die der User eingegeben hat, also die Werte, transponiert und in erg[][] gespeichert.
	for (index = 0; index < dimension_s; index++)
	{
		for (index2 = 0; index2 < dimension_z; index2++)
		{
			// Gibt Feld zurück
			erg[index][index2] = feld[index2][index];
		}
	}
	// Gibt feld zurück 
	return erg;
}

// Funtkion
void multiplikation(int dimension_z, int dimension_s, int dim2_z, int dim2_s, int **feld, int **feld2, int **erg)
{
	// Initialisierungen/ Deklarationen
	int index, index2, index3, zwischenspeicher;
	// Die Bedingung ob die Rechnung überhaupt funktionstüchtig ist

	for (index = 0; index < dim2_s; index++)		// rechnung
	{
		// solange index2 kleiner mit den spalten der ersten Matrizen ist
		for (index2 = 0; index2 < dimension_z; index2++)
		{
			// zwischenspeicher wird gleich 0 gesetzet weil sie gleich immer wieder + gerechnet wird
			zwischenspeicher = 0;
			// solange index3 kleienr spalten der ersten Matrize ist. die spalten der ersten matrize ist mit den zeilen der zweiten Matrize gleich gesetetzt.
			for (index3 = 0; index3 < dim2_z; index3++)
			{
				// die Rechnung für die Multiplikation der Matrize
				zwischenspeicher = zwischenspeicher + feld2[index3][index] * feld[index2][index3];			
			}
			// erg[][] wird gleich zwischenspeicher gesetezt und anschließend ausgegeben
			erg[index2][index] = zwischenspeicher;
		}
	}
	// Gibt feld zurück 
	// return erg;
}

// Funktion
int** rechnung_minus(int **feld, int **feld2, int **erg, int zeile, int spalte)
{
	// Initialisierungen/ Deklarationen
	int index, index2;
	// ergebnis rechnungen. die felder wurden alle mit übergeben
	for (index = 0; index < spalte; index++)
	{
		for (index2 = 0; index2 < zeile; index2++)
		{
			// Rechnung
			erg[index2][index] = feld[index2][index] - feld2[index2][index];
		}
	}
	// Gibt feld zurück 
	return erg;
}

// Funktion
int** rechnung_plus(int **feld, int **feld2, int **erg, int zeile, int spalte)
{
	// Initialisierungen/ Deklarationen
	int index, index2;
	// ergebnis rechnungen. die felder wurden alle mit übergeben
	for (index = 0; index < spalte; index++)
	{
		for (index2 = 0; index2 < zeile; index2++)
		{
			// Rechnung
			erg[index2][index] = feld[index2][index] + feld2[index2][index];
		}
	}
	// Gibt feld zurück 
	return erg;
}

// Funktion für die Eingabe der Arrays
int** eingabe_der_Zahlen(int **feld, int zeile, int spalte)
{
	// Initialisierungen/ Deklarationen
	char eingabe[Groesse] = { 0 };
	int index, index2, wert = 0;
	for (index = 0; index < zeile; index++)
	{
		for (index2 = 0; index2 < spalte; index2++)
		{
			// Textausgabe
			printf("Geben sie eine Zahl fuer die %i.te Zeile der %i.te Spalte ein:\t", index + 1, index2 + 1);
			fgets(eingabe, Groesse, stdin);
			wert = pruefen2(eingabe);
			if (wert == 1)
			{
				// gilt als 2D- Array und die zahlen werden hier eingegeben bzw. eingeführt
				feld[index][index2] = atoi(eingabe);
			}
			else
			{
				// Fehlermeldung
				printf("ungueltiger Wert.\n");
				index2--;
			}
		}
	}
	return feld;
}

// Zur Eingabe der Zahlen.
int zahl_eingabe(void)
{
	// Array/ Variablen		Deklarationen/ Initalisierungen
	char eingabe[Groesse] = { 0 };
	int wert = 0;
	// Array eingabe als zeichenkette
	fgets(eingabe, Groesse, stdin);
	// funktionsaufruf
	wert = pruefen(eingabe);
	// wenn wert = 1
	if (wert == 1)
	{
		// dann wandelt das programm die eingabe(string) in einen integer wert um und speichert es in die Variable wert ab.
		wert = atoi(eingabe);
	}
	// gibt dann wert zurück
	return wert;
}

int zahl_eingabe_ohne_fehler(void)
{
	// Array/ Variablen		Deklarationen/ Initalisierungen
	char eingabe[Groesse] = { 0 };
	int wert = 0, ende = 0;
	while (ende != 1)
	{
		// Array eingabe als zeichenkette
		fgets(eingabe, Groesse, stdin);
		// funktionsaufruf
		wert = pruefen2(eingabe);
		// wenn wert = 1
		if (wert == 1)
		{
			// dann wandelt das programm die eingabe(string) in einen integer wert um und speichert es in die Variable wert ab.
			wert = atoi(eingabe);
			ende = 1;
		}
		else
		{
			printf("Geben sie die Zahl erneut ein:\t");
		}
	}
	// gibt dann wert zurück
	return wert;
}

// setzt das zweiDimensionale Array zusammen und gibt es dann zurück.
int** array_setzen(int **feld, int zeile, int spalte)
{
	// Variablen Deklaration/ Initialisierung
	int index = 0;
	// setzt zeilenanzahl als pointer von feld
	feld = (int**)malloc(zeile * sizeof(int*));
	for (index = 0; index < zeile; index++)
	{
		// anschließend gibt er allen zeilen eine anzahl von integer größen bzw. werten.
		feld[index] = (int*)malloc(spalte * sizeof(int));
	}
	// gibt dann feld überarbeitet zurück
	return feld;
}

// Funktion
void array_ausgeben(int **feld, int zeile, int spalte)
{
	int index = 0, index2 = 0;
	// Gibt die Matrize aus. Alle Werte werden ausgegeben
	for (index = 0; index < zeile; index++)
	{
		for (index2 = 0; index2 < spalte; index2++)
		{
			printf("\t%i", feld[index][index2]);
		}
		printf("\n\n");
	}
}

// funktionsaufruf für pruefen // Gibt die umgewandelte Zahl zurück
int pruefen(char eingabe[Groesse]) {		// ein string wurde übergeben. ein integer wert wird übergeben
	int laenge = 0, fehler = 0, index = 0;	// initialisierungen
	laenge = strlen(eingabe);		// um herauszufinden wie groß der string ist
	if (eingabe[0] == '+') {		// überprüft ob ein + am anfang steht um es abzufangen
		laenge -= 2;		// wenn ja dann dekrementiert er die länge um 2
		for (index = 0; index < laenge; index++) {		// dient dazu um den + weg zu machen und um die zahlen zu vertauschen
			eingabe[index] = eingabe[index + 1];		// tauscht den ersten wert des arrays mit dem nächsten
			eingabe[index + 1] = 0;		// setzt den nächsten wert des arrays auf 0
		}
	}
	else {		// wenn die obige bedingung nicht erfüllt wurde dann führt er das aus
		laenge -= 1;	// länge wird um 1 dekrementiert. (länge--)
	}
	for (index = 0; index < laenge; index++) {		// dient dazu um alle string- zeichen zu überprüfen ob auch alle zahlen sind
		if (isdigit(eingabe[index]) == 0) {	// wenn eine 0 zurückgegeben wurde(also false) dann ist die stelle des arrays KEINE zahl und
			fehler++;		// die variable fehler wird incrementiert
		}
	}
	index = 0;		// index wird auf 0 gesetzt
	if (fehler == 0) {		// wenn fehler = 0 ist dann führt er die schleife aus
		index = atoi(eingabe);		// wandelt den string in einen integer wert um und setzt es mit index gleich
	}
	fehler = 0;	// setzt fehler = 0
	return index;	// gibt index wieder zurück
}			// ende........

// funktionsaufruf für pruefen // Gibt eine 1 oder eine 0 zurück
int pruefen2(char eingabe[Groesse]) {		// ein string wurde übergeben. ein integer wert wird übergeben
	int laenge = 0, fehler = 0, index = 0, minus = 0;	// initialisierungen
	laenge = strlen(eingabe);		// um herauszufinden wie groß der string ist
	if (eingabe[0] == '+') {		// überprüft ob ein + am anfang steht um es abzufangen
		laenge -= 2;		// wenn ja dann dekrementiert er die länge um 2
		for (index = 0; index < laenge; index++) {		// dient dazu um den + weg zu machen und um die zahlen zu vertauschen
			eingabe[index] = eingabe[index + 1];		// tauscht den ersten wert des arrays mit dem nächsten
			eingabe[index + 1] = 0;		// setzt den nächsten wert des arrays auf 0
		}
	}
	else {		// wenn die obige bedingung nicht erfüllt wurde dann führt er das aus
		laenge -= 1;	// länge wird um 1 dekrementiert. (länge--)
	}
	if (eingabe[0] == '-')
	{
		for (index = 1; index < laenge; index++) {		// dient dazu um alle string- zeichen zu überprüfen ob auch alle zahlen sind
			if (isdigit(eingabe[index]) == 0) {	// wenn eine 0 zurückgegeben wurde(also false) dann ist die stelle des arrays KEINE zahl und
				fehler++;		// die variable fehler wird incrementiert
			}
		}
	}
	else
	{
		for (index = 0; index < laenge; index++) {		// dient dazu um alle string- zeichen zu überprüfen ob auch alle zahlen sind
			if (isdigit(eingabe[index]) == 0) {	// wenn eine 0 zurückgegeben wurde(also false) dann ist die stelle des arrays KEINE zahl und
				fehler++;		// die variable fehler wird incrementiert
			}
		}
	}
	index = 0;		// index wird auf 0 gesetzt
	if (fehler == 0) {		// wenn fehler = 0 ist dann führt er die schleife aus
		index = 1;		// wandelt den string in einen integer wert um und setzt es mit index gleich
	}
	fehler = 0;	// setzt fehler = 0
	return index;	// gibt index wieder zurück
}			// ende........