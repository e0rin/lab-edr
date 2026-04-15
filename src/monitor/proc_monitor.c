#include "proc_monitor.h"
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>

Process* get_process(int *amount) {
  struct dirent *entry;
  DIR *dp = opendir("/proc");

if (!dp) return NULL;

  Process *list = malloc(sizeof(Process) * 1024);
  int count = 0;

  while ((entry = readdir(dp)) != NULL) {
    if (isdigit(entry->d_name[0])) {
      char path[256];
      snprintf(path, sizeof(path), "/proc/%s/comm", entry->d_name);
      FILE *fp = fopen(path, "r");
      if (fp) {
        Process p;
        p.pid = atoi(entry->d_name);

        fgets(p.name, sizeof(p.name), fp);
        p.name[strcspn(p.name, "\n")] = 0;

        list[count++] = p;
        fclose(fp);
      }
    }
  }
  closedir(dp);
  *amount = count;
  return list;
}
