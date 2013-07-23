#include "MusicPlayer.hpp"

MusicPlayer::MusicPlayer()
    : mMusic()
    , mFilenames()
    , mVolume(100.f)
{
    mFilenames[Res::Music::main]    = "data/music/song1.flac";
    mFilenames[Res::Music::other]   = "data/music/song2.wav";
}

void MusicPlayer::play(Res::Music theme)
{
    std::string filename = mFilenames[theme];

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

void MusicPlayer::setPaused(bool paused)
{
    if (paused)
        mMusic.pause();
    else
        mMusic.play();
}
