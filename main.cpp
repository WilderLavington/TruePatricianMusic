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
            if (p==0)
                {
                Music[counter].artist = v[p];
                }
            else if(p%3==0)
                {
                Music[counter].genre = v[p];
                }
            else if (p%2==0)
                {
                int newValue = atoi(v[p].c_str());
                Music[counter].rating = newValue;
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
    //find all genres
    vector<std::string> genres;
    for(int h = 0;h<lines-1;h++)
    {
        if (std::find(genres.begin(), genres.end(), Music[h].genre) == genres.end())
        {
        genres.push_back( Music[h].genre);
        }
    }
    //sort Info storage with hash function
    //create seperate hash tables for each genre
    //also clone genres, might use later
    vector <string> genre = genres;
    while(!genre.empty())
{ HashMap hash;
    string current = genre.back();
    string Folder = "Genres//";
    genre.pop_back();
    for(int t = 0;t<lines-1;t++)
    {
        //need to create hash key to run through insert
        int key = Music[t].rating;
        string stuff = Music[t].artist;
        string value = Music[t].album;
        value +=":";
        value += stuff;
        //cout<<stuff;
        //cout<<value<<endl;
        hash.Insert(key, value);
    }
    //now run through current hashmap, and push into vector now ordered by rating
    //call it current->append txt
    current  = current.append(".txt");
    Folder = Folder.append(current);
    //then store ordered values in txt file
    ofstream myfile;
    myfile.open (Folder);
    if (myfile.is_open())
    {
    for(int k = 0; k<128;k++)
    {
        HashNode * temp = hash.access(k);
        if(temp)
        {while(temp->next)
        {
        string tempvalue;
        tempvalue = temp->value;
        myfile << k;
        myfile << ": ";
        myfile << tempvalue;
        myfile << "\n";
        temp = temp->next;
        }}
    }
    myfile.close();
    }
}
//now we push all genres off stack and then put every thing instorage into Genre
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
                cout<<"what is your favorite genre"<<endl;
            string input;
            cin>>input;
            input = input.append(".txt");
            std::string line;
            std::ifstream backstory (input);
            if (backstory.is_open())
            {
                while (backstory.good())
                {
                getline(backstory,line);
                vector<string> v;
                split(line, ' ', v);
                for(int i = 0;i<v.size();i++)
                {
                cout<<v[i]<<" "<<endl;
                }
                cout<<endl;
                }
            backstory.close();
                }
            else
            {
		std::cout << "Give us a real genre fool" << std::endl << std::endl;
            }

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
    cout<<"8. GET OFF THE DUCKING BOARD"<<endl;
}
