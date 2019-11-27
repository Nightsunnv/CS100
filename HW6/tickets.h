#ifndef tickets_h
#define tickets_h
#include "customset.h"
class LotteryTicket{
public:
	LotteryTicket();
    LotteryTicket(const CustomSet<int>& numbers, int round);
    virtual ~LotteryTicket();
    void setRound(const int r);
    int getRound();
    int gettype();
    int getCost();
    int getTicketType();
    void setCost(const int& cost);
    virtual int claimPrize(const CustomSet<int>& prizeNumbers, int round);
    CustomSet<int> m_numbers;
	int m_type;
	int m_round; 
	int m_cost;
};
class Lotto7Ticket : public LotteryTicket{
public:
	Lotto7Ticket();
    Lotto7Ticket(const CustomSet<int>& numbers, int round);
    ~Lotto7Ticket();
    void setRound(const int r);
    int gettype();
    int getRound();
    int getCost();
    int getTicketType();
    void setCost(const int& cost);
    int claimPrize(const CustomSet<int>& prizeNumbers, int round) ;

};
class Lotto6Ticket : public LotteryTicket{
public:
	Lotto6Ticket();
    Lotto6Ticket(const CustomSet<int>& numbers, int round);
    ~Lotto6Ticket();
    void setRound(const int r);
    int gettype();
    int getRound();
    int getCost();
    int getTicketType();
    void setCost(const int& cost);
    int claimPrize(const CustomSet<int>& prizeNumbers, int round) ;
};
#endif
