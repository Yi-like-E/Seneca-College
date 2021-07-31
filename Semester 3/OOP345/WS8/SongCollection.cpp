//  SongCollection module
//  SongCollection.cpp
//  YiHsun Lee
//  129713202
//  2021-07-10.
//  I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments

#include <fstream>
#include <iomanip>
#include <numeric>
#include <functional>
#include <algorithm>
#include "SongCollection.h"
using namespace std;
namespace sdds{
SongCollection::SongCollection(std::string filename){
    ifstream file(filename);
    if(!file){
        throw "Invalid file name.";
    } else{
        while(!file.eof()){
            string str, artist, title, album, price, year, length;
            Song song;
            
            getline(file, str, '\n');
            title = str.substr(0, 25);
            title.erase(0, title.find_first_not_of(' '));
            title.erase(title.find_last_not_of(' ')+1);
            str.erase(0, 25);
            song.m_title = title;
            
            artist = str.substr(0,25);
            artist.erase(0, artist.find_first_not_of(' '));
            artist.erase(artist.find_last_not_of(' ')+1);
            str.erase(0, 25);
            song.m_artist = artist;
            
            album = str.substr(0,25);
            album.erase(0, album.find_first_not_of(' '));
            album.erase(album.find_last_not_of(' ')+1);
            str.erase(0, 25);
            song.m_album = album;
            
            year = str.substr(0,5);
            year.erase(0, year.find_first_not_of(' '));
            year.erase(year.find_last_not_of(' ')+1);
            str.erase(0, 5);
            if(year.empty()){
                song.m_year = 0;
            }else {
                song.m_year = stoi(year);
            }
            
            length = str.substr(0,5);
            length.erase(0, length.find_first_not_of(' '));
            length.erase(length.find_last_not_of(' ')+1);
            str.erase(0, 5);
            song.m_length = stoi(length);
            
            price = str.substr(0,5);
            price.erase(0, price.find_first_not_of(' '));
            price.erase(price.find_last_not_of(' ')+1);
            str.erase(0, 5);
            song.m_price = stod(price);
            
            m_collection.push_back(song);
        }
    }
    file.close();
}

void SongCollection::display(std::ostream& out) const{
    for_each(m_collection.begin(), m_collection.end(), [&](const Song s){
        out << s << endl;
    });
    size_t sum = accumulate(m_collection.begin(), m_collection.end(), 0u, [](const size_t& sumLength, const Song& song){
        return sumLength+song.m_length;
    });
    out << setw(89) << setfill('-') << '\n' << setfill(' ');
    out << "| " << right << setw(77) << "Total Listening Time: "
        << sum / 3600 << ":" << (sum % 3600)/60 << ":" << (sum % 3600) % 60 << " |\n";
}

std::ostream& operator<<(std::ostream& out, const Song& theSong){
    out << "| " << left << setw(20) << theSong.m_title
    << " | " << left << setw(15) << theSong.m_artist
    << " | " << left << setw(20) << theSong.m_album;
    if(theSong.m_year == 0){
        out << " | " << right << setw(6) << ' ';
    }else{
        out << " | " << right << setw(6) << theSong.m_year;
    }
    out << " | " << theSong.m_length/60 << ":"
    << right << setw(2) << setfill('0') << theSong.m_length%60 << setfill(' ');
    out << " | " << theSong.m_price << " |";
    return out;
}

void SongCollection::sort(std::string name){
    if(name == "title"){
        std::sort(m_collection.begin(), m_collection.end(), [](const Song& a, const Song& b){
            return a.m_title < b.m_title;
        });
    } else if(name == "album"){
        std::sort(m_collection.begin(), m_collection.end(), [](const Song& a, const Song& b){
            return a.m_album < b.m_album;
        });
    } else if(name == "length"){
        std::sort(m_collection.begin(), m_collection.end(), [](const Song& a, const Song& b){
            return a.m_length < b.m_length;
        });
    } else {
        throw "Unidentified parameter.";
    }
};

void SongCollection::cleanAlbum(){
    for_each(m_collection.begin(), m_collection.end(), [](Song& s){
        if(s.m_album == "[None]"){
            s.m_album = " ";
        }
    });
};

bool SongCollection::inCollection(std::string artist) const{
    return any_of(m_collection.begin(), m_collection.end(), [&artist](const Song& s){
        return artist == s.m_artist;
    });
};

std::list<Song> SongCollection::getSongsForArtist(std::string artist) const{
    auto count = count_if(m_collection.begin(), m_collection.end(), [&artist](const Song& s){
        return artist == s.m_artist;
    });
    std::list<Song> collection(count);
    copy_if(m_collection.begin(), m_collection.end(), collection.begin(), [&artist](const Song& s){
        return artist == s.m_artist;
    });
    return collection;
};
}
