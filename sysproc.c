#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "pstat.h"

int
sys_fork(void) {
    return fork();
}

int
sys_exit(void) {
    exit();
    return 0;  // not reached
}

int
sys_wait(void) {
    return wait();
}

int
sys_kill(void) {
    int pid;

    if (argint(0, &pid) < 0)
        return -1;
    return kill(pid);
}

int
sys_getpid(void) {
    return myproc()->pid;
}

int
sys_sbrk(void) {
    int addr;
    int n;

    if (argint(0, &n) < 0)
        return -1;
    addr = myproc()->sz;
    if (growproc(n) < 0)
        return -1;
    return addr;
}

int
sys_sleep(void) {
    int n;
    uint ticks0;

    if (argint(0, &n) < 0)
        return -1;
    acquire(&tickslock);
    ticks0 = ticks;
    while (ticks - ticks0 < n) {
        if (myproc()->killed) {
            release(&tickslock);
            return -1;
        }
        sleep(&ticks, &tickslock);
    }
    release(&tickslock);
    return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void) {
    uint xticks;

    acquire(&tickslock);
    xticks = ticks;
    release(&tickslock);
    return xticks;
}

// return the year of which the Unix version 6 was released
int
sys_getyear(void) {
    return 1975;
}

struct rtcdate* sys_gettime(struct rtcdate *r) {
    cmostime(r);
    return r;
}

// Reference:
// https://github.com/wkatsak/xv6
// https://github.com/t3rm1n4l/pintos/blob/master/devices/shutdown.c
// FIXME
int
sys_halt(void) {
    char *p = "Shutdown";

    for (; *p; p++) {
        outw(0xB004, 0x2000);
        outb(0xF, *p);
//      outb(0x8900, *p);
    }
    outb(0x70, 0xF);  // offset 0xF is shutdown code
    outb(0x71+1, 0x0A);
    return 0;
}

void sys_getproc(void) {

    consoleproc();
    return;
}