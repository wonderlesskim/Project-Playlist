#include "Playlist.hpp"
#include <iostream>
#include <string>

int main() {
    Playlist myPlaylist;

    // Pierce the Veil songs
    myPlaylist.addSong("King for a Day", "Pierce the Veil");
    myPlaylist.addSong("Caraphernelia", "Pierce the Veil");
    myPlaylist.addSong("Bulls in the Bronx", "Pierce the Veil");
    myPlaylist.addSong("Circles", "Pierce the Veil");
    myPlaylist.addSong("Hold On Till May", "Pierce the Veil");
    myPlaylist.addSong("Hell Above", "Pierce the Veil");
    myPlaylist.addSong("Props & Mayhem", "Pierce the Veil");
    myPlaylist.addSong("Bulletproof Love", "Pierce the Veil");
    myPlaylist.addSong("A Match Into Water", "Pierce the Veil");
    myPlaylist.addSong("Fast Times at Clairemont High", "Pierce the Veil");

    std::string command;
    std::string songTitle;

    std::cout << "Welcome to your Pierce the Veil Playlist!\n";

    while (true) {
        std::cout << "\nCommands: play, next, prev, like, add, remove, shuffle, display, quit\n> ";
        std::cin >> command;

        if (command == "play") myPlaylist.play();
        else if (command == "next") myPlaylist.next();
        else if (command == "prev") myPlaylist.prev();
        else if (command == "like") myPlaylist.like();
        else if (command == "shuffle") myPlaylist.shuffle();
        else if (command == "display") myPlaylist.displayPlaylist();
        else if (command == "add") {
            std::string artist;
            std::cin.ignore();
            std::cout << "Song title: ";
            std::getline(std::cin, songTitle);
            std::cout << "Artist: ";
            std::getline(std::cin, artist);
            myPlaylist.addSong(songTitle, artist);
        }
        else if (command == "remove") {
            std::cin.ignore();
            std::cout << "Song title to remove: ";
            std::getline(std::cin, songTitle);
            myPlaylist.removeSong(songTitle);
        }
        else if (command == "quit") {
            std::cout << "Exiting playlist. Bye!\n";
            break;
        }
        else std::cout << "Unknown command! Try again.\n";
    }

    return 0;
}
