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

#include "barrack_builder.h"
#include "common/server/worker.h"
#include "common/packet/packet.h"
#include "common/packet/packet_stream.h"
#include "common/packet/packet_type.h"
#include "common/commander/commander.h"

void barrackBuilderMessage(uint8_t msgType, uint8_t *message, zmsg_t *replyMsg) {

    // Length of Message
    int messageLength = strlen(message);

    #pragma pack(push, 1)
    struct {
        VariableSizePacketHeader variableSizeHeader;
        uint8_t msgType;
        uint8_t unk[40];
        uint8_t message[messageLength+1];
    } replyPacket;
    #pragma pack(pop)

    PacketType packetType = BC_MESSAGE;
    CHECK_SERVER_PACKET_SIZE(replyPacket, packetType);

    BUILD_REPLY_PACKET(replyPacket, replyMsg)
    {
        variableSizePacketHeaderInit(&replyPacket.variableSizeHeader, packetType, sizeof(replyPacket));
        replyPacket.msgType = msgType;
        strncpy(replyPacket.message, message, sizeof(replyPacket.message));
    }
}

void barrackBuilderLoginOk(
    uint64_t accountId,
    uint8_t *accountLogin,
    uint8_t *sessionKey,
    AccountSessionPrivileges accountPrivileges,
    zmsg_t *replyMsg)
{
    #pragma pack(push, 1)
    struct {
        ServerPacketHeader header;
        uint16_t unk1;
        uint64_t accountId;
        uint8_t accountLogin[ACCOUNT_SESSION_LOGIN_MAXSIZE];
        uint32_t accountPrivileges;
        uint8_t sessionKey[GAME_SESSION_KEY_MAXSIZE];
    } replyPacket;
    #pragma pack(pop)

    PacketType packetType = BC_LOGINOK;
    CHECK_SERVER_PACKET_SIZE(replyPacket, packetType);

    BUILD_REPLY_PACKET(replyPacket, replyMsg)
    {
        serverPacketHeaderInit(&replyPacket.header, packetType);
        replyPacket.unk1 = 0x3E9; // from iCBT1
        replyPacket.accountId = accountId;
        replyPacket.accountPrivileges = accountPrivileges;
        strncpy(replyPacket.accountLogin, accountLogin, sizeof(replyPacket.accountLogin));
        strncpy(replyPacket.sessionKey, sessionKey, sizeof(replyPacket.sessionKey));
    }
}

void barrackBuilderLogoutOk(zmsg_t *replyMsg) {
    #pragma pack(push, 1)
    struct {
        ServerPacketHeader header;
    } replyPacket;
    #pragma pack(pop)

    PacketType packetType = BC_LOGOUTOK;
    CHECK_SERVER_PACKET_SIZE(replyPacket, packetType);

    BUILD_REPLY_PACKET(replyPacket, replyMsg)
    {
        serverPacketHeaderInit(&replyPacket.header, packetType);
    }
}

void barrackBuilderStartGameOk(
    uint32_t zoneServerId,
    uint32_t zoneServerIp,
    uint32_t zoneServerPort,
    uint16_t mapId,
    uint8_t commanderListId,
    uint64_t socialInfoId,
    uint8_t isSingleMap,
    zmsg_t *replyMsg)
{
    #pragma pack(push, 1)
    struct BcStartGameOkPacket {
        ServerPacketHeader header;
        uint32_t zoneServerId; // TODO : RouterID 16 -> 32
        uint32_t zoneServerIp;
        uint32_t zoneServerPort;
        uint32_t mapId;
        uint8_t commanderListId;
        uint64_t socialInfoId;
        uint8_t isSingleMap;
        uint8_t unk1;
    } replyPacket;
    #pragma pack(pop)

    PacketType packetType = BC_START_GAMEOK;
    CHECK_SERVER_PACKET_SIZE(replyPacket, packetType);

    BUILD_REPLY_PACKET(replyPacket, replyMsg)
    {
        serverPacketHeaderInit(&replyPacket.header, packetType);
        replyPacket.zoneServerId = zoneServerId;
        replyPacket.zoneServerIp = zoneServerIp;
        replyPacket.zoneServerPort = zoneServerPort;
        replyPacket.mapId = mapId;
        replyPacket.commanderListId = commanderListId;
        replyPacket.socialInfoId = socialInfoId;
        replyPacket.isSingleMap = isSingleMap;
        replyPacket.unk1 = 1;
    }
}

void barrackBuilderCommanderMoveOk(
    uint64_t accountId,
    uint16_t commanderListId,
    PositionXYZ *position,
    zmsg_t *replyMsg)
{
    // uncompressed structure
    #pragma pack(push, 1)
    struct {
        PacketNormalHeader normalHeader;
        uint64_t accountId;
        uint8_t unk1;
        PositionXYZ position;
    } replyPacket;
    #pragma pack(pop)

    BUILD_REPLY_PACKET(replyPacket, replyMsg)
    {
        packetNormalHeaderInit(&replyPacket.normalHeader, BC_NORMAL_COMMANDER_MOVE_OK, sizeof(replyPacket));
        replyPacket.accountId = accountId;
        replyPacket.unk1 = 3; // 3, 2, 1, 3, 2, 1, ...
        memcpy(&replyPacket.position, position, sizeof(replyPacket.position));
    }
}

void barrackBuilderNormalUnk1(uint64_t accountId, zmsg_t *replyMsg) {
    #pragma pack(push, 1)
    struct {
        PacketNormalHeader normalHeader;
        uint64_t accountId;
        uint8_t unk1;
        uint64_t unk2;
    } replyPacket;
    #pragma pack(pop)

    BUILD_REPLY_PACKET(replyPacket, replyMsg)
    {
        packetNormalHeaderInit(&replyPacket.normalHeader, BC_NORMAL_UNKNOWN_1, sizeof(replyPacket));
        replyPacket.accountId = accountId;
        replyPacket.unk1 = 0x0B; // ICBT
        replyPacket.unk2 = 0;
    }

    size_t captureSize;
    void *capture = dumpToMem(
        "[03:10:20][main.c:55 in CNetUsr__PacketHandler_0]  4F 00 FF FF FF FF 1D 00 04 00 00 00 4B 0A 0F 06 | O...........K...\n"
        "[03:10:20][main.c:55 in CNetUsr__PacketHandler_0]  01 00 10 01 0B 00 00 00 00 00 00 00 00          | .............\n",
        NULL, &captureSize
    );

    compareMem(&replyPacket, sizeof (replyPacket), capture, captureSize);
}

void barrackBuilderNormalCommanderInfo(uint64_t accountId, zmsg_t *replyMsg) {
    #pragma pack(push, 1)
    struct {
        PacketNormalHeader normalHeader;
        uint64_t accountId;
        uint8_t unk1;
        uint64_t unk2;
    } replyPacket;
    #pragma pack(pop)

    BUILD_REPLY_PACKET(replyPacket, replyMsg)
    {
        packetNormalHeaderInit(&replyPacket.normalHeader, BC_NORMAL_UNKNOWN_1, sizeof(replyPacket));
        replyPacket.accountId = accountId;
        replyPacket.unk1 = 0; // ICBT
        replyPacket.unk2 = 0;
    }

}

void barrackBuilderIesModifyList(zmsg_t *replyMsg) {
    #pragma pack(push, 1)
    struct {
        // not yet implemented
    } replyPacket;
    (void) replyPacket;
    #pragma pack(pop)

    // PacketType packetType = BC_IES_MODIFY_LIST;
    // CHECK_SERVER_PACKET_SIZE (replyPacket, packetType);
    BUILD_REPLY_PACKET(replyPacket, replyMsg)
    {
        size_t memSize;

        void *memory = dumpToMem(
            "[03:07:13][main.c:55 in CNetUsr__PacketHandler_0]  48 00 FF FF FF FF 35 01 01 00 0C 00 53 68 61 72 | H.....5.....Shar\n"
            "[03:07:13][main.c:55 in CNetUsr__PacketHandler_0]  65 64 43 6F 6E 73 74 00 02 00 F5 00 00 00 01 00 | edConst.........\n"
            "[03:07:13][main.c:55 in CNetUsr__PacketHandler_0]  06 00 56 61 6C 75 65 00 02 00 0C 00 00 00 02 00 | ..Value.........\n"
            "[03:07:13][main.c:55 in CNetUsr__PacketHandler_0]  31 00 05 00 31 2E 30 30 00 03 00 51 41 00 0A 00 | 1...1.00...QA...\n"
            "[03:07:13][main.c:55 in CNetUsr__PacketHandler_0]  32 30 31 35 2D 30 38 2D 30 00 0F 00 43 68 61 6E | 2015-08-0...Chan\n"
            "[03:07:13][main.c:55 in CNetUsr__PacketHandler_0]  67 65 20 42 79 20 54 6F 6F 6C 00 0B 00 00 00 02 | ge By Tool......\n"
            "[03:07:13][main.c:55 in CNetUsr__PacketHandler_0]  00 31 00 05 00 31 2E 30 30 00 03 00 51 41 00 0A | .1...1.00...QA..\n"
            "[03:07:13][main.c:55 in CNetUsr__PacketHandler_0]  00 32 30 31 35 2D 30 38 2D 30 00 0F 00 43 68 61 | .2015-08-0...Cha\n"
            "[03:07:13][main.c:55 in CNetUsr__PacketHandler_0]  6E 67 65 20 42 79 20 54 6F 6F 6C 00 FB 00 00 00 | nge By Tool.....\n"
            "[03:07:13][main.c:55 in CNetUsr__PacketHandler_0]  01 00 06 00 56 61 6C 75 65 00 03 00 05 00 00 00 | ....Value.......\n"
            "[03:07:13][main.c:55 in CNetUsr__PacketHandler_0]  02 00 31 00 05 00 31 2E 30 30 00 05 00 4C 69 6C | ..1...1.00...Lil\n"
            "[03:07:13][main.c:55 in CNetUsr__PacketHandler_0]  79 00 0A 00 32 30 31 35 2D 30 38 2D 30 00 0F 00 | y...2015-08-0...\n"
            "[03:07:13][main.c:55 in CNetUsr__PacketHandler_0]  43 68 61 6E 67 65 20 42 79 20 54 6F 6F 6C 00 04 | Change By Tool..\n"
            "[03:07:13][main.c:55 in CNetUsr__PacketHandler_0]  00 00 00 02 00 31 00 05 00 31 2E 30 30 00 05 00 | .....1...1.00...\n"
            "[03:07:13][main.c:55 in CNetUsr__PacketHandler_0]  4C 69 6C 79 00 0A 00 32 30 31 35 2D 30 38 2D 30 | Lily...2015-08-0\n"
            "[03:07:13][main.c:55 in CNetUsr__PacketHandler_0]  00 0F 00 43 68 61 6E 67 65 20 42 79 20 54 6F 6F | ...Change By Too\n"
            "[03:07:13][main.c:55 in CNetUsr__PacketHandler_0]  6C 00 03 00 00 00 02 00 31 00 05 00 31 2E 30 30 | l.......1...1.00\n"
            "[03:07:13][main.c:55 in CNetUsr__PacketHandler_0]  00 05 00 4C 69 6C 79 00 0A 00 32 30 31 35 2D 30 | ...Lily...2015-0\n"
            "[03:07:13][main.c:55 in CNetUsr__PacketHandler_0]  38 2D 30 00 0F 00 43 68 61 6E 67 65 20 42 79 20 | 8-0...Change By \n"
            "[03:07:13][main.c:55 in CNetUsr__PacketHandler_0]  54 6F 6F 6C 00                                  | Tool.\n"
            , NULL, &memSize
        );

        zmsg_add(replyMsg, zframe_new(memory, memSize));
    }
}

void barrackBuilderServerEntry(
    uint32_t ipClientNet,
    uint32_t ipVirtualClientNet,
    uint16_t channelPort1,
    uint16_t channelPort2,
    zmsg_t *replyMsg)
{
    #pragma pack(push, 1)
    struct {
        ServerPacketHeader header;
        uint32_t ipClientNet;
        uint32_t ipVirtualClientNet;
        uint16_t channelPort1;
        uint16_t channelPort2;
    } replyPacket;
    #pragma pack(pop)

    PacketType packetType = BC_SERVER_ENTRY;
    CHECK_SERVER_PACKET_SIZE(replyPacket, packetType);

    BUILD_REPLY_PACKET(replyPacket, replyMsg)
    {
        serverPacketHeaderInit(&replyPacket.header, packetType);
        replyPacket.ipClientNet        = ipClientNet;
        replyPacket.ipVirtualClientNet = ipVirtualClientNet;
        replyPacket.channelPort1       = channelPort1;
        replyPacket.channelPort2       = channelPort2;
    }
}

void barrackBuilderCommanderList(CommanderBarrackInfo * commanders ,zmsg_t *replyMsg) {

    // Initialize commandersCount
    int commandersCount = 0;

    // Get Commanders Count
    if (sizeof(commanders) > 0) {
        int commandersCount = sizeof(commanders)/sizeof(commanders[0]);;
    }

/*
    /// FOR EACH ITEM PROPERTY
    // Item Properties struct
    #pragma pack(push, 1)
    struct {
        uint16_t propertyType; // Property type (Enchant, Potential, Duration, Crafter Name, Memo, etc)
        uint8_t *propertyContent; // Pointer to content (which is variable in bytes length)
    } ItemProperty;
    #pragma pack(pop)



    /// FOR EACH ACCOUNT INFO (yet hard to know which they are)
    // Account Info struct
    #pragma pack(push, 1)
    struct {
        uint16_t accountInfoType;
        uint8_t *AccountInfoContent;
    } AccountInfo;
    #pragma pack(pop)

    */

    int accountInfoCount = 3;

    #pragma pack(push, 1)
    struct {
        VariableSizePacketHeader variableSizeHeader;
        uint64_t accountId;
        uint8_t unk1;
        uint8_t commandersCount;
        uint8_t familyName [COMMANDER_FAMILY_NAME_SIZE];
        uint16_t AccInfoLength; // sizeof(accountInfo)
        //AccountInfo accountInfo[3];
        CommanderBarrackInfo commanders[accountInfoCount];
    } replyPacket;
    #pragma pack(pop)


    PacketType packetType = BC_COMMANDER_LIST;
    CHECK_SERVER_PACKET_SIZE(replyPacket, packetType);

    BUILD_REPLY_PACKET(replyPacket, replyMsg)
    {

        variableSizePacketHeaderInit(&replyPacket.variableSizeHeader, packetType, sizeof(replyPacket));
        //replyPacket.accountId = accountData.accountId;
        replyPacket.unk1 = 3; // ICBT - equal to 1 or 4
        replyPacket.commandersCount = commandersCount;

        /*----------------------
         Test Code
        ------------------------*/
        /*
        // Family name
        strncpy(replyPacket.familyName, accountData.familyName);
        // Account Info
        replyPacket.AccInfoLength = sizeof(replyPacket.accountInfo) / sizeof(uint8_t); // Is this right? (total bytes / 8)

        replyPacket.accountInfo[0].accountInfoType = SWAP_UINT16(0x940e); // 94 0E = Medal (iCoin)
        replyPacket.accountInfo[0].AccountInfoContent = accountData.credits;
        replyPacket.accountInfo[1].accountInfoType = SWAP_UINT16(0x970e); // 97 0E = GiftMedal
        replyPacket.accountInfo[2].AccountInfoContent = 0;
        replyPacket.accountInfo[2].accountInfoType = SWAP_UINT16(0x950e); // 95 0E = ReceiveGiftMedal
        replyPacket.accountInfo[2].AccountInfoContent = 0;
        // Commanders list
        for (int commanderIndex = 0; commanderIndex < replyPacket.commandersCount; commanderIndex++) {
            CommanderBarrackInfo *currentCommanderBarrackInfo = &replyPacket.commanders[commanderIndex];
            CommanderPkt *currentCommander = &currentCommanderBarrackInfo->commander;
            commanderInit(currentCommander);

            CommanderBarrackInfo commanderData = commanders[commanderIndex];
            // Set some info
            if (commanderIndex >= 0) {
                strncpy(currentCommander->commanderName, commanderData.CommanderName, sizeof(currentCommander->commanderName));

                currentCommander->accountId = 0x0; // Not needed
                currentCommander->classId = commanderData.classId;
                currentCommander->unk4 = 0x0;
                currentCommander->jobId = commanderData.jobId;
                currentCommander->level = 1;
                currentCommander->gender = commanderData.gender;
                currentCommander->hairId = 0x2E;

                currentCommander->equipment.head_top = commanderData.head_top;
                currentCommander->equipment.head_middle = commanderData.head_middle;
                currentCommander->equipment.itemUnk1 = commanderData.itemUnk1;
                currentCommander->equipment.body_armor = commanderData.body_armor;
                currentCommander->equipment.gloves = commanderData.gloves;
                currentCommander->equipment.boots = commanderData.boots;
                currentCommander->equipment.itemUnk2 = commanderData.itemUnk2;
                currentCommander->equipment.bracelet = commanderData.bracelet;
                currentCommander->equipment.weapon = commanderData.weapon;
                currentCommander->equipment.shield = commanderData.shield;
                currentCommander->equipment.costume = commanderData.costume;
                currentCommander->equipment.itemUnk3 = commanderData.itemUnk3;
                currentCommander->equipment.itemUnk4 = commanderData.itemUnk4;
                currentCommander->equipment.itemUnk5 = commanderData.itemUnk5;
                currentCommander->equipment.leg_armor = commanderData.leg_armor;
                currentCommander->equipment.itemUnk6 = commanderData.itemUnk6;
                currentCommander->equipment.itemUnk7 = commanderData.itemUnk7;
                currentCommander->equipment.ring_left = commanderData.ring_left;
                currentCommander->equipment.ring_right = commanderData.ring_right;
                currentCommander->equipment.necklace = commanderData.necklace;


                currentCommanderBarrackInfo->socialInfoId = SWAP_UINT64(0xf41100007d000000); // CharUniqueId?
                currentCommanderBarrackInfo->commanderPosition = commanderIndex+1;
                currentCommanderBarrackInfo->mapId = commanderData.mapId; //
                currentCommanderBarrackInfo->unk4 = 0; //
                currentCommanderBarrackInfo->unk5 = 0;
                currentCommanderBarrackInfo->maxXP = commanderData.experience; // ?? Or current XP?
                currentCommanderBarrackInfo->unk6 = 0; //

                currentCommanderBarrackInfo->pos.x = commanderData.positionX;
                currentCommanderBarrackInfo->pos.y = commanderData.positionY;
                currentCommanderBarrackInfo->pos.z = commanderData.positionZ;

                currentCommanderBarrackInfo->dir.x = 0; // Set direction to face camera.
                currentCommanderBarrackInfo->dir.z = 0; // Set direction to face camera.

                currentCommanderBarrackInfo->pos2.x = commanderData.positionX;
                currentCommanderBarrackInfo->pos2.y = commanderData.positionY;
                currentCommanderBarrackInfo->pos2.z = commanderData.positionZ;
                currentCommanderBarrackInfo->dir2.x = 0;
                currentCommanderBarrackInfo->dir2.z = 0;
                currentCommanderBarrackInfo->unk8 = 0; //

                // Iterate through Items
                foreach (Commander. as Item) {
                    /// FOR EACH ITEM
                    // Item Properties struct
                    #pragma pack(push, 1)
                    struct {
                        uint16_t propertiesLength; // Sizeof
                        ItemPropertyContent properties[count(Item.properties)];
                    } ItemProperties;
                    #pragma pack(pop)



                    // Iterate through Item properties
                    foreach (Item.properties as Property) {

                    }
                }


                currentCommanderBarrackInfo->PB.i_1 = 0;
                currentCommanderBarrackInfo->PB.i_2 = 0;
                currentCommanderBarrackInfo->PB.i_3 = 0;
                currentCommanderBarrackInfo->PB.i_4 = SWAP_UINT64(0x0600030f00000000);
                currentCommanderBarrackInfo->PB.i_5 = 0;
                currentCommanderBarrackInfo->PB.i_6 = 0;
                currentCommanderBarrackInfo->PB.i_7 = 0;
                currentCommanderBarrackInfo->PB.i_8 = 0;
                currentCommanderBarrackInfo->PB.i_9 = SWAP_UINT64(0x0600030f00000000);
                currentCommanderBarrackInfo->PB.i_10 = 0;
                currentCommanderBarrackInfo->PB.i_11 = 0;
                currentCommanderBarrackInfo->PB.i_12 = 0;
                currentCommanderBarrackInfo->PB.i_13 = 0;
                currentCommanderBarrackInfo->PB.i_14 = 0;
                currentCommanderBarrackInfo->PB.i_15 = SWAP_UINT64(0x0600030f00000000);
                currentCommanderBarrackInfo->PB.i_16 = 0;
                currentCommanderBarrackInfo->PB.i_17 = 0;
                currentCommanderBarrackInfo->PB.i_18 = 0;
                currentCommanderBarrackInfo->PB.i_19 = 0;
                currentCommanderBarrackInfo->PB.i_20 = 0;
                currentCommanderBarrackInfo->PB.i_21 = 0;

            }

        }


        */

        /*----------------------------
         End test code
        ----------------------------*/

        size_t captureSize;
        void *capture = dumpToMem(
            "[03:07:13][main.c:30 in writePacketToFile]  0F 00 FF FF FF FF 18 06 4B 0A 0F 06 01 00 10 01 | ........K.......\n"
            "[03:07:13][main.c:30 in writePacketToFile]  04 03 4D 6F 72 69 69 00 00 00 00 00 00 00 00 00 | ..Morii.........\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | ................\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | ................\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | ................\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 12 00 94 0E 00 00 67 43 97 0E 00 00 20 41 | ........gC.... A\n"
            "[03:07:13][main.c:30 in writePacketToFile]  95 0E 00 00 A0 40 4D 65 6D 65 6E 74 6F 00 00 00 | .....@Memento...\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | ................\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | ................\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | ................\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | ................\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | ................\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | ................\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | ................\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | ................\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 00 00 00 00 14 27 00 00 A3 0F 02 00 50 00 | .......'......P.\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 30 95 09 00 02 00 00 00 04 00 00 00 BA 1E | ..0.............\n"
            "[03:07:13][main.c:30 in writePacketToFile]  08 00 81 A9 07 00 9A D0 07 00 10 27 00 00 F8 2A | ...........'...*\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 94 11 03 00 B3 5F 03 00 FE 81 09 00 09 00 | ......._........\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 09 00 00 00 04 00 00 00 93 F3 07 00 09 00 | ................\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 09 00 00 00 F6 2F 09 00 01 30 09 00 C0 E5 | ......./...0....\n"
            "[03:07:13][main.c:30 in writePacketToFile]  08 00 2E 00 00 00 26 07 00 00 7C 00 00 00 01 00 | ......&...|.....\n"
            "[03:07:13][main.c:30 in writePacketToFile]  E9 03 03 00 00 00 91 3D 01 00 51 26 06 00 00 00 | .......=..Q&....\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 7D 49 83 41 BD 63 90 41 3F D6 9A BF 00 00 | ..}I.A.c.A?.....\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 00 00 00 00 7D 49 83 41 BD 63 90 41 3F D6 | ......}I.A.c.A?.\n"
            "[03:07:13][main.c:30 in writePacketToFile]  9A BF 00 00 00 00 00 00 00 00 00 00 00 00 06 00 | ................\n"
            "[03:07:13][main.c:30 in writePacketToFile]  03 0F 00 00 00 00 00 00 00 00 0C 00 BA 0E 00 10 | ................\n"
            "[03:07:13][main.c:30 in writePacketToFile]  74 45 03 0F 00 00 00 00 0C 00 BA 0E 00 48 80 45 | tE...........H.E\n"
            "[03:07:13][main.c:30 in writePacketToFile]  03 0F 00 00 00 00 12 00 BA 0E 00 10 74 45 03 0F | ............tE..\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 00 00 0C 0F 00 00 40 40 00 00 00 00 12 00 | ........@@......\n"
            "[03:07:13][main.c:30 in writePacketToFile]  BA 0E 00 80 6F 45 03 0F 00 00 00 00 0C 0F 00 00 | ....oE..........\n"
            "[03:07:13][main.c:30 in writePacketToFile]  80 40 12 00 BA 0E 00 A8 82 45 03 0F 00 00 00 00 | .@.......E......\n"
            "[03:07:13][main.c:30 in writePacketToFile]  0C 0F 00 00 40 40 06 00 03 0F 00 00 00 00 00 00 | ....@@..........\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 00 00 12 00 BA 0E 00 48 80 45 03 0F 00 00 | .........H.E....\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 0C 0F 00 00 40 40 00 00 00 00 3B 00 C5 0E | ......@@....;...\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 40 40 BA 0E 00 10 74 45 03 0F 00 00 00 00 | ..@@....tE......\n"
            "[03:07:13][main.c:30 in writePacketToFile]  84 0F 06 00 53 68 69 6E 65 00 87 0F 09 00 53 68 | ....Shine.....Sh\n"
            "[03:07:13][main.c:30 in writePacketToFile]  69 6E 65 42 72 61 00 8A 0F 08 00 4D 65 6D 65 6E | ineBra.....Memen\n"
            "[03:07:13][main.c:30 in writePacketToFile]  74 6F 00 0C 0F 00 00 40 40 12 00 BA 0E 00 10 74 | to.....@@......t\n"
            "[03:07:13][main.c:30 in writePacketToFile]  45 03 0F 00 00 00 00 0C 0F 00 00 00 40 31 00 BA | E...........@1..\n"
            "[03:07:13][main.c:30 in writePacketToFile]  0E 00 10 74 45 03 0F 00 00 00 00 84 0F 02 00 43 | ...tE..........C\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 87 0F 09 00 4E 65 63 6B 6C 61 63 65 00 8A 0F | .....Necklace...\n"
            "[03:07:13][main.c:30 in writePacketToFile]  08 00 4D 65 6D 65 6E 74 6F 00 0C 0F 00 00 40 40 | ..Memento.....@@\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 53 75 6D 69 54 68 72 6F 77 48 61 6D 73 74 | ..SumiThrowHamst\n"
            "[03:07:13][main.c:30 in writePacketToFile]  65 72 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | er..............\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | ................\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | ................\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | ................\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | ................\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | ................\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | ................\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | ................\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 13 27 00 00 B9 0B 02 00 01 00 00 00 02 00 | ...'............\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 02 00 00 00 04 00 00 00 9D 1A 08 00 06 00 | ................\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 07 00 00 00 10 27 00 00 F8 2A 00 00 4D 75 | .......'...*..Mu\n"
            "[03:07:13][main.c:30 in writePacketToFile]  02 00 7C 96 98 00 04 00 00 00 09 00 00 00 09 00 | ..|.............\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 04 00 00 00 8D F3 07 00 09 00 00 00 09 00 | ................\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 09 00 00 00 09 00 00 00 0A 00 00 00 06 00 | ................\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 F4 11 00 00 7D 00 00 00 02 00 FD 03 00 00 | ......}.........\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 00 00 00 00 0C 00 00 00 00 00 00 00 25 E8 | ..............%.\n"
            "[03:07:13][main.c:30 in writePacketToFile]  52 C1 65 19 E5 41 39 F4 EF 42 00 00 00 00 00 00 | R.e..A9..B......\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 25 E8 52 C1 65 19 E5 41 39 F4 EF 42 00 00 | ..%.R.e..A9..B..\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | ................\n"
            "[03:07:13][main.c:30 in writePacketToFile]  06 00 03 0F 00 00 00 00 00 00 00 00 00 00 00 00 | ................\n"
            "[03:07:13][main.c:30 in writePacketToFile]  06 00 03 0F 00 00 00 00 00 00 00 00 00 00 00 00 | ................\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 06 00 03 0F 00 00 00 00 00 00 00 00 00 00 | ................\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 00 00 00 00 53 75 6D 69 00 00 00 00 00 00 | ......Sumi......\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | ................\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | ................\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | ................\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | ................\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | ................\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | ................\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | ................\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 | ................\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 00 00 00 00 16 27 00 00 D3 07 02 00 1E 00 | .......'........\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 56 95 09 00 02 00 00 00 04 00 00 00 9B 1E | ..V.............\n"
            "[03:07:13][main.c:30 in writePacketToFile]  08 00 6F A5 07 00 9E CC 07 00 10 27 00 00 F8 2A | ..o........'...*\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 40 27 02 00 AF 5F 03 00 2E 7A 09 00 09 00 | ..@'..._...z....\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 09 00 00 00 04 00 00 00 90 F3 07 00 09 00 | ................\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 09 00 00 00 22 2C 09 00 11 2C 09 00 E2 E1 | ......',...,....\n"
            "[03:07:13][main.c:30 in writePacketToFile]  08 00 24 00 00 00 2F 18 00 00 7D 00 00 00 03 00 | ..$.../...}.....\n"
            "[03:07:13][main.c:30 in writePacketToFile]  E9 03 00 00 00 00 82 33 00 00 D4 B3 00 00 00 00 | .......3........\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 FC 78 2F 42 BD 63 90 41 C6 01 4A 40 00 00 | ...x/B.c.A..J@..\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 00 00 00 00 FC 78 2F 42 BD 63 90 41 C6 01 | .......x/B.c.A..\n"
            "[03:07:13][main.c:30 in writePacketToFile]  4A 40 00 00 00 00 00 00 00 00 00 00 00 00 06 00 | J@..............\n"
            "[03:07:13][main.c:30 in writePacketToFile]  03 0F 00 00 00 00 00 00 00 00 12 00 C5 0E 00 00 | ................\n"
            "[03:07:13][main.c:30 in writePacketToFile]  40 40 BA 0E 00 60 86 44 03 0F 00 00 00 00 0C 00 | @@...`.D........\n"
            "[03:07:13][main.c:30 in writePacketToFile]  BA 0E 00 60 86 44 03 0F 00 00 00 00 12 00 C5 0E | ...`.D..........\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 00 40 BA 0E 00 60 86 44 03 0F 00 00 00 00 | ...@...`.D......\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 00 00 0C 00 BA 0E 00 A0 84 44 03 0F 00 00 | ...........D....\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 12 00 C5 0E 00 00 40 40 BA 0E 00 E0 C2 44 | ........@@.....D\n"
            "[03:07:13][main.c:30 in writePacketToFile]  03 0F 00 00 00 00 06 00 03 0F 00 00 00 00 00 00 | ................\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 00 00 00 12 00 C5 0E 00 00 00 40 BA 0E 00 60 | ...........@...`\n"
            "[03:07:13][main.c:30 in writePacketToFile]  86 44 03 0F 00 00 00 00 00 00 00 00 0C 00 BA 0E | .D..............\n"
            "[03:07:13][main.c:30 in writePacketToFile]  00 30 54 45 03 0F 00 00 00 00 0C 00 BA 0E 00 30 | .0TE...........0\n"
            "[03:07:13][main.c:30 in writePacketToFile]  54 45 03 0F 00 00 00 00 0C 00 BA 0E 00 30 54 45 | TE...........0TE\n"
            "[03:07:13][main.c:30 in writePacketToFile]  03 0F 00 00 00 00 00 00                         | ........\n",
            NULL, &captureSize
        );

        compareMem(&replyPacket, sizeof (replyPacket), capture, captureSize);
    }
}

void barrackBuilderPetInformation(zmsg_t *replyMsg) {
    #pragma pack(push, 1)
    struct {
        PacketNormalHeader normalHeader;
        uint32_t petsCount;
    } replyPacket;
    #pragma pack(pop)

    PacketType packetType = BC_NORMAL_PET_INFORMATION;
    BUILD_REPLY_PACKET(replyPacket, replyMsg)
    {
        packetNormalHeaderInit(&replyPacket.normalHeader, packetType, sizeof(replyPacket));
        replyPacket.petsCount = 0;
    }
}

void barrackBuilderZoneTraffics(uint16_t mapId, zmsg_t *replyMsg) {
    #pragma pack(push, 1)
    typedef struct {
        uint16_t zoneListId;
        uint16_t currentPlayersCount;
    } SingleZoneTraffic;
    #pragma pack(pop)

    #pragma pack(push, 1)
    typedef struct {
        uint16_t mapId;
        uint16_t zoneServerCount;
        // SingleZoneTraffic zones[]; // variable length array
    }   SingleMapTraffic;
    #pragma pack(pop)

	#pragma pack(push, 1)
    typedef struct {
        uint16_t zoneMaxPcCount;
        uint16_t mapAvailableCount;
        // SingleMapTraffic maps[]; // variable length array
    } ZoneTrafficsPacket;
    #pragma pack(pop)

    // data from the DB
    int zoneMaxPcCount = 100;

    // number of maps playable
    int mapAvailableCount = 1;

    // array of zone server availables for each map
	int *zoneServerCounts = alloca(sizeof(*zoneServerCounts) * mapAvailableCount);

    // array of mapId for each map
    int *mapsId = alloca(sizeof(*mapsId) * mapAvailableCount);

    // fill the arrays here
    for (int mapIndex = 0; mapIndex < mapAvailableCount; mapIndex++) {
        zoneServerCounts [mapIndex] = 5;
        mapsId [mapIndex] = mapId;
    }
    // number of players per zone
    int currentPlayersCount = 10;

    // count the total memory space needed for the reply packet
    size_t outPacketSize = sizeof(ZoneTrafficsPacket) + (sizeof(SingleMapTraffic) * mapAvailableCount);

    for (int mapIndex = 0; mapIndex < mapAvailableCount; mapIndex++) {
        outPacketSize += sizeof(SingleZoneTraffic) * zoneServerCounts[mapIndex];
    }

    // allocate on the stack the memory for the packet
    uint8_t *stackBuffer = alloca(sizeof(*stackBuffer) * outPacketSize);
    memset(stackBuffer, 0, outPacketSize);

    // construct the packet
    PacketStream stream;
    packetStreamInit(&stream, (uint8_t *)stackBuffer);

    packetStreamAppend(&stream, &zoneMaxPcCount, sizeof_struct_member(ZoneTrafficsPacket, zoneMaxPcCount));
    packetStreamAppend(&stream, &mapAvailableCount, sizeof_struct_member(ZoneTrafficsPacket, mapAvailableCount));

    for (int mapIndex = 0; mapIndex < mapAvailableCount; mapIndex++) {
        packetStreamAppend(&stream, &mapsId [mapIndex], sizeof_struct_member(SingleMapTraffic, mapId));
        packetStreamAppend(&stream, &zoneServerCounts[mapIndex], sizeof_struct_member(SingleMapTraffic, zoneServerCount));

        for (int zoneServerIndex = 0; zoneServerIndex < zoneServerCounts[mapIndex]; zoneServerIndex++) {
            packetStreamAppend(&stream, &zoneServerIndex, sizeof_struct_member(SingleZoneTraffic, zoneListId));
            packetStreamAppend(&stream, &currentPlayersCount, sizeof_struct_member(SingleZoneTraffic, currentPlayersCount));
        }
    }

    // compress the packet
	#pragma pack(push, 1)
    struct {
        PacketNormalHeader normalHeader;
        Zlib zlibData;
    } compressedPacket;
    #pragma pack(pop)

    zlibCompress(&compressedPacket.zlibData, stackBuffer, outPacketSize);
    outPacketSize = ZLIB_GET_COMPRESSED_PACKET_SIZE(&compressedPacket.zlibData, sizeof(compressedPacket));
    packetNormalHeaderInit(&compressedPacket.normalHeader, BC_NORMAL_ZONE_TRAFFIC, outPacketSize);

    zmsg_add(replyMsg, zframe_new (&compressedPacket, outPacketSize));
}

void barrackBuilderBarrackNameChange(BarrackNameResultType resultType, uint8_t *barrackName, zmsg_t *replyMsg) {
    #pragma pack(push, 1)
    struct {
        ServerPacketHeader header;
        uint8_t changed;
        uint32_t resultType;
        uint8_t barrackName[64];
    } replyPacket;
    #pragma pack(pop)

    PacketType packetType = BC_BARRACKNAME_CHANGE;
    CHECK_SERVER_PACKET_SIZE(replyPacket, packetType);

    BUILD_REPLY_PACKET(replyPacket, replyMsg)
    {
        serverPacketHeaderInit(&replyPacket.header, packetType);
        replyPacket.changed = (resultType == BC_BARRACKNAME_CHANGE_OK) ? 1 : 0;
        replyPacket.resultType = resultType;
        strncpy(replyPacket.barrackName, barrackName, sizeof(replyPacket.barrackName));
    }
}

void barrackBuilderCommanderDestroy(uint8_t commanderDestroyMask, zmsg_t *replyMsg) {
    #pragma pack(push, 1)
    struct {
        ServerPacketHeader header;
        uint8_t commanderDestroyMask;
    } replyPacket;
    #pragma pack(pop)

    PacketType packetType = BC_COMMANDER_DESTROY;
    CHECK_SERVER_PACKET_SIZE(replyPacket, packetType);

    BUILD_REPLY_PACKET(replyPacket, replyMsg)
    {
        serverPacketHeaderInit(&replyPacket.header, packetType);
        replyPacket.commanderDestroyMask = commanderDestroyMask;
    }
}

void barrackBuilderCommanderCreate(CommanderCreateInfo *commanderCreate, zmsg_t *replyMsg) {
    #pragma pack(push, 1)
    struct {
        ServerPacketHeader header;
        CommanderCreateInfo commanderCreate;
    } replyPacket;
    #pragma pack(pop)

    // ICBT : those values are zeroes for some reason
    memset(commanderCreate->commander.familyName, 0, sizeof(commanderCreate->commander.familyName));
    commanderCreate->commander.accountId = 0;

    PacketType packetType = BC_COMMANDER_CREATE;
    CHECK_SERVER_PACKET_SIZE(replyPacket, packetType);

    BUILD_REPLY_PACKET(replyPacket, replyMsg)
    {
        serverPacketHeaderInit(&replyPacket.header, packetType);
        memcpy(&replyPacket.commanderCreate, commanderCreate, sizeof(replyPacket.commanderCreate));
    }
}
