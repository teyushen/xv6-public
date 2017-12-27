#include "types.h"
#include "user.h"
#include "date.h"


int
main(void) {

    struct rtcdate r;

    r = *gettime(&r);
//    printf(1, "%d-%d-%d %d:%d:%d\n", r.year, r.month, r.day, r.hour, r.minute, r.second);

    exit();
}