#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "monitor/proc_monitor.h"
#include "detector/detector.h"

int main() {
  int old_amount = 0;
  Process *list_old = get_process(&old_amount);

  while (1) {
    sleep(2);

    int new_amount = 0;
    Process *list_new = get_process(&new_amount);

    compare_lists(list_old, old_amount,
                 list_new, new_amount);

    free(list_old);
    list_old = list_new;
    old_amount = new_amount;
  }
  return 0;
}

