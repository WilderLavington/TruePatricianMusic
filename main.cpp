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
 #include <algorithm>.

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
    std::string line;
	std::ifstream backstory ("mu.txt");
	if (backstory.is_open())
	{
		while (backstory.good())
		{
			getline(backstory,line);
			lines++;
		}
		backstory.close();
	}
	else
	{
		std::cout << "Unable to open file" << std::endl << std::endl;
	}
	//cout<<lines<<endl;
    //read txt file then store in array of structs for easy access
    InfoStorage Music[lines-1];
    int counter = 0;
    //kill first line
    std::string line1;
	std::ifstream backstory1 ("mu.txt");
	if (backstory1.is_open())
	{
		while (backstory1.good())
		{
			getline(backstory1,line1);
            vector<string> v;
            string s = line1;
            split(s, '@', v);
            for (int p = 0; p<v.size();p++)
            {
            if(p%3==0)
                {
                Music[counter].genre = v[p];
                }
            else if (p%2==0)
                {
                int newValue = atoi(v[p].c_str());
                Music[counter].rating = newValue;
                }
            else if (p==0)
                {
                Music[counter].artist = v[p];
                }
            else
                {
                Music[counter].album = v[p];
                }
            }counter++;//cout<<counter;
		}
		backstory.close();
	}
	else
	{
    std::cout << "Unable to open file" << std::endl << std::endl;
	}
    //now store each struct in music to genre
    vector<std::string> genres;
    for(int h = 0;h<lines-1;h++)
    {
        //check contains
        //cout<<Music[h].genre;
        if (std::find(genres.begin(), genres.end(), Music[h].genre) == genres.end())
        {
        genres.push_back( Music[h].genre);
        }
    }

    //cout<<genres.size()<<endl;
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
    cout<<"4. Delete some pleb tier shite"<<endl;
    cout<<"5. Add user"<<endl;
    cout<<"6. Delete your shite account and shite taste"<<endl;
    cout<<"7. Top 3 true patricians lmao ayyy"<<endl;
    cout<<"8. GET OFF THE FUCKING BOARD"<<endl;
}

