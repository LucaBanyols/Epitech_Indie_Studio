/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../../include/Input/ChangePlayer.hpp"

ChangePlayer::ChangePlayer()
{
    this->_x = 508;
    this->_y = 820;
    this->_selectionNb = 1;

    this->_isPlayerOne = true;
    this->_isPlayerTwo = true;
    this->_isPlayerThree = true;
    this->_isPlayerFour = true;

    this->_currentPlayer = KEY_PLAYER_ONE;
}

ChangePlayer::~ChangePlayer()
{
}

// Setter

const void ChangePlayer::setChangePlayer()
{
    this->_arrowRightButton = new ArrowRight;
    this->_arrowLeftButton = new ArrowLeft;
    this->_arrowUpButton = new ArrowUp;
    this->_arrowDownButton = new ArrowDown;
    this->_border = new Border;

    this->_arrowLeftButton->setArrowLeft();
    this->_arrowRightButton->setArrowRight();
    this->_arrowDownButton->setArrowDown();
    this->_arrowUpButton->setArrowUp();
    this->_border->setBorder();
    setTexturePlayers();
}

const void ChangePlayer::setTexturePlayers()
{
    try
    {
        this->_texturePicturePlayer1 = this->_texture->getTexture2D("../src/resources/assets/player1.png");
        this->_texturePicturePlayer2 = this->_texture->getTexture2D("../src/resources/assets/player2.png");
        this->_texturePicturePlayer3 = this->_texture->getTexture2D("../src/resources/assets/player3.png");
        this->_texturePicturePlayer4 = this->_texture->getTexture2D("../src/resources/assets/player4.png");
    }
    catch (Texture2D)
    {
        this->_texturePicturePlayer1 = this->_texture->getTexture2D("../../src/resources/assets/player1.png");
        this->_texturePicturePlayer2 = this->_texture->getTexture2D("../../src/resources/assets/player2.png");
        this->_texturePicturePlayer3 = this->_texture->getTexture2D("../../src/resources/assets/player3.png");
        this->_texturePicturePlayer4 = this->_texture->getTexture2D("../../src/resources/assets/player4.png");
    }
    catch (Error &e)
    {
        std::cerr << e.what() << '\n';
    }
}

// Gestion

const void ChangePlayer::gestionStatePlayerIa(Vector2 &mousePoint, Mouse *mouse)
{
    this->_arrowUpButton->gestionArrowUp(mousePoint, mouse);
    this->_arrowDownButton->gestionArrowDown(mousePoint, mouse);
    if (this->_currentPlayer == KEY_PLAYER_ONE)
    {
        if ((this->_keyEvent->getIsKeyPressed(KEY_UP) && this->_isPlayerOne == false) || (this->_arrowUpButton->_btnArrowUpAction == true && this->_isPlayerOne == false))
        {
            this->_isPlayerOne = true;
        }
        else if ((this->_keyEvent->getIsKeyPressed(KEY_DOWN) && this->_isPlayerOne == true) || (this->_arrowDownButton->_btnArrowDownAction == true && this->_isPlayerOne == true))
        {
            this->_isPlayerOne = false;
        }
    }
    else if (this->_currentPlayer == KEY_PLAYER_TWO)
    {
        if ((this->_keyEvent->getIsKeyPressed(KEY_UP) && this->_isPlayerTwo == false) || (this->_arrowUpButton->_btnArrowUpAction == true && this->_isPlayerTwo == false))
        {
            this->_isPlayerTwo = true;
        }
        else if ((this->_keyEvent->getIsKeyPressed(KEY_DOWN) && this->_isPlayerTwo == true) || (this->_arrowDownButton->_btnArrowDownAction == true && this->_isPlayerTwo == true))
        {
            this->_isPlayerTwo = false;
        }
    }
    else if (this->_currentPlayer == KEY_PLAYER_THREE)
    {
        if ((this->_keyEvent->getIsKeyPressed(KEY_UP) && this->_isPlayerThree == false) || (this->_arrowUpButton->_btnArrowUpAction == true && this->_isPlayerThree == false))
        {
            this->_isPlayerThree = true;
        }
        else if ((this->_keyEvent->getIsKeyPressed(KEY_DOWN) && this->_isPlayerThree == true) || (this->_arrowDownButton->_btnArrowDownAction == true && this->_isPlayerThree == true))
        {
            this->_isPlayerThree = false;
        }
    }
    else if (this->_currentPlayer == KEY_PLAYER_FOUR)
    {
        if ((this->_keyEvent->getIsKeyPressed(KEY_UP) && this->_isPlayerFour == false) || (this->_arrowUpButton->_btnArrowUpAction == true && this->_isPlayerFour == false))
        {
            this->_isPlayerFour = true;
        }
        else if (this->_keyEvent->getIsKeyPressed(KEY_DOWN) && this->_isPlayerFour == true || (this->_arrowDownButton->_btnArrowDownAction == true && this->_isPlayerFour == true))
        {
            this->_isPlayerFour = false;
        }
    }
    this->_arrowUpButton->_btnArrowUpAction = false;
    this->_arrowDownButton->_btnArrowDownAction = false;
}

const void ChangePlayer::gestionChangePlayer(Vector2 &mousePoint, Mouse *mouse)
{
    this->_arrowLeftButton->gestionArrowLeft(mousePoint, mouse);
    this->_arrowRightButton->gestionArrowRight(mousePoint, mouse);
    if (this->_selectionNb > 0 && this->_selectionNb < 5)
    {
        if ((this->_arrowRightButton->_btnArrowRightAction == true && this->_selectionNb != 4) || (this->_keyEvent->getIsKeyPressed(KEY_RIGHT) && this->_selectionNb != 4))
        {
            this->_selectionNb++;
            this->_x += 230;
            this->_currentPlayer++;
            if (this->_currentPlayer > KEY_PLAYER_FOUR)
                this->_currentPlayer = KEY_PLAYER_FOUR;
        }
        else if ((this->_arrowLeftButton->_btnArrowLeftAction == true && this->_selectionNb != 1) || (this->_keyEvent->getIsKeyPressed(KEY_LEFT) && this->_selectionNb != 1))
        {
            this->_selectionNb--;
            this->_x -= 230;
            this->_currentPlayer--;
            if (this->_currentPlayer < KEY_PLAYER_ONE)
                this->_currentPlayer = KEY_PLAYER_ONE;
        }
    }
    this->_arrowLeftButton->_btnArrowLeftAction = false;
    this->_arrowRightButton->_btnArrowRightAction = false;
    gestionStatePlayerIa(mousePoint, mouse);
}

// Display

const void ChangePlayer::displayTexturePlayers() const
{
    this->_texture->setDrawTexture(this->_texturePicturePlayer1, 500, 810);
    this->_texture->setDrawTexture(this->_texturePicturePlayer2, 730, 810);
    this->_texture->setDrawTexture(this->_texturePicturePlayer3, 960, 820);
    this->_texture->setDrawTexture(this->_texturePicturePlayer4, 1190, 810);
}

const void ChangePlayer::displayAllPlayerStatus() const
{
    if (this->_isPlayerOne == true)
    {
        this->_texts->setDrawText("PLAYER", 1730, 410, 30, RED);
    }
    else
    {
        this->_texts->setDrawText("IA", 1730, 405, 40, RED);
    }
    if (this->_isPlayerTwo == true)
    {
        this->_texts->setDrawText("PLAYER", 1730, 460, 30, RED);
    }
    else
    {
        this->_texts->setDrawText("IA", 1730, 455, 40, RED);
    }
    if (this->_isPlayerThree == true)
    {
        this->_texts->setDrawText("PLAYER", 1730, 510, 30, RED);
    }
    else
    {
        this->_texts->setDrawText("IA", 1730, 505, 40, RED);
    }
    if (this->_isPlayerFour == true)
    {
        this->_texts->setDrawText("PLAYER", 1730, 560, 30, RED);
    }
    else
    {
        this->_texts->setDrawText("IA", 1730, 555, 40, RED);
    }
}

const void ChangePlayer::displayPlayerStatus() const
{
    this->_texts->setDrawText("1 :", 1650, 400, 50, RED);
    this->_texts->setDrawText("2 :", 1650, 450, 50, RED);
    this->_texts->setDrawText("3 :", 1650, 500, 50, RED);
    this->_texts->setDrawText("4 :", 1650, 550, 50, RED);
    if (this->_currentPlayer == KEY_PLAYER_ONE) {
        if (this->_isPlayerOne == true) {
            this->_texts->setDrawText("PLAYER", 1500, 920, 50, RED);
        } else {
            this->_texts->setDrawText("IA", 1500, 920, 50, RED);
        }
    }
    else if (this->_currentPlayer == KEY_PLAYER_TWO) {
        if (this->_isPlayerTwo == true) {
            this->_texts->setDrawText("PLAYER", 1500, 920, 50, RED);
        } else {
            this->_texts->setDrawText("IA", 1500, 920, 50, RED);
        }
    }
    else if (this->_currentPlayer == KEY_PLAYER_THREE) {
        if (this->_isPlayerThree == true) {
            this->_texts->setDrawText("PLAYER", 1500, 920, 50, RED);
        } else {
            this->_texts->setDrawText("IA", 1500, 920, 50, RED);
        }
    }
    else  if (this->_currentPlayer == KEY_PLAYER_FOUR) {
        if (this->_isPlayerFour == true) {
            this->_texts->setDrawText("PLAYER", 1500, 920, 50, RED);
        } else {
            this->_texts->setDrawText("IA", 1500, 920, 50, RED);
        }
    }
}

const void ChangePlayer::displayChangePlayer() const
{
    this->_arrowRightButton->displayArrowRight();
    this->_arrowLeftButton->displayArrowLeft();
    this->_arrowDownButton->displayArrowDown();
    this->_arrowUpButton->displayArrowUp();
    this->_border->displayBorder(this->_x, this->_y);
    displayTexturePlayers();
    displayPlayerStatus();
    displayAllPlayerStatus();
}

// Delete

const void ChangePlayer::deleteTexturePlayers() const
{
    this->_texture->setUnloadTexture(this->_texturePicturePlayer1);
    this->_texture->setUnloadTexture(this->_texturePicturePlayer2);
    this->_texture->setUnloadTexture(this->_texturePicturePlayer3);
    this->_texture->setUnloadTexture(this->_texturePicturePlayer4);
}

const void ChangePlayer::deleteChangePlayer() const
{
    this->_arrowRightButton->deleteArrowRight();
    this->_arrowLeftButton->deleteArrowLeft();
    this->_arrowUpButton->deleteArrowUp();
    this->_arrowDownButton->deleteArrowDown();
    this->_border->deleteBorder();
    deleteTexturePlayers();

    delete (this->_arrowLeftButton);
    delete (this->_arrowRightButton);
    delete (this->_arrowDownButton);
    delete (this->_arrowUpButton);
    delete (this->_border);
}

const bool ChangePlayer::getIsPlayerOne() const
{
    return (this->_isPlayerOne);
}

const bool ChangePlayer::getIsPlayerTwo() const
{
    return (this->_isPlayerTwo);
}

const bool ChangePlayer::getIsPlayerThree() const
{
    return (this->_isPlayerThree);
}

const bool ChangePlayer::getIsPlayerFour() const
{
    return (this->_isPlayerFour);
}