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
#define LOTTO6 6
#define LOTTO7 7
using namespace std;
template <typename T>
class CustomSet
{
public:
	// Constructors and destructor:
	CustomSet() {
		vector<T>cset;
	};
	// Default constructor

	CustomSet(const CustomSet& other) {
		cset.insert(cset.end(), other.cset.begin(), other.cset.end());
	};
	// Copy constructor. Should construct a copy of "other".

	CustomSet(T arr[], int size) {
		bool judge = true;
		for (int fff = 0; fff < size; fff++) {
			for (int eee = 0; eee < fff; eee++) {
				if (arr[eee] == arr[fff]) {
					judge = false;
					break;
				}
			}
			if (judge) {
				cset.push_back(arr[fff]);
			}
		}
	};
	// Constructor using an array. 
	// Note that if there are duplicates in the array, you should ignore them.
	// And then the size of your "CustomSet" will be different from the "size" given!

	~CustomSet() {};
	// Destructor. Pay attention to memory leaks!

// Other member functions:
	int size() {
		return cset.size();
	};
	// Returns the size of the set.

	bool add(const T& item) {
	    typename vector<T>::iterator iter=find(cset.begin(),cset.end(),item);
		if(iter==cset.end())return false;
		else{
			cset.push_back(item);
			return true;
		}
	};
	// If "item" is already in the set, return false. 
	// Otherwise, add it to the set and return true.
    bool lookFor(const int item){
    	for (vector<int>::iterator iter = cset.begin(); iter != cset.end(); iter++) {
			if (*iter == item)return true;
		}
		return false;
	}
	T* find(const T& item) {
		for (typename vector<T>::iterator iter = cset.begin(); iter != cset.end(); iter++) {
			if (*iter == item)return iter;
		}
		return NULL;
	};

	// If an object in the set equals "item", return a pointer to it.
	// If "item" is not found, return nullptr(NULL).

	bool erase(const T& item) {
		for (typename vector<T>::iterator iter = cset.begin(); iter != cset.end(); ++iter) {
			if (*iter == item) {
				cset.erase(iter);
				return true;
			}
		}
		return false;
	};
	// If "item" is not in the set, return false.
	// Otherwise, erase it from the set and return true.

	CustomSet intersection(const CustomSet& other) {
		CustomSet intersectiono;unsigned int i;
		for (i = 0; i < this->cset.size(); i++) {
			for (unsigned int j = 0; j < other.cset.size(); j++) {
				if (this->cset[i] == other.cset[j]) {
					intersectiono.cset.push_back(other.cset[j]); break;
				}
			}
		}
		return intersectiono;
	};
	// This function returns the intersection of two sets (*this and other).
	// In other words, the set of all objects that is in both *this and other.
	// If there is no intersection, just return an empty set.

	void sortSet() {
		sort(cset.begin(), cset.end());
	};
	// This function sorts the objects in the set in ascending order.
	// Directly using (std::)sort is enough, if you are using an STL container.

	void printSet() {
		cout << "{";
		for (unsigned int i = 0; i < cset.size() - 1; i++)cout << cset[i] << ", ";
		cout << cset[cset.size() - 1] << "}" << endl;
	};
	// This function prints the set, seperating elements by { , , , }.
	// It's safe to assume that it supports operator<< of ostream (cout).
	// For example, Assume you've added 2, 4, -2, and 800 to the set, in this order.
	// This function will print: "{2, 4, -2, 800}\n"
	// Note that there are spaces between a comma(,) and the next object.
	// Print a newline at the end. (indicated by the '\n' above)

// Operators:
	CustomSet operator+ (const T& item) {
		CustomSet oo(*this);
		oo.add(item);
		return oo;
	};
	CustomSet operator+ (const CustomSet& that) {
		CustomSet oo(*this);
		for (int i = 0; i < that.cset.size(); i++) {
			oo.add(that.cset[i]);
		}
		return oo;
	};
	CustomSet operator+= (const T& item) {
		add(item);
		return *this;
	};
	CustomSet operator+= (const CustomSet& that) {
		for (int i = 0; i < that.cset.size(); i++) {
			add(that.cset[i]);
		}
		return *this;
	};
	// The operator+ and operator += are overloaded.
	// They can be understood intuitively, or consider this:
	// A set "plus" an item means adding in the item. 
	// A set "plus" a set means taking the union of two sets.
	// However, the difference between + and += is not written here.
	// Try to figure out on your own!

	CustomSet operator- (const T& item) {
		CustomSet oo(*this);
		oo.erase(item);
		return oo;
	};
	CustomSet operator- (const CustomSet& that) {
		CustomSet oo(*this);
		for (int i = 0; i < that.cset.size(); i++) {
			oo.erase(that.cset[i]);
		}
		return oo;
	};
	CustomSet operator-= (const T& item) {
		erase(item);
		return *this;
	};
	CustomSet operator-= (const CustomSet that) {
		for (int i = 0; i < that.cset.size(); i++) {
			erase(that.cset[i]);
		}
		return *this;
	};
	// The operator- and operator -= are overloaded.
	// They can be understood intuitively, or consider this:
	// A set "minus" an item means erasing the item. 
	// A set A "minus" a set B means subtracting B from A, or namely, A\B.
	// However, the difference between - and -= is not written here.
	// Try to figure out on your own!


	CustomSet<pair<T, T> > operator* (const CustomSet& that) {
		return make_pair<this, that>;
	};
	// This function returns the Cartesian product of two sets (*this and that).
	// The Cartesian product of two sets is the set of all ordered pairs that satisfy:
	//		The first element of the ordered pair belongs to first set (*this);
	//		The second element of the ordered pair belongs the second set (that).
	// The (std::)pair (in header <utility>) helps representing the object in it.
	// If you have any question with Cartesian products or std::pair, just look up on Internet!
	vector<T>cset;
};

/*****************************************************************\
|                            Problem 2                            |
\*****************************************************************/
int randInt(int min, int max)
{
	if (max < min)
		swap(max, min);
	return rand() % (max - min + 1) + min;
}
long long zuhe(int m,int n){
	long long result=1;int l=m-n;
	while(m>0){
		result*=m;
		m--;
	}
	while(n>0){
		result/=n;
		n--;
	}
	while(l>0){
		result/=l;
		l--;
	}
	return result;
}
class LotteryTicket
{
public:
	LotteryTicket(){
	};
	LotteryTicket(const CustomSet<int>& numbers, int round);
	virtual ~LotteryTicket(){
	};
    void setRound(const int r) {
		m_round = r;
	}
	int getRound() {
		return m_round;
	};
	int gettype(){
		return m_type;
	}
	int getCost() {
		return m_cost;
	};
	int getTicketType() {
		return m_type;
	};
	void setCost(const int& cost) {
		m_cost = cost;
	};
	virtual int claimPrize(const CustomSet<int>& prizeNumbers, int round){
	};
	CustomSet<int> m_numbers;
	int m_type;
	int m_round; // The valid round of a ticket. An outdated ticket is invalid.
	int m_cost; // The amount of money spent on this ticket.
};
class Lotto7Ticket : public LotteryTicket
{
public:
	Lotto7Ticket() {
//		for (int i = 0; i < 7; i++) {
//			int bb = randInt(1, 30);
//			if (!m_numbers.find(bb))m_numbers.cset.push_back(bb);
//		}
	};
	Lotto7Ticket(const CustomSet<int>& numbers, int round) {
		m_type=7;
		for (unsigned int i = 0; i < numbers.cset.size(); i++) {
			m_numbers.cset.push_back(numbers.cset[i]);
		}
		setRound(round);
	}
	~Lotto7Ticket(){
	};
	void setRound(const int r) {
		m_round = r;
	}
	int gettype(){
		return m_type;
	}
	int getRound() {
		return m_round;
	};
	int getCost() {
		return m_cost;
	};
	int getTicketType() {
		return LOTTO7;
	};
	void setCost(const int& cost) {
		m_cost = cost;
	};
	int claimPrize(const CustomSet<int>& prizeNumbers, int round) {
		CustomSet<int> m(m_numbers.intersection(prizeNumbers));
		if (8 - m.cset.size() < 5)return 8 - m.cset.size();
		else return 0;
	}
//	CustomSet<int> m_numbers;int m_type;
//	int m_round; // The valid round of a ticket. An outdated ticket is invalid.
//	int m_cost; // The amount of money spent on this ticket.
};
class Lotto6Ticket : public LotteryTicket
{
public:
	Lotto6Ticket() {
//		for (int i = 0; i < 6; i++) {
//			int bb = randInt(1, 43);
//			if (!m_numbers.find(bb))m_numbers.cset.push_back(bb);
//		}
	};
	Lotto6Ticket(const CustomSet<int>& numbers, int round) {
		m_type=6;
		for (unsigned int i = 0; i < numbers.cset.size(); i++) {
			m_numbers.cset.push_back(numbers.cset[i]);
		}
		setRound(round);
	}
	~Lotto6Ticket(){
	};
	void setRound(const int r) {
		m_round = r;
	}
	int getRound() {
		return m_round;
	};
	int gettype(){
		return m_type;
	}
	int getCost() {
		return m_cost;
	};
	int getTicketType() {
		return LOTTO6;
	};
	void setCost(const int& cost) {
		m_cost = cost;
	};
	int claimPrize(const CustomSet<int>& prizeNumbers, int round) {
		CustomSet<int> m(m_numbers.intersection(prizeNumbers));
		if (7 - m.cset.size() < 5)return 7 - m.cset.size();
		else return 0;
	}
//	CustomSet<int> m_numbers;int m_type;
//	int m_round; // The valid round of a ticket. An outdated ticket is invalid.
//	int m_cost; // The amount of money spent on this ticket.
};

class LotteryStation
{
public:
	LotteryStation() {
		s_round = 0;
	};
	~LotteryStation(){
	};

	LotteryTicket* buy(CustomSet<int> numbers, unsigned int tickettype) {
		if (numbers.cset.size() < tickettype){
			cout << "failed." << endl;
			return NULL;
		}
		if (tickettype == 6) {
			Lotto6Ticket* a=new Lotto6Ticket(numbers, s_round);
			cout <<"Bought a Lotto 6 ticket for ";
			long long b = 1; int c = numbers.cset.size();
			while (c > 0) {
				b *= c;
				c--;
			}
			int d = 720; long long e = 1; int f = numbers.cset.size() - 6;
			while (f > 0) {
				e *= f;
				f--;
			}
			long long g = 2*b / (d * e);
			cout << g << " Yuan at round " << s_round << "." << endl;
			a->setCost(g);
			a->m_round=s_round;
			return a;
		}
		if (tickettype == 7) {
			Lotto7Ticket* a=new Lotto7Ticket(numbers, s_round);
			cout <<"Bought a Lotto 7 ticket for ";
			long long b = 1; int c = numbers.cset.size();
			while (c > 0) {
				b *= c;
				c--;
			}
			int d = 5040; long long e = 1; int f = numbers.cset.size() - 7;
			while (f > 0) {
				e *= f;
				f--;
			}
			long long g = 2*b / (d * e);
			cout << g << " Yuan at round " << s_round << "." << endl;
			a->setCost(g);
			a->m_round=s_round;
			return a;
		}
	};
	// Represents buying a ticket of "tickettype" with "numbers" at round "m_round".
	// "tickettype" is either LOTTO6 or LOTTO7 (predefined).
	// If succeeds, output a message: 
	// "Bought a (??) ticket for (??) Yuan at round (??).\n", then return a pointer to it.
	// See examples for more details.
	// If the numbers are not enough, or some numbers are out of bound for the ticket,
	//   output "Failed.\n" and return nullptr(NULL).

	void claimPrize(LotteryTicket* ticket) {
		int hhh;CustomSet<int>awsl;int times,y,z;
		int type = ticket->m_type;
		//if (ticket->m_round != m_round)return;
		if (type == LOTTO6){
			hhh = ticket->claimPrize(m_Lotto6, s_round);
			CustomSet<int>awsl(ticket->m_numbers.intersection(m_Lotto6));
		} 
		if (type == LOTTO7){
			hhh = ticket->claimPrize(m_Lotto7, s_round);
			CustomSet<int>awsl(ticket->m_numbers.intersection(m_Lotto7));
		} 
		switch (hhh)
		{
		case 1:
			cout << "This ticket wins 2000000 Yuan." << endl;
			break;
		case 2:
			y=ticket->m_numbers.cset.size()-awsl.cset.size();
			z=type-awsl.cset.size();
			times=zuhe(y,z);
			cout << "This ticket wins "<<times*4500<<" Yuan." << endl;
			break;
		case 3:
			y=ticket->m_numbers.cset.size()-awsl.cset.size();
			z=type-awsl.cset.size();
			times=zuhe(y,z);
			cout << "This ticket wins "<<times*75<<" Yuan." << endl;
			break;
		case 4:
			y=ticket->m_numbers.cset.size()-awsl.cset.size();
			z=type-awsl.cset.size();
			times=zuhe(y,z);
			cout << "This ticket wins "<<times*5<<" Yuan." << endl;
			break;
		default:
			cout << "This ticket wins 0 Yuan." << endl;
			break;
		}
	};
	// Claims prize for a given ticket.
	// You should use the claimPrize() function of the ticket.
	// However, you should check the type of the ticket first,
	//   as you need to pass the right prize numbers as parameter.
	// Output a message in the end:
	// "This ticket wins (??) Yuan.\n"
	// You should not claim a ticket that's already claimed or with wrong rounds.
	// In either case above, simply print: "This ticket wins 0 Yuan.\n"
	void newRound() {
		int i = 0;int smdx; 
		s_round++;
		m_Lotto6.cset.clear();
		m_Lotto7.cset.clear();
		while (i < 6) {
			smdx = randInt(1, 43);
			if (!m_Lotto6.lookFor(smdx)) {
				m_Lotto6.cset.push_back(smdx);
				i++;
			}
		}
		m_Lotto6.sortSet(); i = 0;
		while (i < 7) {
			smdx = randInt(1, 30);
			if (!m_Lotto7.lookFor(smdx)) {
				m_Lotto7.cset.push_back(smdx);
				i++;
			}
		}
		m_Lotto7.sortSet();
	};
	// Begins a new round, generating new prize numbers for Lotto7 and Lotto6.
	// You may use the randInt() function given. 

	bool setPrizeNumbers(CustomSet<int> numbers, int tickettype) {
		if (numbers.size() != tickettype)return false;
		if (tickettype == 6) {
			m_Lotto6.cset.clear();
			for (int i = 0; i < 6; i++) {
				if (numbers.cset[i] > 43 || numbers.cset[i] < 1)return false;
				else m_Lotto6.cset.push_back(numbers.cset[i]);
			}
			return true;
		}
		if (tickettype == 7) {
			m_Lotto7.cset.clear();
			for (int i = 0; i < 7; i++) {
				if (numbers.cset[i] > 30 || numbers.cset[i] < 1)return false;
				else m_Lotto7.cset.push_back(numbers.cset[i]);
			}
			return true;
		}
	};
	// This function simply serves for the purpose of:
	// Making it easier for you to debug, and also easier for us to check your results.
	// It sets the prize numbers of the type given as the "numbers".
	// "tickettype" is either LOTTO6 or LOTTO7 (predefined).
	// If "numbers" are invalid (not enough/out of bounds), do nothing and return false.
	// If succeeded, return true.

private:
	int s_round; // Should be initialized to 0. 
	CustomSet<int> m_Lotto6;
	CustomSet<int> m_Lotto7;// Other private variables...
};

/*int main()
{
int a[6] = { 1,2,3,4,5,6 };
CustomSet<int> foo(a, 6);
LotteryStation sample;
sample.newRound();
sample.setPrizeNumbers(foo, LOTTO6); // LOTTO6 is predefined
LotteryTicket* jackpot = sample.buy(foo, LOTTO6);
// prints "Bought a Lotto 6 ticket for 2 Yuan at round 1.\n"
sample.claimPrize(jackpot);
// prints "This ticket wins 2000000 Yuan.\n"
}*/




/*****************************************************************\
|                            Problem 3                            |
\*****************************************************************/
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
bool operator ==(GechatUser a,GechatUser b){
	if(a.getname()==b.getname())return true;
	else return false;
};
ostream & operator<<( ostream & os, GechatUser  fslsm)
{
    os << fslsm.getname();
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
	if(user=NULL)return false;
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
