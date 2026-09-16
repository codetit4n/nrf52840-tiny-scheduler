#include <stdint.h>

#define MAX_SCHEDULED 100

typedef enum {
	NOT_READY,
	READY,	 // Task ready to run
	RUNNING, // Task running
	SLEEPING // Task blocked for I/O or something
} task_state;

typedef void (*fn_ptr)(void);

typedef struct {
	uint32_t tid; // 1-MAX_SCHEDULED
	fn_ptr fptr;
	task_state tstate;
} task_t;

void schedule_task(fn_ptr fn);
task_t tasks(int idx);
int task_ctr(void);
void task_sleep(uint32_t tid);
