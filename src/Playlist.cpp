#include "Playlist.hpp"

// Constructor
Playlist::Playlist() : head(nullptr), tail(nullptr), current(nullptr) {
    std::srand(std::time(0)); // for shuffle
}

// Destructor
Playlist::~Playlist() {
    Song* temp = head;
    while (temp) {
        Song* nextSong = temp->next;
        delete temp;
        temp = nextSong;
    }
}

// Add song to end
void Playlist::addSong(const std::string& title, const std::string& artist) {
    Song* newSong = new Song(title, artist);
    if (!head) {
        head = tail = current = newSong;
    } else {
        tail->next = newSong;
        newSong->prev = tail;
        tail = newSong;
    }
    std::cout << "Added: " << title << " by " << artist << std::endl;
}

// Remove song by title
void Playlist::removeSong(const std::string& title) {
    Song* temp = head;
    while (temp) {
        if (temp->title == title) {
            if (temp->prev) temp->prev->next = temp->next;
            else head = temp->next;
            if (temp->next) temp->next->prev = temp->prev;
            else tail = temp->prev;
            if (current == temp) current = temp->next ? temp->next : temp->prev;
            delete temp;
            std::cout << "Removed: " << title << std::endl;
            return;
        }
        temp = temp->next;
    }
    std::cout << "Song not found: " << title << std::endl;
}

// Play current song
void Playlist::play() {
    if (!current) {
        std::cout << "Playlist is empty!" << std::endl;
        return;
    }
    std::cout << "Playing: " << current->title << " by " << current->artist;
    if (current->liked) std::cout << " ❤️";
    std::cout << std::endl;
}

// Next song
void Playlist::next() {
    if (current && current->next) current = current->next;
    else current = head; // loop around
    play();
}

// Previous song
void Playlist::prev() {
    if (current && current->prev) current = current->prev;
    else current = tail; // loop around
    play();
}

// Like current song
void Playlist::like() {
    if (!current) return;
    current->liked = true;
    std::cout << "Liked: " << current->title << std::endl;
}

// Shuffle playlist
void Playlist::shuffle() {
    if (!head) return;

    std::vector<Song*> songs;
    Song* temp = head;
    while (temp) {
        songs.push_back(temp);
        temp = temp->next;
    }

    for (size_t i = 0; i < songs.size(); i++) {
        size_t j = std::rand() % songs.size();
        std::swap(songs[i]->title, songs[j]->title);
        std::swap(songs[i]->artist, songs[j]->artist);
        std::swap(songs[i]->liked, songs[j]->liked);
    }
    std::cout << "Playlist shuffled!" << std::endl;
}

// Display playlist
void Playlist::displayPlaylist() {
    Song* temp = head;
    std::cout << "Playlist:" << std::endl;
    while (temp) {
        std::cout << "- " << temp->title << " by " << temp->artist;
        if (temp->liked) std::cout << " ❤️";
        if (temp == current) std::cout << " <-- currently playing";
        std::cout << std::endl;
        temp = temp->next;
    }
}
