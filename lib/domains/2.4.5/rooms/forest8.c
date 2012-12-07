#include "../domain.h"
inherit ROOM;

void setup(void) {
   add_area("2.4.5");

   set_brief("Deep forest");
   set_long("You are in the deep forest.");

   add_exit("south", DIR + "/rooms/forest9.c");
   add_exit("east", DIR + "/rooms/forest5.c");
}
