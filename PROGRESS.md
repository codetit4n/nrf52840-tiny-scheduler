## Progress

- [x] Set up bare-metal project and UARTE logging
- [x] Add static task table and task registration
- [x] Add task states: `READY`, `RUNNING`, `SLEEPING`
- [x] Add cooperative round-robin scheduler
- [x] Skip sleeping tasks
- [x] Move scheduler loop into `scheduler.c`
- [x] Add SysTick setup for a 1 ms tick
- [x] Add `SysTick_Handler()` and software tick counter
- [x] Verify the 1 ms timebase
- [x] Verify tick counter wraparound behavior
- [x] Add timed sleep/wakeup for tasks
- [x] Make wakeup checks wraparound-safe
- [x] Preserve task state changes made while running
- [x] Test repeated scheduling and sleeping behavior
- [ ] Add cooperative yield behavior
- [ ] Clean up scheduler flow
- [ ] Document scheduler design and current limitations
