#include "board.h"
#include "utils.h"

static task_t task_table[MAX_SCHEDULED];
static int tctr = 0;

int task_ctr(void) {
	return tctr;
}

void schedule_task(fn_ptr fn) {
	if (tctr >= MAX_SCHEDULED) {
		return;
	}

	uint32_t id = (uint32_t)tctr;

	task_t t = {
		.tid = id,
		.fptr = fn,
		.tstate = READY,
	};

	task_table[id] = t;
	tctr++;
}

static inline void delay(volatile uint32_t ctr) {
	while (ctr--) {
		__asm__ volatile("nop");
	}
}

void start_scheduler(void) {
	while (1) {
		if (task_ctr() == 0)
			continue;
		else {
			for (int i = 0; i < task_ctr(); i++) {
				task_t* t = &task_table[i];
				if (t->tstate == READY) {
					t->tstate = RUNNING;
					t->fptr();
					t->tstate = READY;
				}
			}
		}

		delay(6 * 1000 * 1000); // small delay
	}
}

void task_sleep(uint32_t tid) {
	task_table[tid].tstate = SLEEPING;
}
