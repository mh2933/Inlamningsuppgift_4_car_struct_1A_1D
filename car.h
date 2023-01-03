#ifndef CAR_H_
#define CAR_H_

#include <stdio.h>  // printf mm.
#include <stdlib.h> // malloc, ralloc samt free mm. 

/********************************************************************************   
  enumerationer har oändligt scope i C likt Makron 
 ********************************************************************************/
enum transmission
{
	TRANSMISSION_MANUAL,
	TRANSMISSION_AUTOMATIC,
	TRANSMISSION_NONE
};

/********************************************************************************
  deklaration av strukten Car
 ********************************************************************************/
struct Car
{
	char* brand;
	char* model;
	char* color;
	unsigned int year_of_launch;
	enum transmission transmission;



};

/**********************************************************************************************
  car_init: Lagrar angiven bil data i ett car_objekt, initieringsrutin.
    
	        - brand          : Bilmärket lagrat som text.
			- model          : Bilmodell lagrad som text.
			- color          : Bilens färg lagrad som text.
			- year_of_launch : Året då bilmodellen togs i bruk lagrat som 
			                   ett heltal (gärna osignerat).
			- transmissiion  : Bilens transmissionstyp (manuell/automat) som 
			                   en enumerator av enumerationen car_transmission.
 **********************************************************************************************/
void car_init(struct Car* self,
	          char* brand,
	          char* model,
	          char* color,
	          unsigned int year_of_launch,
	          enum transmission transmission);

/**********************************************************************************************
  car_clear: Nollställer bildata lagrat av angivet car_objekt.

			- self          : Pekare till objektet som skall nollställas.
 **********************************************************************************************/
void car_clear(struct Car* self);

/**********************************************************************************************
  car_new: Allokerar minne och lagrar angiven car-data i ett car-objekt.
           En pekare till det dynamiskt allokerade objektet returneras.
		   Om minnesallokeringen misslyckas så returneras null.

		   - brand          : Bilmärket lagrat som text.
		   - model          : Bilmodell lagrad som text.
		   - color          : Bilens färg lagrad som text.
		   - year_of_launch : Året då bilmodellen togs i bruk lagrat som 
		                      ett heltal (gärna osignerat).

		   - transmissiion  : Bilens transmissionstyp (manuell/automat) som 
		                      en enumerator av enumerationen car_transmission.
 ***********************************************************************************************/
struct Car* car_new(char* brand,
	                char* model,
	                char* color,
	                unsigned int year_of_launch,
	                enum transmission transmission);

/*************************************************************************************************
  car_delete: Raderar angivet car-objekt genom att frigöra dynamiskt 
              allokerat minne för denna och sätter motsvarande pekare 
			  till null. För att möjliggöra detta passeras adressen till 
			  den pekare som pekar på det dynamiskt allokerade minnet.
              
			- self          : Pekare till objektet som skall nollställas.
 *************************************************************************************************/
void car_delete(struct Car** self);

/*************************************************************************************************
  car_print: Skriver ut lagrad car-data via angiven utström, där
             standardutenheten stdout används som default för utskrift
			 i terminalen.

			- self          : Pekare till objektet som lagrar car-data.
			- ostream       : Pekare till angiven utström (default = stdout).
 *************************************************************************************************/
void car_print(struct Car* self,
	           FILE* ostream);

/*************************************************************************************************
  car_transmission_str: Retunerar bilens växellåda (manuell/automat) i textform.

			            - self       : Pekare till objektet som lagrar car-data.
 *************************************************************************************************/
char* car_transmission_str(struct Car* self);

/*************************************************************************************************
  car_change_color: Ändrar färgen på car-objektet
   
                    - self                : Pekare till Car objektet.
				    - changed_color       : Pekare till medlemmen color inuti strukten car.
					- FILE*               : Fil pekare för vald utström.
 *************************************************************************************************/
void car_change_color(struct Car* self, char* changed_color, FILE* ostream);

/*************************************************************************************************
  car_change_transmission: Ändrar växellådan till motsatsen, 

					       - self       : Pekare till Car objektet.
						   - FILE*      : Fil pekare för vald utström.
 *************************************************************************************************/
char car_change_transmission(struct Car* self, FILE* ostream);

#endif
