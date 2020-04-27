/*

Playlist.cpp

Group 3 Members: Hunter Bell, Tariq Green, Darrell Brown, Christian Pierre Paul

Date Last Edited: 04/20/20

*/

  #include <iostream>

	#include <iomanip>

	#include <vector>

	#include <fstream>

  #include <string>

	#include "Playlist.h"

	#include "Song.h"

	#include "StringHelper.h"

	

  using namespace std;

	

	char Playlist::option = 'N'; 

	

	

  /**************************************************************

	 *                         addsong                                                                                   

	 * Passed   : 1 argument: object of song class                                     

	 * Purpose  : To add songs to vector(playlist)                 

	 * Returns  : Void                                     

	**************************************************************/

	void Playlist::addSong(Song &s)

	{

	songs.push_back(s); // Songs pushed back in vector

	}

	



 /**************************************************************

	 *                          deleteSong                                                                                    

	 * Passed   : 1 argument: object of song class                                         

	 * Purpose  : removes song from vector(playlist)                

	 * Returns  : Void                                     

	**************************************************************/	

	void Playlist::deleteSong(Song &s)

	{

	

	bool song=false;

	

	for (int i = 0; i < songs.size(); i++)

	 {

	if (songs[i] == s)

	  {

	song=true;

	songs.erase(songs.begin() + i);

	  }

	 }

	}



   /**************************************************************

	 *                          getplaylistsong                                                                                   

	 * Passed   : 1 argument: object of song class                                         

	 * Purpose  : gets songs from playlist              

	 * Returns  : vector of songs                                  

	**************************************************************/	

	vector<Song> Playlist::getplaylistsongs()

	{

	return songs;

	}



	/**************************************************************

	 *                          intersect                                                                                 

	 * Passed   : 1 argument: object of playlist class                                         

	 * Purpose  : intersects two playlists                

	 * Returns  : Void                                     

	 **************************************************************/

	Playlist Playlist::intersect(Playlist &p)

	{

	

	Playlist obj;

	bool playlist;

	vector<Song> temp = p.getplaylistsongs();

	playlist = false;	

	

	for (int i = 0; i < songs.size(); i++) 

	{ 

	for (int j = 0; j < temp.size(); j++)

	{

	if (songs[i] == temp[j] && linearsearch(obj.getplaylistsongs(), songs[i]))

	

	playlist = true;

	

	obj.addSong(songs[i]);

	}

	}

	return obj;

	}



  /**************************************************************

	 *                          play                                                                                    

	 * Passed   : Void                                         

	 * Purpose  : Outputs song depending on player mode                

	 * Returns  : Void                                     

	 **************************************************************/

	void Playlist::play() 

	{

	if (option == 'N')

	{

	currentsong++;

	if (currentsong < songs.size())

	cout << "Now Playing: " <<songs[currentsong] << endl;

	else

	cout << "No more songs in playlist." << endl;

	}

	else if (option == 'R')

	{

	cout << songs[currentsong] << endl;

	}

	else if (option == 'L')

	{

	currentsong++;

	if (currentsong > songs.size())

	currentsong = 0;

	cout << "Now Playing: "  <<songs[currentsong] << endl;

	}

	}

	



   /**************************************************************

	 *                          mode                                                                                    

	 * Passed   : 1 argument: character                                        

	 * Purpose  : changes player modes            

	 * Returns  : Void                                     

	 **************************************************************/



	void Playlist::mode(char option)

	{

	Playlist::option = option;

	}

	

  /**************************************************************

	 *                         linearsearch                                                                                   

	 * Passed   : 2 arguments: vector and song object                                     

	 * Purpose  : Linear search of songs           

	 * Returns  : Bool                                

	 **************************************************************/

	

	bool Playlist::linearsearch(vector<Song> b, Song &g)

	{

	bool exist;

	

	exist = false;

	for (int i = 0; i < b.size(); i++)

	if (b[i] == g)

	exist = true;

	return exist;

	}



/** adds song to playlist **/ 

  Playlist operator+(Playlist &p1, Song &s1)

	{

	Playlist p;

	p = p1;

	p.addSong(s1);

	return Playlist(p);

	}

	

 /*** adds two playlists together **/

	Playlist operator+(Playlist &p, Playlist &p1)

	{

	Playlist add;

	add = p;

	bool valid;

	vector<Song> temp = p1.getplaylistsongs();

	

	valid = false;

	

	for (int i = 0; i < temp.size(); i++)

	{

	

	valid = true;

	

	add.addSong(temp[i]);

	}

	return Playlist(add);

	}

	

  /** removes song from playlist **/

	Playlist operator-(Playlist &p1, Song &s1)

	{

	Playlist p;

	p = p1;

	p.deleteSong(s1);

	return p;

	}

	

  /** outputs songs from playlist **/

	ostream &operator<<(ostream &o, const Playlist &p)

	{

	for (int i = 0; i < p.songs.size(); i++)

	{

	o << p.songs[i];

	}

	return o;

	}



        /**************************************************************

	 *                        setPlaylistName                                                                              

	 * Passed   : 1 arguments: string                                     

	 * Purpose  : sets name of playlist          

	 * Returns  : Void                               

	 **************************************************************/

	

	void Playlist::setPlaylistName(string pname)

	{

	Pname = pname;

	}



         /**************************************************************

	 *                        getPlaylistName                                                                              

	 * Passed   : Void                                    

	 * Purpose  : gets name of playlist          

	 * Returns  : playlist name                           

	 **************************************************************/

	string Playlist::getPlaylistName()

	{

	return Pname;

	}

	

	//Constructors

	Playlist::Playlist()

	{

	Pname = "";

	}



	Playlist::Playlist(string name)

	{

	setPlaylistName(name);

	string play_listname = name + ".playlist";

	play_listname = (play_listname);

	

	fstream in;

	in.open(play_listname.c_str(), ios::in);

	Song s;

	int k = 0;

	while (in >> s)

	{

	

	songs.push_back(s);

	}

	in.close();

	}
