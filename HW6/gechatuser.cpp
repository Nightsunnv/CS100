#include "gechatuser.h"
bool operator ==(GechatUser a,GechatUser b){
	if(a.getname()==b.getname())return true;
	else return false;
};
ostream & operator<<( ostream & os, GechatUser  fslsm)
{
    os << fslsm.getname()<<" (friends: "<<fslsm.numFriends()<<")";
    return os;
} 
GechatUser::GechatUser(){};
GechatUser::GechatUser(string username){
	setUsername(username);
};
GechatUser::GechatUser(const GechatUser& other){
	name=other.name;
	friends=other.friends;
};
GechatUser::~GechatUser(){};
string GechatUser::getname(){
		return name;
}
int GechatUser::numFriends(){
	return friends.size();
};
void GechatUser::setUsername(string username){
	name=username;
};
bool GechatUser::haveFriend(shared_ptr<GechatUser> user){
	map<string,shared_ptr<GechatUser> >::iterator it=friends.find(user->name);
	if(it==friends.end())return false; 
	else return true;
};
bool GechatUser::addFriend(shared_ptr<GechatUser> user){
    friends[user->name]=user;
	return true;
};
bool GechatUser::singleDelete(shared_ptr<GechatUser> user){
	map<string,shared_ptr<GechatUser> >::iterator iter=friends.find(user->name);
	if(iter==friends.end())return false;
	friends.erase(iter);
	return true;
};
bool GechatUser::singleDelete(string username){
	map<string,shared_ptr<GechatUser> >::iterator iter=friends.find(username);
	if(iter==friends.end())return false;
	friends.erase(iter);
	return true;
};
bool GechatUser::doubleDelete(shared_ptr<GechatUser> user){
	map<string,shared_ptr<GechatUser> >::iterator iter=friends.find(user->name);
	if(iter==friends.end())return false;
	friends.erase(iter);
	user->singleDelete(name);
	return true;
};
bool GechatUser::doubleDelete(string username){
	map<string,shared_ptr<GechatUser> >::iterator iter=friends.find(username);
	if(iter==friends.end())return false;
	iter->second->singleDelete(name);
	friends.erase(iter);
	return true;
};
