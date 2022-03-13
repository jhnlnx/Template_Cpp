#include "customLib.hpp"
#include <iostream>

int main(int argc, char** argv){

    std::cout<<"Dummy Run\n";
    for(int i=0; i<argc;i++)
        std::cout<<argv[i]<<'\n';

    Dummy d;
    d.hello();
}