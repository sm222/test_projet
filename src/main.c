

#include "../include.h"

int main(void)
{
	printf(CLE);
	signature();
	sm_print_str(WHT"v1.0, work in progress - type 'help' to start\n");
	menu_loop(("user"),(""));
	return(0);
}