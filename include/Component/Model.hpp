/*
** EPITECH PROJECT, 2021
** model
** File description:
** modelc class
*/

#include "../ICore.hpp"

#ifndef MODEL_HPP_
#define MODEL_HPP_

class MakeModel
{
private:
    Model _model;
    ModelAnimation *_animModel;
    int _animCount;
    int _animFrameCounter;
    int _animFrameCounterStanding;
    ModelAnimation *_animModelStanding;

public:
    MakeModel();
    const Model getModel() const;
    const ModelAnimation *getAnimModel(bool Standing) const;

    void setAnimFrameCounter(bool Standing);
    const int getAnimFrameCounter() const;
    const void setUpdateModelAnimation(Model model, ModelAnimation anim, int frame) const;
    ~MakeModel() = default;
};



#endif