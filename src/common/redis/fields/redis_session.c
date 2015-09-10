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
#include "redis_session.h"
#include "redis_socket_session.h"
#include "redis_game_session.h"
#include "redis_account_session.h"


// ------ Structure declaration -------


// ------ Static declaration -------


// ------ Extern function implementation -------

bool redisGetSession (Redis *self, RedisSessionKey *key, Session *session) {

    GameSession *gameSession = &session->game;
    SocketSession *socketSession = &session->socket;
    AccountSession *accountSession = &gameSession->accountSession;

    RedisSocketSessionKey *socketKey = &key->socketKey;

    // Search for the Socket Session
    if (!redisGetSocketSession(self, socketKey, socketSession)) {
        error("Cannot get Socket Session.");
        return false;
    }

    if (!socketSession->authenticated) {
        // This is the first time the client connect.
        // Initialize an empty game session
        CommanderInfo commanderInfo;
        commanderInfoInit (&commanderInfo);
        gameSessionInit (gameSession, &commanderInfo);
        dbg("Welcome, SOCKET_%s ! A new session has been initialized for you.", socketKey->sessionKey);
    } else {
        // Get account session
        RedisAccountSessionKey accountKey = {
            .accountId = socketSession->accountId
        };

        if (!redisGetAccountSession(self, &accountKey, accountSession)) {
            error("Cannot get Account Session.");
            return false;
        }

        // The client already exist in the game, get Game Session
        RedisGameSessionKey gameKey = {
            .routerId  = socketSession->routerId,
            .mapId     = socketSession->mapId,
            .accountId = socketSession->accountId
        };
        if (!redisGetGameSession(self, &gameKey, gameSession)) {
            error("Cannot get Game Session.");
            return false;
        }
        // dbg("Welcome back, SOCKET_%s !", sessionKey);
    }

    return true;
}

bool redisUpdateSession (Redis *self, Session *session) {

    RedisSocketSessionKey socketKey = {
        .routerId = session->socket.routerId,
        .sessionKey = session->socket.sessionKey
    };
    if (!redisUpdateSocketSession (self, &socketKey, &session->socket)) {
        error("Cannot update the socket session.");
        return false;
    }
    RedisGameSessionKey gameKey = {
        .routerId  = session->socket.routerId,
        .mapId     = session->socket.mapId,
        .accountId = session->socket.accountId
    };

    if (!(redisUpdateGameSession(self, &gameKey, session->socket.sessionKey, &session->game))) {
        error("Cannot update the game session");
        return false;
    }

    if (session->socket.accountId > 0) {
        RedisAccountSessionKey accountKey = {
            .accountId = session->socket.accountId
        };

        if (!(redisUpdateAccountSession(self, &accountKey, &session->game.accountSession))) {
            error("Cannot update the account session");
            return false;
        }
    }

    return true;
}

bool redisFlushSession (Redis *self, RedisSessionKey *key) {

    RedisSocketSessionKey *socketKey = &key->socketKey;
    // Retrieve the entire SocketSession
    SocketSession socketSession;

    if (!(redisGetSocketSession(self, socketKey, &socketSession))) {
        error("Cannot get the SocketSession for %s.", socketKey->sessionKey);
        return false;
    }

    // Flush Account Session
    RedisAccountSessionKey accountKey = {
        .accountId = socketSession.accountId
    };
    if (!(redisFlushAccountSession (self, &accountKey))) {
        error("Cannot flush the Account Session associated with the Socket Session.");
        return false;
    }

    // Flush the game session
    RedisGameSessionKey gameKey = {
        .routerId = socketSession.routerId,
        .mapId = socketSession.mapId,
        .accountId = socketSession.accountId
    };
    if (!(redisFlushGameSession (self, &gameKey))) {
        error("Cannot flush the Game Session associated with the Socket Session.");
        return false;
    }

    // Flush the socket session
    if (!(redisFlushSocketSession (self, socketKey))) {
        error("Cannot flush the Game Session associated with the Socket Session.");
        return false;
    }


    return true;
}
