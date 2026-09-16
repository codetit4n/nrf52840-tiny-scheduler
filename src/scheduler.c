#include "scheduler.h"
#include "uarte.h"

// from task id 1 - MAX_SCHEDULED
static task_t task_table[MAX_SCHEDULED];
static int tctr = 0;

int task_ctr(void) {
	return tctr;
}

void schedule_task(fn_ptr fn) {
	if (tctr >= MAX_SCHEDULED) {
		return;
	}

	uint32_t id = ++tctr;
	task_t t = {id, fn, READY};
	task_table[id] = t;
}

task_t tasks(int idx) {
	return task_table[idx];
}

void task_sleep(uint32_t tid) {
	task_table[tid].tstate = SLEEPING;
}
