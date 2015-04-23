#include <iostream>
#include "TruePatricianMusic.h"
 #include <fstream>
 #include <sstream>
 #include <string>
 #include <iomanip>
 #include <locale>
 #include <vector>
 #include <algorithm>
 #include <cstdlib> //the standard C library header
using namespace std;

void mainMenu();
void split(const string& s, char c,vector<string>& v)
{
   string::size_type i = 0;
   string::size_type j = s.find(c);

   while (j != string::npos) {
      v.push_back(s.substr(i, j-i));
      i = ++j;
      j = s.find(c, j);

      if (j == string::npos)
         v.push_back(s.substr(i, s.length()));
   }
}

struct InfoStorage
{
    string artist;
    string album;
    int rating;
    string genre;
};
int main()
{
    bool OGRaps= true;
    //find size of file
    int lines = 0;
    string line;
    ifstream inFile("mu.txt");while(getline(inFile, line)){lines++;};inFile.close();
    //read txt file then store in array of structs for easy access
    InfoStorage Music[lines-1];
    //OGRaps are always true
    if(OGRaps)
    {
    //kill first line
    string line;
    ifstream inFile("mu.txt");
     if (inFile.good())
     {
          getline(inFile, line);
     }
     //fill struct
    string line1;
    int counter = 0;

    while(getline(inFile, line1))
    {
    vector<string> v;
    string s = line1;
    split(s, ',', v);
    for (int p = 0; p<v.size();p++)
    {
    if(!(p+1)%2)
        {
        Music[counter].album = v[p];
        }
    else if (!(p+1)%3)
        {
            int newValue = atoi(v[p].c_str());
            Music[counter].rating = newValue;
        }
    else if (!(p+1)%4)
    {
        Music[counter].genre = v[p];
    }
    else if (p==0)
    {
        Music[counter].artist = v[p];
    }
    counter++;
} inFile.close();}

}

    string option = " ";
    while(option!="8"){
        option.erase();
        int invalid = 0;
        while(option!="1"&&option!="2"&&option!="3"&&option!="4"&&option!="5"&&
              option!="6"&&option!="7"&&option!="8"){
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
    cout<<"======/mu/ menu, Duck you======="<<endl;
    cout<<"1. R8 my taste!"<<endl;
    cout<<"2. Recommend me some tunes pls"<<endl;
    cout<<"3. Add music to the library"<<endl;
    cout<<"4. Delete some pleb tier shit"<<endl;
    cout<<"5. Add user"<<endl;
    cout<<"6. Delete your shit account and shit taste"<<endl;
    cout<<"7. Top 3 true patricians lmao ayyy"<<endl;
    cout<<"8. GET OFF THE FUCKING BOARD"<<endl;
}
