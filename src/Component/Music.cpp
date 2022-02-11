/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../../include/Component/Music.hpp"

Musics::Musics()
{
}

const Music Musics::getMusicStream(const char *path) const
{
    return (LoadMusicStream(path));
}

const void Musics::setPlayStream(Music music) const
{
    return (PlayMusicStream(music));
}

const void Musics::setPauseMusicStream(Music music) const
{
    return (PauseMusicStream(music));
}

const void Musics::setResumeMusicStream(Music music) const
{
    return (ResumeMusicStream(music));
}

const void Musics::setUpdateMusicStream(Music music) const
{
    return (UpdateMusicStream(music));
}

const void Musics::setNewMusicVolume(Music music, float volume) const
{
    return (SetMusicVolume(music, volume));
}

const void Musics::deleteMusicStream(Music music) const
{
    return (UnloadMusicStream(music));
}