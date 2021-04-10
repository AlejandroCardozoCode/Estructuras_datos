#include <iostream>
#include <fstream>
#include "quadtree.h"
#include "quadnodo.h"
#include <string>
#include <ctime>
#include <set>
#include <list>

int main(int argc, char *argv[])
{
    std::string v = "202002100012102001001";
    for (int i = 0; i <= v.size(); i++)
    {
        std::cout << v[i];
        if(v[i] == '2')
        {
            std::cout << std::endl;
        }
    }
    
}