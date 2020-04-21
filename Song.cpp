#include "Song.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

//constructors
 Song::Song()
 {
     title="";
     artist="";
     album="";
     length=0;
     year=0;
 }
 Song::Song(string title, string artist, string album, int year, int length)
 {
   this->title=title;
   this->artist=artist;
   this->album=album;
   this->year=year;
   this->length=length;

 }

 //Set Song
 void Song::set(string title, string artist, string album, int year, int length)
 {
   this->title=title;
   this->artist=artist;
   this->album=album;
   this->length=length;
   this->year=year;
 }

// output the song in the format:
		// title, artist, album, year, length
		// output to console
		ostream& operator<<(ostream& os, const Song& song)     
        {
            int p1=song.length/60;
            int p2=(song.length%60);
            os <<song.title <<endl;
            os <<song.artist <<endl;
            os <<song.album <<"(" << p1 <<":"<< p2 <<")" << endl;
            os <<song.year;
            return os;
        }

		//output to file
		ofstream& operator<<(ofstream& os, const Song& song)
        {
            int p1=song.length/60;
            int p2=(song.length%60);
            
            os <<song.title << ',';
            os <<song.artist << ',';
            os <<song.album << ',';
            os <<song.year << ',';
            os <<song.length;
            //os <<p1 <<":"<< p2 << endl;
            
            return os;
        }

		// input the song in the format:
		// title, artist, album, year, length
		istream& operator>>(istream& is, Song& song)
        {
            cout << "Title: ";
            is >> song.title;
            cout << "Artist: ";
            is >>song.artist;
            cout << "Album: ";
            is >> song.album;
            cout << "Year: ";
            is >> song.year;
            cout << "Length (in seconds): ";
            is >> song.length;
            return is;
        }

		//input from file
		fstream& operator>>(fstream& is, Song& song)
        {
            
            //reads from file and sets each value of the 
            //object equal to its perspective value
            string y, l; //song.year and song.length in string form
            
            getline(is ,song.title,',');
            getline(is ,song.artist,',');
            getline(is ,song.album,',');
            getline(is ,l,',');
            getline(is ,y);
            
            return is;
        }

		// compare two song objects for equality
		bool operator==(const Song& lhs, const Song& rhs)
        {
            bool c=false;
            
            if ((lhs.title==rhs.title) && (lhs.artist==rhs.artist) 
                && (lhs.album==rhs.album) && (lhs.length==rhs.length) && (lhs.year==rhs.year))
            {
                c=true;
            }
            return c;
        }
