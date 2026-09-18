#include "utils.h"
#include "uarte.h"

void* mem_cpy(void* dest, const void* src, size_t n) {
	uint8_t* d = (uint8_t*)dest;
	const uint8_t* s = (const uint8_t*)src;

	while (n--) {
		*d++ = *s++;
	}

	return dest;
}

uint8_t format_u32(uint32_t value, uint8_t* out) {

	uint8_t tmp[10];
	uint8_t n = 0;
	uint8_t pos = 0;

	if (out == NULL)
		return 0;

	if (value == 0) {
		out[0] = (uint8_t)'0';
		return 1;
	}

	while (value != 0 && n < sizeof(tmp)) {
		uint32_t digit = value % 10u;
		tmp[n++] = (uint8_t)('0' + digit);
		value /= 10u;
	}

	for (uint8_t i = 0; i < n; i++) {
		out[pos + i] = tmp[n - 1 - i];
	}

	return pos + n;
}

void log_br(void) {
	uint8_t line[2];

	line[0] = '\r';
	line[1] = '\n';

	uarte_write((const char*)line, 2);
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

void log_wake_tick(uint32_t t) {

	uint8_t line[32];
	size_t line_len = 0;

	const char label[] = "WAKE TICK: ";
	mem_cpy(&line[line_len], label, sizeof(label) - 1);
	line_len += sizeof(label) - 1;
	line_len += format_u32(t, &line[line_len]);
	line[line_len++] = '\r';
	line[line_len++] = '\n';

	uarte_write((const char*)line, line_len);
}
