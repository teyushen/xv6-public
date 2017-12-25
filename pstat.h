#include "param.h"

struct pstat {
    int pid[NPROC];               // Process ID
    char *state[NPROC];           // Process state
    char *name[NPROC];            // Process name (debugging)
};

extern struct pstat pstat;