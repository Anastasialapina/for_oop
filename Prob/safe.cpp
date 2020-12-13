#include "safe.h"

bool safe::clearFile = true;

safe::safe(int mode)
{
if (clearFile){ 
    std::ofstream outputFile("Safe.txt", std::ofstream::trunc); // открываем, удаляем содержимое файла, если он существует
    clearFile=false;
    }
else{ 
    std::ofstream outputFile ("Safe.txt",  std::ofstream::app); // открываем для записи в конец
    clearFile = false;
    }

/*else {
std::ofstream outputFile ("Safe.txt",  std::ofstream::in); // открываем для записи в конец
    clearFile = false;

}
*/


}

safe::~safe()
{
    outputFile.close();
}

void safe::check(){
/* if(!feof(outputFile))
{  
            std::string line;
        while (getline(outputFile, line))
        {
            std::cout << line << std::endl;
        }
    cout<<"GGG";
}  */
}


void safe::addLog(string log)
{
   outputFile << log ;
}

