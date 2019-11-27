#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <utility>
#include <string>
#include <memory>
#include <random>
#include <time.h>
#include <string>
#include <algorithm>
#include "customset.h"
#include "gechatuser.h"
#include "gechatuser.cpp"
using namespace std;
int main() {
shared_ptr<GechatUser> gzw(new GechatUser("GeziWang"));
shared_ptr<GechatUser> gf(new GechatUser("Girlfriend"));
gzw->addFriend(gf);
gf->addFriend(gzw);
gf->doubleDelete(gzw);
CustomSet<GechatUser> sad_story;
sad_story.add(*gzw);
sad_story.add(*gf);
sad_story.printSet();
// prints "{GeziWang (friends: 0), Girlfriend (friends: 0)}\n"
}
