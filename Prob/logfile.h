#ifndef LOGFILE_H
#define LOGFILE_H

#include <fstream>
#include <iostream>

using namespace std;

class logfile
{
    public:
        logfile();
        ~logfile();
       void addLog(string log); //для вывода
    private:
   	 ofstream *outputFile;
   	 static bool clearFile;
};

#endif
