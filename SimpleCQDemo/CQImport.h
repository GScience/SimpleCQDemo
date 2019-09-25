#ifndef _CQ_IMPORT
#define _CQ_IMPORT

#include "CQType.h"

#define CQ_IMPORT_DECL_HELPER(ReturnType, FuncName, ...)\
    extern ReturnType(__stdcall *CQ_##FuncName##)(__VA_ARGS__);

// Message
CQ_IMPORT_DECL_HELPER(int32_t, sendPrivateMsg, int32_t auth_code, int64_t qq, const char* msg)
CQ_IMPORT_DECL_HELPER(int32_t, sendGroupMsg, int32_t auth_code, int64_t group_id, const char* msg)
CQ_IMPORT_DECL_HELPER(int32_t, sendDiscussMsg, int32_t auth_code, int64_t discuss_id, const char* msg)
CQ_IMPORT_DECL_HELPER(int32_t, deleteMsg, int32_t auth_code, int64_t msg_id)

// Send Like
CQ_IMPORT_DECL_HELPER(int32_t, sendLike, int32_t auth_code, int64_t qq)
CQ_IMPORT_DECL_HELPER(int32_t, sendLikeV2, int32_t auth_code, int64_t qq, int32_t times)

// Group & Discuss Operation
CQ_IMPORT_DECL_HELPER(int32_t, setGroupKick, int32_t auth_code, int64_t group_id, int64_t qq, cq_bool_t reject_add_request)
CQ_IMPORT_DECL_HELPER(int32_t, setGroupBan, int32_t auth_code, int64_t group_id, int64_t qq, int64_t duration)
CQ_IMPORT_DECL_HELPER(int32_t, setGroupAnonymousBan, int32_t auth_code, int64_t group_id, const char* anonymous, int64_t duration)
CQ_IMPORT_DECL_HELPER(int32_t, setGroupWholeBan, int32_t auth_code, int64_t group_id, cq_bool_t enable)
CQ_IMPORT_DECL_HELPER(int32_t, setGroupAdmin, int32_t auth_code, int64_t group_id, int64_t qq, cq_bool_t set)
CQ_IMPORT_DECL_HELPER(int32_t, setGroupAnonymous, int32_t auth_code, int64_t group_id, cq_bool_t enable)
CQ_IMPORT_DECL_HELPER(int32_t, setGroupCard, int32_t auth_code, int64_t group_id, int64_t qq, const char* new_card)
CQ_IMPORT_DECL_HELPER(int32_t, setGroupLeave, int32_t auth_code, int64_t group_id, cq_bool_t is_dismiss)
CQ_IMPORT_DECL_HELPER(int32_t, setGroupSpecialTitle, int32_t auth_code, int64_t group_id, int64_t qq, const char* new_special_title, int64_t duration)
CQ_IMPORT_DECL_HELPER(int32_t, setDiscussLeave, int32_t auth_code, int64_t discuss_id)

// Request Operation
CQ_IMPORT_DECL_HELPER(int32_t, setFriendAddRequest, int32_t auth_code, const char* response_flag, int32_t response_operation, const char* remark)
CQ_IMPORT_DECL_HELPER(int32_t, setGroupAddRequest, int32_t auth_code, const char* response_flag, int32_t request_type, int32_t response_operation)
CQ_IMPORT_DECL_HELPER(int32_t, setGroupAddRequestV2, int32_t auth_code, const char* response_flag, int32_t request_type, int32_t response_operation, const char* reason)

// Get QQ Information
CQ_IMPORT_DECL_HELPER(int64_t, getLoginQQ, int32_t auth_code)
CQ_IMPORT_DECL_HELPER(const char*, getLoginNick, int32_t auth_code)
CQ_IMPORT_DECL_HELPER(const char*, getStrangerInfo, int32_t auth_code, int64_t qq, cq_bool_t no_cache)
CQ_IMPORT_DECL_HELPER(const char*, getGroupList, int32_t auth_code)
CQ_IMPORT_DECL_HELPER(const char*, getGroupMemberList, int32_t auth_code, int64_t group_id)
CQ_IMPORT_DECL_HELPER(const char*, getGroupMemberInfoV2, int32_t auth_code, int64_t group_id, int64_t qq, cq_bool_t no_cache)

// Get CoolQ Information
CQ_IMPORT_DECL_HELPER(const char*, getCookies, int32_t auth_code)
CQ_IMPORT_DECL_HELPER(int32_t, getCsrfToken, int32_t auth_code)
CQ_IMPORT_DECL_HELPER(const char*, getAppDirectory, int32_t auth_code)
CQ_IMPORT_DECL_HELPER(const char*, getRecord, int32_t auth_code, const char* file, const char* out_format)
CQ_IMPORT_DECL_HELPER(const char*, getRecordV2, int32_t auth_code, const char* file, const char* out_format)
CQ_IMPORT_DECL_HELPER(const char*, getImage, int32_t auth_code, const char* file)
CQ_IMPORT_DECL_HELPER(int, canSendImage, int32_t auth_code)
CQ_IMPORT_DECL_HELPER(int, canSendRecord, int32_t auth_code)

CQ_IMPORT_DECL_HELPER(int32_t, addLog, int32_t auth_code, int32_t log_level, const char* category, const char* log_msg)
CQ_IMPORT_DECL_HELPER(int32_t, setFatal, int32_t auth_code, const char* error_info)
CQ_IMPORT_DECL_HELPER(int32_t, setRestart, int32_t auth_code) // currently ineffective

void InitImportFunc();

#endif