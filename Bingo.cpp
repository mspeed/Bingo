#include <iostream>

#include "BingoCage.h"
#include "BingoCard.h"
#include "ResultLogger.h"

int main(int argc, char * argv[])
{

  if(argc != 5)
  {
    std::cout << "Usage: " << argv[0];
    std::cout << " <Num Balls> <Numbers on Cards> <Num Tests> <Results Filename>";
    std::cout << std::endl;
    return -1;
  }
  
  const int NumBalls = atoi(argv[1]);
  const int NumbersOnCards = atoi(argv[2]);
  const int NumTests = atoi(argv[3]);
  const std::string ResultsFilename(argv[4]);
  
  BingoCage Cage(NumBalls);
  BingoCard Card(NumbersOnCards, NumBalls);
  ResultLogger Logger(ResultsFilename);

  int DrawnBall;
  
  for(int i = 0; i < NumTests; i++)
  {  

    DrawnBall = Cage.Draw();
    while(Card.Check(DrawnBall))
    {
      DrawnBall = Cage.Draw();
    }
        
    Logger.LogValue(Cage.NumDraws);    
    Cage.Restart();
    Card.Restart();
  }  
  
  Logger.Close();

  return 0;  
}
