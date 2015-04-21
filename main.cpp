#include <iostream>
#include "TruePatricianMusic.h"
using namespace std;

void mainMenu();

int main()
{
    string option = " ";
    while(option!="8"){
        option.erase();
        int invalid = 0;
        while(option!="1"&&option!="2"&&option!="3"&&option!="4"&&option!="5"&&option!="6"&&option!="7"&&option!="8"){
            if(invalid>0){
                cout<<"Invalid Input"<<endl;
            }
            mainMenu();
            getline(cin,option);
            invalid++;
        }
        if(option=="1"){
        }
        else if(option=="2"){
        }
        else if(option=="3"){
        }
        else if(option=="4"){
        }
        else if(option=="5"){
        }
        else if(option=="6"){
        }
        else if(option=="7"){
        }
    }
    cout<<"Fuck off lol"<<endl;
}

void mainMenu(){
    cout<<"======/mu/ menu, fuck you======="<<endl;
    cout<<"1. R8 my taste!"<<endl;
    cout<<"2. Recommend me some tunes pls"<<endl;
    cout<<"3. Add music to the library"<<endl;
    cout<<"4. Delete some pleb tier shit"<<endl;
    cout<<"5. Add user"<<endl;
    cout<<"6. Delete your shit account and shit taste"<<endl;
    cout<<"7. Top 3 true patricians lmao ayyy"<<endl;
    cout<<"8. GET OFF THE FUCKING BOARD"<<endl;
}
