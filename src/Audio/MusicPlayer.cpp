#include "MusicPlayer.hpp"
#include "../Utils/Log.hpp"

MusicPlayer::MusicPlayer()
    : mMusic()
    , fileMap()
    , mVolume(100.f)
{
}

void MusicPlayer::addSong(Res::Music identifier, const std::string& filename)
{
    auto found = fileMap.find(identifier);
    
    if (found == fileMap.end())
        fileMap[identifier] = filename;
    else
        logf("Attempting to add  \'%s\' a second time", filename.c_str());
}

void MusicPlayer::play(Res::Music theme)
{
    std::string filename = fileMap[theme];

    if (!mMusic.openFromFile(filename))
        throw std::runtime_error("Music " + filename + " could not be loaded.");

    mMusic.setVolume(mVolume);
    mMusic.setLoop(true);
    mMusic.play();
}

void MusicPlayer::stop()
{
    mMusic.stop();
}

void MusicPlayer::pause()
{
    if (mMusic.getStatus() == sf::Music::Status::Paused)
        mMusic.play();
    else if (mMusic.getStatus() == sf::Music::Status::Playing)
        mMusic.pause();
}

void MusicPlayer::setVolume(float volume)
{
    mVolume = volume;
    mMusic.setVolume(mVolume);
}

bool MusicPlayer::getVolume() const
{
    pAssert(mVolume == mMusic.getVolume(), "MusicPlayer volume level mismatch");
    return mVolume;
}

void MusicPlayer::setPaused(bool paused)
{
    if (paused)
        mMusic.pause();
    else
        mMusic.play();
}

void MusicPlayer::absSeek(sf::Time offset)
{
    sf::Time current = mMusic.getPlayingOffset();
    if (current + offset > sf::Time::Zero)
        mMusic.setPlayingOffset(offset);
}

void MusicPlayer::relSeek(sf::Time offset)
{
    sf::Time current = mMusic.getPlayingOffset();
    if (current + offset > sf::Time::Zero)
        mMusic.setPlayingOffset(mMusic.getPlayingOffset() + offset);
}

void MusicPlayer::setLoop(bool loop)
{
    mMusic.setLoop(loop);
}

bool MusicPlayer::getLoop() const
{
    return mMusic.getLoop();
}

sf::Time MusicPlayer::getTime() const
{
    return mMusic.getPlayingOffset();
}

sf::Time MusicPlayer::getDuration() const
{
    return mMusic.getDuration();
}

// sf::Music& MusicPlayer::getMusic()
// {
//     return mMusic;
// }

