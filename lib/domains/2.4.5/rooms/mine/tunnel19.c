#include "../../domain.h"
inherit ROOM;

void setup(void) {
   add_area("2.4.5");

   set_brief("Tunnel");
   set_long("The tunnel splits up in a fork forward.");

   add_exit("north", DIR + "/rooms/mine/tunnel17.c");
   add_exit("south", DIR + "/rooms/mine/tunnel22.c");
}