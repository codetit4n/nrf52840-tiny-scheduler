#include "board.h"
#include "scheduler.h"
#include "uarte.h"
#include "utils.h"

void fn1() {
	char text[] = "Running function 1...";
	uarte_write(text, sizeof(text));
}

void fn2() {
	char text[] = "Running function 2...";
	uarte_write(text, sizeof(text));
}

void fn3() {
	char text[] = "Running function 3...";
	uarte_write(text, sizeof(text));
}

void fn4() {
	char text[] = "Running function 4...";
	uarte_write(text, sizeof(text));
}

void fn5() {
	char text[] = "Running function 5...";
	uarte_write(text, sizeof(text));
}

void log_task(task_t t) {

	uint8_t line[32];
	size_t line_len = 0;

	const char label[] = "TASK: ";
	mem_cpy(&line[line_len], label, sizeof(label) - 1);
	line_len += sizeof(label) - 1;
	line_len += format_u32(t.tid, &line[line_len]);

	if (t.tstate == NOT_READY) {
		const char st[] = ", NOT READY";
		mem_cpy(&line[line_len], st, sizeof(st) - 1);
		line_len += sizeof(st) - 1;
	} else if (t.tstate == READY) {
		const char st[] = ", READY";
		mem_cpy(&line[line_len], st, sizeof(st) - 1);
		line_len += sizeof(st) - 1;
	} else if (t.tstate == RUNNING) {
		const char st[] = ", RUNNING";
		mem_cpy(&line[line_len], st, sizeof(st) - 1);
		line_len += sizeof(st) - 1;
	} else if (t.tstate == SLEEPING) {
		const char st[] = ", SLEEPING";
		mem_cpy(&line[line_len], st, sizeof(st) - 1);
		line_len += sizeof(st) - 1;
	}
	line[line_len++] = '\r';
	line[line_len++] = '\n';

	uarte_write((const char*)line, line_len);
}

int main(void) {
	init_uarte0();
	schedule_task(fn1);
	schedule_task(fn2);
	schedule_task(fn3);
	schedule_task(fn4);
	schedule_task(fn5);

	task_sleep(1);
	task_sleep(3);

	while (1) {
		if (task_ctr() == 0)
			continue;
		else {
			for (int i = 1; i <= task_ctr(); i++) {
				task_t t = tasks(i);
				if (t.tstate == READY)
					log_task(t);
				else
					log_task(t);
			}
		}

		delay(6 * 1000 * 1000); // small delay
	}
}
