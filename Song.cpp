//
// Created by srira on 10/21/2019.
//

#include "Song.h"

Song::Song()
{
    sizeInMB = 0;
    artist = "";
    title = "";
}

Song::Song(std::string artist, std::string title, int size)
{
    this->sizeInMB = size;
    this->artist = artist;
    this->title = title;
}

int Song::getSize() const
{
    return sizeInMB;
}

string Song::getArtist() const
{
    return artist;
}

string Song::getTitle() const
{
    return title;
}
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
bool Song::operator == (Song const &RHS)
{
    return(sizeInMB == RHS.getSize() && title == RHS.getTitle() && artist == RHS.getArtist());
}
void Song::swap(Song &song2)
{
    Song temp = song2;
    song2 = *this;
    *this = temp;
}