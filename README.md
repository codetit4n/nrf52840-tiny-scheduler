# nrf52840-tiny-scheduler

> [!WARNING]
> Work in progress!

A small bare-metal scheduler for the [nRF52840](https://www.nordicsemi.com/Products/nRF52840), built to learn
task scheduling, timing, Cortex-M context switching, and basic RTOS internals.

The project starts with a simple cooperative round-robin scheduler and will progress toward real task context switching
and preemptive scheduling using SysTick and PendSV.

The final goal is to run and stress-test small existing firmware workloads on top of the scheduler to check its behavior
and limitations in more realistic use.

### Current state

A basic cooperative round-robin scheduler with SysTick-based timed sleep/wakeup is working.

The next phase is to add separate task contexts and cooperative context switching before moving to preemption.

### Implementation Checklist

See [PROGRESS.md](./PROGRESS.md) for the current project status and remaining work.
