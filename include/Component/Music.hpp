/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../ICore.hpp"

#ifndef MUSIC_HPP_
#define MUSIC_HPP_

class Musics
{
public:
    Musics();
    ~Musics() = default;
    const Music getMusicStream(const char *path) const;
    const void setPlayStream(Music music) const;
    const void setUpdateMusicStream(Music music) const;
    const void setPauseMusicStream(Music music) const;
    const void setResumeMusicStream(Music music) const;
    const void setNewMusicVolume(Music music, float volume) const;
    const void deleteMusicStream(Music music) const;
};

#endif