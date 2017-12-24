#include "types.h"
#include "user.h"
#include "date.h"


int
main(void) {

    struct rtcdate r;

    r = *gettime(&r);
    printf(1, "\n%d\n", r.second);
    printf(1, "%d\n", r.minute);
    printf(1, "%d\n", r.hour);
    printf(1, "%d\n", r.day);
    printf(1, "%d\n", r.month);
    printf(1, "%d\n", r.year);

    exit();
}