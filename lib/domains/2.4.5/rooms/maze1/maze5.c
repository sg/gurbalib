#include "../../domain.h"
inherit ROOM;

void setup(void) {
   add_area("2.4.5");

   set_brief("End of the maze");
   set_long("Congradulations you have done it.);

   add_exit("south", DIR + "/rooms/maze1/maze4.c");

   set_objects (([
      DIR + "/obj/leather.c": 1,
   ]));

}