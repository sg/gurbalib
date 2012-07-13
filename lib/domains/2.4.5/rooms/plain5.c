#include "../domain.h"
inherit ROOM;

void setup(void) {
   add_area("2.4.5");

   set_brief("A large open plain");
   set_long("A large open plain.");

   add_exit("north", DIR + "/rooms/plain7.c");
   add_exit("east", DIR + "/rooms/plain2.c");
}