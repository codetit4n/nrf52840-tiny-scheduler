# nrf52840-tiny-scheduler

> [!WARNING]
> Work in progress!

A small bare-metal scheduler for the [nRF52840](https://www.nordicsemi.com/Products/nRF52840) built to learn task scheduling,
timing, and basic RTOS concepts.

## Current state

Initial project structure and UARTE logging are in place.

## Notes

- Some low-level code is reused from my earlier [nRF52840 bare-metal project](https://github.com/codetit4n/nrf52840-baremetal).
- The UARTE logging code is based on [this code](https://github.com/codetit4n/nrf52840-baremetal/blob/main/uarte-tx-only/src/main.c)
  from that project. Read more about it [here](https://loke.sh/blog/nrf52840-web-server/1-nrf52840-baremetal/#uarte-transmit-only-minimal-logger).
