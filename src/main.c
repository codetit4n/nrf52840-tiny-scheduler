#include "board.h"
#include "uarte.h"

int main(void) {
	init_uarte0();

	while (1) {
		uarte_write("Scheduler ready!\r\n", sizeof("Scheduler ready!\r\n") - 1);
		delay(6 * 1000 * 1000); // small delay
	}
}
