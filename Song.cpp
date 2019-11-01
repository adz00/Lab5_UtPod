//
// Created by srira on 10/21/2019.
//

#include "Song.h"

//default constructor for Song
Song::Song()
{
    sizeInMB = 0;
    artist = "";
    title = "";
}

//constructor for Song with parameters
Song::Song(string artist, string title, int size)
{
    this->sizeInMB = size;
    this->artist = artist;
    this->title = title;
}

//gets size of song
//inputs: none
//outputs: sizeInMB
int Song::getSize() const
{
    return sizeInMB;
}

//gets artist of song
//inputs: none
//outputs: artist
string Song::getArtist() const
{
    return artist;
}

//gets title of song
//inputs: none
//outputs: title
string Song::getTitle() const
{
    return title;
}

//sets size of song
//inputs: desired size
//outputs: none
void Song::setSize(int size) {
    sizeInMB = size;
}

//sets artist of song
//inputs: desired artist
//outputs: none
void Song::setArtist(string artist) {
    this->artist = artist;
}

//sets title of song
//inputs: desired title
//outputs: none
void Song::setTitle(string title) {
    this->title = title;
}

//overloads > operator
bool Song::operator > (Song const &RHS)
{
    if(artist >  RHS.getArtist()) {
        return true;
    }
    else if(artist == RHS.getArtist())
    {
        if(title > RHS.getTitle())
        {
            return true;
        }
        else if(title == RHS.getTitle())
        {
            if(sizeInMB > RHS.getSize())
            {
                return true;
            }
        }
    }
    return (false);
}

//overloads < operator
bool Song::operator < (Song const &RHS)
{
    if(artist <  RHS.getArtist())
    {
        return true;
    }
    else if(artist == RHS.getArtist())
    {
        if(title < RHS.getTitle())
        {
            return true;
        }
        else if(title == RHS.getTitle())
        {
            if(sizeInMB < RHS.getSize())
            {
                return true;
            }
        }
    }
    return (false);
}

//overloads == operator
bool Song::operator == (Song const &RHS)
{
    return(sizeInMB == RHS.getSize() && title == RHS.getTitle() && artist == RHS.getArtist());
}

//swaps 2 songs in a linked list
//inputs: song to be swapped
//outputs: none
void Song::swap(Song &song2)
{
    Song temp = song2;
    song2 = *this;
    *this = temp;
}