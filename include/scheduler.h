#include <stdint.h>

#define MAX_SCHEDULED 100
#define MAX_TASK_SLEEP_MS 2147483647U // ~24.855 days - half of max u32

typedef enum {
	NOT_READY,
	READY,	 // Task ready to run
	RUNNING, // Task running
	SLEEPING // Task blocked for some time
} task_state;

typedef void (*fn_ptr)(void);

typedef struct {
	uint32_t tid; // 0-MAX_SCHEDULED
	fn_ptr fptr;
	task_state tstate;
	uint32_t wake_tick;
} task_t;

void schedule_task(fn_ptr fn);
task_t tasks(int idx);
void task_sleep(uint32_t wake_ms);
void start_scheduler(void);
