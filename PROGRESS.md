## Progress

- [x] Set up bare-metal project and UARTE logging
- [x] Add static task table and task registration
- [x] Add task states: `READY`, `RUNNING`, `SLEEPING`
- [x] Add cooperative round-robin scheduler
- [x] Add SysTick-based 1 ms timebase
- [x] Add timed task sleep/wakeup
- [x] Make wakeup checks wraparound-safe
- [x] Track the currently running task
- [x] Add self-sleep behavior for running tasks
- [x] Test repeated scheduling and sleeping behavior
- [ ] Add separate task stacks
- [ ] Add cooperative context switching
- [ ] Add PendSV-based context switching
- [ ] Add SysTick-driven preemptive round-robin scheduling
- [ ] Test with real firmware workloads
- [ ] Clean up scheduler flow
- [ ] Document scheduler design and limitations
