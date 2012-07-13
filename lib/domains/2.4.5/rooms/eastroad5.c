#include "../domain.h"
inherit ROOM;

void setup(void) {
   add_area("2.4.5");

   set_brief("East road");
   set_long("East road runs south from here.  To the west lies the " +
      "Eastroad Inn.");

   add_exit("south", DIR + "/rooms/eastroad4.c");
   add_exit("west", DIR + "/rooms/inn.c");
}