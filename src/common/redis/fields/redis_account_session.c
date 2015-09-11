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
#include "redis_account_session.h"
#include "redis_game_session.h"


// ------ Structure declaration -------


// ------ Static declaration -------


// ------ Extern variables implementation -------
const char *redisAccountSessionsStr [] = {
	[REDIS_ACCOUNT_SESSION_credits] = REDIS_ACCOUNT_SESSION_credits_str,
	[REDIS_ACCOUNT_SESSION_privilegeLevel] = REDIS_ACCOUNT_SESSION_privilegeLevel_str,
	[REDIS_ACCOUNT_SESSION_familyName] = REDIS_ACCOUNT_SESSION_familyName_str,
	[REDIS_ACCOUNT_SESSION_barrackType] = REDIS_ACCOUNT_SESSION_barrackType_str
};

// ------ Extern functions implementation -------
bool redisGetAccountSession(Redis *self, RedisAccountSessionKey *key, AccountSession *accountSession) {

	redisReply *reply = NULL;

	reply = redisCommandDbg(self,
        "HMGET accountId%llx "
        REDIS_ACCOUNT_SESSION_credits_str " "
        REDIS_ACCOUNT_SESSION_privilegeLevel_str " "
        REDIS_ACCOUNT_SESSION_familyName_str " "
        REDIS_ACCOUNT_SESSION_barrackType_str " ",
        key->accountId
    );

    if (!reply) {
        error("Redis error encountered : The request is invalid.");
        return false;
    }

    switch (reply->type)
    {
        case REDIS_REPLY_ERROR:
            error("Redis error encountered : %s", reply->str);
            redisReplyDestroy(&reply);
            return false;
            break;

        case REDIS_REPLY_STATUS:
            // info("Redis status : %s", reply->str);
            redisReplyDestroy(&reply);
            return false;
            break;

        case REDIS_REPLY_ARRAY:
            if (reply->elements != REDIS_ACCOUNT_SESSION_COUNT) {
                error("Wrong number of elements received.");
                redisReplyDestroy(&reply);
                return false;
            }

            if (redisAnyElementIsNull (reply->element, reply->elements) != -1) {
                // AccountSession not found
                return false;
            }
            else {
                // Read the socket Session from the Redis server
                accountSession->accountId = key->accountId;
                accountSession->credits = strtof(reply->element[REDIS_ACCOUNT_SESSION_credits]->str, NULL);
                accountSession->privilege = strtoul(reply->element[REDIS_ACCOUNT_SESSION_privilegeLevel]->str, NULL, 16);
                strncpy(accountSession->familyName, reply->element[REDIS_ACCOUNT_SESSION_familyName]->str, sizeof(accountSession->familyName));
                accountSession->barrackType = strtoul(reply->element[REDIS_ACCOUNT_SESSION_barrackType]->str, NULL, 16);

            }
        break;

        default :
            error("Unexpected Redis status : %d", reply->type);
            redisReplyDestroy(&reply);
            return false;
            break;
    }

    redisReplyDestroy(&reply);

    return true;
}

bool redisUpdateAccountSession(Redis *self, RedisAccountSessionKey *key, AccountSession *accountSession) {

    redisReply *reply = NULL;

    dbg("HMSET accountId%llx"
        " " REDIS_ACCOUNT_SESSION_credits_str " %f"
        " " REDIS_ACCOUNT_SESSION_privilegeLevel_str " %x"
        " " REDIS_ACCOUNT_SESSION_familyName_str " %s"
        " " REDIS_ACCOUNT_SESSION_barrackType_str " %x"
        , key->accountId,
        accountSession->credits,
        accountSession->privilege,
        accountSession->familyName,
        accountSession->barrackType);

    reply = redisCommandDbg(self,
        "HMSET accountId%llx"
        " " REDIS_ACCOUNT_SESSION_credits_str " %f"
        " " REDIS_ACCOUNT_SESSION_privilegeLevel_str " %x"
        " " REDIS_ACCOUNT_SESSION_familyName_str " %s"
        " " REDIS_ACCOUNT_SESSION_barrackType_str " %x"
        , key->accountId,
        accountSession->credits,
        accountSession->privilege,
        CHECK_REDIS_EMPTY_STRING(accountSession->familyName),
        accountSession->barrackType
    );

    if (!reply) {
        error("Redis error encountered : The request is invalid.");
        return false;
    }

    switch (reply->type)
    {
        case REDIS_REPLY_ERROR:
            error("Redis error encountered : %s", reply->str);
            return false;
            break;

        case REDIS_REPLY_STATUS:
            // info("Redis status : %s", reply->str);
            break;

        default :
            error("Unexpected Redis status : %d", reply->type);
            redisReplyDestroy(&reply);
            return false;
            break;
    }

    redisReplyDestroy(&reply);

    return true;
}

bool redisFlushAccountSession(Redis *self, RedisAccountSessionKey *key) {

    redisReply *reply = NULL;

    // Delete the key from the Redis
    reply = redisCommandDbg(self,
        "DEL accountId%llx",
        key->accountId
    );

    if (!reply) {
        error("Redis error encountered : The request is invalid.");
        return false;
    }

    switch (reply->type)
    {
        case REDIS_REPLY_ERROR:
            error("Redis error encountered : %s", reply->str);
            return false;
            break;

        case REDIS_REPLY_INTEGER:
            // Delete OK
            break;

        default :
            error("Unexpected Redis status : %d", reply->type);
            redisReplyDestroy(&reply);
            return false;
            break;
    }

    redisReplyDestroy(&reply);

    return true;
}
