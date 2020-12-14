#include "safe.h"
bool safe::clearFile = true;

safe::safe()
{
if (clearFile){ 
    //outputFile = new ofstream("Safe.txt", std::fstream::out | std::fstream::trunc); // открываем, удаляем содержимое файла, если он существует
     outputFile = new ofstream ("Safe.txt", std::ios::out|std::ios::trunc); // открываем, удаляем содержимое файла, если он существует
    clearFile=false;
    }
else{ 
    outputFile = new ofstream ("Safe.txt", std::ios::app|std::ios::in); 
    //outputFile = new ofstream("Safe.txt", std::fstream::out | std::fstream::in); // открываем для записи в конец
    clearFile = false;
    }
    
}

safe::~safe()
{
    outputFile->close();
}

void safe::check(){
 if(!feof((FILE *)outputFile))
{  
           /* std::string line;
            std::getline((std::stringstream&)*outputFile, line);*/
       /* while (getline(*outputFile, line))
        {
            std::cout << line << std::endl;
        }*/
   
}  
}


void safe::addLog(string log)
{
    *outputFile << log ;
}

