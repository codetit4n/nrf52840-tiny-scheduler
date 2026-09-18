#include "board.h"
#include "systick.h"
#include "uarte.h"
#include "utils.h"

static task_t task_table[MAX_SCHEDULED];
static int tctr = 0;

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

void start_scheduler(void) {
	uarte_write("SCHEDULER: STARTED\r\n", sizeof("SCHEDULER: STARTED\r\n") - 1);

	while (1) {
		if (tctr == 0)
			continue;

		for (int i = 0; i < tctr; i++) {
			task_t* t = &task_table[i];

			if (t->tstate == SLEEPING) {
				uint32_t current_tick = scheduler_tick();

				// wraparound safe
				if ((int32_t)(current_tick - t->wake_tick) >= 0) {
					// log_wake_tick(current_tick);
					t->tstate = READY;
				}
			}

			if (t->tstate == READY) {
				t->tstate = RUNNING;

				t->fptr();

				// if the fn (fptr) calls sleep while runnning it
				// will be kept in SLEEPING state, otherwise it
				// will be set to READY
				if (t->tstate == RUNNING) {
					t->tstate = READY;
				}
			}
		}
	}
}

void task_sleep(uint32_t tid, uint32_t wake_ms) {
	if (tid >= (uint32_t)tctr) {
		uarte_write("Invalid task ID\r\n", 17);
		return;
	}
	if (wake_ms > MAX_TASK_SLEEP_MS) {
		uarte_write("Cannot sleep for more than 2147483647 ms (~24.855 days)\r\n", 66);
		return;
	}
	task_table[tid].wake_tick = scheduler_tick() + wake_ms; // 1 tick per ms
	task_table[tid].tstate = SLEEPING;
}
