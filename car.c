#include "car.h"
struct Car car1, car2, car3;

void car_init(struct Car* self,
	char* brand,
	char* model,
	char* color,
	unsigned int year_of_launch,
	enum transmission transmission)
{
	self->brand = brand;
	self->model = model;
	self->color = color;
	self->year_of_launch = year_of_launch;
	self->transmission = transmission;

	self->print = &car_print;
	self->transmission_str = &car_transmission_str;
	self->clear = &car_clear;
	self->change_color = &car_change_color;
	self->change_transmission = &car_change_transmission;
	self->transmission_swap = &car_transmission_swap;

	return;
}

void car_clear(struct Car* self)
{
	self->brand = 0;
	self->model = 0;
	self->color = 0;
	self->year_of_launch = 0;
	self->transmission = TRANSMISSION_NONE;

	self->print = 0;
	self->transmission_str = 0;
	self->clear = 0;
	self->change_color = 0;
	self->change_transmission = TRANSMISSION_NONE;
	self->transmission_swap = 0;

	return;
}

struct Car* car_new(char* brand,
	                char* model,
	                char* color,
	                unsigned int year_of_launch,
	                enum transmission transmission)
{
	struct Car* self = (struct Car*)malloc(sizeof(struct Car));
	if (!self) return 0;
	car_init(self, brand, model, color, year_of_launch, transmission);
	return self;
}

void car_delete(struct Car** self)
{
	free(*self);
	*self = 0;
	return;
}

void car_print(struct Car* self,
	FILE* ostream)
{
	if (!ostream) ostream = stdout;
	fprintf(ostream, "--------------------------------------------------------------------------------\n");
	fprintf(ostream, "Brand: %s\n", self->brand);
	fprintf(ostream, "Model: %s\n", self->model);
	fprintf(ostream, "Color: %s\n", self->color);
	fprintf(ostream, "Year of launch: %u\n", self->year_of_launch);
	fprintf(ostream, "Transmission: %s\n", car_transmission_str(self));
	fprintf(ostream, "--------------------------------------------------------------------------------\n\n");
	return;
}

/************************************************************************
* car_transmission_str: Tilldelar Enumerationen transmission till
*                       funktionen car_print.
*
*                       - self: Pekare till car objektet.
************************************************************************/
char* car_transmission_str(struct Car* self)
{
	if (self->transmission == TRANSMISSION_AUTOMATIC) return "Automatic";
	else if (self->transmission == TRANSMISSION_MANUAL) return "Manual";
	else if (self->transmission == TRANSMISSION_NONE) return "NONE";
	else return "Unspecified";

}

void car_change_color(struct Car* self, char* changed_color)
{

	//if (!ostream) ostream = stdout;
	//fprintf(ostream,"%s\n", self->color = changed_color);
	self->color = changed_color;
	return;
}

/************************************************************************
car_change_transmission: Byter växellådorna till motsatsten
						 Automatic <---> Manual.

			             - self              : Pekare till car objektet.
						 - transmission_type : växellåda specifieras
************************************************************************/
void car_change_transmission(struct Car* self, char* transmission_type)
{
	if (transmission_type == TRANSMISSION_MANUAL) self->transmission = TRANSMISSION_MANUAL;
	if (transmission_type == TRANSMISSION_AUTOMATIC) self->transmission = TRANSMISSION_AUTOMATIC;
}

// försök att få bort TRANSMISSION_ i main.c
void car_transmission_swap(struct Car* self)
{
	if (car_transmission_str(self) == "Automatic")
	{
		self->transmission = TRANSMISSION_MANUAL;
	}
	else if (car_transmission_str(self) == "Manual")
	{
		self->transmission = TRANSMISSION_AUTOMATIC;
	}
	return;
}
