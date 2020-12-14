#include "run.h"

run::run()
{
    outputFile.open("Safe.txt", std::fstream ::in); // открываем для чтения
    
}

run::~run()
{
    outputFile.close();
}

int run::check(){
 if(outputFile.is_open()){  
        std::string line;
        count = 0;
        while (getline(outputFile, line))
        {
            count++;
        }
        std::cout << count<< "\n";
        if (line=="WIN"||line=="LOST"||count==0)
            //std::cout << "Нельзя\n";
            return 0;
        else return 1;
}  

}

void run::starting(std::string arr[19]){
     outputFile.close();
     outputFile.open("Safe.txt", std::fstream ::in);
     if(outputFile.is_open()){  
         std::string line;
         for (int i = 0; i<count-19;i++)
             getline(outputFile, line);
         for (int i = 0; i<19; i++){
            getline(outputFile, line);
            arr[i] = line;
         }
       } 
}

