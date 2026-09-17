#pragma once

#include "scheduler.h"
#include <stddef.h>
#include <stdint.h>

void* mem_cpy(void* dest, const void* src, size_t n);
uint8_t format_u32(uint32_t value, uint8_t* out);
void log_br(void);
void log_task(task_t t);
