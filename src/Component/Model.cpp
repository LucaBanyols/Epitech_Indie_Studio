/*
** EPITECH PROJECT, 2021
** model
** File description:
** model
*/

#include "../../include/Component/Model.hpp"

MakeModel::MakeModel()
{
    this->_model = LoadModel("../src/resources/assets/running.iqm");
    this->_animCount = 0;
    this->_animModel = LoadModelAnimations("../src/resources/assets/runninganim.iqm", &this->_animCount);
    this->_animModelStanding = LoadModelAnimations("../src/resources/assets/standingAnim.iqm", &this->_animCount);
    this->_animFrameCounter = 0;
    this->_animFrameCounterStanding = 0;
}

const Model MakeModel::getModel() const
{
    return this->_model;
}

const ModelAnimation *MakeModel::getAnimModel(bool Standing) const
{
    if (Standing == true)
        return this->_animModelStanding;
    return this->_animModel;
}

const int MakeModel::getAnimFrameCounter() const
{
    return this->_animFrameCounter;
}

const void MakeModel::setUpdateModelAnimation(Model model, ModelAnimation anim, int frame) const
{
    return (UpdateModelAnimation(model, anim, frame));
}

void MakeModel::setAnimFrameCounter(bool Standing)
{
    if (Standing == true)
        if (this->_animFrameCounterStanding >= this->_animModelStanding[0].frameCount) {
        this->_animFrameCounterStanding = 0;
        }
        else {
            this->_animFrameCounterStanding++;
        }
    else {
        if (this->_animFrameCounter >= this->_animModel[0].frameCount) {
        this->_animFrameCounter = 0;
        }
        else {
            this->_animFrameCounter++;
        }
    }
}