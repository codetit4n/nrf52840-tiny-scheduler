## Progress

- [x] Set up bare-metal project and UARTE logging
- [x] Add static task table and task registration
- [x] Add task states: `READY`, `RUNNING`, `SLEEPING`
- [x] Add cooperative round-robin scheduler
- [x] Skip sleeping tasks
- [x] Move scheduler loop into `scheduler.c`
- [x] Start SysTick setup for a 1 ms tick
- [ ] Add `SysTick_Handler()` and software tick counter
- [ ] Verify the 1 ms timebase
- [ ] Add timed sleep/wakeup for tasks
- [ ] Add cooperative yield behavior
- [ ] Clean up task state transitions and scheduler flow
- [ ] Test repeated scheduling and sleeping behavior
- [ ] Document scheduler design and current limitations
