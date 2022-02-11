/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../ICore.hpp"

#ifndef TEXTURES_HPP_
#define TEXTURES_HPP_

class Textures
{
private:
public:
    Textures();
    ~Textures() = default;
    const Texture2D getTexture2D(const char *path) const;
    const Texture2D getTexture2DFromImage(Image image) const;
    const void setBeginDrawing() const;
    const void setEndDrawing() const;
    const void setDrawTexture(Texture2D texture, int x, int y) const;
    const void setDrawTextureGradiant(Texture2D texture, int x, int y, int gradiant) const;
    const void setDrawTextureRec(Texture2D texture, Rectangle  rectangle, int x, int y) const;
    const void setUnloadTexture(Texture2D texture) const;
    const void setDrawCubeTexture(Texture2D texture, Vector3 position, float width, float height, float length, Color color) const;
    const void setDrawSphere(Vector3 centerPos, float radius, Color color) const;
    const void setDrawSphereWires(Vector3 centerPos, float radius, int rings, int slices, Color color) const;
};

#endif