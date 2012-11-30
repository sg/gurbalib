void usage() {
   write("Usage: give [-h] [all|OBJ] [to] PLAYER\n");
   write("Allows you to give OBJ to PLAYER\n");
   write("Options:\n");
   write("\t-h\tHelp, this usage message.\n");
   write("\tall\tGive everything you are carring to PLAYER.\n");
   write("See also: get, drop.\n");
}

void do_give(object obj1, object obj2, int loud) {
   string slot;
   object worn;

   if (!obj1) {
      if (loud) {
         write("What are you trying to put where?");
      }
      return;
   }

   if (!obj2) {
      if (loud) {
         write("Where are you trying to put that?\n");
      }
      return;
   }

   if (!obj2->is_living()) {
      if (loud) {
         write("You can only give things to the living.\n");
      }
      return;
   }

   if (obj2 == this_player()) {
      if (loud) {
         write("You may not give things to yourself.\n");
      }
      return;
   }

   if (obj1->is_worn()) {
      if (obj1->is_cursed()) {
         this_player()->targetted_action("$N $vtry to remove $o, but $vfumble.",
            nil, obj1);
         write("Strange... It won't come off.\n");
         return;
      } else {
         this_player()->do_remove(obj1);
         this_player()->targetted_action(obj1->query_remove_message(), nil, obj1);
      }
   }

   if (obj1->is_wielded()) {
      if (obj1->is_cursed()) {
         this_player()->targetted_action("$N $vtry to unwield $o, " +
            "but $vfumble.", nil, obj1);
         write("Strange... You can't unwield that..\n");
         return;
      } else {
         this_player()->do_unwield(obj1);
         this_player()->targetted_action(obj1->query_unwield_message(), 
            nil, obj1);
      }
   }

   if (obj1->move(obj2)) {
      this_player()->targetted_action("$N $vgive $o to $o1.", nil, obj1, obj2);
   } else {
      this_player()->targetted_action("$N $vtryto give $o to $o1, but $vfail.",
         nil, obj1, obj2);
   }
}

void main(string str) {
   object obj, obj2;
   object *inv;
   int i, max;
   string what, where;

   if (!str || str == "") {
      usage();
      return;
   }

   if (sscanf(str, "-%s", str)) {
      usage();
      return;
   }

   if (sscanf(str, "%s to %s",what,where) == 2) {
   } else if (sscanf(str, "%s %s",what,where) == 2) {
   } else {
      write("You want to give what to who?");
      return;
   }

   obj = this_environment()->present(where);
   if (!obj) {
      write("Who are you trying to give that to?");
      return;
   }

   if (what == "all") {
      inv = this_player()->query_inventory();
      max = sizeof(inv);
      for (i = 0; i < max; i++) {
         do_give(inv[i], obj, 0);
      }
      return;
   }

   obj2 = this_player()->present(lowercase(what));
   if (!obj2) {
      obj2 = this_player()->query_environment()->present(lowercase(what));
   }
   do_give(obj2, obj, 1);
}