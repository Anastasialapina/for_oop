#ifndef RUN_H
#define RUN_H

#include <fstream>
#include <iostream>
#include <string>

class run
{
    public:
        run();
        ~run();
       int check();
       int count;
       void starting(std::string arr[19]);
    private:
   	 std::fstream outputFile;
};

#endif
