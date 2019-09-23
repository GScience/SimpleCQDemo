#ifndef _CQ_EXPORT
#define _CQ_EXPORT

#define CQ_EXPORT_HELPER(ReturnType, Name, Size) \
    __pragma(comment(linker, "/EXPORT:" #Name "=_" #Name "@" #Size)) __declspec(dllexport) \
        ReturnType __stdcall Name
/**
 * Return app info.
 */
#define AppInfo CQ_EXPORT_HELPER(const char*, AppInfo, 0) \
	()

/**
 * Initialize SDK using the auth code given by CoolQ.
 */
#define Initialize CQ_EXPORT_HELPER(int32_t, Initialize, 4) \
	(const int32_t auth_code)
/**
 * Event: Plugin is enabled.
 */
#define OnEnable CQ_EXPORT_HELPER(int32_t, cq_app_enable, 0) \
	()

/**
 * Event: Plugin is disabled.
 */
#define OnDisable CQ_EXPORT_HELPER(int32_t, cq_app_disable, 0) \
	()

/**
 * Event: CoolQ is starting.
 */
#define OnCQStart CQ_EXPORT_HELPER(int32_t, cq_coolq_start, 0) \
	()

/**
 * Event: CoolQ is exiting.
 */
#define OnCQExit CQ_EXPORT_HELPER(int32_t, cq_coolq_exit, 0) \
	()

/**
 * Type=21 私聊消息
 * sub_type 子类型，11/来自好友 1/来自在线状态 2/来自群 3/来自讨论组
 */
#define EventPrivateMsg CQ_EXPORT_HELPER(int32_t, cq_event_private_msg, 24) \
	(int32_t sub_type, int32_t msg_id, int64_t from_qq, const char* msg, int32_t font)

/**
 * Type=2 群消息
 */
#define EventGroupMsg CQ_EXPORT_HELPER(int32_t, cq_event_group_msg, 36) \
	(int32_t sub_type, int32_t msg_id, int64_t from_group, int64_t from_qq, const char* from_anonymous, const char* msg, int32_t font)

/**
 * Type=4 讨论组消息
 */
#define EventDiscussMsg CQ_EXPORT_HELPER(int32_t, cq_event_discuss_msg, 32) \
(int32_t sub_type, int32_t msg_id, int64_t from_discuss, int64_t from_qq, const char* msg, int32_t font)

/**
 * Type=11 群事件-文件上传
 */
#define EventGroupUpload CQ_EXPORT_HELPER(int32_t, cq_event_group_upload, 28) \
(int32_t sub_type, int32_t send_time, int64_t from_group, int64_t from_qq, const char* file)

/**
 * Type=101 群事件-管理员变动
 * sub_type 子类型，1/被取消管理员 2/被设置管理员
 */
#define EventGroupAdmin CQ_EXPORT_HELPER(int32_t, cq_event_group_admin, 24) \
(int32_t sub_type, int32_t send_time, int64_t from_group, int64_t being_operate_qq)

/**
 * Type=102 群事件-群成员减少
 * sub_type 子类型，1/群员离开 2/群员被踢 3/自己(即登录号)被踢
 * from_qq 操作者QQ(仅subType为2、3时存在)
 * being_operate_qq 被操作QQ
 */
#define EventGroupMemberDecrease CQ_EXPORT_HELPER(int32_t, cq_event_group_member_decrease, 32) \
(int32_t sub_type, int32_t send_time, int64_t from_group, int64_t from_qq, int64_t being_operate_qq)

/**
 * Type=103 群事件-群成员增加
 * sub_type 子类型，1/管理员已同意 2/管理员邀请
 * from_qq 操作者QQ(即管理员QQ)
 * being_operate_qq 被操作QQ(即加群的QQ)
 */
#define EventGroupMemberIncrease CQ_EXPORT_HELPER(int32_t, cq_event_group_member_increase, 32) \
(int32_t sub_type, int32_t send_time, int64_t from_group, int64_t from_qq, int64_t being_operate_qq)

/**
 * Type=201 好友事件-好友已添加
 */
#define EventFriendAdd CQ_EXPORT_HELPER(int32_t, cq_event_friend_add, 16) \
(int32_t sub_type, int32_t send_time, int64_t from_qq)

/**
 * Type=301 请求-好友添加
 * msg 附言
 * response_flag 反馈标识(处理请求用)
 */
#define EventAddFriendRequest CQ_EXPORT_HELPER(int32_t, cq_event_add_friend_request, 24) \
(int32_t sub_type, int32_t send_time, int64_t from_qq, const char* msg, const char* response_flag)

/**
 * Type=302 请求-群添加
 * sub_type 子类型，1/他人申请入群 2/自己(即登录号)受邀入群
 * msg 附言
 * response_flag 反馈标识(处理请求用)
 */
#define EventAddGroupRequest CQ_EXPORT_HELPER(int32_t, cq_event_add_group_request, 32) \
(int32_t sub_type, int32_t send_time, int64_t from_group, int64_t from_qq, const char* msg, const char* response_flag)

#endif