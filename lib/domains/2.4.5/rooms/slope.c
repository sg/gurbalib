#include "../domain.h"
inherit ROOM;

void setup(void) {
   add_area("2.4.5");

   set_brief("A slope");
   set_long("The forest gets light here, and slopes down to the west.");

   add_exit("south", DIR + "/rooms/orc_vall.c");
   add_exit("east", DIR + "/rooms/forest2.c");
   add_exit("west", DIR + "/rooms/forest3.c");
}