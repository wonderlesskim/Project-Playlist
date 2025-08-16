#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

struct Song {
    std::string title;
    std::string artist;
    bool liked;
    Song* next;
    Song* prev;

    Song(std::string t, std::string a)
        : title(t), artist(a), liked(false), next(nullptr), prev(nullptr) {}
};

class Playlist {
private:
    Song* head;
    Song* tail;
    Song* current;

public:
    Playlist();
    ~Playlist();

    void addSong(const std::string& title, const std::string& artist);
    void removeSong(const std::string& title);
    void play();
    void next();
    void prev();
    void like();
    void shuffle();
    void displayPlaylist();
};

#endif
