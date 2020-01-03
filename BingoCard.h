#ifndef _BINGOCARD_H_
#define _BINGOCARD_H_

#include <vector>
#include <random>

class BingoCard
{

 public:
  BingoCard(int NumEntries, int NumBalls);
  
  /**
   * @retval Number of balls on the card.
   */
  int Restart();
  
  /**
   * @param Ball A ball to check in the list.
   * @retval Number of balls on the card. 
   */
  int Check(int Ball);

  void Print();

 private:

  std::vector<int> Entries;
  std::default_random_engine * RNG;
  int InitialNumEntries;
  int InitialNumBalls;

};

#endif
