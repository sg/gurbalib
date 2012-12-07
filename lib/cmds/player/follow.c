void usage() {
   string *lines;

   lines = ({ "Usage: follow [-h] [WHO]" });
   lines += ({ "" });
   lines += ({ "Allows you to follow/unfollow another player." });
   lines += ({ "If you give no aguments, it will print who you are following." 
      });
   lines += ({ "" });
   lines += ({ "Options:" });
   lines += ({ "\t-h\tHelp, this usage message." });
   lines += ({ "Examples:" });
   lines += ({ "\tfollow sirdude" });
   lines += ({ "\tfollow" });
   lines += ({ "See also:" });
   lines += ({ "\tattack, cast, eat, enter, go, pray" });

   this_player()->more(lines);
}

/* XXX need to still put backend of this in..... */

void main(string str) {
   string name;
   object obj;

   if (str == this_player()->query_name()) {
      write("You can not follow yourself.\n");
      return;
   }

   name = this_player()->query_follow();
   if (!str || str == "") {
      if (name && name != "") {
         write("You are currently following: " + name + "\n");
      } else {
         write("You are currently not following anyone.\n");
      }
      return;
   }
   if (sscanf(str, "-%s", str)) {
      usage();
      return;
   }

   /* Stop following whoever we are following */
   if (str == name) {
      this_player()->set_follow("");
      write("You stop following " + str + ".\n");
      this_environment()->tell_room(this_player(), 
         this_player()->query_Name() + " stops following " + 
         capitalize(str) + ".\n");
      obj = find_object(name);
      obj->remove_follower(this_player());
      return;
   }

   /* Actually follow someone */
   obj = this_environment()->present(str);
   if (obj) {
      this_player()->set_follow(str);

      write("You start following " + str + ".\n");
      this_environment()->tell_room(this_player(), 
         this_player()->query_Name() + " starts following " + 
         capitalize(str) + ".\n");
       obj->add_follower(this_player());
   } else {
      write("You can not find: " + str + ".\n");
   }
}
