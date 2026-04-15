#pragma once

void log_start(const char *name, int pid);
void log_end(const char *name, int pid);
void log_info(const char *msg);
void log_warning(const char *msg);
void log_alert(const char *name, int pid);

