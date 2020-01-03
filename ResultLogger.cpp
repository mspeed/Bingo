#include "ResultLogger.h"

ResultLogger::ResultLogger(std::string const &FileName)
{
  // Open a results file.
  OutputStream.open(FileName.c_str());
}

void ResultLogger::LogValue(int Count)
{
  OutputStream << Count << ", ";
}

void ResultLogger::Close()
{
  OutputStream.close();
}

