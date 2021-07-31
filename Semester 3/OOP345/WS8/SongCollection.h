//  SongCollection module
//  SongCollection.h
//  YiHsun Lee
//  129713202
//  2021-07-10.
//  I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments

#ifndef SDDS_SongCollection_h
#define SDDS_SongCollection_h

#include <iostream>
#include <string>
#include <vector>
#include <list>
namespace sdds{
struct Song{
    std::string m_artist;
    std::string m_title;
    std::string m_album;
    double m_price;
    size_t m_year;
    size_t m_length;
};
class SongCollection{
    std::vector<Song> m_collection;
public:
    SongCollection(std::string filename);
    void display(std::ostream& out) const;
    void sort(std::string name);
    void cleanAlbum();
    bool inCollection(std::string artist) const;
    std::list<Song> getSongsForArtist(std::string artist) const;
};
std::ostream& operator<<(std::ostream& out, const Song& theSong);
}

#endif /* SDDS_SongCollection_h */
