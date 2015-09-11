/**
 *
 *   ██████╗   ██╗ ███████╗ ███╗   ███╗ ██╗   ██╗
 *   ██╔══██╗ ███║ ██╔════╝ ████╗ ████║ ██║   ██║
 *   ██████╔╝ ╚██║ █████╗   ██╔████╔██║ ██║   ██║
 *   ██╔══██╗  ██║ ██╔══╝   ██║╚██╔╝██║ ██║   ██║
 *   ██║  ██║  ██║ ███████╗ ██║ ╚═╝ ██║ ╚██████╔╝
 *   ╚═╝  ╚═╝  ╚═╝ ╚══════╝ ╚═╝     ╚═╝  ╚═════╝
 *
 * @file redis_account_session.h
 * @brief RedisAccountSession fields definition
 *
 * @license GNU GENERAL PUBLIC LICENSE - Version 2, June 1991
 *          See LICENSE file for further information
 */

#pragma once

#include "R1EMU.h"
#include "common/redis/redis.h"

#define REDIS_ACCOUNT_SESSION_credits_str "credits"
#define REDIS_ACCOUNT_SESSION_privilegeLevel_str "privilegeLevel"
#define REDIS_ACCOUNT_SESSION_familyName_str "familyName"
#define REDIS_ACCOUNT_SESSION_barrackType_str "barrackType"

enum RedisAccountSession {
	REDIS_ACCOUNT_SESSION_credits,
	REDIS_ACCOUNT_SESSION_privilegeLevel,
	REDIS_ACCOUNT_SESSION_familyName,
	REDIS_ACCOUNT_SESSION_barrackType,
	REDIS_ACCOUNT_SESSION_COUNT
};

typedef struct {
    uint64_t accountId;
} RedisAccountSessionKey;

extern const char *redisAccountSessionsStr[];

/**
 * @brief Get the AccountSession associated with the Account ID
 * @param self An allocated Redis
 * @param key The AccountSession key
 * @param[out] accountSession The account Session
 * @return
 */
bool redisGetAccountSession(Redis *self, RedisAccountSessionKey *key, AccountSession *accountSession);

/**
 * @brief Save an entire AccountSession to the Redis server.
 * @param self An allocated Redis instance
 * @param key The AccountSession key
 * @param accountSession An allocated account session to refresh
 * @return true on success, false otherwise
 */
bool redisUpdateAccountSession(Redis *self, RedisAccountSessionKey *key, AccountSession *accountSession);

/**
 * @brief Flush an account session
 * @param self An allocated Redis instance
 * @param key The AccountSession key
 * @return true on success, false otherwise
 */
bool redisFlushAccountSession(Redis *self, RedisAccountSessionKey *key);


