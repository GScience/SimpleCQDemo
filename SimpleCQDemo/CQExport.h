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
 * Type=21 ˽����Ϣ
 * sub_type �����ͣ�11/���Ժ��� 1/��������״̬ 2/����Ⱥ 3/����������
 */
#define EventPrivateMsg CQ_EXPORT_HELPER(int32_t, cq_event_private_msg, 24) \
	(int32_t sub_type, int32_t msg_id, int64_t from_qq, const char* msg, int32_t font)

/**
 * Type=2 Ⱥ��Ϣ
 */
#define EventGroupMsg CQ_EXPORT_HELPER(int32_t, cq_event_group_msg, 36) \
	(int32_t sub_type, int32_t msg_id, int64_t from_group, int64_t from_qq, const char* from_anonymous, const char* msg, int32_t font)

/**
 * Type=4 ��������Ϣ
 */
#define EventDiscussMsg CQ_EXPORT_HELPER(int32_t, cq_event_discuss_msg, 32) \
(int32_t sub_type, int32_t msg_id, int64_t from_discuss, int64_t from_qq, const char* msg, int32_t font)

/**
 * Type=11 Ⱥ�¼�-�ļ��ϴ�
 */
#define EventGroupUpload CQ_EXPORT_HELPER(int32_t, cq_event_group_upload, 28) \
(int32_t sub_type, int32_t send_time, int64_t from_group, int64_t from_qq, const char* file)

/**
 * Type=101 Ⱥ�¼�-����Ա�䶯
 * sub_type �����ͣ�1/��ȡ������Ա 2/�����ù���Ա
 */
#define EventGroupAdmin CQ_EXPORT_HELPER(int32_t, cq_event_group_admin, 24) \
(int32_t sub_type, int32_t send_time, int64_t from_group, int64_t being_operate_qq)

/**
 * Type=102 Ⱥ�¼�-Ⱥ��Ա����
 * sub_type �����ͣ�1/ȺԱ�뿪 2/ȺԱ���� 3/�Լ�(����¼��)����
 * from_qq ������QQ(��subTypeΪ2��3ʱ����)
 * being_operate_qq ������QQ
 */
#define EventGroupMemberDecrease CQ_EXPORT_HELPER(int32_t, cq_event_group_member_decrease, 32) \
(int32_t sub_type, int32_t send_time, int64_t from_group, int64_t from_qq, int64_t being_operate_qq)

/**
 * Type=103 Ⱥ�¼�-Ⱥ��Ա����
 * sub_type �����ͣ�1/����Ա��ͬ�� 2/����Ա����
 * from_qq ������QQ(������ԱQQ)
 * being_operate_qq ������QQ(����Ⱥ��QQ)
 */
#define EventGroupMemberIncrease CQ_EXPORT_HELPER(int32_t, cq_event_group_member_increase, 32) \
(int32_t sub_type, int32_t send_time, int64_t from_group, int64_t from_qq, int64_t being_operate_qq)

/**
 * Type=201 �����¼�-���������
 */
#define EventFriendAdd CQ_EXPORT_HELPER(int32_t, cq_event_friend_add, 16) \
(int32_t sub_type, int32_t send_time, int64_t from_qq)

/**
 * Type=301 ����-�������
 * msg ����
 * response_flag ������ʶ(����������)
 */
#define EventAddFriendRequest CQ_EXPORT_HELPER(int32_t, cq_event_add_friend_request, 24) \
(int32_t sub_type, int32_t send_time, int64_t from_qq, const char* msg, const char* response_flag)

/**
 * Type=302 ����-Ⱥ���
 * sub_type �����ͣ�1/����������Ⱥ 2/�Լ�(����¼��)������Ⱥ
 * msg ����
 * response_flag ������ʶ(����������)
 */
#define EventAddGroupRequest CQ_EXPORT_HELPER(int32_t, cq_event_add_group_request, 32) \
(int32_t sub_type, int32_t send_time, int64_t from_group, int64_t from_qq, const char* msg, const char* response_flag)

#endif