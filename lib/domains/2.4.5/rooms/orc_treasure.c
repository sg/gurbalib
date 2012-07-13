#include "../domain.h"
inherit ROOM;

void setup(void) {
   add_area("2.4.5");

   set_brief("The orc treasury");
   set_long("You are in the orc treasury.  It is normally heavily guarded.");

   add_exit("south", DIR + "/rooms/fortress.c");

   set_objects (([
      DIR + "/monsters/orc_shayman.c": 1,
   ]));
}
