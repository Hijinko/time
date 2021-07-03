#include "../include/time_functs.h"
#include <time.h>

char * time_get(void)
{
    // returns a string of the current time
    time_t now;
    time(&now);
    return ctime(&now);
}
