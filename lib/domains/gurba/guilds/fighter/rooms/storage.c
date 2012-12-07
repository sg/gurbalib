#include "../../../domain.h"
inherit ROOM;
inherit M_STORAGE;

void setup(void) {
   set_brief("%^BLUE%^Fighters Guild Storage%^RESET%^");
   set_long("The room is filled with assorted weapons and armor..");

   set_exits(([
      "south" : DIR + "/guilds/fighter/rooms/main",
   ]));

   set_objects(([
      DIR + "/guilds/fighter/objects/storage_sign" : 1,
   ]));

   set_storage_size(30);
}
