# Project-Playlist

Pierce the Veil Playlist Project

## Overview
This project is a C++ interactive music playlist application that allows users to manage and play songs from Pierce the Veil. The playlist is implemented using a doubly linked list, which allows efficient navigation forward and backward through songs, as well as dynamic addition and removal of songs.
The project is designed as a choose-your-own-adventure style playlist manager, demonstrating practical use of linked lists and basic object-oriented programming concepts in C++. Users can interact with the playlist through a simple text-based interface.

## Features
- Add Songs – Users can add new songs to the playlist.
- Remove Songs – Users can remove songs by title.
- Play Songs – Play the current song in the playlist.
- Navigate – Move to the next or previous song.
- Like Songs – Mark songs as liked; liked songs are indicated with a ❤️.
- Shuffle – Randomly rearrange the order of songs in the playlist.
- Display Playlist – Shows all songs with their status (current song and liked songs).

## Data Structure
The playlist uses a doubly linked list of Song nodes. Each node stores:
- `title` – the song name
- `artist` – the artist name
- `liked` – a boolean to mark a song as liked
- `next` and `prev` pointers – to navigate forward and backward through the playlist

This data structure allows O(1) insertion and removal at any position if the node is known, as well as easy navigation in both directions.
