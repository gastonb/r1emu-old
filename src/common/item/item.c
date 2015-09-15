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
#include "item.h"
#include "common/commander/inventory.h"

// ------ Structure declaration -------


// ------ Static declaration -------


// ------ Extern function implementation -------

Item *itemNew(void) {
    Item *self;

    if ((self = malloc(sizeof(Item))) == NULL) {
        return NULL;
    }

    if (!itemInit(self)) {
        itemDestroy(&self);
        error("Item failed to initialize.");
        return NULL;
    }

    return self;
}

bool itemInit(Item *self) {
    memset(self, 0, sizeof(Item));

    return true;
}

void itemFree(Item *self) {
    // TODO
}

void itemDestroy(Item **_self) {
    Item *self = *_self;

    if (_self && self) {
        itemFree(self);
        free(self);
        *_self = NULL;
    }
}

bool itemCreateEmptyItemitemCreateEmptyItem(Item *self) {
    ItemAttributes *attributes;
    if ((attributes = malloc(sizeof(ItemAttributes))) == NULL) {
        return false;
    }
    memset(attributes, 0, sizeof(ItemAttributes));
    self->attributes = attributes;

    return true;
}

bool itemSetDefaults(Item *self) {
    // Default attributes
    switch (self->itemCategory) {
        case INVENTORY_CAT_WEAPON: {
            break;
        }
        case INVENTORY_CAT_ARMOR: {
            ItemAttributes *attributes;
            if ((attributes = malloc(sizeof(ItemAttributes))) == NULL) {
                return false;
            }
            /*
            self->attributes = attributes;
            attributes->cooldown = 0;
            attributes->durabilty = 4200;
            */
            break;
        }
        default: {
            dbg("Item category unkown: %d", self->itemCategory);
            break;
        }
    }

    return true;
}


size_t itemGetAttributesPacket(Item *item, char **attributesPacket) {

    char *packet; // where the packet will get built.
    size_t sizeOfPacket = 2; // size of the packet, starting with 2, because it counts 2 bytes needed to set the size of packet later.

    packet = malloc(2); // We allocate space at the begining, to save the size of the whole packet at the end of the process.

    // If this item have no attributes, we return the NoAttribute packet (00 00)
    if (item->attributes == NULL) {
        #pragma pack(push, 1)
        typedef struct NoAttributesPacket {
            uint16_t type;
        } NoAttributesPacket;
        #pragma pack(pop)
        NoAttributesPacket attr = {
            .type = 0,
        };
        sizeOfPacket = sizeof(NoAttributesPacket);
        packet = (char*) realloc(packet, sizeOfPacket);
        memcpy(packet, &attr, sizeOfPacket);

        *attributesPacket = packet;
        return sizeOfPacket;
    }

    size_t newSize; // Used for counting size of each attribute

    // Cooldown (always present in Items)
    newSize = itemGetPacketFloatAttribute(ITEM_ATTRIBUTE_COOLDOWN, item->attributes->cooldown, &packet, sizeOfPacket);
    if (newSize != 0) {
        sizeOfPacket = newSize + sizeOfPacket;
    }

    // Durability
    if (item->attributes->durabilty > 0.f) {
        newSize = itemGetPacketFloatAttribute(ITEM_ATTRIBUTE_DURABILITY, item->attributes->durabilty, &packet, sizeOfPacket);
        if (newSize != 0) {
            sizeOfPacket = newSize + sizeOfPacket;
        }
    }

    // Custom Name
    if (strlen(item->attributes->customName) != 0) {
        newSize = itemGetPacketStringAttribute(ITEM_ATTRIBUTE_CUSTOM_NAME, item->attributes->customName, &packet, sizeOfPacket);
            if (newSize != 0) {
            sizeOfPacket = newSize + sizeOfPacket;
        }
    }

    // Memo
    if (strlen(item->attributes->memo) != 0) {
        newSize = itemGetPacketStringAttribute(ITEM_ATTRIBUTE_MEMO, item->attributes->memo, &packet, sizeOfPacket);
            if (newSize != 0) {
            sizeOfPacket = newSize + sizeOfPacket;
        }
    }

    // Crafter Name
    if (strlen(item->attributes->crafterName) != 0) {
        newSize = itemGetPacketStringAttribute(ITEM_ATTRIBUTE_CRAFTER_NAME, item->attributes->crafterName, &packet, sizeOfPacket);
            if (newSize != 0) {
            sizeOfPacket = newSize + sizeOfPacket;
            dbg("new size of packet: %d", sizeOfPacket);
        }
    }

    size_t tempSize = sizeOfPacket - 2; // Remove 2 bytes from size we added at the begining of the function, to store TOTAL attributes size

    // Add the size of the whole packet, at the begining of the packet.
    memcpy(packet, &tempSize, sizeof(uint16_t));

    // Assign packet for return
    *attributesPacket = packet;

    // Return the size of the packet
    return sizeOfPacket;
}

size_t itemGetPacketFloatAttribute(ItemAttributeType attrType, float value, char **_packet, size_t sizeOfPacket) {

    char *thisPacket; // Pointer to this attribute
    char *packet = *_packet;

    #pragma pack(push, 1)
    typedef struct FloatItemAttributePacket {
        uint16_t type;
        float value ;
    } FloatItemAttributePacket;
    #pragma pack(pop)

    size_t thisAttributeSize = sizeof(FloatItemAttributePacket);

    // allocate memory
    thisPacket = realloc(packet, sizeOfPacket + thisAttributeSize);
    if (thisPacket != NULL) {
        *_packet = thisPacket;

        // Prepare struct
        FloatItemAttributePacket attr = {
            .type = attrType,
            .value = value,
        };

        // Copy to packet
        memcpy((thisPacket)+sizeOfPacket, &attr, thisAttributeSize);

        // Debug
        //size_t newSize = sizeOfPacket + thisAttributeSize;
        //buffer_print (thisPacket, newSize, NULL);

        return thisAttributeSize;
    } else {
        return 0;
    }
}


size_t itemGetPacketStringAttribute(ItemAttributeType attrType, char *value, char **_packet, size_t sizeOfPacket) {

    char *thisPacket; // Pointer to this packet
    char *packet = *_packet;


    size_t stringLen = strlen(value) + 1; // Length of string

    #pragma pack(push, 1)
    typedef struct StringItemAttributePacket {
        uint16_t type;
        uint16_t valueSize;
        char value[stringLen];
    } StringItemAttributePacket;
    #pragma pack(pop)

    size_t thisAttributeSize = sizeof(StringItemAttributePacket);

    // allocate memory
    thisPacket = realloc(packet, sizeOfPacket + thisAttributeSize);

    if (thisPacket != NULL) {
        *_packet = thisPacket;

        // Prepare struct
        StringItemAttributePacket attr;
        attr.type = attrType;
        attr.valueSize = stringLen;
        strncpy(attr.value, value, stringLen);

        // Copy to packet
        memcpy(thisPacket+sizeOfPacket, &attr, thisAttributeSize);

        // Debug
        //size_t newSize = sizeOfPacket + thisAttributeSize;
        //buffer_print (thisPacket, newSize, NULL);

        return thisAttributeSize;
    } else {
        return 0;
    }
}


