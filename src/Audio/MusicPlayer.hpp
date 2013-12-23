#ifndef _MusicPlayer_hpp_
#define _MusicPlayer_hpp_

#include "../System/ResourceHolder.hpp"
#include "../System/ResourceIdentifiers.hpp"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Audio/Music.hpp>

#include <map>
#include <string>


class MusicPlayer : private sf::NonCopyable
{
    public:
    MusicPlayer();

    void addSong(Res::Music song, const std::string& filename);
    void play(Res::Music theme);
    void stop();
    void pause();

    void setPaused(bool paused);
    void setVolume(float volume);
    void absSeek(sf::Time offset);
    void relSeek(sf::Time offset);

    private:
    sf::Music mMusic;
    std::map<Res::Music, std::string> fileMap;
    float mVolume;
};

#endif // _MusicPlayer_hpp_

