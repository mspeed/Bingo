#include <iostream>

#include "BingoCage.h"
#include "BingoCard.h"


int main()
{

  const int NumBalls = 49;
  
  BingoCage gBingoCage(NumBalls);
  //  gBingoCage.Print();

  BingoCard gBingoCard(5, NumBalls);
  //  gBingoCard.Print();
  
  bool Bingo = false;
  // Begin.

  //  std::cout << "Drawing numbers: " << std::endl;

  int DrawnBall = gBingoCage.Draw();
  while(DrawnBall && (!Bingo))
  {
    //    std::cout << DrawnBall << "-";
    if(!gBingoCard.Check(DrawnBall))
    {
      Bingo = true;
      std::cout << "Bingo!" << std::endl;
      std::cout << "Took: " << gBingoCage.NumDraws << " draws." << std::endl;
    }
    DrawnBall = gBingoCage.Draw();
  }
  std::cout << std::endl;


  //  gBingoCage.Restart();
  //  gBingoCage.Print();

  return 0;  
}
