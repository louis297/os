#include "console.h"

int kern_entry()
{
	console_clear();

	console_write_color("Hello, Louis!\n", rc_black, rc_light_brown);


	return 0;
}
