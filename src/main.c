#include "board.h"
#include "scheduler.h"
#include "systick.h"
#include "uarte.h"

void fn1() {
	char text[] = "Running function 1...\r\n";
	uarte_write(text, sizeof(text));
}

void fn2() {
	char text[] = "Running function 2...\r\n";
	uarte_write(text, sizeof(text));
}

void fn3() {
	char text[] = "Running function 3...\r\n";
	uarte_write(text, sizeof(text));
}

void fn4() {
	char text[] = "Running function 4...\r\n";
	uarte_write(text, sizeof(text));
}

void fn5() {
	char text[] = "Running function 5...\r\n";
	uarte_write(text, sizeof(text));
}

int main(void) {
	init_uarte0();
	init_systick();

	schedule_task(fn1);
	schedule_task(fn2);
	schedule_task(fn3);
	schedule_task(fn4);
	schedule_task(fn5);

	task_sleep(1);
	task_sleep(3);

	start_scheduler();

	for (;;)
		;

	return 0;
}
