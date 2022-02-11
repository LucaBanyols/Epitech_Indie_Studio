/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../../include/Component/Textures.hpp"

Textures::Textures()
{
}

const Texture2D Textures::getTexture2D(const char *path) const
{
    return (LoadTexture(path));
}

const Texture2D Textures::getTexture2DFromImage(Image image) const
{
    return (LoadTextureFromImage(image));
}

const void Textures::setBeginDrawing() const
{
    return (BeginDrawing());
}

const void Textures::setEndDrawing() const
{
    return (EndDrawing());
}

const void Textures::setDrawTexture(Texture2D texture, int x, int y) const
{
    return (DrawTexture(texture, x, y, WHITE));
}

const void Textures::setDrawTextureGradiant(Texture2D texture, int x, int y, int gradiant) const
{
    Color color;

    color.r = 255;
    color.g = 255;
    color.b = 255;
    color.a = static_cast<unsigned char>(gradiant);
    return (DrawTexture(texture, x, y, CLITERAL(color)));
}

const void Textures::setDrawTextureRec(Texture2D texture, Rectangle rectangle, int x, int y) const
{
    Vector2 vector;

    vector.x = x;
    vector.y = y;
    return (DrawTextureRec(texture, rectangle, vector, WHITE));
}

const void Textures::setUnloadTexture(Texture2D texture) const
{
    return (UnloadTexture(texture));
}

const void Textures::setDrawCubeTexture(Texture2D texture, Vector3 position, float width, float height, float length, Color color) const
{
    return(DrawCubeTexture(texture, position, width, height, length, color));
}

const void Textures::setDrawSphere(Vector3 centerPos, float radius, Color color) const
{
    return (DrawSphere(centerPos, radius, color));
}

const void Textures::setDrawSphereWires(Vector3 centerPos, float radius, int rings, int slices, Color color) const
{
    return (DrawSphereWires(centerPos, radius, rings, slices, color));
}
