//
// Created by srira on 10/21/2019.
//

#include "UtPod.h"
#include <iostream>
#include<ctime>
#include<cstdlib>

using namespace std;


UtPod::UtPod() {
    memSize = MAX_MEMORY;
    songs = NULL;
}

UtPod::UtPod(int size) {
    unsigned int currentTime = (unsigned)time(0);
    if((size > MAX_MEMORY) || (size < 0))
    {
        memSize = MAX_MEMORY;
    }
    else
    {
        memSize = size;
    }
    srand(currentTime);
    songs = NULL; // initialize the linked list
}
int UtPod::addSong(Song const &s) {

    if(getRemainingMemory() >= s.getSize())
    {
        SongNode *newNode = new SongNode; // new songNode that we will add to UtPod
        newNode->s = s;
        newNode->next = songs;
        songs = newNode;
        return SUCCESS;
    }
    else // not enough memory for the new Song
    {
        return NO_MEMORY;
    }
}
int UtPod::removeSong(Song const &s) {
    SongNode *prevPtr = songs;

    if(songs == NULL)
    {
        return NOT_FOUND;
    }
    SongNode *ptr = prevPtr->next;
    if(prevPtr->s == s)
    {
        songs = ptr;
        delete(prevPtr);
        return SUCCESS;
    }

    while(ptr != NULL)
    {
        if(ptr->s == s)
        {
            if(ptr->next == NULL) // we are deleting last element of the linked list
            {
                prevPtr->next = NULL;
                delete(ptr);
            }
            else
            {
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
int UtPod::getRemainingMemory(){
    int remainder = memSize;

    SongNode *ptr = songs;

    while(ptr != NULL)
    {
        remainder -= (ptr->s).getSize();
        ptr = ptr->next;
    }
    return remainder;
}
void UtPod::clearMemory() {
    SongNode *ptr = songs;
    while(ptr != NULL)
    {
        SongNode temp = *ptr; // copy of the current Song Node
        free(ptr);
        ptr = temp.next;
    }
}
void UtPod::showSongList() {
    if (songs==NULL) {
        cout << "There are no songs on the UtPod right now" << endl;
    }
    SongNode *ptr = songs;

    while(ptr != NULL)
    {
        cout << (ptr->s).getTitle() << ", " << (ptr->s).getArtist() << ", " << (ptr->s).getSize() << endl;
        ptr = ptr->next;
    }
    cout << endl;
}
void UtPod::sortSongList()
{
    for(SongNode *p1 = songs; p1 != NULL; p1 = p1->next)
    {
        for(SongNode *p2 = p1->next; p2 != NULL; p2 = p2->next)
        {
            if(p2->s < p1->s)
            {
                p1->s.swap(p2->s);
            }
        }
    }
}
void UtPod::shuffle()
{
    int count = 0;
    SongNode *ptr = songs;
    while(ptr != NULL) // count the number of songs in the UtPod
    {
        count++;
        ptr = ptr->next;
    }
    for(int i = 0; i < count * 10; i++)
    {
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
UtPod::~UtPod()
{
    clearMemory();
}