#include <stdint.h>
#include "Logger.h"
#include "CQExport.h"
#include "CQImport.h"

extern int32_t authCode;

AppInfo
{
	return "9,cc.gscience.SimpleCQDemo";
}

Initialize
{
	InitImportFunc();
	InitLogger(auth_code);
	return 0;
}

OnEnable
{
	AddLog(DEBUG_LEVEL_INFO_SUCCESS, "Debug", "Plugin Enabled");
	return 0;
}

OnDisable
{
	AddLog(DEBUG_LEVEL_INFO_SUCCESS, "Debug", "Plugin Disabled");
	return 0;
}

OnCQStart
{
	AddLog(DEBUG_LEVEL_INFO_SUCCESS, "Debug", "CQ Start");
	return 0;
}

OnCQExit
{
	DestroyLogger();
	AddLog(DEBUG_LEVEL_INFO_SUCCESS, "Debug", "CQ Exit");
	return 0;
}

EventPrivateMsg
{
	AddLog(DEBUG_LEVEL_INFO_SUCCESS,
	"Debug",
	"Private msg event msg=%s",
	msg);
	return 0;
}

EventGroupMsg
{
	AddLog(DEBUG_LEVEL_INFO_SUCCESS,
	"Debug",
	"Group msg event msg=%s",
	msg);
	return 0;
}

EventDiscussMsg
{
	AddLog(DEBUG_LEVEL_INFO_SUCCESS,
	"Debug",
	"Discuss msg event");
	return 0;
}

EventGroupUpload
{
	AddLog(DEBUG_LEVEL_INFO_SUCCESS,
	"Debug",
	"Group upload event");
	return 0;
}

EventGroupAdmin
{
	AddLog(DEBUG_LEVEL_INFO_SUCCESS,
	"Debug",
	"Group admin event");
	return 0;
}

EventGroupMemberDecrease
{
	AddLog(DEBUG_LEVEL_INFO_SUCCESS,
	"Debug",
	"Group member decrease event");
	return 0;
}

EventGroupMemberIncrease
{
	AddLog(DEBUG_LEVEL_INFO_SUCCESS,
	"Debug",
	"Group member increate event");
	return 0;
}

EventFriendAdd
{
	AddLog(DEBUG_LEVEL_INFO_SUCCESS,
	"Debug",
	"Friend add event");
	return 0;
}

EventAddFriendRequest
{
	AddLog(DEBUG_LEVEL_INFO_SUCCESS,
	"Debug",
	"Add friend request event");
	return 0;
}

EventAddGroupRequest
{
	AddLog(DEBUG_LEVEL_INFO_SUCCESS,
	"Debug",
	"Add group request event");
	return 0;
}
