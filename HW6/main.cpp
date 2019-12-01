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
#include "tickets.h"
#include "tickets.cpp"
#include "lotterystation.h"
#include "lotterystation.cpp"
#include "gechatuser.h"
#include "gechatuser.cpp"
using namespace std;
int main() {
int a[6] = { 1,2,3,4,5,6 };
int b[7] = { 1,2,3,8,9,10,11};
CustomSet<int> foo(a, 6);CustomSet<int> fooo(b, 7);
LotteryStation sample;
sample.newRound();
sample.setPrizeNumbers(foo, LOTTO6); // LOTTO6 is predefined
LotteryTicket* jackpot = sample.buy(fooo, LOTTO6);
// prints "Bought a Lotto 6 ticket for 2 Yuan at round 1.\n"
sample.claimPrize(jackpot);
// prints "This ticket wins 2000000 Yuan.\n"
}
