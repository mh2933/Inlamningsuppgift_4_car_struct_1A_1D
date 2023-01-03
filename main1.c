#include "car.h"
#include <locale.h> // svenska tecken



/*************************************************************************************************
 main.c: Lagrar car-data för x antal bilar och skriver ut i terminalen
         samt till filen "car.txt". Nere i for loopen väljs stdout för utskrift till terminalen.
	 Växellådan på car3 byts till automatic från manual inuti car_intit() och 
	 car_change_transmission() funktionerna. Färgen byts från White till Green i funktionen
	 car_change_color.
 *************************************************************************************************/
int main(void)
{
	setlocale(LC_ALL, "Swedish"); // svenska tecken

	struct Car car1, car2, car3;
	FILE* ostream = fopen("car.txt", "w"); // "r" = read, "w" = write, "a" = append, "r+", "w+", "a+"

	/* array som används längre ner då ej car_print funktionen används */
	struct Car* car_array[] =
	{
		&car1,
		&car2,
		&car3
	};

	const size_t num_objects = sizeof(car_array) / sizeof(struct Car*);

	/* första initieringen av car objekten */
	car_init(&car1, "Volvo", "V70", "Black", 1995, TRANSMISSION_MANUAL);
	car_init(&car2, "BMW", "Z3", "Blue", 2001, TRANSMISSION_AUTOMATIC);
	car_init(&car3, "Skoda", "Octavia RS", "White", 2003, TRANSMISSION_MANUAL);

	
	/* andra initieringen, Ändrar växellådan till motsatsen på car1-car3 */
	//car_init(&car1, "Volvo", "V70", "Black", 1995, car_change_transmission(&car1));
	//car_init(&car2, "BMW", "Z3", "Blue", 2001, car_change_transmission(&car2));
	car_init(&car3, "Skoda", "Octavia RS", "White", 2003, car_change_transmission(&car3));
	
	/* Ändrar färgen på car3 till Grön, och output stream anges här som 0 = stdout */
	car_change_color(&car3, "Green");
	
/************************************************************************
 Array itterator, för de tre struct car objekten, en dubbelpekare behövs 
 då car_array är en enkelpekare. Startvärde är första array objektet
 i räknar sedan upp med hjälp av num_objects variablen som tar hjälp av 
 sizeof() operatorn. car_print funktionen används inne i ittetratorn.

	                  - ostream : skriver ut en .txt fil.
			  - stdout  : skriver ut till terminalen.   
************************************************************************/
	for (struct Car** i = car_array; i < car_array + num_objects; i++)
	{
		car_print(*i, stdout);
	}

	return 0;
}

