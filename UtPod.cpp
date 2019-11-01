//
// Created by srira on 10/21/2019.
//

#include "UtPod.h"
#include <iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

//Default constructor
//set the memory size to MAX_MEMORY
UtPod::UtPod() {
    memSize = MAX_MEMORY;
    songs = NULL;
}

//Constructor with size parameter
//The user of the class will pass in a size.
//If the size is greater than MAX_MEMORY or less than or equal to 0,
//set the size to MAX_MEMORY.
UtPod::UtPod(int size) {
    unsigned int currentTime = (unsigned)time(0);
    if((size > MAX_MEMORY) || (size < 0)) {
        memSize = MAX_MEMORY;
    }
    else {
        memSize = size;
    }
    srand(currentTime);
    songs = NULL; // initialize the linked list
}

/* FUNCTION - int addSong
 * attempts to add a new song to the UtPod
     o returns a 0 if successful
     o returns -1 if not enough memory to add the song

 precondition: s is a valid Song

 input parms - pointer to a song

 output parms - integer that conveys success of the song
*/
int UtPod::addSong(Song const &s) {
    if (s.getSize() <= 0 || s.getArtist() == "" || s.getTitle() == "") {
        cout << "Song is not valid" << endl;
        return NO_MEMORY;
    }

    if(getRemainingMemory() >= s.getSize()) {
        SongNode *newNode = new SongNode; // new songNode that we will add to UtPod
        newNode->s = s;
        newNode->next = songs;
        songs = newNode;
        return SUCCESS;
    }
    else { // not enough memory for the new Song
        return NO_MEMORY;
    }
}

/* FUNCTION - int removeSong
 * attempts to remove a song from the UtPod
 * removes the first instance of a song that is in the the UtPod multiple times
     o returns 0 if successful
     o returns -1 if nothing is removed


   input parms - pointer to a song

   output parms - integer that conveys success of the song
*/
int UtPod::removeSong(Song const &s) {
    SongNode *prevPtr = songs;

    if(songs == NULL) {
        return NOT_FOUND;
    }
    SongNode *ptr = prevPtr->next;
    if(prevPtr->s == s) {
        songs = ptr;
        delete(prevPtr);
        return SUCCESS;
    }

    while(ptr != NULL) {
        if(ptr->s == s) {
            if(ptr->next == NULL) { // we are deleting last element of the linked list
                prevPtr->next = NULL;
                delete(ptr);
            }
            else {
                prevPtr->next = ptr->next;
                delete(ptr);
            }
            return SUCCESS; // successful removal
        }
        ptr = ptr->next;
        prevPtr = prevPtr->next;
    }
    return NOT_FOUND;
}

/* FUNCTION - void shuffle
     *  shuffles the songs into random order
        o will do nothing if there are less than two songs in the current list

       input parms - none

       output parms - none
    */
void UtPod::shuffle() {
    srand(time(0));
    int count = 0;
    SongNode *ptr = songs;
    while(ptr != NULL) { // count the number of songs in the UtPod
        count++;
        ptr = ptr->next;
    }
    for(int i = 0; i < count * 10; i++) {
        int random1 = rand() % count; // generates 2 numbers between 0 and the number of songs, inclusive
        int random2 = rand() % count;

        ptr = songs;
        int j = 0;
        while(j < random1)
        {
            ptr = ptr->next;
            j++;
        }
        SongNode *ptr2 = songs;
        j = 0;
        while(j < random2)
        {
            ptr2 = ptr2->next;
            j++;
        }

        // now ptr and ptr2 should be pointers to two random nodes that should be swapped

        (ptr->s).swap(ptr2->s); // swap the two songNodes
    }
}

/* FUNCTION - void showSongList
 * prints the current list of songs in order from first to last to standard output
 * format - Title, Artist, size in MB (one song per line)

   input parms - none

   output parms - none
*/
void UtPod::showSongList() {
    if (songs==NULL) {
        cout << "There are no songs on the UtPod right now" << endl;
    }
    SongNode *ptr = songs;

    while(ptr != NULL) {
        cout << (ptr->s).getArtist() << ", " << (ptr->s).getTitle() << ", " << (ptr->s).getSize() << endl;
        ptr = ptr->next;
    }
    cout << endl;
}

/* FUNCTION - void sortSongList
 *  sorts the songs in ascending order
    o will do nothing if there are less than two songs in the current list

   input parms - none

   output parms - none
*/
void UtPod::sortSongList() {
    for(SongNode *p1 = songs; p1 != NULL; p1 = p1->next) {
        for(SongNode *p2 = p1->next; p2 != NULL; p2 = p2->next) {
            if(p2->s < p1->s) {
                p1->s.swap(p2->s);
            }
        }
    }
}

/* FUNCTION - void clearMemory
 * clears all the songs from memory

   input parms - none

   output parms - none
*/
void UtPod::clearMemory() {
    SongNode *ptr = songs;
    while(ptr != NULL) {
        SongNode *temp = ptr; // copy of the current Song Node
        ptr = ptr->next;
        delete(temp);
    }
    songs = NULL;
}

/* FUNCTION - int getRemainingMemory
 *  returns the amount of memory available for adding new songs

   input parms - none

   output parms - integer for total remaining memory
*/
int UtPod::getRemainingMemory() {
    int remainder = memSize;

    SongNode *ptr = songs;

    while(ptr != NULL) {
        remainder -= (ptr->s).getSize();
        ptr = ptr->next;
    }
    return remainder;
}

//destructor for UtPod; removes all songs
UtPod::~UtPod() {
    clearMemory();
}