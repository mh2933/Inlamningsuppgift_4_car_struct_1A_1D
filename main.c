
#include "car.h"
#include <locale.h> // svenska tecken



/*************************************************************************************************
 main.c: Lagrar car-data f�r x antal bilar och skriver ut i terminalen
         samt till filen "car.txt". Undantag sker om dynamiskt minne inte
		 kunde allokeras, d� avslutas programmet med felkod 1.
 *************************************************************************************************/
int main(void)
{
	setlocale(LC_ALL, "Swedish"); // svenska tecken

	struct Car car1, car2, car3;
	FILE* ostream = fopen("car4.txt", "a+"); // "r" = read, "w" = write, "a" = append, "r+", "w+", "a+"

	/* array som anv�nds l�ngre ner d� ej car_print funktionen anv�nds */
	struct Car* car_array[] =
	{
		&car1,
		&car2,
		&car3
	};

	const size_t num_objects = sizeof(car_array) / sizeof(struct Car*);

	/* f�rsta initieringen av car objekten */
	car_init(&car1, "Volvo", "V70", "Black", 1995, TRANSMISSION_MANUAL);
	car_init(&car2, "BMW", "Z3", "Blue", 2001, TRANSMISSION_AUTOMATIC);
	car_init(&car3, "Skoda", "Octavia RS", "White", 2003, TRANSMISSION_MANUAL);

	
	/* andra initieringen, �ndrar v�xell�dan till motsatsen p� car1-car3, och s�tter utstr�m stdout */
	//car_init(&car1, "Volvo", "V70", "Black", 1995, car_change_transmission(&car1));
	//car_init(&car2, "BMW", "Z3", "Blue", 2001, car_change_transmission(&car2));
	car_init(&car3, "Skoda", "Octavia RS", "White", 2003, car_change_transmission(&car3));
	
	/* �ndrar f�rgen p� car3 till Gr�n, och output stream anges h�r som 0 = stdout */
	car_change_color(&car3, "Green");
	
/************************************************************************
 Array itterator, f�r de tre struct car objekten, en dubbelpekare beh�vs 
 d� car_array �r en enkelpekare. Startv�rde �r f�rsta array objektet
 i r�knar sedan upp med hj�lp av num_objects variablen som tar hj�lp av 
 sizeof() operatorn. car_print funktionen anv�nds inne i ittetratorn.

	                 - ostream : skriver ut en .txt fil.
					 - stdout  : skriver ut till terminalen.   
************************************************************************/
	for (struct Car** i = car_array; i < car_array + num_objects; i++)
	{
		car_print(*i, ostream);
		//printf("%s\n", *i);
	}

	return 0;
}