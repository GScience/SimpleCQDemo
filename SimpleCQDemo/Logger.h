#ifndef _LOGGER
#define _LOGGER

#include <stdint.h>

void InitLogger(int32_t auth_code);
void DestroyLogger();
void AddLog(int32_t log_level, const char* category, const char* log_msg, ...);

#endif