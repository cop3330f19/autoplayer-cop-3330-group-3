/*

Playlist.h

Group 3 Members: Hunter Bell, Tariq Green, Darrell Brown, Christian Pierre Paul

Date Last Edited: 04/20/20

*/



#ifndef PLAYLIST_H

#define PLAYLIST_

#include <cstdlib>

#include <string>

#include "Song.h"

#include <iostream>

#include <vector>

	

class Playlist

{

private:

static char option;

int currentsong;

std::string Pname;

std::vector<Song> songs;

		

public:

void addSong(Song &);

void deleteSong(Song &);

Playlist intersect(Playlist &);

void play();

static void mode(char);

bool linearsearch(std::vector<Song>, Song &);

friend Playlist operator+(Playlist &, Song &);

friend Playlist operator+(Playlist &, Playlist &);

friend Playlist operator-(Playlist &, Song &);

friend std::ostream &operator<<(std::ostream &, const Playlist &);

std::vector<Song> getplaylistsongs();

void setPlaylistName(std::string);

std::string getPlaylistName();

Playlist();

Playlist(std::string);

};

#endif



