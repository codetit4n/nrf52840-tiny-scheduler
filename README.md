# nrf52840-tiny-scheduler

> [!WARNING]
> Work in progress!

A small bare-metal cooperative scheduler for the [nRF52840](https://www.nordicsemi.com/Products/nRF52840), built to learn
task scheduling, timing, task states, and basic RTOS concepts.

The current design uses round-robin cooperative scheduling with a small static task table.

### Current state

Basic cooperative scheduling is working, with SysTick integration in progress for timed task sleeping and wakeup.

### Implementation Checklist

See the [PROGRESS.md](./PROGRESS.md) for the current project status and remaining work.

### Notes

- Some low-level code is reused from my earlier [nRF52840 bare-metal project](https://github.com/codetit4n/nrf52840-baremetal).
- The UARTE logging code is based on [this code](https://github.com/codetit4n/nrf52840-baremetal/blob/main/uarte-tx-only/src/main.c)
  from that project. Read more about it [here](https://loke.sh/blog/nrf52840-web-server/1-nrf52840-baremetal/#uarte-transmit-only-minimal-logger).
- This version is intentionally limited to cooperative scheduling. Preemptive scheduling and context switching may be explored separately later.
