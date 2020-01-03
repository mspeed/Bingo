#ifndef _RESULTLOGGER_H_
#define _RESULTLOGGER_H_

#include<string>
#include<fstream>

class ResultLogger
{

 public:
  ResultLogger(std::string const &FileName);

  void LogValue(int Count);
  void Close();
  
 private:

  std::ofstream OutputStream;
};



#endif
