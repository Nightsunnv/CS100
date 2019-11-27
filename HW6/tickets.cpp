#include "tickets.h"
#define LOTTO6 6
#define LOTTO7 7
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

LotteryTicket::LotteryTicket(){};
LotteryTicket::LotteryTicket(const CustomSet<int>& numbers, int round);
virtual LotteryTicket::~LotteryTicket(){
	};
void LotteryTicket::setRound(const int r) {
	m_round = r;
}
int LotteryTicket::getRound() {
	return m_round;
};
int Lotteryticket::gettype(){
	return m_type;
}
int LotteryTicket::getCost() {
	return m_cost;
};
int LotteryTicket::getTicketType() {
	return m_type;
};
void LotteryTicket::setCost(const int& cost) {
	m_cost = cost;
};
virtual int LotteryTicket::claimPrize(const CustomSet<int>& prizeNumbers, int round){};


Lotto7Ticket::	Lotto7Ticket() {
//		for (int i = 0; i < 7; i++) {
//			int bb = randInt(1, 30);
//			if (!m_numbers.find(bb))m_numbers.cset.push_back(bb);
//		}
	};
    Lotto7Ticket::Lotto7Ticket(const CustomSet<int>& numbers, int round) {
		m_type=7;
		for (unsigned int i = 0; i < numbers.cset.size(); i++) {
			m_numbers.cset.push_back(numbers.cset[i]);
		}
		setRound(round);
	}
	Lotto7Ticket::~Lotto7Ticket(){
	};
	void Lotto7Ticket::setRound(const int r) {
		m_round = r;
	}
	int Lotto7Ticket::gettype(){
		return m_type;
	}
	int Lotto7Ticket::getRound() {
		return m_round;
	};
	int Lotto7Ticket::getCost() {
		return m_cost;
	};
	int Lotto7Ticket::getTicketType() {
		return LOTTO7;
	};
	void Lotto7Ticket::setCost(const int& cost) {
		m_cost = cost;
	};
	int Lotto7Ticket::claimPrize(const CustomSet<int>& prizeNumbers, int round) {
		CustomSet<int> m(m_numbers.intersection(prizeNumbers));
		if (8 - m.cset.size() < 5)return 8 - m.cset.size();
		else return 0;
	}

Lotto6Ticket::	Lotto6Ticket() {
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
	Lotto6Ticket::~Lotto6Ticket(){
	};
	void Lotto6Ticket::setRound(const int r) {
		m_round = r;
	}
	int Lotto6Ticket::getRound() {
		return m_round;
	};
	int Lotto6Ticket::gettype(){
		return m_type;
	}
	int Lotto6Ticket::getCost() {
		return m_cost;
	};
	int Lotto6Ticket::getTicketType() {
		return LOTTO6;
	};
	void Lotto6Ticket::setCost(const int& cost) {
		m_cost = cost;
	};
	int Lotto6Ticket::claimPrize(const CustomSet<int>& prizeNumbers, int round) {
		CustomSet<int> m(m_numbers.intersection(prizeNumbers));
		if (7 - m.cset.size() < 5)return 7 - m.cset.size();
		else return 0;
	}
