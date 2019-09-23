
#define _CRT_SECURE_NO_WARNINGS

#include <stdint.h>
#include <stdio.h>
#include "CQImport.h"

#define LOGGER_BUFFER_SIZE 2048

int32_t authCode = -1;
char logBuff[LOGGER_BUFFER_SIZE];

void InitLogger(int32_t auth_code)
{
	authCode = auth_code;
}

void DestroyLogger()
{
	authCode = -1;
}

void AddLog(int32_t log_level, const char* category, const char* log_msg_format, ...)
{
	if (authCode == -1)
		return;

	va_list arg_list;
	__crt_va_start(arg_list, log_msg_format);
	vsprintf(logBuff, log_msg_format, arg_list);
	__crt_va_end(arg_list);
	
	CQ_addLog(authCode, log_level, category, logBuff);
}