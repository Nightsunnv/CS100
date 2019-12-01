LotteryStation::	LotteryStation() {
		s_round = 0;
	};
LotteryStation::	~LotteryStation(){
	};

	LotteryTicket* LotteryStation::buy(CustomSet<int> numbers, unsigned int tickettype) {
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

	void LotteryStation::claimPrize(LotteryTicket* ticket) {
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
	void LotteryStation::newRound() {
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

	bool LotteryStation::setPrizeNumbers(CustomSet<int> numbers, int tickettype) {
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
