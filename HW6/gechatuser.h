#ifndef GECHATUSER_H
#define GECHATUSER_H
#include <string>
#include <memory>
#include <map>
using namespace std;
class GechatUser
{
public:
	// Assume using namespace std;
	GechatUser();
	GechatUser(string username);
	GechatUser(const GechatUser& other);
	~GechatUser();
	string getname();
	int numFriends();
	void setUsername(string username);
	bool haveFriend(shared_ptr<GechatUser> user); // return true if user is a friend to *this.
	bool addFriend(shared_ptr<GechatUser> user); // return false only if user is invalid or already a friend.
	bool singleDelete(shared_ptr<GechatUser> user); // return false only if user is invalid or not a friend.
	bool singleDelete(string username); // return false only if username not found in friends.
	bool doubleDelete(shared_ptr<GechatUser> user); // return false only if user is invalid or not a friend.
	bool doubleDelete(string username); // return false only if username not found in friends.

	// Not complete...
private:
    string name;
	map <string,shared_ptr<GechatUser> > friends;
};
#endif
