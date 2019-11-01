

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
    Song();

    Song(std::string artist, std::string title, int size);

    int getSize() const;
    string getArtist() const;
    string getTitle() const;
    bool operator > (Song const &RHS);
    bool operator < (Song const &RHS);
    bool operator == (Song const &RHS);
    void swap(Song &song2);

};


#endif //LAB5UTPOD_SONG_H
