/**
 *
 *   ██████╗   ██╗ ███████╗ ███╗   ███╗ ██╗   ██╗
 *   ██╔══██╗ ███║ ██╔════╝ ████╗ ████║ ██║   ██║
 *   ██████╔╝ ╚██║ █████╗   ██╔████╔██║ ██║   ██║
 *   ██╔══██╗  ██║ ██╔══╝   ██║╚██╔╝██║ ██║   ██║
 *   ██║  ██║  ██║ ███████╗ ██║ ╚═╝ ██║ ╚██████╔╝
 *   ╚═╝  ╚═╝  ╚═╝ ╚══════╝ ╚═╝     ╚═╝  ╚═════╝
 *
 * @license GNU GENERAL PUBLIC LICENSE - Version 2, June 1991
 *          See LICENSE file for further information
 */


// ---------- Includes ------------
#include "packet_type.h"


// ------ Structure declaration -------

const PacketTypeInfo packetTypeInfo = {
    #define REGISTER_PACKET_TYPE_ENTRY(packetType, packetValue, packetSize) \
        .packets[packetType] = {.value = packetValue, .size = packetSize, .string = STRINGIFY (packetType)}
    REGISTER_PACKET_TYPE_ENTRY (CB_LOGIN, 3, 65),
    REGISTER_PACKET_TYPE_ENTRY (CB_LOGIN_BY_PASSPORT, 4, 1052),
    REGISTER_PACKET_TYPE_ENTRY (CB_LOGOUT, 5, 10),
    REGISTER_PACKET_TYPE_ENTRY (CB_START_GAME, 9, 13),
    REGISTER_PACKET_TYPE_ENTRY (CB_START_BARRACK, 6, 11),
    REGISTER_PACKET_TYPE_ENTRY (CB_COMMANDER_CREATE, 7, 92),
    REGISTER_PACKET_TYPE_ENTRY (CB_COMMANDER_DESTROY, 8, 11),
    REGISTER_PACKET_TYPE_ENTRY (CB_ECHO, 12, 30),
    REGISTER_PACKET_TYPE_ENTRY (CB_BARRACKNAME_CHANGE, 10, 74),
    REGISTER_PACKET_TYPE_ENTRY (CB_COMMANDER_MOVE, 11, 31),
    REGISTER_PACKET_TYPE_ENTRY (BC_LOGINOK, 13, 117),
    REGISTER_PACKET_TYPE_ENTRY (BC_LOGOUTOK, 14, 6),
    REGISTER_PACKET_TYPE_ENTRY (BC_START_GAMEOK, 18, 33),
    REGISTER_PACKET_TYPE_ENTRY (BC_SINGLE_INFO, 19, 309),
    REGISTER_PACKET_TYPE_ENTRY (BC_COMMANDER_LIST, 15, 0),
    REGISTER_PACKET_TYPE_ENTRY (BC_COMMANDER_CREATE, 16, 318),
    REGISTER_PACKET_TYPE_ENTRY (BC_COMMANDER_DESTROY, 17, 7),
    REGISTER_PACKET_TYPE_ENTRY (BC_MESSAGE, 20, 0),
    REGISTER_PACKET_TYPE_ENTRY (BC_ECHO, 21, 26),
    REGISTER_PACKET_TYPE_ENTRY (CB_IES_MODIFY_INFO, 70, 0),
    REGISTER_PACKET_TYPE_ENTRY (BC_IES_MODIFY_INFO, 71, 0),
    REGISTER_PACKET_TYPE_ENTRY (BC_IES_MODIFY_LIST, 72, 0),
    REGISTER_PACKET_TYPE_ENTRY (CB_IES_REVISION_DELETE, 73, 0),
    REGISTER_PACKET_TYPE_ENTRY (BC_IES_REVISION_DELETE, 74, 0),
    REGISTER_PACKET_TYPE_ENTRY (BC_MYPAGE_MAP, 22, 0),
    REGISTER_PACKET_TYPE_ENTRY (BC_BARRACKNAME_CHANGE, 23, 75),
    REGISTER_PACKET_TYPE_ENTRY (CB_VISIT, 75, 74),
    REGISTER_PACKET_TYPE_ENTRY (CB_BUY_THEMA, 76, 18),
    REGISTER_PACKET_TYPE_ENTRY (BC_ACCOUNT_PROP, 77, 0),
    REGISTER_PACKET_TYPE_ENTRY (CB_CURRENT_BARRACK, 78, 39),
    REGISTER_PACKET_TYPE_ENTRY (BC_NORMAL, 79, 0),
    REGISTER_PACKET_TYPE_ENTRY (CB_POSE, 80, 15),
    REGISTER_PACKET_TYPE_ENTRY (CB_PLACE_CMD, 81, 46),
    REGISTER_PACKET_TYPE_ENTRY (CB_CHAT, 82, 0),
    REGISTER_PACKET_TYPE_ENTRY (BC_CHAT, 83, 0),
    REGISTER_PACKET_TYPE_ENTRY (CB_ECHO_NORMAL, 84, 0),
    REGISTER_PACKET_TYPE_ENTRY (CB_JUMP, 85, 19),
    REGISTER_PACKET_TYPE_ENTRY (BC_JUMP, 86, 19),
    REGISTER_PACKET_TYPE_ENTRY (BC_SERVER_ENTRY, 87, 18),
    REGISTER_PACKET_TYPE_ENTRY (CB_PET_PC, 88, 26),
    REGISTER_PACKET_TYPE_ENTRY (CB_DELETE_PET, 89, 18),
    REGISTER_PACKET_TYPE_ENTRY (CB_REQ_CHANGE_POSTBOX_STATE, 90, 22),
    REGISTER_PACKET_TYPE_ENTRY (CB_REQ_GET_POSTBOX_ITEM, 91, 30),
    REGISTER_PACKET_TYPE_ENTRY (BC_WAIT_QUEUE_ORDER, 92, 10),
    REGISTER_PACKET_TYPE_ENTRY (CB_CANCEL_SERVER_WAIT_QUEUE, 93, 10),
    REGISTER_PACKET_TYPE_ENTRY (CS_LOGIN, 2901, 64),
    REGISTER_PACKET_TYPE_ENTRY (SC_NORMAL, 2902, 0),
    REGISTER_PACKET_TYPE_ENTRY (SC_FROM_INTEGRATE, 2903, 0),
    REGISTER_PACKET_TYPE_ENTRY (CS_REGISTER_SNS_ID, 2904, 16),
    REGISTER_PACKET_TYPE_ENTRY (CS_REQ_SNS_PC_INFO, 2905, 0),
    REGISTER_PACKET_TYPE_ENTRY (CS_REQ_MARKET_LIST, 2906, 158),
    REGISTER_PACKET_TYPE_ENTRY (CS_REQ_MY_SELL_LIST, 2907, 10),
    REGISTER_PACKET_TYPE_ENTRY (CS_REQ_ADD_FRIEND, 2908, 70),
    REGISTER_PACKET_TYPE_ENTRY (CS_REQ_BLOCK_FRIEND, 2909, 70),
    REGISTER_PACKET_TYPE_ENTRY (CS_FRIEND_CMD, 2910, 24),
    REGISTER_PACKET_TYPE_ENTRY (CS_FRIEND_SET_ADDINFO, 2911, 160),
    REGISTER_PACKET_TYPE_ENTRY (CS_CHAT, 2912, 0),
    REGISTER_PACKET_TYPE_ENTRY (CS_CREATE_GROUP_CHAT, 2913, 6),
    REGISTER_PACKET_TYPE_ENTRY (CS_GROUP_CHAT_INVITE, 2914, 78),
    REGISTER_PACKET_TYPE_ENTRY (CS_REFRESH_GROUP_CHAT, 2915, 6),
    REGISTER_PACKET_TYPE_ENTRY (CS_CHAT_HISTORY, 2916, 22),
    REGISTER_PACKET_TYPE_ENTRY (CS_CHAT_READ, 2917, 30),
    REGISTER_PACKET_TYPE_ENTRY (CS_REMOVE_GROUP_MEMBER, 2918, 14),
    REGISTER_PACKET_TYPE_ENTRY (CS_PC_INTERACTION, 2919, 24),
    REGISTER_PACKET_TYPE_ENTRY (CS_PC_INTERACTION_HISTORY, 2921, 32),
    REGISTER_PACKET_TYPE_ENTRY (CS_ADD_RELATION_SCORE, 2932, 88),
    REGISTER_PACKET_TYPE_ENTRY (CS_GET_LIKE_COUNT, 2933, 16),
    REGISTER_PACKET_TYPE_ENTRY (CS_LIKE_IT, 2929, 80),
    REGISTER_PACKET_TYPE_ENTRY (CS_UNLIKE_IT, 2930, 16),
    REGISTER_PACKET_TYPE_ENTRY (CS_LIKE_IT_CONFIRM, 2931, 16),
    REGISTER_PACKET_TYPE_ENTRY (CS_REQ_RELATED_PC_SESSION, 2920, 16),
    REGISTER_PACKET_TYPE_ENTRY (CS_REDIS_SKILLPOINT, 2922, 22),
    REGISTER_PACKET_TYPE_ENTRY (CS_PARTY_CLIENT_INFO_SEND, 2923, 0),
    REGISTER_PACKET_TYPE_ENTRY (CS_NORMAL_GAME_START, 2924, 6),
    REGISTER_PACKET_TYPE_ENTRY (CS_PVP_COMMAND, 2925, 18),
    REGISTER_PACKET_TYPE_ENTRY (CS_REQUEST_PVP_RANKING, 2926, 83),
    REGISTER_PACKET_TYPE_ENTRY (CS_INVITE_PARTY_PVP, 2927, 10),
    REGISTER_PACKET_TYPE_ENTRY (CS_ACCEPT_PARTY_PVP, 2928, 19),
    REGISTER_PACKET_TYPE_ENTRY (CZ_CONNECT, 3001, 1164),
    REGISTER_PACKET_TYPE_ENTRY (CZ_GAME_READY, 3070, 10),
    REGISTER_PACKET_TYPE_ENTRY (CZ_KEYBOARD_MOVE, 3081, 41),
    REGISTER_PACKET_TYPE_ENTRY (CZ_EXPECTED_STOP_POS, 3082, 31),
    REGISTER_PACKET_TYPE_ENTRY (CZ_MOVE_PATH, 3086, 27),
    REGISTER_PACKET_TYPE_ENTRY (CZ_MOVE_STOP, 3087, 35),
    REGISTER_PACKET_TYPE_ENTRY (CZ_JUMP, 3083, 11),
    REGISTER_PACKET_TYPE_ENTRY (CZ_DASHRUN, 3084, 11),
    REGISTER_PACKET_TYPE_ENTRY (CZ_REST_SIT, 3088, 10),
    REGISTER_PACKET_TYPE_ENTRY (CZ_ON_AIR, 3089, 10),
    REGISTER_PACKET_TYPE_ENTRY (CZ_ON_GROUND, 3090, 10),
    REGISTER_PACKET_TYPE_ENTRY (CZ_SKILL_JUMP_REQ, 3085, 30),
    REGISTER_PACKET_TYPE_ENTRY (CZ_LOGOUT, 3072, 11),
    REGISTER_PACKET_TYPE_ENTRY (CZ_MOVE_BARRACK, 3073, 11),
    REGISTER_PACKET_TYPE_ENTRY (CZ_MOVE_ZONE_OK, 3004, 10),
    REGISTER_PACKET_TYPE_ENTRY (CZ_MOVEMENT_INFO, 3091, 23),
    REGISTER_PACKET_TYPE_ENTRY (CZ_SKILL_TARGET, 3092, 19),
    REGISTER_PACKET_TYPE_ENTRY (CZ_SKILL_TARGET_ANI, 3093, 23),
    REGISTER_PACKET_TYPE_ENTRY (CZ_SKILL_GROUND, 3094, 57),
    REGISTER_PACKET_TYPE_ENTRY (CZ_SKILL_SELF, 3095, 35),
    REGISTER_PACKET_TYPE_ENTRY (CZ_SKILL_CANCEL, 3096, 11),
    REGISTER_PACKET_TYPE_ENTRY (CZ_HOLD, 3097, 11),
    REGISTER_PACKET_TYPE_ENTRY (CZ_SHOUT, 3104, 0),
    REGISTER_PACKET_TYPE_ENTRY (CZ_CHAT, 3102, 0),
    REGISTER_PACKET_TYPE_ENTRY (CZ_CHAT_LOG, 3103, 0),
    REGISTER_PACKET_TYPE_ENTRY (CZ_ITEM_USE, 3107, 22),
    REGISTER_PACKET_TYPE_ENTRY (CZ_ITEM_USE_TO_ITEM, 3108, 30),
    REGISTER_PACKET_TYPE_ENTRY (CZ_ITEM_USE_TO_GROUND, 3109, 30),
    REGISTER_PACKET_TYPE_ENTRY (CZ_ITEM_DROP, 3105, 22),
    REGISTER_PACKET_TYPE_ENTRY (CZ_ITEM_EQUIP, 3112, 19),
    REGISTER_PACKET_TYPE_ENTRY (CZ_ITEM_UNEQUIP, 3113, 11),
    REGISTER_PACKET_TYPE_ENTRY (ZC_CHECK_INVINDEX, 3114, 30),
    REGISTER_PACKET_TYPE_ENTRY (CZ_ITEM_DELETE, 3106, 0),
    REGISTER_PACKET_TYPE_ENTRY (CZ_ITEM_BUY, 3110, 0),
    REGISTER_PACKET_TYPE_ENTRY (CZ_ITEM_SELL, 3111, 0),
    REGISTER_PACKET_TYPE_ENTRY (CZ_DIALOG_ACK, 3139, 14),
    REGISTER_PACKET_TYPE_ENTRY (CZ_DIALOG_SELECT, 3140, 11),
    REGISTER_PACKET_TYPE_ENTRY (CZ_DIALOG_STRINGINPUT, 3141, 138),
    REGISTER_PACKET_TYPE_ENTRY (CZ_LEAVE_TO_DUNGEON, 3026, 10),
    REGISTER_PACKET_TYPE_ENTRY (CZ_MOVE_CAMP, 3160, 18),
    REGISTER_PACKET_TYPE_ENTRY (CZ_CAMPINFO, 3161, 18),
    REGISTER_PACKET_TYPE_ENTRY (ZC_CAMPINFO, 3162, 18),
    REGISTER_PACKET_TYPE_ENTRY (CZ_CLICK_TRIGGER, 3080, 15),
    REGISTER_PACKET_TYPE_ENTRY (CZ_ROTATE, 3098, 18),
    REGISTER_PACKET_TYPE_ENTRY (CZ_HEAD_ROTATE, 3099, 18),
    REGISTER_PACKET_TYPE_ENTRY (CZ_TARGET_ROTATE, 3100, 18),
    REGISTER_PACKET_TYPE_ENTRY (CZ_POSE, 3101, 34),
    REGISTER_PACKET_TYPE_ENTRY (ZC_ENTER_PC, 3006, 370),
    REGISTER_PACKET_TYPE_ENTRY (ZC_ENTER_MONSTER, 3007, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_ENTER_DUMMYPC, 3008, 292),
    REGISTER_PACKET_TYPE_ENTRY (ZC_UPDATED_DUMMYPC, 3009, 250),
    REGISTER_PACKET_TYPE_ENTRY (ZC_ENTER_ITEM, 3010, 103),
    REGISTER_PACKET_TYPE_ENTRY (ZC_LEAVE, 3011, 12),
    REGISTER_PACKET_TYPE_ENTRY (ZC_MOVE_PATH, 3012, 42),
    REGISTER_PACKET_TYPE_ENTRY (ZC_MOVE_POS, 3013, 42),
    REGISTER_PACKET_TYPE_ENTRY (ZC_MSPD, 3016, 14),
    REGISTER_PACKET_TYPE_ENTRY (ZC_MOVE_SPEED, 3017, 18),
    REGISTER_PACKET_TYPE_ENTRY (ZC_MOVE_DIR, 3014, 40),
    REGISTER_PACKET_TYPE_ENTRY (ZC_EXPECTED_STOPPOS, 3015, 35),
    REGISTER_PACKET_TYPE_ENTRY (ZC_MOVE_STOP, 3018, 23),
    REGISTER_PACKET_TYPE_ENTRY (ZC_REST_SIT, 3019, 11),
    REGISTER_PACKET_TYPE_ENTRY (ZC_JUMP, 3020, 19),
    REGISTER_PACKET_TYPE_ENTRY (ZC_JUMP_DIR, 3021, 34),
    REGISTER_PACKET_TYPE_ENTRY (ZC_ORDER_SKILL_JUMP, 3022, 10),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SKILL_JUMP, 3023, 38),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SET_POS, 3024, 22),
    REGISTER_PACKET_TYPE_ENTRY (ZC_FILE_MOVE, 3025, 46),
    REGISTER_PACKET_TYPE_ENTRY (ZC_MESSAGE, 3076, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_CONNECT_OK, 3002, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_CONNECT_FAILED, 3005, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_START_GAME, 3078, 26),
    REGISTER_PACKET_TYPE_ENTRY (ZC_MOVE_ZONE, 3003, 7),
    REGISTER_PACKET_TYPE_ENTRY (ZC_MOVE_BARRACK, 3074, 6),
    REGISTER_PACKET_TYPE_ENTRY (ZC_MOVE_ZONE_OK, 3071, 57),
    REGISTER_PACKET_TYPE_ENTRY (ZC_DEAD, 3056, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_RESURRECT, 3057, 18),
    REGISTER_PACKET_TYPE_ENTRY (ZC_RESURRECT_DIALOG, 3059, 7),
    REGISTER_PACKET_TYPE_ENTRY (CZ_RESURRECT, 3067, 11),
    REGISTER_PACKET_TYPE_ENTRY (ZC_RESURRECT_SAVE_POINT_ACK, 3068, 7),
    REGISTER_PACKET_TYPE_ENTRY (ZC_RESURRECT_HERE_ACK, 3069, 7),
    REGISTER_PACKET_TYPE_ENTRY (ZC_UPDATED_PCAPPEARANCE, 3027, 250),
    REGISTER_PACKET_TYPE_ENTRY (ZC_UPDATED_MONSTERAPPEARANCE, 3028, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_ADD_HP, 3032, 22),
    REGISTER_PACKET_TYPE_ENTRY (ZC_UPDATE_SP, 3136, 15),
    REGISTER_PACKET_TYPE_ENTRY (ZC_UPDATE_MHP, 3138, 14),
    REGISTER_PACKET_TYPE_ENTRY (ZC_EXP_UP, 3130, 14),
    REGISTER_PACKET_TYPE_ENTRY (ZC_EXP_UP_BY_MONSTER, 3131, 18),
    REGISTER_PACKET_TYPE_ENTRY (ZC_PC_LEVELUP, 3132, 14),
    REGISTER_PACKET_TYPE_ENTRY (ZC_PC_STAT_AVG, 3133, 30),
    REGISTER_PACKET_TYPE_ENTRY (ZC_MAX_EXP_CHANGED, 3134, 18),
    REGISTER_PACKET_TYPE_ENTRY (ZC_UPDATE_ALL_STATUS, 3171, 26),
    REGISTER_PACKET_TYPE_ENTRY (ZC_CHANGE_RELATION, 3058, 11),
    REGISTER_PACKET_TYPE_ENTRY (ZC_QUICK_SLOT_LIST, 3122, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SKILL_LIST, 3123, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SKILL_ADD, 3124, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SKILL_CAST_CANCEL, 3033, 10),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SKILL_CAST, 3034, 38),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SKILL_READY, 3035, 46),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SKILL_USE_CANCEL, 3037, 10),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SKILL_DISABLE, 3036, 15),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SKILL_MELEE_TARGET, 3038, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SKILL_FORCE_TARGET, 3040, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SKILL_MELEE_GROUND, 3039, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SKILL_FORCE_GROUND, 3041, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SKILL_HIT_INFO, 3042, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_ABILITY_LIST, 3125, 0),
    REGISTER_PACKET_TYPE_ENTRY (CZ_ACTIVE_ABILITY, 3126, 15),
    REGISTER_PACKET_TYPE_ENTRY (ZC_ACTIVE_ABILITY, 3127, 11),
    REGISTER_PACKET_TYPE_ENTRY (CZ_DISPEL_DEBUFF_TOGGLE, 3128, 14),
    REGISTER_PACKET_TYPE_ENTRY (CZ_JUNGTAN_TOGGLE, 3129, 16),
    REGISTER_PACKET_TYPE_ENTRY (ZC_BUFF_LIST, 3043, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_BUFF_ADD, 3044, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_BUFF_UPDATE, 3045, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_BUFF_REMOVE, 3046, 17),
    REGISTER_PACKET_TYPE_ENTRY (ZC_BUFF_CLEAR, 3047, 11),
    REGISTER_PACKET_TYPE_ENTRY (CZ_BUFF_REMOVE, 3048, 14),
    REGISTER_PACKET_TYPE_ENTRY (CZ_INTE_WARP, 3049, 14),
    REGISTER_PACKET_TYPE_ENTRY (ZC_HIT_INFO, 3060, 60),
    REGISTER_PACKET_TYPE_ENTRY (ZC_HEAL_INFO, 3061, 30),
    REGISTER_PACKET_TYPE_ENTRY (ZC_CAUTION_DAMAGE_INFO, 3063, 15),
    REGISTER_PACKET_TYPE_ENTRY (ZC_CAUTION_DAMAGE_RELEASE, 3064, 10),
    REGISTER_PACKET_TYPE_ENTRY (ZC_KNOCKBACK_INFO, 3065, 70),
    REGISTER_PACKET_TYPE_ENTRY (ZC_KNOCKDOWN_INFO, 3066, 71),
    REGISTER_PACKET_TYPE_ENTRY (ZC_CHAT, 3029, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_CHAT_WITH_TEXTCODE, 3030, 14),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SHOUT, 3174, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SHOUT_FAILED, 3175, 7),
    REGISTER_PACKET_TYPE_ENTRY (ZC_TEXT, 3135, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_QUIET, 3079, 7),
    REGISTER_PACKET_TYPE_ENTRY (ZC_DIALOG_CLOSE, 3147, 6),
    REGISTER_PACKET_TYPE_ENTRY (ZC_DIALOG_OK, 3143, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_DIALOG_NEXT, 3144, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_DIALOG_SELECT, 3145, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_DIALOG_TRADE, 3148, 39),
    REGISTER_PACKET_TYPE_ENTRY (ZC_DIALOG_COMMON_TRADE, 3149, 39),
    REGISTER_PACKET_TYPE_ENTRY (ZC_DIALOG_ITEM_SELECT, 3146, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_DIALOG_NUMBERRANGE, 3150, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_DIALOG_STRINGINPUT, 3151, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_STANCE_CHANGE, 3031, 14),
    REGISTER_PACKET_TYPE_ENTRY (ZC_ITEM_ADD, 3118, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_ITEM_INVENTORY_LIST, 3115, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_ITEM_INVENTORY_INDEX_LIST, 3116, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_ITEM_EQUIP_LIST, 3117, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_ITEM_REMOVE, 3119, 20),
    REGISTER_PACKET_TYPE_ENTRY (ZC_ITEM_USE, 3120, 14),
    REGISTER_PACKET_TYPE_ENTRY (ZC_ITEM_USE_TO_GROUND, 3121, 22),
    REGISTER_PACKET_TYPE_ENTRY (ZC_RESET_VIEW, 3077, 6),
    REGISTER_PACKET_TYPE_ENTRY (ZC_RESTORATION, 3137, 12),
    REGISTER_PACKET_TYPE_ENTRY (ZC_ROTATE, 3050, 20),
    REGISTER_PACKET_TYPE_ENTRY (ZC_ROTATE_RESERVED, 3051, 18),
    REGISTER_PACKET_TYPE_ENTRY (ZC_HEAD_ROTATE, 3052, 18),
    REGISTER_PACKET_TYPE_ENTRY (ZC_TARGET_ROTATE, 3053, 18),
    REGISTER_PACKET_TYPE_ENTRY (ZC_QUICK_ROTATE, 3054, 18),
    REGISTER_PACKET_TYPE_ENTRY (ZC_POSE, 3055, 34),
    REGISTER_PACKET_TYPE_ENTRY (ZC_DUMP_PROPERTY, 3173, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_OBJECT_PROPERTY, 3172, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_ADDON_MSG, 3152, 0),
    REGISTER_PACKET_TYPE_ENTRY (CZ_UI_EVENT, 3153, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_LOGOUT_OK, 3075, 6),
    REGISTER_PACKET_TYPE_ENTRY (ZC_PLAY_SOUND, 3154, 15),
    REGISTER_PACKET_TYPE_ENTRY (ZC_STOP_SOUND, 3155, 14),
    REGISTER_PACKET_TYPE_ENTRY (ZC_PLAY_MUSICQUEUE, 3156, 14),
    REGISTER_PACKET_TYPE_ENTRY (ZC_STOP_MUSICQUEUE, 3157, 14),
    REGISTER_PACKET_TYPE_ENTRY (ZC_PLAY_ANI, 3158, 24),
    REGISTER_PACKET_TYPE_ENTRY (ZC_CHANGE_ANI, 3159, 44),
    REGISTER_PACKET_TYPE_ENTRY (ZC_PLAY_ALARMSOUND, 3167, 83),
    REGISTER_PACKET_TYPE_ENTRY (ZC_STOP_ALARMSOUND, 3168, 10),
    REGISTER_PACKET_TYPE_ENTRY (ZC_PLAY_EXP_TEXT, 3169, 14),
    REGISTER_PACKET_TYPE_ENTRY (ZC_PLAY_NAVI_EFFECT, 3170, 150),
    REGISTER_PACKET_TYPE_ENTRY (CZ_EXCHANGE_REQUEST, 3176, 14),
    REGISTER_PACKET_TYPE_ENTRY (ZC_EXCHANGE_REQUEST_ACK, 3177, 72),
    REGISTER_PACKET_TYPE_ENTRY (ZC_EXCHANGE_REQUEST_RECEIVED, 3178, 71),
    REGISTER_PACKET_TYPE_ENTRY (CZ_EXCHANGE_ACCEPT, 3179, 10),
    REGISTER_PACKET_TYPE_ENTRY (CZ_EXCHANGE_DECLINE, 3180, 10),
    REGISTER_PACKET_TYPE_ENTRY (ZC_EXCHANGE_DECLINE_ACK, 3181, 6),
    REGISTER_PACKET_TYPE_ENTRY (ZC_EXCHANGE_START, 3182, 71),
    REGISTER_PACKET_TYPE_ENTRY (CZ_EXCHANGE_OFFER, 3183, 30),
    REGISTER_PACKET_TYPE_ENTRY (ZC_EXCHANGE_OFFER_ACK, 3184, 0),
    REGISTER_PACKET_TYPE_ENTRY (CZ_EXCHANGE_AGREE, 3185, 10),
    REGISTER_PACKET_TYPE_ENTRY (ZC_EXCHANGE_AGREE_ACK, 3186, 7),
    REGISTER_PACKET_TYPE_ENTRY (CZ_EXCHANGE_FINALAGREE, 3187, 10),
    REGISTER_PACKET_TYPE_ENTRY (ZC_EXCHANGE_FINALAGREE_ACK, 3188, 7),
    REGISTER_PACKET_TYPE_ENTRY (CZ_EXCHANGE_CANCEL, 3189, 10),
    REGISTER_PACKET_TYPE_ENTRY (ZC_EXCHANGE_CANCEL_ACK, 3190, 6),
    REGISTER_PACKET_TYPE_ENTRY (ZC_EXCHANGE_SUCCESS, 3191, 6),
    REGISTER_PACKET_TYPE_ENTRY (ZC_COOLDOWN_LIST, 3192, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_COOLDOWN_CHANGED, 3193, 22),
    REGISTER_PACKET_TYPE_ENTRY (ZC_OVERHEAT_CHANGED, 3194, 26),
    REGISTER_PACKET_TYPE_ENTRY (ZC_TEST_AGENT, 3195, 18),
    REGISTER_PACKET_TYPE_ENTRY (CZ_COMMON_SHOP_LIST, 3196, 10),
    REGISTER_PACKET_TYPE_ENTRY (ZC_COMMON_SHOP_LIST, 3197, 8),
    REGISTER_PACKET_TYPE_ENTRY (ZC_TIME_FACTOR, 3198, 10),
    REGISTER_PACKET_TYPE_ENTRY (ZC_PARTY_ENTER, 3199, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_PARTY_OUT, 3200, 24),
    REGISTER_PACKET_TYPE_ENTRY (ZC_PARTY_DESTROY, 3201, 15),
    REGISTER_PACKET_TYPE_ENTRY (ZC_PARTY_INFO, 3202, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_PARTY_LIST, 3203, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_PARTY_CHAT, 3204, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_PARTY_INST_INFO, 3205, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_CHANGE_EQUIP_DURABILITY, 3206, 11),
    REGISTER_PACKET_TYPE_ENTRY (CZ_DIALOG_TX, 3207, 0),
    REGISTER_PACKET_TYPE_ENTRY (CZ_REQ_RECIPE, 3208, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_CUSTOM_DIALOG, 3209, 75),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SESSION_OBJECTS, 3210, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SESSION_OBJ_ADD, 3211, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SESSION_OBJ_REMOVE, 3212, 10),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SESSION_OBJ_TIME, 3213, 14),
    REGISTER_PACKET_TYPE_ENTRY (CZ_S_OBJ_VALUE_C, 3214, 24),
    REGISTER_PACKET_TYPE_ENTRY (CZ_REQ_NORMAL_TX, 3215, 29),
    REGISTER_PACKET_TYPE_ENTRY (ZC_COMMANDER_LOADER_INFO, 3216, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_MOVE_SINGLE_ZONE, 3217, 18),
    REGISTER_PACKET_TYPE_ENTRY (ZC_BACKTO_ORIGINAL_SERVER, 3218, 8),
    REGISTER_PACKET_TYPE_ENTRY (CZ_BACKTO_ORIGINAL_SERVER, 3219, 12),
    REGISTER_PACKET_TYPE_ENTRY (CZ_REQ_NORMAL_TX_NUMARG, 3220, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_WIKI_LIST, 3221, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_WIKI_ADD, 3222, 22),
    REGISTER_PACKET_TYPE_ENTRY (CZ_WIKI_GET, 3223, 14),
    REGISTER_PACKET_TYPE_ENTRY (CZ_WIKI_RECIPE_UPDATE, 3224, 10),
    REGISTER_PACKET_TYPE_ENTRY (ZC_UI_OPEN, 3225, 39),
    REGISTER_PACKET_TYPE_ENTRY (ZC_ENABLE_CONTROL, 3226, 11),
    REGISTER_PACKET_TYPE_ENTRY (ZC_CHANGE_CAMERA, 3227, 31),
    REGISTER_PACKET_TYPE_ENTRY (ZC_MONSTER_SDR_CHANGED, 3228, 11),
    REGISTER_PACKET_TYPE_ENTRY (ZC_MOVE_IGNORE_COLLISION, 3229, 30),
    REGISTER_PACKET_TYPE_ENTRY (ZC_CHANGE_CAMERA_ZOOM, 3230, 34),
    REGISTER_PACKET_TYPE_ENTRY (ZC_PLAY_SKILL_ANI, 3231, 82),
    REGISTER_PACKET_TYPE_ENTRY (ZC_PLAY_SKILL_CAST_ANI, 3232, 30),
    REGISTER_PACKET_TYPE_ENTRY (CZ_REQ_ITEM_GET, 3233, 14),
    REGISTER_PACKET_TYPE_ENTRY (ZC_ITEM_GET, 3234, 18),
    REGISTER_PACKET_TYPE_ENTRY (CZ_GUARD, 3235, 19),
    REGISTER_PACKET_TYPE_ENTRY (ZC_GUARD, 3236, 19),
    REGISTER_PACKET_TYPE_ENTRY (ZC_STAMINA, 3237, 10),
    REGISTER_PACKET_TYPE_ENTRY (ZC_ADD_STAMINA, 3238, 10),
    REGISTER_PACKET_TYPE_ENTRY (ZC_GM_ORDER, 3239, 10),
    REGISTER_PACKET_TYPE_ENTRY (ZC_MYPC_ENTER, 3240, 18),
    REGISTER_PACKET_TYPE_ENTRY (ZC_LOCK_KEY, 3241, 75),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SAVE_INFO, 3242, 6),
    REGISTER_PACKET_TYPE_ENTRY (CZ_SAVE_INFO, 3243, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_OPTION_LIST, 3244, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SKILLMAP_LIST, 3245, 0),
    REGISTER_PACKET_TYPE_ENTRY (CZ_GIVEITEM_TO_DUMMYPC, 3246, 22),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SET_LAYER, 3247, 10),
    REGISTER_PACKET_TYPE_ENTRY (ZC_CREATE_LAYERBOX, 3248, 38),
    REGISTER_PACKET_TYPE_ENTRY (ZC_RESET_BOX, 3249, 11),
    REGISTER_PACKET_TYPE_ENTRY (ZC_CREATE_SCROLLLOCKBOX, 3250, 38),
    REGISTER_PACKET_TYPE_ENTRY (ZC_REMOVE_SCROLLLOCKBOX, 3251, 10),
    REGISTER_PACKET_TYPE_ENTRY (CZ_DYNAMIC_CASTING_START, 3252, 23),
    REGISTER_PACKET_TYPE_ENTRY (CZ_DYNAMIC_CASTING_END, 3253, 19),
    REGISTER_PACKET_TYPE_ENTRY (CZ_SKILL_CANCEL_SCRIPT, 3254, 10),
    REGISTER_PACKET_TYPE_ENTRY (ZC_LEAVE_TRIGGER, 3255, 6),
    REGISTER_PACKET_TYPE_ENTRY (ZC_BORN, 3256, 10),
    REGISTER_PACKET_TYPE_ENTRY (ZC_ACHIEVE_POINT_LIST, 3257, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_ACHIEVE_POINT, 3258, 18),
    REGISTER_PACKET_TYPE_ENTRY (CZ_ACHIEVE_EQUIP, 3259, 18),
    REGISTER_PACKET_TYPE_ENTRY (ZC_ACHIEVE_EQUIP, 3260, 22),
    REGISTER_PACKET_TYPE_ENTRY (CZ_CHANGE_CONFIG, 3261, 18),
    REGISTER_PACKET_TYPE_ENTRY (CZ_CHANGE_CONFIG_STR, 3262, 34),
    REGISTER_PACKET_TYPE_ENTRY (ZC_WORLD_MSG, 3263, 43),
    REGISTER_PACKET_TYPE_ENTRY (ZC_ENABLE_SHOW_ITEM_GET, 3264, 8),
    REGISTER_PACKET_TYPE_ENTRY (ZC_LOGIN_TIME, 3265, 14),
    REGISTER_PACKET_TYPE_ENTRY (ZC_GIVE_EXP_TO_PC, 3266, 42),
    REGISTER_PACKET_TYPE_ENTRY (ZC_LAYER_PC_LIST, 3267, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_LAYER_PC_SOBJ_PROP, 3268, 0),
    REGISTER_PACKET_TYPE_ENTRY (CZ_CUSTOM_COMMAND, 3269, 26),
    REGISTER_PACKET_TYPE_ENTRY (CZ_ADD_HELP, 3424, 14),
    REGISTER_PACKET_TYPE_ENTRY (ZC_LAYER_INFO, 3270, 10),
    REGISTER_PACKET_TYPE_ENTRY (CZ_CHAT_MACRO, 3271, 146),
    REGISTER_PACKET_TYPE_ENTRY (ZC_CHAT_MACRO_LIST, 3272, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_RULLET_LIST, 3273, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_QUICKSLOT_REGISTER, 3274, 46),
    REGISTER_PACKET_TYPE_ENTRY (CZ_QUICKSLOT_LIST, 3275, 0),
    REGISTER_PACKET_TYPE_ENTRY (CZ_DOUBLE_ITEM_EQUIP, 3276, 28),
    REGISTER_PACKET_TYPE_ENTRY (ZC_TRICK_PACKET, 3277, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_COOLDOWN_RATE, 3278, 22),
    REGISTER_PACKET_TYPE_ENTRY (ZC_MAP_REVEAL_LIST, 3279, 0),
    REGISTER_PACKET_TYPE_ENTRY (CZ_MAP_REVEAL_INFO, 3280, 146),
    REGISTER_PACKET_TYPE_ENTRY (CZ_MAP_SEARCH_INFO, 3281, 55),
    REGISTER_PACKET_TYPE_ENTRY (ZC_UI_INFO_LIST, 3282, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_EXEC_CLIENT_SCP, 3283, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SET_NPC_STATE, 3284, 18),
    REGISTER_PACKET_TYPE_ENTRY (ZC_NPC_STATE_LIST, 3285, 0),
    REGISTER_PACKET_TYPE_ENTRY (CZ_QUEST_NPC_STATE_CHECK, 3286, 14),
    REGISTER_PACKET_TYPE_ENTRY (ZC_RANK_ACHIEVE_ADD, 3287, 14),
    REGISTER_PACKET_TYPE_ENTRY (CZ_GET_MAP_REVEAL_ACHIEVE, 3288, 10),
    REGISTER_PACKET_TYPE_ENTRY (CZ_IES_MODIFY_INFO, 3289, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_IES_MODIFY_INFO, 3290, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_IES_MODIFY_LIST, 3291, 0),
    REGISTER_PACKET_TYPE_ENTRY (CZ_IES_REVISION_DELETE, 3292, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_IES_REVISION_DELETE, 3293, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_EQUIP_ITEM_REMOVE, 3294, 18),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SOLD_ITEM_LIST, 3295, 0),
    REGISTER_PACKET_TYPE_ENTRY (CZ_SOLD_ITEM, 3296, 19),
    REGISTER_PACKET_TYPE_ENTRY (CZ_WAREHOUSE_CMD, 3297, 31),
    REGISTER_PACKET_TYPE_ENTRY (CZ_SWAP_ETC_INV_CHANGE_INDEX, 3298, 35),
    REGISTER_PACKET_TYPE_ENTRY (CZ_SORT_ETC_INV_CHANGE_INDEX, 3299, 11),
    REGISTER_PACKET_TYPE_ENTRY (CZ_SORT_INV_CHANGE_INDEX, 3300, 11),
    REGISTER_PACKET_TYPE_ENTRY (CZ_CAST_CONTROL_SHOT, 3301, 10),
    REGISTER_PACKET_TYPE_ENTRY (ZC_PC_PROP_UPDATE, 3302, 9),
    REGISTER_PACKET_TYPE_ENTRY (CZ_CLIENT_DAMAGE, 3303, 14),
    REGISTER_PACKET_TYPE_ENTRY (CZ_CLIENT_ATTACK, 3304, 15),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SYSTEM_MSG, 3305, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_FSM_MOVE, 3306, 0),
    REGISTER_PACKET_TYPE_ENTRY (CZ_QUEST_CHECK_SAVE, 3307, 50),
    REGISTER_PACKET_TYPE_ENTRY (CZ_SPRAY_REQ_INFO, 3308, 14),
    REGISTER_PACKET_TYPE_ENTRY (CZ_SPRAY_DRAW_INFO, 3309, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SPRAY_ID, 3310, 18),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SPRAY_DRAW_INFO, 3311, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_MONSTER_LIFETIME, 3312, 14),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SPRAY_LIKE_LIST, 3313, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_WIKI_COUNT_UPDATE, 3314, 19),
    REGISTER_PACKET_TYPE_ENTRY (ZC_WIKI_INT_PROP_UPDATE, 3315, 15),
    REGISTER_PACKET_TYPE_ENTRY (ZC_WIKI_BOOL_PROP_UPDATE, 3316, 12),
    REGISTER_PACKET_TYPE_ENTRY (CZ_REQ_WIKI_RANK, 3317, 15),
    REGISTER_PACKET_TYPE_ENTRY (ZC_WIKI_RANK_LIST, 3318, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SHARED_MSG, 3319, 10),
    REGISTER_PACKET_TYPE_ENTRY (CZ_REQ_WIKI_PROP_RANK, 3320, 16),
    REGISTER_PACKET_TYPE_ENTRY (CZ_REQ_TX_ITEM, 3322, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_TEST_DBG, 3323, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_MONSTER_DIST, 3324, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_RESET_SKILL_FORCEID, 3325, 10),
    REGISTER_PACKET_TYPE_ENTRY (ZC_EMOTICON, 3326, 18),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SHOW_EMOTICON, 3327, 18),
    REGISTER_PACKET_TYPE_ENTRY (ZC_TREASUREMARK_BY_MAP, 3328, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SHOW_MAP, 3329, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_TREASUREMARK_LIST_MAP, 203, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_FIX_ANIM, 3163, 14),
    REGISTER_PACKET_TYPE_ENTRY (ZC_MOVE_ANIM, 3164, 12),
    REGISTER_PACKET_TYPE_ENTRY (CZ_FLEE_OBSTACLE, 3330, 26),
    REGISTER_PACKET_TYPE_ENTRY (ZC_HOLD_MOVE_PATH, 3331, 11),
    REGISTER_PACKET_TYPE_ENTRY (ZC_ENTER_HOOK, 3332, 10),
    REGISTER_PACKET_TYPE_ENTRY (ZC_LEAVE_HOOK, 3333, 10),
    REGISTER_PACKET_TYPE_ENTRY (ZC_MONSTER_PROPERTY, 3334, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_GROUND_EFFECT, 3335, 50),
    REGISTER_PACKET_TYPE_ENTRY (ZC_FLY, 3336, 18),
    REGISTER_PACKET_TYPE_ENTRY (ZC_FLY_MATH, 3337, 22),
    REGISTER_PACKET_TYPE_ENTRY (ZC_FLY_HEIGHT, 3338, 14),
    REGISTER_PACKET_TYPE_ENTRY (ZC_UPDATE_SHIELD, 3339, 12),
    REGISTER_PACKET_TYPE_ENTRY (ZC_UPDATE_MSHIELD, 3340, 12),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SHOW_MODEL, 3341, 15),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SKILL_RANGE_DBG, 3342, 58),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SKILL_RANGE_FAN, 3343, 40),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SKILL_RANGE_SQUARE, 3344, 40),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SKILL_RANGE_CIRCLE, 3345, 28),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SKILL_RANGE_DONUTS, 3346, 32),
    REGISTER_PACKET_TYPE_ENTRY (ZC_TEAMID, 3347, 11),
    REGISTER_PACKET_TYPE_ENTRY (ZC_PC, 3348, 0),
    REGISTER_PACKET_TYPE_ENTRY (CZ_LOG, 3349, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_MOTIONBLUR, 3350, 11),
    REGISTER_PACKET_TYPE_ENTRY (ZC_PLAY_FORCE, 3351, 78),
    REGISTER_PACKET_TYPE_ENTRY (ZC_CAST_TARGET, 3352, 14),
    REGISTER_PACKET_TYPE_ENTRY (ZC_START_INFO, 3353, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_JOB_EXP_UP, 3354, 10),
    REGISTER_PACKET_TYPE_ENTRY (ZC_JOB_PTS, 3355, 10),
    REGISTER_PACKET_TYPE_ENTRY (ZC_MON_STAMINA, 3356, 22),
    REGISTER_PACKET_TYPE_ENTRY (CZ_CUSTOM_SCP, 3357, 14),
    REGISTER_PACKET_TYPE_ENTRY (ZC_VIEW_FOCUS, 3358, 24),
    REGISTER_PACKET_TYPE_ENTRY (ZC_HARDCODED_SKILL, 3359, 26),
    REGISTER_PACKET_TYPE_ENTRY (CZ_HARDCODED_SKILL, 3360, 34),
    REGISTER_PACKET_TYPE_ENTRY (ZC_FORCE_MOVE, 3361, 30),
    REGISTER_PACKET_TYPE_ENTRY (ZC_HSKILL_CONTROL, 3362, 22),
    REGISTER_PACKET_TYPE_ENTRY (ZC_CANCEL_DEADEVENT, 3363, 10),
    REGISTER_PACKET_TYPE_ENTRY (ZC_ACTION_PKS, 3364, 35),
    REGISTER_PACKET_TYPE_ENTRY (CZ_HARDCODED_ITEM, 3365, 22),
    REGISTER_PACKET_TYPE_ENTRY (CZ_BRIQUET, 3367, 30),
    REGISTER_PACKET_TYPE_ENTRY (CZ_CANCEL_TRANSFORM_SKILL, 3366, 10),
    REGISTER_PACKET_TYPE_ENTRY (ZC_VIBRATE, 3368, 30),
    REGISTER_PACKET_TYPE_ENTRY (ZC_COUNTER_MOVE, 3369, 10),
    REGISTER_PACKET_TYPE_ENTRY (CZ_COUNTER_ATTACK, 3370, 14),
    REGISTER_PACKET_TYPE_ENTRY (CZ_CLIENT_DIRECT, 3371, 30),
    REGISTER_PACKET_TYPE_ENTRY (ZC_CLIENT_DIRECT, 3372, 30),
    REGISTER_PACKET_TYPE_ENTRY (ZC_OWNER, 3373, 14),
    REGISTER_PACKET_TYPE_ENTRY (ZC_GD_RANK, 3374, 10),
    REGISTER_PACKET_TYPE_ENTRY (CZ_RUN_BGEVENT, 3375, 74),
    REGISTER_PACKET_TYPE_ENTRY (ZC_ADD_SKILL_EFFECT, 3376, 18),
    REGISTER_PACKET_TYPE_ENTRY (ZC_ITEM_DROPABLE, 3377, 10),
    REGISTER_PACKET_TYPE_ENTRY (CZ_ITEM_DROP_TO_OBJECT, 3378, 26),
    REGISTER_PACKET_TYPE_ENTRY (ZC_NORMAL, 3379, 0),
    REGISTER_PACKET_TYPE_ENTRY (CZ_G_QUEST_CHECK, 3380, 14),
    REGISTER_PACKET_TYPE_ENTRY (ZC_MOVE_PATH_MATH, 3381, 30),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SHOW_GROUND_ITEM_MARK, 3398, 30),
    REGISTER_PACKET_TYPE_ENTRY (ZC_HELP_LIST, 3399, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_HELP_ADD, 3400, 11),
    REGISTER_PACKET_TYPE_ENTRY (ZC_STD_ANIM, 3165, 11),
    REGISTER_PACKET_TYPE_ENTRY (CZ_CLIENT_HIT_LIST, 3401, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_PC_ATKSTATE, 3402, 11),
    REGISTER_PACKET_TYPE_ENTRY (CZ_HELP_READ_TYPE, 3403, 18),
    REGISTER_PACKET_TYPE_ENTRY (CZ_MOVE_PATH_END, 3404, 10),
    REGISTER_PACKET_TYPE_ENTRY (ZC_COLL_DAMAGE, 3405, 11),
    REGISTER_PACKET_TYPE_ENTRY (CZ_KEYBOARD_BEAT, 3406, 10),
    REGISTER_PACKET_TYPE_ENTRY (CZ_MOVEHIT_SCP, 3407, 22),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SYNC_START, 3408, 10),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SYNC_END, 3409, 14),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SYNC_EXEC, 3410, 10),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SYNC_EXEC_BY_SKILL_TIME, 3411, 18),
    REGISTER_PACKET_TYPE_ENTRY (CZ_STOP_TIMEACTION, 3412, 11),
    REGISTER_PACKET_TYPE_ENTRY (CZ_REQ_DUMMYPC_INFO, 3413, 18),
    REGISTER_PACKET_TYPE_ENTRY (CZ_VISIT_BARRACK, 3414, 74),
    REGISTER_PACKET_TYPE_ENTRY (CZ_SPC_SKILL_POS, 3415, 22),
    REGISTER_PACKET_TYPE_ENTRY (CZ_REQ_CHANGEJOB, 3416, 14),
    REGISTER_PACKET_TYPE_ENTRY (CZ_REQ_MINITEXT, 3419, 266),
    REGISTER_PACKET_TYPE_ENTRY (ZC_PC_MOVE_STOP, 3420, 35),
    REGISTER_PACKET_TYPE_ENTRY (CZ_SKILL_TOOL_GROUND_POS, 3430, 26),
    REGISTER_PACKET_TYPE_ENTRY (CZ_CHANGE_HEAD, 3417, 14),
    REGISTER_PACKET_TYPE_ENTRY (CZ_CREATE_ARROW_CRAFT, 3418, 14),
    REGISTER_PACKET_TYPE_ENTRY (CZ_MYPAGE_COMMENT_ADD, 3382, 278),
    REGISTER_PACKET_TYPE_ENTRY (CZ_MYPAGE_COMMENT_DELETE, 3383, 18),
    REGISTER_PACKET_TYPE_ENTRY (CZ_GET_TARGET_MYPAGE, 3385, 14),
    REGISTER_PACKET_TYPE_ENTRY (CZ_ON_MYPAGE_MODE, 3386, 14),
    REGISTER_PACKET_TYPE_ENTRY (CZ_RESET_SOCIAL_MODE, 3387, 10),
    REGISTER_PACKET_TYPE_ENTRY (CZ_GUESTPAGE_COMMENT_ADD, 3384, 278),
    REGISTER_PACKET_TYPE_ENTRY (CZ_GET_TARGET_GUESTPAGE, 3388, 14),
    REGISTER_PACKET_TYPE_ENTRY (CZ_ADD_SELLMODE_ITEM, 3389, 30),
    REGISTER_PACKET_TYPE_ENTRY (CZ_DELETE_SELLMODE_ITEM, 3390, 18),
    REGISTER_PACKET_TYPE_ENTRY (CZ_ON_SELLITEM_MODE, 3391, 14),
    REGISTER_PACKET_TYPE_ENTRY (CZ_ON_ITEMBUY_MODE, 3396, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_MYPAGE_MAP, 3392, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_GUESTPAGE_MAP, 3393, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_ON_MYPAGE_MODE, 3394, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_RESET_SOCIAL_MODE, 3395, 10),
    REGISTER_PACKET_TYPE_ENTRY (ZC_ON_BUYITEM_MODE, 3397, 0),
    REGISTER_PACKET_TYPE_ENTRY (CZ_STOP_ALLPC, 3421, 10),
    REGISTER_PACKET_TYPE_ENTRY (CZ_COMPLETE_PRELOAD, 3422, 14),
    REGISTER_PACKET_TYPE_ENTRY (CZ_MGAME_JOIN_CMD, 3423, 46),
    REGISTER_PACKET_TYPE_ENTRY (ZC_ATTACH_TO_OBJ, 3425, 49),
    REGISTER_PACKET_TYPE_ENTRY (ZC_DETACH_FROM_OBJ, 3426, 14),
    REGISTER_PACKET_TYPE_ENTRY (ZC_RUN_FROM, 3427, 14),
    REGISTER_PACKET_TYPE_ENTRY (ZC_LOOKAT_OBJ, 3428, 14),
    REGISTER_PACKET_TYPE_ENTRY (CZ_SKILL_CELL_LIST, 3429, 0),
    REGISTER_PACKET_TYPE_ENTRY (CZ_DIRECTION_PROCESS, 3431, 18),
    REGISTER_PACKET_TYPE_ENTRY (CZ_DIRECTION_MOVE_STATE, 3432, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_TO_ALL_CLIENT, 3433, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_TO_CLIENT, 3434, 0),
    REGISTER_PACKET_TYPE_ENTRY (CZ_REWARD_CMD, 3435, 14),
    REGISTER_PACKET_TYPE_ENTRY (CZ_PROPERTY_COMPARE, 3436, 15),
    REGISTER_PACKET_TYPE_ENTRY (ZC_PROPERTY_COMPARE, 3437, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_RECOMMEND_PARTYMEMBER_INFO, 3497, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_FACTION, 3438, 14),
    REGISTER_PACKET_TYPE_ENTRY (ZC_BEGIN_KILL_LOG, 3439, 6),
    REGISTER_PACKET_TYPE_ENTRY (ZC_END_KILL_LOG, 3440, 6),
    REGISTER_PACKET_TYPE_ENTRY (ZC_CLEAR_KILL_LOG, 3441, 6),
    REGISTER_PACKET_TYPE_ENTRY (CZ_NPC_AUCTION_CMD, 3442, 30),
    REGISTER_PACKET_TYPE_ENTRY (ZC_DIRECTION_APC, 3443, 22),
    REGISTER_PACKET_TYPE_ENTRY (ZC_BGMODEL_ANIM_INFO, 3444, 15),
    REGISTER_PACKET_TYPE_ENTRY (ZC_ATTACH_BY_KNOCKBACK, 3445, 38),
    REGISTER_PACKET_TYPE_ENTRY (CZ_OBJECT_MOVE, 3446, 30),
    REGISTER_PACKET_TYPE_ENTRY (CZ_CONTROL_OBJECT_ROTATE, 3447, 22),
    REGISTER_PACKET_TYPE_ENTRY (CZ_SUMMON_COMMAND, 3448, 18),
    REGISTER_PACKET_TYPE_ENTRY (CZ_VEHICLE_RIDE, 3449, 15),
    REGISTER_PACKET_TYPE_ENTRY (CZ_REQ_WIKI_CATEGORY_RANK_PAGE_INFO, 3450, 78),
    REGISTER_PACKET_TYPE_ENTRY (CZ_REQ_ACHIEVE_RANK_PAGE_INFO, 3451, 78),
    REGISTER_PACKET_TYPE_ENTRY (CZ_REQ_MONSTER_RANK_INFO, 3452, 74),
    REGISTER_PACKET_TYPE_ENTRY (ZC_SPC_TRIGGER_EXEC, 3453, 30),
    REGISTER_PACKET_TYPE_ENTRY (CZ_REQ_MGAME_VIEW, 3454, 18),
    REGISTER_PACKET_TYPE_ENTRY (CZ_REQ_MGAME_CHAT, 3455, 0),
    REGISTER_PACKET_TYPE_ENTRY (CZ_TOURNAMENT_GIFT, 3456, 18),
    REGISTER_PACKET_TYPE_ENTRY (CZ_PARTY_INVITE_ACCEPT, 3457, 79),
    REGISTER_PACKET_TYPE_ENTRY (CZ_PARTY_INVITE_CANCEL, 3458, 83),
    REGISTER_PACKET_TYPE_ENTRY (CZ_PARTY_PROP_CHANGE, 3459, 145),
    REGISTER_PACKET_TYPE_ENTRY (CZ_REQ_MARKET_REGISTER, 3460, 27),
    REGISTER_PACKET_TYPE_ENTRY (CZ_REQ_MARKET_BUY, 3461, 0),
    REGISTER_PACKET_TYPE_ENTRY (CZ_REQ_CABINET_LIST, 3462, 10),
    REGISTER_PACKET_TYPE_ENTRY (CZ_REQ_GET_CABINET_ITEM, 3463, 26),
    REGISTER_PACKET_TYPE_ENTRY (CZ_REQ_CANCEL_MARKET_ITEM, 3464, 18),
    REGISTER_PACKET_TYPE_ENTRY (CZ_OBJ_RECORD_POS, 3465, 0),
    REGISTER_PACKET_TYPE_ENTRY (CZ_FORMATION_CMD, 3466, 32),
    REGISTER_PACKET_TYPE_ENTRY (CZ_REGISTER_AUTOSELLER, 3467, 0),
    REGISTER_PACKET_TYPE_ENTRY (CZ_OPEN_AUTOSELLER, 3468, 34),
    REGISTER_PACKET_TYPE_ENTRY (CZ_BUY_AUTOSELLER_ITEMS, 3469, 0),
    REGISTER_PACKET_TYPE_ENTRY (CZ_SELL_MY_AUTOSELLER_ITEMS, 3470, 0),
    REGISTER_PACKET_TYPE_ENTRY (CZ_PUZZLE_CRAFT, 3471, 0),
    REGISTER_PACKET_TYPE_ENTRY (CZ_GET_WIKI_REWARD, 3321, 11),
    REGISTER_PACKET_TYPE_ENTRY (CZ_PET_EQUIP, 3472, 30),
    REGISTER_PACKET_TYPE_ENTRY (ZC_FOUND_PARTY_LIST, 3473, 0),
    REGISTER_PACKET_TYPE_ENTRY (ZC_RECOMMEND_PARTY_INFO, 3474, 0),
    REGISTER_PACKET_TYPE_ENTRY (CZ_REQUEST_SOME_PARTY, 3475, 90),
    REGISTER_PACKET_TYPE_ENTRY (CZ_REFRESH_MEMBERRECOMMEND_LIST, 3476, 10),
    REGISTER_PACKET_TYPE_ENTRY (ZC_TO_SOMEWHERE_CLIENT, 3477, 0),
    REGISTER_PACKET_TYPE_ENTRY (CZ_REVEAL_NPC_STATE, 3478, 14),
    REGISTER_PACKET_TYPE_ENTRY (CZ_CHANGE_CHANNEL, 3479, 12),
    REGISTER_PACKET_TYPE_ENTRY (CZ_REQ_CHANNEL_TRAFFICS, 3480, 12),
    REGISTER_PACKET_TYPE_ENTRY (CZ_BUY_PROPERTYSHOP_ITEM, 3481, 0),
    REGISTER_PACKET_TYPE_ENTRY (CZ_SKILL_USE_HEIGHT, 3482, 14),
    REGISTER_PACKET_TYPE_ENTRY (CZ_ACCEPT_PARTY_QUEST, 3483, 20),
    REGISTER_PACKET_TYPE_ENTRY (CZ_ACCEPT_PARTY_EVENT, 3484, 20),
    REGISTER_PACKET_TYPE_ENTRY (CZ_DELETE_PARTY_EVENT, 3485, 20),
    REGISTER_PACKET_TYPE_ENTRY (CZ_PING, 3486, 10),
    REGISTER_PACKET_TYPE_ENTRY (ZC_PING, 3487, 10),
    REGISTER_PACKET_TYPE_ENTRY (ZC_XIGNCODE_BUFFER, 3488, 524),
    REGISTER_PACKET_TYPE_ENTRY (CZ_XIGNCODE_BUFFER, 3489, 524),
    REGISTER_PACKET_TYPE_ENTRY (CZ_CHANGE_TITLE, 3490, 74),
    REGISTER_PACKET_TYPE_ENTRY (CZ_PC_COMMENT_CHANGE, 3491, 0),
    REGISTER_PACKET_TYPE_ENTRY (CZ_AUTTOSELLER_BUYER_CLOSE, 3492, 18),
    REGISTER_PACKET_TYPE_ENTRY (CZ_REQ_ITEM_LIST, 3493, 11),
    REGISTER_PACKET_TYPE_ENTRY (CZ_HIT_MISSILE, 3494, 14),
    REGISTER_PACKET_TYPE_ENTRY (CZ_I_NEED_PARTY, 3495, 23),
    REGISTER_PACKET_TYPE_ENTRY (CZ_PARTY_JOIN_BY_LINK, 3496, 19),
    REGISTER_PACKET_TYPE_ENTRY (CZ_PVP_ZONE_CMD, 3498, 22),
    REGISTER_PACKET_TYPE_ENTRY (CZ_PVP_CHAT, 3499, 0),
    REGISTER_PACKET_TYPE_ENTRY (CZ_CARDBATTLE_CMD, 3500, 26),
    #undef REGISTER_PACKET_TYPE_ENTRY
};

char *
packetTypeToString (PacketType type)
{
    return packetTypeInfo.packets [type].string;
}
