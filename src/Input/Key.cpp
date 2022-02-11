/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../../include/Input/Key.hpp"

Key::Key()
{
    this->_changePlayer = new ChangePlayer;

    this->_playerOneKey.push_back(KEY_UP);
    this->_playerOneKey.push_back(KEY_DOWN);
    this->_playerOneKey.push_back(KEY_LEFT);
    this->_playerOneKey.push_back(KEY_RIGHT);
    this->_playerOneKey.push_back(KEY_SPACE);
    this->_playerTwoKey.push_back(KEY_W);
    this->_playerTwoKey.push_back(KEY_S);
    this->_playerTwoKey.push_back(KEY_A);
    this->_playerTwoKey.push_back(KEY_D);
    this->_playerTwoKey.push_back(KEY_E);
    this->_playerThreeKey.push_back(KEY_T);
    this->_playerThreeKey.push_back(KEY_G);
    this->_playerThreeKey.push_back(KEY_F);
    this->_playerThreeKey.push_back(KEY_H);
    this->_playerThreeKey.push_back(KEY_Y);
    this->_playerFourKey.push_back(KEY_I);
    this->_playerFourKey.push_back(KEY_K);
    this->_playerFourKey.push_back(KEY_J);
    this->_playerFourKey.push_back(KEY_L);
    this->_playerFourKey.push_back(KEY_O);
    this->_keyClicked = 0;

    this->_btnBackAction = false;
    this->_buttonBackState = 0;

    this->_mousePoint = {0.0f, 0.0f};

    this->_btnKeyActionAction = false;
    this->_btnKeyUpAction = false;
    this->_btnKeyDownAction = false;
    this->_btnKeyLeftAction = false;
    this->_btnKeyRightAction = false;

    this->_buttonKeyUpState = 0;
    this->_buttonKeyDownState = 0;
    this->_buttonKeyLeftState = 0;
    this->_buttonKeyRightState = 0;
    this->_buttonKeyActionState = 0;
}

Key::~Key()
{
    delete (this->_changePlayer);
}

const void Key::setBackKey()
{
    try
    {
        this->_textureBack = this->_texture->getTexture2D("../src/resources/assets/back_button.png");
    }
    catch (Texture2D)
    {
        this->_textureBack = this->_texture->getTexture2D("../../src/resources/assets/back_button.png");
    }
    catch (Error &e)
    {
        std::cerr << e.what() << '\n';
    }
    this->_sound->setSoundButton();

    this->_frameBackHeight = (float)this->_textureBack.height / 2;
    this->_sourceBackRec = {0, 0, (float)this->_textureBack.width, this->_frameBackHeight};
    this->_btnBackBounds = {10, 10, (float)this->_textureBack.width, this->_frameBackHeight};
}

const void Key::setPlayerKeys()
{
    try
    {
        this->_textureKeyUp = this->_texture->getTexture2D("../src/resources/assets/key.png");
        this->_textureKeyDown = this->_texture->getTexture2D("../src/resources/assets/key.png");
        this->_textureKeyLeft = this->_texture->getTexture2D("../src/resources/assets/key.png");
        this->_textureKeyRight = this->_texture->getTexture2D("../src/resources/assets/key.png");
        this->_textureKeyAction = this->_texture->getTexture2D("../src/resources/assets/key.png");
    }
    catch (Texture2D)
    {
        this->_textureKeyUp = this->_texture->getTexture2D("../../src/resources/assets/key.png");
        this->_textureKeyDown = this->_texture->getTexture2D("../../src/resources/assets/key.png");
        this->_textureKeyLeft = this->_texture->getTexture2D("../../src/resources/assets/key.png");
        this->_textureKeyRight = this->_texture->getTexture2D("../../src/resources/assets/key.png");
        this->_textureKeyAction = this->_texture->getTexture2D("../../src/resources/assets/key.png");
    }
    catch (Error &e)
    {
        std::cerr << e.what() << '\n';
    }
    this->_frameKeyUpActionHeight = (float)this->_textureKeyUp.height / 2;
    this->_frameKeyDownActionHeight = (float)this->_textureKeyDown.height / 2;
    this->_frameKeyLeftActionHeight = (float)this->_textureKeyLeft.height / 2;
    this->_frameKeyRightActionHeight = (float)this->_textureKeyRight.height / 2;
    this->_frameKeyActionActionHeight = (float)this->_textureKeyAction.height / 2;

    this->_sourceKeyUpRec = {0, 0, (float)this->_textureKeyUp.width, this->_frameKeyUpActionHeight};
    this->_sourceKeyRightRec = {0, 0, (float)this->_textureKeyRight.width, this->_frameKeyRightActionHeight};
    this->_sourceKeyLeftRec = {0, 0, (float)this->_textureKeyLeft.width, this->_frameKeyLeftActionHeight};
    this->_sourceKeyDownRec = {0, 0, (float)this->_textureKeyDown.width, this->_frameKeyDownActionHeight};
    this->_sourceKeyActionRec = {0, 0, (float)this->_textureKeyAction.width, this->_frameKeyActionActionHeight};

    this->_btnKeyUpBounds = {1920 / 2.0f - this->_textureKeyUp.width / 2.0f, 350, (float)this->_textureKeyUp.width, (float)this->_textureKeyUp.height / 2};
    this->_btnKeyDownBounds = {1920 / 2.0f - this->_textureKeyDown.width / 2.0f, 500, (float)this->_textureKeyDown.width, (float)this->_textureKeyDown.height / 2};
    this->_btnKeyRightBounds = {1050, 500, (float)this->_textureKeyRight.width, (float)this->_textureKeyRight.height / 2};
    this->_btnKeyLeftBounds = {725, 500, (float)this->_textureKeyLeft.width, (float)this->_textureKeyLeft.height / 2};
    this->_btnKeyActionBounds = {450, 500, (float)this->_textureKeyAction.width, (float)this->_textureKeyAction.height / 2};
}

const void Key::setBackgroundKey()
{
    try
    {
        this->_textureBackground = this->_texture->getTexture2D("../src/resources/assets/background_select.png");
    }
    catch (Texture2D)
    {
        this->_textureBackground = this->_texture->getTexture2D("../../src/resources/assets/background_select.png");
    }
    catch (Error &e)
    {
        std::cerr << e.what() << '\n';
    }
}

const void Key::setAllKeys()
{
    setBackgroundKey();
    setBackKey();
    setPlayerKeys();
    this->_changePlayer->setChangePlayer();
}

const void Key::gestionKeyUp()
{
    if (this->_btnKeyDownAction == false && this->_btnKeyLeftAction == false && this->_btnKeyRightAction == false && this->_btnKeyActionAction == false) {
        if (this->_mouse->getCollisionPointRec(this->_mousePoint, this->_btnKeyUpBounds))
        {
            if (this->_mouse->getClickPressed(MOUSE_LEFT_BUTTON))
            {
                this->_buttonKeyUpState = 2;
                this->_sound->playSoundClickButton();
            }
            else
                this->_buttonKeyUpState = 1;
            if (_mouse->getClickReleased(MOUSE_LEFT_BUTTON))
            {
                this->_btnKeyUpAction = true;
                this->_buttonKeyUpState = 2;
            }
        } else
            this->_buttonKeyUpState = 0;
        this->_sourceKeyUpRec.y = this->_buttonKeyUpState * this->_frameKeyUpActionHeight;
    }
}

const void Key::gestionKeyDown()
{
    if (this->_btnKeyUpAction == false && this->_btnKeyLeftAction == false && this->_btnKeyRightAction == false && this->_btnKeyActionAction == false) {
        if (this->_mouse->getCollisionPointRec(this->_mousePoint, this->_btnKeyDownBounds))
        {
            if (this->_mouse->getClickPressed(MOUSE_LEFT_BUTTON))
            {
                this->_buttonKeyDownState = 2;
                this->_sound->playSoundClickButton();
            }
            else
                this->_buttonKeyDownState = 1;
            if (_mouse->getClickReleased(MOUSE_LEFT_BUTTON))
            {
                this->_btnKeyDownAction = true;
                this->_buttonKeyDownState = 2;
            }
        } else
            this->_buttonKeyDownState = 0;
        this->_sourceKeyDownRec.y = this->_buttonKeyDownState * this->_frameKeyDownActionHeight;
    }
}

const void Key::gestionKeyLeft()
{
    if (this->_btnKeyDownAction == false && this->_btnKeyUpAction == false && this->_btnKeyRightAction == false && this->_btnKeyActionAction == false) {
        if (this->_mouse->getCollisionPointRec(this->_mousePoint, this->_btnKeyLeftBounds))
        {
            if (this->_mouse->getClickPressed(MOUSE_LEFT_BUTTON))
            {
                this->_buttonKeyLeftState = 2;
                this->_sound->playSoundClickButton();
            }
            else
                this->_buttonKeyLeftState = 1;
            if (_mouse->getClickReleased(MOUSE_LEFT_BUTTON))
            {
                this->_btnKeyLeftAction = true;
                this->_buttonKeyLeftState = 2;
            }
        } else
            this->_buttonKeyLeftState = 0;
        this->_sourceKeyLeftRec.y = this->_buttonKeyLeftState * this->_frameKeyLeftActionHeight;
    }
}

const void Key::gestionKeyRight()
{
    if (this->_btnKeyDownAction == false && this->_btnKeyLeftAction == false && this->_btnKeyUpAction == false && this->_btnKeyActionAction == false) {
        if (this->_mouse->getCollisionPointRec(this->_mousePoint, this->_btnKeyRightBounds))
        {
            if (this->_mouse->getClickPressed(MOUSE_LEFT_BUTTON))
            {
                this->_buttonKeyRightState = 2;
                this->_sound->playSoundClickButton();
            }
            else
                this->_buttonKeyRightState = 1;
            if (this->_mouse->getClickReleased(MOUSE_LEFT_BUTTON))
            {
                this->_btnKeyRightAction = true;
                this->_buttonKeyRightState = 2;
            }
        } else
            this->_buttonKeyRightState = 0;
        this->_sourceKeyRightRec.y = this->_buttonKeyRightState * this->_frameKeyRightActionHeight;
    }
}

const void Key::gestionKeyAction()
{
    if (this->_btnKeyDownAction == false && this->_btnKeyLeftAction == false && this->_btnKeyRightAction == false && this->_btnKeyUpAction == false) {
        if (this->_mouse->getCollisionPointRec(this->_mousePoint, this->_btnKeyActionBounds))
        {
            if (this->_mouse->getClickPressed(MOUSE_LEFT_BUTTON))
            {
                this->_buttonKeyActionState = 2;
                this->_sound->playSoundClickButton();
            }
            else
                this->_buttonKeyActionState = 1;
            if (this->_mouse->getClickReleased(MOUSE_LEFT_BUTTON))
            {
                this->_btnKeyActionAction = true;
                this->_buttonKeyActionState = 2;
            }
        } else
            this->_buttonKeyActionState = 0;
        this->_sourceKeyActionRec.y = this->_buttonKeyActionState * this->_frameKeyActionActionHeight;
    }
}

const void Key::gestionBack()
{
    if (this->_mouse->getCollisionPointRec(this->_mousePoint, this->_btnBackBounds))
    {
        if (this->_mouse->getClickPressed(MOUSE_LEFT_BUTTON))
        {
            this->_sound->playSoundClickButton();
            this->_buttonBackState = 2;
        }
        else
            this->_buttonBackState = 1;
        if (this->_mouse->getClickPressed(MOUSE_LEFT_BUTTON))
        {
            this->_btnBackAction = true;
        }
    }
    else
        this->_buttonBackState = 0;
    this->_sourceBackRec.y = this->_buttonBackState * this->_frameBackHeight;
}

const void Key::gestionBindingCurrentKey()
{
    if (this->_changePlayer->_currentPlayer == KEY_PLAYER_ONE) {
        this->_playerOneKey = gestionPlayerKey(this->_playerOneKey);
    } else if (this->_changePlayer->_currentPlayer == KEY_PLAYER_TWO) {
        this->_playerTwoKey = gestionPlayerKey(this->_playerTwoKey);
    } else if (this->_changePlayer->_currentPlayer == KEY_PLAYER_THREE) {
        this->_playerThreeKey = gestionPlayerKey(this->_playerThreeKey);
    } else if (this->_changePlayer->_currentPlayer == KEY_PLAYER_FOUR) {
        this->_playerFourKey = gestionPlayerKey(this->_playerFourKey);
    }
}

std::vector<int> Key::gestionPlayerKey(std::vector<int> player)
{
    if (this->_btnKeyActionAction == true) {
        if (this->_keyClicked = this->_keyEvent->setNewKeyPressed()) {
            this->_btnKeyActionAction = false;
            if (this->_keyClicked != this->_playerOneKey[TAB_KEY_UP]
            && this->_keyClicked != this->_playerOneKey[TAB_KEY_DOWN]
            && this->_keyClicked != this->_playerOneKey[TAB_KEY_LEFT]
            && this->_keyClicked != this->_playerOneKey[TAB_KEY_RIGHT]
            && this->_keyClicked != this->_playerOneKey[TAB_KEY_DROP]
            && this->_keyClicked != this->_playerTwoKey[TAB_KEY_UP]
            && this->_keyClicked != this->_playerTwoKey[TAB_KEY_DOWN]
            && this->_keyClicked != this->_playerTwoKey[TAB_KEY_LEFT]
            && this->_keyClicked != this->_playerTwoKey[TAB_KEY_RIGHT]
            && this->_keyClicked != this->_playerTwoKey[TAB_KEY_DROP]
            && this->_keyClicked != this->_playerThreeKey[TAB_KEY_UP]
            && this->_keyClicked != this->_playerThreeKey[TAB_KEY_DOWN]
            && this->_keyClicked != this->_playerThreeKey[TAB_KEY_LEFT]
            && this->_keyClicked != this->_playerThreeKey[TAB_KEY_RIGHT]
            && this->_keyClicked != this->_playerThreeKey[TAB_KEY_DROP]
            && this->_keyClicked != this->_playerFourKey[TAB_KEY_UP]
            && this->_keyClicked != this->_playerFourKey[TAB_KEY_DOWN]
            && this->_keyClicked != this->_playerFourKey[TAB_KEY_LEFT]
            && this->_keyClicked != this->_playerFourKey[TAB_KEY_RIGHT]
            && this->_keyClicked != this->_playerFourKey[TAB_KEY_DROP]) {
                player[TAB_KEY_DROP] = this->_keyClicked;
            }
        }
    }
    if (this->_btnKeyUpAction == true) {
        if (this->_keyClicked = this->_keyEvent->setNewKeyPressed()) {
            this->_btnKeyUpAction = false;
            if (this->_keyClicked != this->_playerOneKey[TAB_KEY_UP]
            && this->_keyClicked != this->_playerOneKey[TAB_KEY_DOWN]
            && this->_keyClicked != this->_playerOneKey[TAB_KEY_LEFT]
            && this->_keyClicked != this->_playerOneKey[TAB_KEY_RIGHT]
            && this->_keyClicked != this->_playerOneKey[TAB_KEY_DROP]
            && this->_keyClicked != this->_playerTwoKey[TAB_KEY_UP]
            && this->_keyClicked != this->_playerTwoKey[TAB_KEY_DOWN]
            && this->_keyClicked != this->_playerTwoKey[TAB_KEY_LEFT]
            && this->_keyClicked != this->_playerTwoKey[TAB_KEY_RIGHT]
            && this->_keyClicked != this->_playerTwoKey[TAB_KEY_DROP]
            && this->_keyClicked != this->_playerThreeKey[TAB_KEY_UP]
            && this->_keyClicked != this->_playerThreeKey[TAB_KEY_DOWN]
            && this->_keyClicked != this->_playerThreeKey[TAB_KEY_LEFT]
            && this->_keyClicked != this->_playerThreeKey[TAB_KEY_RIGHT]
            && this->_keyClicked != this->_playerThreeKey[TAB_KEY_DROP]
            && this->_keyClicked != this->_playerFourKey[TAB_KEY_UP]
            && this->_keyClicked != this->_playerFourKey[TAB_KEY_DOWN]
            && this->_keyClicked != this->_playerFourKey[TAB_KEY_LEFT]
            && this->_keyClicked != this->_playerFourKey[TAB_KEY_RIGHT]
            && this->_keyClicked != this->_playerFourKey[TAB_KEY_DROP]) {
                player[TAB_KEY_UP] = this->_keyClicked;
            }
        }
    }
    if (this->_btnKeyDownAction == true) {
        if (this->_keyClicked = this->_keyEvent->setNewKeyPressed()) {
            this->_btnKeyDownAction = false;
            if (this->_keyClicked != this->_playerOneKey[TAB_KEY_UP]
            && this->_keyClicked != this->_playerOneKey[TAB_KEY_DOWN]
            && this->_keyClicked != this->_playerOneKey[TAB_KEY_LEFT]
            && this->_keyClicked != this->_playerOneKey[TAB_KEY_RIGHT]
            && this->_keyClicked != this->_playerOneKey[TAB_KEY_DROP]
            && this->_keyClicked != this->_playerTwoKey[TAB_KEY_UP]
            && this->_keyClicked != this->_playerTwoKey[TAB_KEY_DOWN]
            && this->_keyClicked != this->_playerTwoKey[TAB_KEY_LEFT]
            && this->_keyClicked != this->_playerTwoKey[TAB_KEY_RIGHT]
            && this->_keyClicked != this->_playerTwoKey[TAB_KEY_DROP]
            && this->_keyClicked != this->_playerThreeKey[TAB_KEY_UP]
            && this->_keyClicked != this->_playerThreeKey[TAB_KEY_DOWN]
            && this->_keyClicked != this->_playerThreeKey[TAB_KEY_LEFT]
            && this->_keyClicked != this->_playerThreeKey[TAB_KEY_RIGHT]
            && this->_keyClicked != this->_playerThreeKey[TAB_KEY_DROP]
            && this->_keyClicked != this->_playerFourKey[TAB_KEY_UP]
            && this->_keyClicked != this->_playerFourKey[TAB_KEY_DOWN]
            && this->_keyClicked != this->_playerFourKey[TAB_KEY_LEFT]
            && this->_keyClicked != this->_playerFourKey[TAB_KEY_RIGHT]
            && this->_keyClicked != this->_playerFourKey[TAB_KEY_DROP])
                player[TAB_KEY_DOWN] = this->_keyClicked;
        }
    }
    if (this->_btnKeyRightAction == true) {
        if (this->_keyClicked = this->_keyEvent->setNewKeyPressed()) {
            this->_btnKeyRightAction = false;
            if (this->_keyClicked != this->_playerOneKey[TAB_KEY_UP]
            && this->_keyClicked != this->_playerOneKey[TAB_KEY_DOWN]
            && this->_keyClicked != this->_playerOneKey[TAB_KEY_LEFT]
            && this->_keyClicked != this->_playerOneKey[TAB_KEY_RIGHT]
            && this->_keyClicked != this->_playerOneKey[TAB_KEY_DROP]
            && this->_keyClicked != this->_playerTwoKey[TAB_KEY_UP]
            && this->_keyClicked != this->_playerTwoKey[TAB_KEY_DOWN]
            && this->_keyClicked != this->_playerTwoKey[TAB_KEY_LEFT]
            && this->_keyClicked != this->_playerTwoKey[TAB_KEY_RIGHT]
            && this->_keyClicked != this->_playerTwoKey[TAB_KEY_DROP]
            && this->_keyClicked != this->_playerThreeKey[TAB_KEY_UP]
            && this->_keyClicked != this->_playerThreeKey[TAB_KEY_DOWN]
            && this->_keyClicked != this->_playerThreeKey[TAB_KEY_LEFT]
            && this->_keyClicked != this->_playerThreeKey[TAB_KEY_RIGHT]
            && this->_keyClicked != this->_playerThreeKey[TAB_KEY_DROP]
            && this->_keyClicked != this->_playerFourKey[TAB_KEY_UP]
            && this->_keyClicked != this->_playerFourKey[TAB_KEY_DOWN]
            && this->_keyClicked != this->_playerFourKey[TAB_KEY_LEFT]
            && this->_keyClicked != this->_playerFourKey[TAB_KEY_RIGHT]
            && this->_keyClicked != this->_playerFourKey[TAB_KEY_DROP]) {
                player[TAB_KEY_RIGHT] = this->_keyClicked;
            }
        }
    }
    if (this->_btnKeyLeftAction == true) {
        if (this->_keyClicked = this->_keyEvent->setNewKeyPressed()) {
            this->_btnKeyLeftAction = false;
            if (this->_keyClicked != this->_playerOneKey[TAB_KEY_UP]
            && this->_keyClicked != this->_playerOneKey[TAB_KEY_DOWN]
            && this->_keyClicked != this->_playerOneKey[TAB_KEY_LEFT]
            && this->_keyClicked != this->_playerOneKey[TAB_KEY_RIGHT]
            && this->_keyClicked != this->_playerOneKey[TAB_KEY_DROP]
            && this->_keyClicked != this->_playerTwoKey[TAB_KEY_UP]
            && this->_keyClicked != this->_playerTwoKey[TAB_KEY_DOWN]
            && this->_keyClicked != this->_playerTwoKey[TAB_KEY_LEFT]
            && this->_keyClicked != this->_playerTwoKey[TAB_KEY_RIGHT]
            && this->_keyClicked != this->_playerTwoKey[TAB_KEY_DROP]
            && this->_keyClicked != this->_playerThreeKey[TAB_KEY_UP]
            && this->_keyClicked != this->_playerThreeKey[TAB_KEY_DOWN]
            && this->_keyClicked != this->_playerThreeKey[TAB_KEY_LEFT]
            && this->_keyClicked != this->_playerThreeKey[TAB_KEY_RIGHT]
            && this->_keyClicked != this->_playerThreeKey[TAB_KEY_DROP]
            && this->_keyClicked != this->_playerFourKey[TAB_KEY_UP]
            && this->_keyClicked != this->_playerFourKey[TAB_KEY_DOWN]
            && this->_keyClicked != this->_playerFourKey[TAB_KEY_LEFT]
            && this->_keyClicked != this->_playerFourKey[TAB_KEY_RIGHT]
            && this->_keyClicked != this->_playerFourKey[TAB_KEY_DROP]) {
                player[TAB_KEY_LEFT] = this->_keyClicked;
            }
        }
    }
    return (player);
}

const void Key::gestionAllKey()
{
    gestionKeyDown();
    gestionKeyLeft();
    gestionKeyRight();
    gestionKeyUp();
    gestionBack();
    gestionKeyAction();
    gestionBindingCurrentKey();
    this->_changePlayer->gestionChangePlayer(this->_mousePoint, this->_mouse);
}

const void Key::unloadKeysTexture() const
{
    this->_texture->setUnloadTexture(this->_textureBack);
    this->_texture->setUnloadTexture(this->_textureBackground);
    this->_texture->setUnloadTexture(this->_textureKeyAction);
    this->_texture->setUnloadTexture(this->_textureKeyDown);
    this->_texture->setUnloadTexture(this->_textureKeyLeft);
    this->_texture->setUnloadTexture(this->_textureKeyRight);
    this->_texture->setUnloadTexture(this->_textureKeyUp);
}

const void Key::displayKeys() const
{
    this->_texture->setDrawTexture(this->_textureBackground, 0, 0);
    this->_texts->setDrawText("SETTINGS", 730, 100, 70, WHITE);
    this->_texts->setDrawText("ACTION", 410, 250, 60, RED);
    this->_texts->setDrawText("MOVE", 870, 250, 60, RED);
    this->_texts->setDrawText("PLAYER ", 1920 / 2 - 190, 720, 60, RED);
    this->_texts->setDrawText(TextFormat("%d", this->_changePlayer->_selectionNb), 1920 / 2 + 150, 720, 60, RED);
    this->_texture->setDrawTextureRec(this->_textureKeyUp, this->_sourceKeyUpRec, this->_btnKeyUpBounds.x, this->_btnKeyUpBounds.y);
    this->_texture->setDrawTextureRec(this->_textureKeyDown, this->_sourceKeyDownRec, this->_btnKeyDownBounds.x, this->_btnKeyDownBounds.y);
    this->_texture->setDrawTextureRec(this->_textureKeyLeft, this->_sourceKeyLeftRec, this->_btnKeyLeftBounds.x, this->_btnKeyLeftBounds.y);
    this->_texture->setDrawTextureRec(this->_textureKeyRight, this->_sourceKeyRightRec, this->_btnKeyRightBounds.x, this->_btnKeyRightBounds.y);
    this->_texture->setDrawTextureRec(this->_textureKeyAction, this->_sourceKeyActionRec, this->_btnKeyActionBounds.x, this->_btnKeyActionBounds.y);
    this->_texture->setDrawTextureRec(this->_textureBack, this->_sourceBackRec, this->_btnBackBounds.x, this->_btnBackBounds.y);
    if (this->_changePlayer->_currentPlayer == KEY_PLAYER_ONE) {
        displayPlayerKeys(this->_playerOneKey);
    } else if (this->_changePlayer->_currentPlayer == KEY_PLAYER_TWO) {
        displayPlayerKeys(this->_playerTwoKey);
    } else if (this->_changePlayer->_currentPlayer == KEY_PLAYER_THREE) {
        displayPlayerKeys(this->_playerThreeKey);
    } else if (this->_changePlayer->_currentPlayer == KEY_PLAYER_FOUR) {
        displayPlayerKeys(this->_playerFourKey);
    }
    this->_changePlayer->displayChangePlayer();
}

const void Key::displayPlayerKeys(std::vector<int> player) const
{
    if (player[TAB_KEY_UP] >= 33 && player[TAB_KEY_UP] <= 125)
        this->_texts->setDrawText(TextFormat("%c", player[TAB_KEY_UP]), 940, 390, 60, BLACK);
    else
        this->_texts->setDrawText(TextFormat("?"), 940, 390, 60, BLACK);
    if (player[TAB_KEY_DOWN] >= 33 && player[TAB_KEY_DOWN] <= 125)
        this->_texts->setDrawText(TextFormat("%c", player[TAB_KEY_DOWN]), 940, 540, 60, BLACK);
    else
        this->_texts->setDrawText(TextFormat("?"), 940, 540, 60, BLACK);
    if (player[TAB_KEY_LEFT] >= 33 && player[TAB_KEY_LEFT] <= 125)
        this->_texts->setDrawText(TextFormat("%c", player[TAB_KEY_LEFT]), 780, 540, 60, BLACK);
    else
        this->_texts->setDrawText(TextFormat("?"), 780, 540, 60, BLACK);
    if (player[TAB_KEY_RIGHT] >= 33 && player[TAB_KEY_RIGHT] <= 125)
        this->_texts->setDrawText(TextFormat("%c", player[TAB_KEY_RIGHT]), 1105, 540, 60, BLACK);
    else
        this->_texts->setDrawText(TextFormat("?"), 1105, 540, 60, BLACK);
    if (player[TAB_KEY_DROP] >= 33 && player[TAB_KEY_DROP] <= 125)
        this->_texts->setDrawText(TextFormat("%c", player[TAB_KEY_DROP]), 502, 540, 60, BLACK);
    else
        this->_texts->setDrawText(TextFormat("?"), 502, 540, 60, BLACK);
}

const void Key::startKeys()
{
    setAllKeys();
    while (!WindowShouldClose())
    {
        this->_mousePoint = this->_mouse->getMousePos();
        this->_btnBackAction = false;
        gestionAllKey();
        if (this->_btnBackAction == true)
        {
            break;
        }
        this->_texture->setBeginDrawing();
        this->_window->setClearBackground();
        displayKeys();
        this->_texture->setEndDrawing();
    }
    unloadKeysTexture();
    this->_changePlayer->deleteChangePlayer();
}

const void Key::deleteKeys() const
{
    this->_sound->deleteSoundButton();
    unloadKeysTexture();
}
