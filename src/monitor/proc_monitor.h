#pragma once

typedef struct {
  int pid;
  char name[256];
} Process;

Process* get_process(int *amount);

