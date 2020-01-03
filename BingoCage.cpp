#include "BingoCage.h"

#include <iostream>
#include <algorithm>
#include <chrono>

BingoCage::BingoCage(int NumBalls) :
  InitialNumBalls(NumBalls)
{
  RNG = new std::default_random_engine;
  RNG->seed(std::chrono::system_clock::now().time_since_epoch().count());
  Restart();

}

int BingoCage::Restart()
{
  Balls.clear();
  NumDraws = 0;

  auto it = Balls.begin();
  for(int i = 1; i < (InitialNumBalls+1); i++)
  {
    it = Balls.insert(it, i);
  }

  // Shuffle.
  std::shuffle(Balls.begin(), Balls.end(), *RNG);
  
  return InitialNumBalls;
}

void BingoCage::Print()
{
  int BallsLeft = Balls.size();
  std::cout << "There are: " << BallsLeft << " balls in the cage." << std::endl;
  auto it = Balls.begin();
  for(int i = 0; i < BallsLeft; i++)
  {
    std::cout << *it << ", ";
    it++;
  }
  std::cout << std::endl; 
}

int BingoCage::Draw()
{
  if(!Balls.size())
    return 0;

  int retval = Balls.back();
  Balls.pop_back();
  NumDraws++;

  return retval;
}

