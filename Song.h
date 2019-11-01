

#ifndef LAB5UTPOD_SONG_H
#define LAB5UTPOD_SONG_H
#include <string>

using namespace std;


class Song {

private:
    int sizeInMB;
    string artist;
    string title;

public:
    //default constructor for Song
    Song();

    //constructor for Song with parameters
    Song(std::string artist, std::string title, int size);

    //gets size of song
    //inputs: none
    //outputs: sizeInMB
    int getSize() const;

    //gets artist of song
    //inputs: none
    //outputs: artist
    string getArtist() const;

    //gets title of song
    //inputs: none
    //outputs: title
    string getTitle() const;

    //sets size of song
    //inputs: desired size
    //outputs: none
    void setSize(int size);

    //sets artist of song
    //inputs: desired title
    //outputs: none
    void setArtist(string artist);

    //sets title of song
    //inputs: desired title
    //outputs: none
    void setTitle(string title);

    //overloads > operator
    bool operator > (Song const &RHS);

    //overloads < operator
    bool operator < (Song const &RHS);

    //overloads == operator
    bool operator == (Song const &RHS);

    //swaps 2 songs in a linked list
    //inputs: song to be swapped
    //outputs: none
    void swap(Song &song2);

};


#endif //LAB5UTPOD_SONG_H
