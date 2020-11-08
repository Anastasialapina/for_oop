#include "logfile.h"
bool logfile::clearFile = true;

logfile::logfile()
{
if (clearFile){ 
    outputFile = new ofstream("Logic.txt", ios_base::trunc); // открываем, удаляем содержимое файла, если он существует
    clearFile=false;
    }
else{ 
    outputFile = new ofstream("Logic.txt", ios_base::app); // открываем для записи в конец
    clearFile = false;
    }
}

logfile::~logfile()
{
    outputFile->close();
}


void logfile::addLog(string log)
{
    *outputFile << "LOG:\t" << log << '\n';
}

