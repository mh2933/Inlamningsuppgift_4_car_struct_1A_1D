
#include "car.h"
#include <locale.h> // svenska tecken



/*************************************************************************************************
 main.c: Lagrar car-data för x antal bilar och skriver ut i terminalen
         samt till filen "car.txt". Undantag sker om dynamiskt minne inte
		 kunde allokeras, då avslutas programmet med felkod 1.
 *************************************************************************************************/
int main(void)
{
	setlocale(LC_ALL, "Swedish"); // svenska tecken

	struct Car car1, car2, car3;

	/* första initieringen av car objekten */
	car_init(&car1, "Volvo", "V70", "Black", 1995, TRANSMISSION_MANUAL);
	car_init(&car2, "BMW", "Z3", "Blue", 2001, TRANSMISSION_AUTOMATIC);
	car_init(&car3, "Skoda", "Octavia RS", "White", 2003, TRANSMISSION_MANUAL);

	// Skriver ut filen car.txt till terminalen
	file_read("car.txt");

	return 0;
}