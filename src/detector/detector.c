#include "detector.h"
#include <stdio.h>

int there_are_process(Process *list, int amount, int pid) {
  for (int i = 0; i < amount; i++) {
    if (list[i].pid == pid) return 1;
  }
  return 0;
}

void compare_lists(Process *old, int old_amount,
                   Process *new, int new_amount) {
  for (int i = 0; i < new_amount; i++) {
    if (!there_are_process(old, old_amount, new[i].pid)) {
      printf("[>] New process: %s (PID %d)\n",
             new[i].name, new[i].pid);
    }
  }
  for (int i = 0; i < old_amount; i++) {
    if (!there_are_process(new, new_amount, old[i].pid)) {
      printf("[<] Process completed: %s (PID %d)\n",
             old[i].name, old[i].pid);
    }
  }
}
