/*
Playlist.cpp
Group 3 Members: Hunter Bell, Tariq Green, Darrell Brown, Christian Pierre Paul
Date Last Edited: 04/20/20
*/

#include <iostream>
#include "Playlist.h"
#include "Song.h"
#include <fstream>
#include <string>
#include "StringHelper.h"

using namespace std;

struct songDetails
{
 string name;
 string filename;
};

void loadPlayList(vector<songDetails> &);
void showPlaylists(vector<songDetails> &);
void addNewPlaylist(string, vector<songDetails> &);
bool Menu(Playlist &);
void deleteSong(Playlist &);
void addSong(Playlist &);
void modeChange();
Playlist playlistObject;

int main()

{
 vector<songDetails> vectorOfSongs;
 loadPlayList(vectorOfSongs);
 Playlist playlistObject;
 int menuChoice;
 int selection;
 string newplaylist;

 cout << "-------WELCOME to the AutoPlayer----------" << endl;
 do
 {
 do
 {
 cout << "1 - Open an exisiting playlist" << endl;
 cout << "2 - Create new list" << endl;
 cout << "3 - Exit" << endl;
 cout << "Selection: ";
 cin >> menuChoice;
 } while (menuChoice != 1 && menuChoice != 2 && menuChoice != 3);

 if (menuChoice == 1)
 {
 cout << "Please select a playlist from below: " << endl;
 showPlaylists(vectorOfSongs);
   
 do
 {
 cout << "Selection: ";
 cin >> selection;
 if (selection < 1 || selection > vectorOfSongs.size())
 cout << "Invalid selection" << endl;
 } while (selection < 1 || selection > vectorOfSongs.size());
 cout << endl;
 Playlist p1(vectorOfSongs[selection - 1].name);
   
 Menu(p1);

 }
 else if (menuChoice == 2)
 {
 do
 {
 cout << "1 - Create new empty list" << endl;
 cout << "2 - Merge 2 exisitng playlists" << endl;
 cout << "3 - Intersect 2 exisinting playlists" << endl;
 cout << "Selection: ";
 cin >> selection;
 } while (selection != 1 && selection != 2 && selection != 3);

 cin.ignore();

 cout << "Name of new playlist (cannot contain underscores): ";
 getline(cin, newplaylist);
   
 switch (selection)
 {
 case 1:
 {

 Playlist p;
 p.setPName(newplaylist);
 addNewPlaylist(newplaylist, vectorOfSongs);
 Menu(p);
 }
 break;
 case 2:
 {
 cout << endl
 << "Which of the following playlists would you like to merge? " << endl;
 showPlaylists(vectorOfSongs);
 int listOfSongs[2];
 for (int i = 0, j = 1; j < 3; j++, i++)
 {
 do
 {
 cout << "Playlist " << j << ": ";
 cin >> listOfSongs[i];
 if (listOfSongs[i] < 1 || listOfSongs[i] > vectorOfSongs.size())
 cout << "Invalid selection" << endl;
   
 } while (listOfSongs[i] < 1 || listOfSongs[i] > vectorOfSongs.size());
 }


 Playlist p1(vectorOfSongs[listOfSongs[0] - 1].name);
 Playlist p2(vectorOfSongs[listOfSongs[1] - 1].name);

 Playlist p3 = p1 + p2;



 p3.setPName(newplaylist);
 addNewPlaylist(newplaylist, vectorOfSongs);
 while (Menu(p3));

 }
 break;
 case 3:
 {
 cout << endl << "Which of the following playlists would you like to intersect? " << endl;
 showPlaylists(vectorOfSongs);
 int listOfSongs[2];

 for (int i = 0, j = 1; j < 3; j++, i++)
 {
 do
 {
 cout << "Playlist " << j << ": ";
 cin >> listOfSongs[i;
 if (listOfSongs[i] < 1 || listOfSongs[i] > vectorOfSongs.size())
 cout << "Invalid selection" << endl;

 } while (listOfSongs[i] < 1 || listOfSongs[i] > vectorOfSongs.size());
 }

 Playlist p1(vectorOfSongs[listOfSongs[0] - 1].name);
 Playlist p2(vectorOfSongs[listOfSongs[1] - 1].name);

 Playlist p3 = p1.intersect(p2);

 addNewPlaylist(newplaylist, vectorOfSongs);
 while (Menu(p3));
 }
 break;
 }

 cout << endl;
 }
 } while (menuChoice != 3);

 return 0; //terminates program
}

/**************************************************************
	*                   showPlaylists
	* Passed : 1 argument: song vector
	* Purpose : displays playlists 
	* Returns : Void
	**************************************************************/
	void showPlaylists(vector<songDetails> &vectorOfSongs)
	{
	for (int i = 0, j = 1; ir < vectorOfSongs.size(); i++, j++)
	cout << j << " " << vectorOfSongs[i].name << endl;
	}
fp
	/**************************************************************
	*                     loadPlaylist 
	* Passed : 1 argument: song vector
	* Purpose : loads playlists for menu
	* Returns : Void
	**************************************************************/
	void loadPlayList(vector<songDetails> &vectorOfSongs)
	{
	
	ifstream in;
	in.open("Playlist.list");
	string filename;
	if (in)
	{
	
	while (in >> filename)
	{
	
	songDetails l = {StringHelper::utos(filename), filename};
	vectorOfSongs.push_back(l);
	}
	}
	else
	{
	cout << "Could not open Playlist.list" << endl;
	}
	in.close();
	}

	/**************************************************************
 	*                         Menu 
	* Passed : 1 argument: song object 
	* Purpose : displays menu
	* Returns : bool
	**************************************************************/
	bool Menu(Playlist &playlist)
	{
	bool menuOption;
	char menuChoice;
	
	do
	{
	menuOption = true;
	
	cout << "You are now playing: " << playlist.getPlaylistname() << endl;
	cout << "A - Add a song" << endl;
	cout << "D - Delete a song" << endl;
	cout << "P - Play a song" << endl;
	cout << "M - Set the mode" << endl;
	cout << "S - Show all songs" << endl;
	cout << "Q - Quit" << endl
	<< "Selection: " << endl;
	cin >> menuChoice;
	
	switch (toupper(menuChoice))
	{
	case 'A':
	addSong(playlist);
	break;
	case 'D':
	deleteSong(playlist);
	break;
	case 'P':
	{
	cout << endl;
	cout << "NOW PLAYING:" << endl;
	playlistObject.play();
	}
	
	break;
	
	case 'M':
	modeChange();
	break;
	
	case 'S':
	{
	std::vector<Song> temp = playlist.getSong();
	
	for (int i = 0; i < temp.size(); i++)
	cout << temp[i] << endl;
	}
	
	break;
	}
	} while (menuChoice != 'Q' && menuChoice != 'q');
	return true;
	}
	
	
	/**************************************************************
	*                       addNewPlaylist
	* Passed : 2 arguments: string and vector of songs 
	* Purpose : adds a new playlist 
	* Returns : Void
	**************************************************************/
	void addNewPlaylist(string playlistName, vector<songDetails> &v_song)
	{
	songDetails listOfSongs = {playlistName, StringHelper::stou(playlistName)};
	v_song.push_back(listOfSongs);
	ofstream out;
	out.open("Playlist.list", ios::app);
	out << StringHelper::stou(playlistName) << endl;
	out.close();
	}
	
	/**************************************************************
	*                           addSong 
	* Passed : 1 argument: object of playlist class
	* Purpose : adds song to playlist 
	* Returns : Void
	**************************************************************/
	void addSong(Playlist &playlist)
	{
	cin.ignore();
	Song s; // Create song playlistObjectect
	cin >> s;
	string name = playlist.getPlaylistName();
	name + ".playlist";
	name = StringHelper::stou(name);
	
	playlist.addSong(s);
	ofstream out;
	
	out.open(name.c_str(), ofstream::app);
	out << s;
	}
	
	/**************************************************************
	*                      deleteSong 
	* Passed : 1 argument: object of playlist class 
	* Purpose : removes song from playlist 
	* Returns : Void 
	**************************************************************/
	void deleteSong(Playlist &playlist)
	{
	cin.ignore();
	string title, artist;
	cout << "Enter to delete: " << endl;
	cout << "Title: ";
	getline(cin, title);
	cout << "Artist: ";
	getline(cin, artist);
	
	Song delete_s(title, artist, "", 0, 0);
	playlist.deleteSong(delete_s);
	
	string name = playlist.getPlaylistName();
	name + ".playlist";
	name = StringHelper::stou(name);
	
	ofstream out;
	
	out.open(name.c_str());
	
	playlist.getSong();
	std::vector<Song> temp = playlist.getSong();
	
	for (int i = 0; i < temp.size(); i++)
	out << temp[i] << endl;
	}
	
	/**************************************************************
	*                         modeChange 
	* Passed : Void
	* Purpose : changes playlist mode
	* Returns : Void
	**************************************************************/
	void modeChange()
	{
	bool good;
	
	do
	{
	good = true;
	
	cout << "Enter mode: " << endl;
	cout << "N - Normal" << endl;
	cout << "R - Repeat" << endl;
	cout << "L - Loop" << endl
	<< "Selection: " << endl;
	char menuOption;
	cin >> menuOption;
	
	switch (toupper(menuOption))
	{
	case 'N':
	Playlist::mode(0);
	break;
	case 'R':
	Playlist::mode(1);
	break;
	case 'L':
	Playlist::mode(2);
	break;
	default:
	good = false;
	}
	} while (!good);
	}





