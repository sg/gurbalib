#include "../domain.h"
inherit ROOM;

void setup(void) {
   add_area("2.4.5");

   set_brief("The orc fortress");
   set_long("THis is the local strong point of the orcs.  There is an " +
      "entrance to a small room to the north.");

   set_objects (([
      DIR + "/monsters/orc.c": 2,
   ]));

   add_exit("north", DIR + "/rooms/orc_treasure.c");
   add_exit("south", DIR + "/rooms/orc_vall.c");

}
