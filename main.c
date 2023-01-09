#include "car.h"
#include <locale.h> // svenska tecken



/*************************************************************************************************
 main.c: Uppgift 2.
		 Lagrar car-data för x antal bilar och skriver ut i terminalen
		 eller till filen "car.txt" då ostream väljs. 
		 Växellåda byts och kulör updateras. 
		 
		 b) Detta var mycket arbete för lite resultat, när man känner sig mer bekväm med 
		    koden så kommer det vara kul att snygga till koden men med tanke på att man 
		    dessutom förlorar massa minne så är motivationen svår. 
		    Jag föredrar nog just nu den lite mer lättskrivna koden, där inte funtionspekare
		    används. OMG det var en långkörare detta!! 
 *************************************************************************************************/
int main(void)
{
	setlocale(LC_ALL, "Swedish"); // svenska tecken

	struct Car car1, car2, car3;
	FILE* ostream = fopen("car.txt", "a"); // "r" = read, "w" = write, "a" = append, "r+", "w+", "a+"

	/* första initieringen av car objekten */
	car_init(&car1, "Volvo", "V70", "Black", 1995, TRANSMISSION_MANUAL);
	car_init(&car2, "BMW", "Z3", "Blue", 2001, TRANSMISSION_AUTOMATIC);
	car_init(&car3, "Skoda", "Octavia RS", "White", 2003, TRANSMISSION_MANUAL);
	

	// Här byts kulör, och växellåda byts.
	car3.change_color(&car3, "Green");
	car3.transmission_swap(&car3);

	// usskrift i terminalen
	car1.print(&car1, 0);
	car2.print(&car2, 0);
	car3.print(&car3, 0);

	// utskrift till fil
	car1.print(&car1, ostream);
	car2.print(&car2, ostream);
	car3.print(&car3, ostream);

	
	fclose(ostream);

	return 0;
}
