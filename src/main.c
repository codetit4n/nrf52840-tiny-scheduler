#include "board.h"
#include "scheduler.h"
#include "systick.h"
#include "uarte.h"

void fn1(void) {
	char text[] = "RUN: fn1\r\n";
	uarte_write(text, sizeof(text) - 1);

	task_sleep(1000); // sleep for 1 second
}

void fn2(void) {
	char text[] = "RUN: fn2\r\n";
	uarte_write(text, sizeof(text) - 1);

	task_sleep(2000); // sleep for 2 seconds
}

void fn3(void) {
	char text[] = "RUN: fn3\r\n";
	uarte_write(text, sizeof(text) - 1);

	task_sleep(3000); // sleep for 3 seconds
}

void fn4(void) {
	char text[] = "RUN: fn4\r\n";
	uarte_write(text, sizeof(text) - 1);

	task_sleep(4000); // sleep for 4 seconds
}

void fn5(void) {
	char text[] = "RUN: fn5\r\n";
	uarte_write(text, sizeof(text) - 1);

	task_sleep(5000); // sleep for 5 seconds
}

int main(void) {
	init_uarte0();
	init_systick();

	schedule_task(fn1);
	schedule_task(fn2);
	schedule_task(fn3);
	schedule_task(fn4);
	schedule_task(fn5);

	start_scheduler();

	for (;;)
		;

	return 0;
}
