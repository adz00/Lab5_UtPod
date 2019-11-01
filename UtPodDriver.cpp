/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;

    t.showSongList();

    Song s1("Beatles", "Hey Jude1", 4);
    int result = t.addSong(s1); // this doesn't work rn
    cout << "result = " << result << endl;

    t.showSongList();

    Song s2("Beatles", "Hey Jude2", 5);
    result = t.addSong(s2);
    cout << "result = " << result << endl;

    t.showSongList();

    Song s3("Beatles", "Hey Jude3", 6);
    result = t.addSong(s3);
    cout << "result = " << result << endl;

    Song s4("Beatles", "Hey Jude4", 7);
    result = t.addSong(s4);
    cout << "result = " << result << endl;

    Song s5("Beatles", "Hey Jude5", 241);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    Song s6("", "", 0);
    result = t.addSong(s6);
    cout << "add result = " << result << endl;

    Song s7("", "", -15);
    result = t.addSong(s7);
    cout << "add result = " << result << endl;

    Song s8("", "ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss", 49);
    result = t.addSong(s8);
    cout << "add result = " << result << endl;

    Song s9("a", "asdf", 1);
    result = t.addSong(s9);
    cout << "add result = " << result << endl;

    Song s10("b", "asdf", 1);
    result = t.addSong(s10);
    cout << "add result = " << result << endl;

    Song s11("c", "asdf", 1);
    result = t.addSong(s11);
    cout << "add result = " << result << endl;

    Song s12("d", "asdf", 1);
    result = t.addSong(s12);
    cout << "add result = " << result << endl;

    Song s13("e", "ghij", 10);
    result = t.addSong(s13);
    cout << "add result = " << result << endl;

    Song s14("e", "ghij", 20);
    result = t.addSong(s14);
    cout << "add result = " << result << endl;

    Song s15("e", "ghij", 30);
    result = t.addSong(s15);
    cout << "add result = " << result << endl;

    Song s16("e", "ghij", 40);
    result = t.addSong(s16);
    cout << "add result = " << result << endl;
    result = t.addSong(s16);
    cout << "add result = " << result << endl;
    result = t.addSong(s16);
    cout << "add result = " << result << endl;

    Song s17("e", "ghij", 500);
    result = t.addSong(s17);
    cout << "add result = " << result << endl;

    Song s18("", "", 513);
    result = t.addSong(s7);
    cout << "add result = " << result << endl;

    t.showSongList();

    t.shuffle();

    t.showSongList();

    t.sortSongList();

    t.showSongList();

    t.shuffle();

    t.showSongList();

    t.sortSongList();

    t.showSongList();

    t.shuffle();

    t.showSongList();

    t.sortSongList();

    t.showSongList();

    t.shuffle();

    t.showSongList();

    t.sortSongList();

    t.showSongList();


    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    t.showSongList();

    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s9);
    cout << "delete result = " << result << endl;
    result = t.removeSong(s10);
    cout << "delete result = " << result << endl;
    result = t.removeSong(s11);
    cout << "delete result = " << result << endl;
    result = t.removeSong(s12);
    cout << "delete result = " << result << endl;
    result = t.removeSong(s13);
    cout << "delete result = " << result << endl;
    result = t.removeSong(s14);
    cout << "delete result = " << result << endl;
    result = t.removeSong(s15);
    cout << "delete result = " << result << endl;
    result = t.removeSong(s16);
    cout << "delete result = " << result << endl;
    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;


    t.showSongList();

    result = t.addSong(s5);
    cout << "add result = " << result << endl;
    result = t.addSong(s4);
    cout << "add result = " << result << endl;
    result = t.addSong(s3);
    cout << "add result = " << result << endl;

    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;

    t.clearMemory();
    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;

    result = t.addSong(s4);
    cout << "add result = " << result << endl;
    result = t.addSong(s1);
    cout << "add result = " << result << endl;
    result = t.addSong(s4);
    cout << "add result = " << result << endl;
    result = t.addSong(s2);
    cout << "add result = " << result << endl;
    result = t.addSong(s4);
    cout << "add result = " << result << endl;

    t.showSongList();

    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;

    t.showSongList();

    Song s19("test", "test", 490);
    result = t.addSong(s19);
    cout << "add result = " << result << endl;

    Song s20("test", "test", 489);
    result = t.addSong(s20);
    cout << "add result = " << result << endl;

    t.showSongList();

    t.shuffle();

    t.showSongList();

    t.shuffle();

    t.showSongList();

    t.clearMemory();

    result = t.addSong(s1);
    cout << "add result = " << result << endl;
    t.showSongList();
    s1.setArtist("not the beatles");
    s1.setTitle("hey there");
    s1.setSize(50);
    t.showSongList();
    t.shuffle();
    t.showSongList();
    cout << s1.getArtist() << " " << s1.getTitle() << " " << s1.getSize() << endl;

    t.clearMemory();
    t.shuffle();
    t.showSongList();
    cout << t.getTotalMemory() << endl;


}