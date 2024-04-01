#include "Next.hpp"

void Next::useCommand(){
    cout<<"\033[1;96m\nGo to the next player!\033[0m"<<endl;
}

string Next::getName(){
    return "NEXT";
}