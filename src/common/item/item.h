/**
 *
 *   ██████╗   ██╗ ███████╗ ███╗   ███╗ ██╗   ██╗
 *   ██╔══██╗ ███║ ██╔════╝ ████╗ ████║ ██║   ██║
 *   ██████╔╝ ╚██║ █████╗   ██╔████╔██║ ██║   ██║
 *   ██╔══██╗  ██║ ██╔══╝   ██║╚██╔╝██║ ██║   ██║
 *   ██║  ██║  ██║ ███████╗ ██║ ╚═╝ ██║ ╚██████╔╝
 *   ╚═╝  ╚═╝  ╚═╝ ╚══════╝ ╚═╝     ╚═╝  ╚═════╝
 *
 * @file item.h
 * @brief
 *
 *
 *
 * @license GNU GENERAL PUBLIC LICENSE - Version 2, June 1991
 *          See LICENSE file for further information
 */

#pragma once

// ---------- Includes ------------
#include "R1EMU.h"
//#include "common/commander/inventory.h"

// ---------- Defines -------------
#define ITEM_ATTR_MEMO_MAX_SIZE 64
#define ITEM_ATTR_CUSTOM_MAX_NAME_SIZE 64
#define ITEM_ATTR_CRAFTER_MAX_NAME_SIZE 64

// ------ Structure declaration -------

typedef enum {
    INVENTORY_CAT_WEAPON = 1,
    INVENTORY_CAT_ARMOR = 2,
    INVENTORY_CAT_SUBWEAPON = 3,
    INVENTORY_CAT_COSTUME = 4,
    INVENTORY_CAT_ACCESSORY = 5,
    INVENTORY_CAT_CONSUMABLE = 6,
    INVENTORY_CAT_GEM = 7,
    INVENTORY_CAT_MATERIAL = 8,
    INVENTORY_CAT_CARD = 9,
    INVENTORY_CAT_COLLECTION = 10,
    INVENTORY_CAT_BOOK = 11,
    INVENTORY_CAT_QUEST = 12,
    INVENTORY_CAT_PETWEAPON = 13,
    INVENTORY_CAT_PETARMOR = 14,
}   InventoryCategory;

typedef enum ItemAttributeType
{
    ITEM_ATTRIBUTE_DURABILITY = 3770,
    ITEM_ATTRIBUTE_PR = 3781,
    ITEM_ATTRIBUTE_COOLDOWN   = 3843,
    ITEM_ATTRIBUTE_REIFORCE_2   = 3852,
    ITEM_ATTRIBUTE_MEMO   = 3972,
    ITEM_ATTRIBUTE_CUSTOM_NAME   = 3975,
    ITEM_ATTRIBUTE_CRAFTER_NAME   = 3978,
} ItemAttributeType;

typedef struct ItemAttributes {
    float durabilty;
    float cooldown;
    char memo[ITEM_ATTR_MEMO_MAX_SIZE]; // Or pointer to char?
    char customName[ITEM_ATTR_CUSTOM_MAX_NAME_SIZE]; // Or pointer to char?
    char crafterName[ITEM_ATTR_CRAFTER_MAX_NAME_SIZE]; // Or pointer to char?
    float pr; // dont know what it means yet
    float reinforce_2; // I belive it is +1, +2, +3
} ItemAttributes;

typedef struct {
    uint64_t uniqueId;
    uint32_t amount;
    uint32_t inventoryIndex;
    uint32_t id;
} ItemPkt;


/**
 * @brief Item contains
 */

typedef struct Item
{
    uint64_t itemId; // Unique ID for an Item - key.
    InventoryCategory itemCategory;
    uint32_t itemType; // ID of this item indicating which item is it.
    uint32_t amount; // amount of this item
    ItemAttributes *attributes;
    uint8_t useGender;
    uint8_t useJob;
    bool isTwoHanded;
    uint8_t equipSlot;
    bool isDummy; // When an item is created for dummy porpuses.
    uint32_t inventoryIndex;
} Item;



// ------ Structure declaration -------




// ----------- Functions ------------

Item *itemNew(void);
bool itemInit(Item *self);
void itemFree(Item *self);
void itemDestroy(Item **_self);
bool itemSetDefaults(Item *self);
/**
 * Prepares a packet with attributes, to send to client
 * @param item The item to get the attributes from
 * @param attributesPacket attributes to be populated
 *
 * @return the size of this packet
 */
size_t itemGetAttributesPacket(Item * item, char **attributesPacket);

/**
 * Prepares an Item Attribute of float value to send to client
 * @param attrType The type of attribute
 * @param value Attribute value
 * @param the packet where the attribute will be appended
 * @param size of current packet being sent to the function (will not be modified) //TODO could be sent as reference, and return a bool for success
 *
 * @return size of this specific attribute
 */
size_t itemGetPacketFloatAttribute(ItemAttributeType attrType, float value, char **_packet, size_t sizeOfPacket);
/**
 * Prepares an Item Attribute of string value to send to client
 * @param attrType The type of attribute
 * @param value Attribute value
 * @param the packet where the attribute will be appended
 * @param size of current packet being sent to the function (will not be modified) //TODO could be sent as reference, and return a bool for success
 *
 * @return size of this specific attribute
 */
size_t itemGetPacketStringAttribute(ItemAttributeType attrType, char *value, char **_packet, size_t sizeOfPacket);
