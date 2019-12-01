#ifndef LOTTERYSTATION_H
#define LOTTERYSTATION_H
class LotteryStation{
public:
	LotteryStation();
    ~LotteryStation();
    LotteryTicket* buy(CustomSet<int> numbers, unsigned int tickettype);
    void claimPrize(LotteryTicket* ticket);
    void newRound();
    bool setPrizeNumbers(CustomSet<int> numbers, int tickettype);
private:
	int s_round; 
	CustomSet<int> m_Lotto6;
	CustomSet<int> m_Lotto7;    
};
#endif
