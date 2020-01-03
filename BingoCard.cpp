#include "BingoCard.h"

#include <iostream>
#include <algorithm>
#include <chrono>

BingoCard::BingoCard(int NumEntries, int NumBalls) :
  InitialNumEntries(NumEntries),
  InitialNumBalls(NumBalls)
{
  RNG = new std::default_random_engine;
  RNG->seed(std::chrono::system_clock::now().time_since_epoch().count());
  Restart();
}

int BingoCard::Restart()
{
  Entries.clear();
  auto it = Entries.begin();

  for(int i = 1; i < (InitialNumBalls+1); i++)
  {
    it = Entries.insert(it, i);
  }

  // Shuffle.
  std::shuffle(Entries.begin(), Entries.end(), *RNG);

  // There are "InitialNumBalls" in the list.
  // Keep removing until there's "InitialNumEntries" in the list.
  while(Entries.size() > InitialNumEntries)
    Entries.pop_back();

  
  return InitialNumEntries;
}

int BingoCard::Check(int Ball)
{
  std::vector<int>::iterator found_ball;
  found_ball = std::find(Entries.begin(), Entries.end(), Ball);
  if(found_ball != Entries.end())
  {
    // Found a ball.
    Entries.erase(found_ball);
  }
  return Entries.size();
}

void BingoCard::Print()
{
  int EntriesLeft = Entries.size();
  std::cout << "There are: " << EntriesLeft << " entries left on the card." << std::endl;
  auto it = Entries.begin();
  for(int i = 0; i < EntriesLeft; i++)
  {
    std::cout << *it << ", ";
    it++;
  }
  std::cout << std::endl; 
}
