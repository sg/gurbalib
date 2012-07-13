#include "../domain.h"
inherit ROOM;

void setup(void) {
   add_area("2.4.5");

   set_brief("All at sea");
   set_long("You are swimming out at the sea.");

   add_exit("west", DIR + "/rooms/jetty2.c");

   add_room_command("dive", "dive");

   set_objects (([
      DIR + "/obj/bag.c": 1,
   ]));
}

int dive(string str) {
   object *inv;
   int i,max;
   string dest;

   inv = this_player()->query_inventory();
   max = sizeof(inv);
   for(i=0;i<max;i++) {
      if (inv[i]->is_container()) {
         dest = DIR + "/rooms/sea_bottom.c";
         this_player()->query_environment()->tell_room(this_player(),
            this_player()->query_Name() + " dives under the water.\n");
         write("You dive down into the sea.\n");
         this_player()->move(dest);
         this_player()->query_environment()->tell_room(this_player(),
            this_player()->query_Name() + " swims down.\n");
         this_player()->do_look(0);
         return 1;
      }
   }
   write("You can not breathe under water.  You should try to get " +
      "some portable air supply!");
   this_player()->query_environment()->tell_room(this_player(),
      this_player()->query_Name() + " sputers as they attempt to swim.\n");
   return 1;
}