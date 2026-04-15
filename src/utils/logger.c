#include <stdio.h>
#include <time.h>
#include "colors.h"

void get_time(char *buffer) {
  time_t now = time(NULL);
  struct tm *t = localtime(&now);
  strftime(buffer, 9, "%H:%M:%S", t);
}

// formato base
void log_format(const char *color, const char *symbol, const char *name, int pid) {
  char timebuf[9];
  get_time(timebuf);

  printf("%s[%s]%s %s%s%s %-15s%s %sPID:%d%s\n",
      COLOR_TIME, timebuf, RESET,
      color, symbol, RESET,
      COLOR_NAME, name, RESET
      COLOR_PID, pid, RESET
  );
}

// eventos
void log_start(const char *name, int pid) {
  log_format(COLOR_START, "▶ STARTED ", name, pid);
  //printf(GREEN ">> " RESET BOLD "New process: " RESET MAGENTA "%s" RESET YELLOW " (PID %d)\n" RESET, name, pid);
}

void log_end(const char *name, int pid) {
  log_format(COLOR_STOP, "■ STOPPED ", name, pid);
  //printf(RED "<< " RESET BOLD "Process completed: " RESET MAGENTA "%s" RESET YELLOW " (PID %d)\n" RESET, name, pid);
}

void log_info(const char *msg) {
  printf(CYAN "[i] %s\n" RESET, msg);
}

void log_warning(const char *msg) {
  printf(YELLOW "[!] %s\n" RESET, msg);
}
