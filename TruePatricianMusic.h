#ifndef TRUEPATRICIANMUSIC_H
#define TRUEPATRICIANMUSIC_H

#include <vector>
#include <string>

struct Info{
    std::string band;
    std::string album;
    std::string genre;
    int rating;

    Info(){};

    Info(std::string _band, std::string _album, int _rating, std::string _genre){
        band = _band;
        album = _album;
        rating = _rating;
        genre = _genre;
    }
};

class Genre{
    public:
    protected:
    private:
        std::vector<Info> library;
};
#endif // TRUEPATRICIANMUSIC_H
