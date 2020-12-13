#ifndef SAFE_H
#define SAFE_H

#include <fstream>
#include <iostream>

using namespace std;

class safe
{
    public:
        safe(int clearFile);
        ~safe();
       void addLog(string log); //для вывода
       static bool clearFile;
       void check();
    private:
   
   	 ofstream outputFile;
   	 //static bool clearFile;
};

#endif
