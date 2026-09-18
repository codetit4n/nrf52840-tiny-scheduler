#include "board.h"
#include "scheduler.h"
#include "systick.h"
#include "uarte.h"

void fn1(void) {
	char text[] = "RUN: fn1\r\n";
	uarte_write(text, sizeof(text) - 1);

	task_sleep(0, 1000);
}

void fn2(void) {
	char text[] = "RUN: fn2\r\n";
	uarte_write(text, sizeof(text) - 1);

	task_sleep(1, 2000);
}

void fn3(void) {
	char text[] = "RUN: fn3\r\n";
	uarte_write(text, sizeof(text) - 1);

	task_sleep(2, 3000);
}

void fn4(void) {
	char text[] = "RUN: fn4\r\n";
	uarte_write(text, sizeof(text) - 1);

	task_sleep(3, 4000);
}

void fn5(void) {
	char text[] = "RUN: fn5\r\n";
	uarte_write(text, sizeof(text) - 1);

	task_sleep(4, 5000);
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
