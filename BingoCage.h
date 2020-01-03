#ifndef _BINGOCAGE_H_
#define _BINGOCAGE_H_

#include <vector>
#include <random>

class BingoCage
{
 public:
  BingoCage(int NumBalls);

  /**
   * @retval Number of balls in the drum. 
   */
  int Restart();
  
  /**
   * @retval Number of balls in the drum. 
   */
  int Draw();

  void Print();

  int NumDraws;
  
 private:

  std::vector<int> Balls;
  std::default_random_engine * RNG;
  int InitialNumBalls;

};

#endif
