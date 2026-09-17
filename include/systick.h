#include "board.h"

#define CTRL_CSR REG32(0xE000E010UL)
#define LOAD_RVR REG32(0xE000E014UL)
#define VAL_CVR REG32(0xE000E018UL)
#define CALIB REG32(0xE000E01CUL)

void init_systick(void);
