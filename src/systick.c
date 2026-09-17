#include "systick.h"

void init_systick() {
	// Program reload value.
	LOAD_RVR = 63999; // For the 64Mhz processor

	// Clear current value
	VAL_CVR = 0; // write of any value clears to 0 - as per datasheet

	// Program Control and Status register.
	CTRL_CSR = (1 << 0) | // ENABLE - enable
		   (1 << 1) | // TICKINT - enable SysTick exception request on count reaching 0
		   (1 << 2) | // CLKSOURCE - processor clock
		   (0 << 16); // COUNTFLAG
}
