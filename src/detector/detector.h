#ifndef DETECTOR_H
#define DETECTOR_H

#include "../monitor/proc_monitor.h"

void compare_lists(Process *old, int old_amount,
                   Process *new, int new_amount);

#endif
