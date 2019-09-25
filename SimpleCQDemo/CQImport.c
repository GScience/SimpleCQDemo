#include <Windows.h>
#include <assert.h>
#include <stdint.h>
#include "CQType.h"

#define CQ_IMPORT_DEF_HELPER(ReturnType, FuncName, ...)\
    ReturnType (__stdcall *CQ_##FuncName##)(__VA_ARGS__);

// Message
CQ_IMPORT_DEF_HELPER(int32_t, sendPrivateMsg, int32_t auth_code, int64_t qq, const char* msg)
CQ_IMPORT_DEF_HELPER(int32_t, sendGroupMsg, int32_t auth_code, int64_t group_id, const char* msg)
CQ_IMPORT_DEF_HELPER(int32_t, sendDiscussMsg, int32_t auth_code, int64_t discuss_id, const char* msg)
CQ_IMPORT_DEF_HELPER(int32_t, deleteMsg, int32_t auth_code, int64_t msg_id)

// Send Like
CQ_IMPORT_DEF_HELPER(int32_t, sendLike, int32_t auth_code, int64_t qq)
CQ_IMPORT_DEF_HELPER(int32_t, sendLikeV2, int32_t auth_code, int64_t qq, int32_t times)

// Group & Discuss Operation
CQ_IMPORT_DEF_HELPER(int32_t, setGroupKick, int32_t auth_code, int64_t group_id, int64_t qq, cq_bool_t reject_add_request)
CQ_IMPORT_DEF_HELPER(int32_t, setGroupBan, int32_t auth_code, int64_t group_id, int64_t qq, int64_t duration)
CQ_IMPORT_DEF_HELPER(int32_t, setGroupAnonymousBan, int32_t auth_code, int64_t group_id, const char* anonymous, int64_t duration)
CQ_IMPORT_DEF_HELPER(int32_t, setGroupWholeBan, int32_t auth_code, int64_t group_id, cq_bool_t enable)
CQ_IMPORT_DEF_HELPER(int32_t, setGroupAdmin, int32_t auth_code, int64_t group_id, int64_t qq, cq_bool_t set)
CQ_IMPORT_DEF_HELPER(int32_t, setGroupAnonymous, int32_t auth_code, int64_t group_id, cq_bool_t enable)
CQ_IMPORT_DEF_HELPER(int32_t, setGroupCard, int32_t auth_code, int64_t group_id, int64_t qq, const char* new_card)
CQ_IMPORT_DEF_HELPER(int32_t, setGroupLeave, int32_t auth_code, int64_t group_id, cq_bool_t is_dismiss)
CQ_IMPORT_DEF_HELPER(int32_t, setGroupSpecialTitle, int32_t auth_code, int64_t group_id, int64_t qq, const char* new_special_title, int64_t duration)
CQ_IMPORT_DEF_HELPER(int32_t, setDiscussLeave, int32_t auth_code, int64_t discuss_id)

// Request Operation
CQ_IMPORT_DEF_HELPER(int32_t, setFriendAddRequest, int32_t auth_code, const char* response_flag, int32_t response_operation, const char* remark)
CQ_IMPORT_DEF_HELPER(int32_t, setGroupAddRequest, int32_t auth_code, const char* response_flag, int32_t request_type, int32_t response_operation)
CQ_IMPORT_DEF_HELPER(int32_t, setGroupAddRequestV2, int32_t auth_code, const char* response_flag, int32_t request_type, int32_t response_operation, const char* reason)

// Get QQ Information
CQ_IMPORT_DEF_HELPER(int64_t, getLoginQQ, int32_t auth_code)
CQ_IMPORT_DEF_HELPER(const char*, getLoginNick, int32_t auth_code)
CQ_IMPORT_DEF_HELPER(const char*, getStrangerInfo, int32_t auth_code, int64_t qq, cq_bool_t no_cache)
CQ_IMPORT_DEF_HELPER(const char*, getGroupList, int32_t auth_code)
CQ_IMPORT_DEF_HELPER(const char*, getGroupMemberList, int32_t auth_code, int64_t group_id)
CQ_IMPORT_DEF_HELPER(const char*, getGroupMemberInfoV2, int32_t auth_code, int64_t group_id, int64_t qq, cq_bool_t no_cache)

// Get CoolQ Information
CQ_IMPORT_DEF_HELPER(const char*, getCookies, int32_t auth_code)
CQ_IMPORT_DEF_HELPER(int32_t, getCsrfToken, int32_t auth_code)
CQ_IMPORT_DEF_HELPER(const char*, getAppDirectory, int32_t auth_code)
CQ_IMPORT_DEF_HELPER(const char*, getRecord, int32_t auth_code, const char* file, const char* out_format)
CQ_IMPORT_DEF_HELPER(const char*, getRecordV2, int32_t auth_code, const char* file, const char* out_format)
CQ_IMPORT_DEF_HELPER(const char*, getImage, int32_t auth_code, const char* file)
CQ_IMPORT_DEF_HELPER(int, canSendImage, int32_t auth_code)
CQ_IMPORT_DEF_HELPER(int, canSendRecord, int32_t auth_code)

CQ_IMPORT_DEF_HELPER(int32_t, addLog, int32_t auth_code, int32_t log_level, const char* category, const char* log_msg)
CQ_IMPORT_DEF_HELPER(int32_t, setFatal, int32_t auth_code, const char* error_info)
CQ_IMPORT_DEF_HELPER(int32_t, setRestart, int32_t auth_code) // currently ineffective

void InitImportFunc()
{
	HMODULE dll;
	assert ((dll = GetModuleHandleW(L"CQP.dll")) != 0);

	assert((CQ_sendPrivateMsg = (void*)GetProcAddress(dll, "CQ_sendPrivateMsg")) != 0);
	assert((CQ_sendGroupMsg =	(void*)GetProcAddress(dll, "CQ_sendGroupMsg")) != 0);
	assert((CQ_sendDiscussMsg = (void*)GetProcAddress(dll, "CQ_sendDiscussMsg")) != 0);
	assert((CQ_deleteMsg =		(void*)GetProcAddress(dll, "CQ_deleteMsg")) != 0);
	
	assert((CQ_sendLike =		(void*)GetProcAddress(dll, "CQ_sendLike")) != 0);
	assert((CQ_sendLikeV2 =		(void*)GetProcAddress(dll, "CQ_sendLikeV2")) != 0);
	
	assert((CQ_setGroupKick =			(void*)GetProcAddress(dll, "CQ_setGroupKick")) != 0);
	assert((CQ_setGroupBan =			(void*)GetProcAddress(dll, "CQ_setGroupBan")) != 0);
	assert((CQ_setGroupAnonymousBan =	(void*)GetProcAddress(dll, "CQ_setGroupAnonymousBan")) != 0);
	assert((CQ_setGroupWholeBan =		(void*)GetProcAddress(dll, "CQ_setGroupWholeBan")) != 0);
	assert((CQ_setGroupAdmin =			(void*)GetProcAddress(dll, "CQ_setGroupAdmin")) != 0);
	assert((CQ_setGroupAnonymous =		(void*)GetProcAddress(dll, "CQ_setGroupAnonymous")) != 0);
	assert((CQ_setGroupCard =			(void*)GetProcAddress(dll, "CQ_setGroupCard")) != 0);
	assert((CQ_setGroupLeave =			(void*)GetProcAddress(dll, "CQ_setGroupLeave")) != 0);
	assert((CQ_setGroupSpecialTitle =	(void*)GetProcAddress(dll, "CQ_setGroupSpecialTitle")) != 0);
	assert((CQ_setDiscussLeave =		(void*)GetProcAddress(dll, "CQ_setDiscussLeave")) != 0);

	assert((CQ_setFriendAddRequest =	(void*)GetProcAddress(dll, "CQ_setFriendAddRequest")) != 0);
	assert((CQ_setGroupAddRequest =		(void*)GetProcAddress(dll, "CQ_setGroupAddRequest")) != 0);
	assert((CQ_setGroupAddRequestV2 =	(void*)GetProcAddress(dll, "CQ_setGroupAddRequestV2")) != 0);
	
	assert((CQ_getLoginQQ =				(void*)GetProcAddress(dll, "CQ_getLoginQQ")) != 0);
	assert((CQ_getLoginNick =			(void*)GetProcAddress(dll, "CQ_getLoginNick")) != 0);
	assert((CQ_getStrangerInfo =		(void*)GetProcAddress(dll, "CQ_getStrangerInfo")) != 0);
	assert((CQ_getGroupList =			(void*)GetProcAddress(dll, "CQ_getGroupList")) != 0);
	assert((CQ_getGroupMemberList =		(void*)GetProcAddress(dll, "CQ_getGroupMemberList")) != 0);
	assert((CQ_getGroupMemberInfoV2 =	(void*)GetProcAddress(dll, "CQ_getGroupMemberInfoV2")) != 0);
	
	assert((CQ_getCookies =			(void*)GetProcAddress(dll, "CQ_getCookies")) != 0);
	assert((CQ_getCsrfToken =		(void*)GetProcAddress(dll, "CQ_getCsrfToken")) != 0);
	assert((CQ_getAppDirectory =	(void*)GetProcAddress(dll, "CQ_getAppDirectory")) != 0);
	assert((CQ_getRecord =			(void*)GetProcAddress(dll, "CQ_getRecord")) != 0);
	assert((CQ_getRecordV2 =		(void*)GetProcAddress(dll, "CQ_getRecordV2")) != 0);
	assert((CQ_getImage =			(void*)GetProcAddress(dll, "CQ_getImage")) != 0);
	assert((CQ_canSendImage =		(void*)GetProcAddress(dll, "CQ_canSendImage")) != 0);
	assert((CQ_canSendRecord =		(void*)GetProcAddress(dll, "CQ_canSendRecord")) != 0);
	
	assert((CQ_addLog =			(void*)GetProcAddress(dll, "CQ_addLog")) != 0);
	assert((CQ_setFatal =		(void*)GetProcAddress(dll, "CQ_setFatal")) != 0);
}