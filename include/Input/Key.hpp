/*
** EPITECH PROJECT, 2021
** indie
** File description:
** indie
*/

#include "../ICore.hpp"
#include "../Component/IComponent.hpp"
#include "../Input/ChangePlayer.hpp"

#ifndef KEY_HPP_
#define KEY_HPP_

#define EXIT '1'

class Key : IComponent
{
private:
    Vector2 _mousePoint;

protected:
    Texture2D _textureBackground;

    Texture2D _textureKeyUp;
    Texture2D _textureKeyDown;
    Texture2D _textureKeyLeft;
    Texture2D _textureKeyRight;
    Texture2D _textureKeyAction;
    Rectangle _sourceKeyUpRec;
    Rectangle _sourceKeyDownRec;
    Rectangle _sourceKeyLeftRec;
    Rectangle _sourceKeyRightRec;
    Rectangle _sourceKeyActionRec;
    Rectangle _btnKeyUpBounds;
    Rectangle _btnKeyDownBounds;
    Rectangle _btnKeyLeftBounds;
    Rectangle _btnKeyRightBounds;
    Rectangle _btnKeyActionBounds;
    bool _btnKeyUpAction;
    bool _btnKeyDownAction;
    bool _btnKeyLeftAction;
    bool _btnKeyRightAction;
    bool _btnKeyActionAction;
    float _frameKeyUpActionHeight;
    float _frameKeyDownActionHeight;
    float _frameKeyLeftActionHeight;
    float _frameKeyRightActionHeight;
    float _frameKeyActionActionHeight;
    int _buttonKeyUpState;
    int _buttonKeyDownState;
    int _buttonKeyLeftState;
    int _buttonKeyRightState;
    int _buttonKeyActionState;

    Texture2D _textureBack;
    Rectangle _sourceBackRec;
    Rectangle _btnBackBounds;
    bool _btnBackAction;
    float _frameBackHeight;
    int _buttonBackState;

public:
    Key();
    ~Key();
    const void setBackKey();
    const void setPlayerKeys();
    const void setBackgroundKey();
    const void setAllKeys();
    const void gestionAllKey();
    const void gestionKeyUp();
    const void gestionKeyDown();
    const void gestionKeyRight();
    const void gestionKeyLeft();
    const void gestionKeyAction();
    const void gestionBindingCurrentKey();
    std::vector<int> gestionPlayerKey(std::vector<int> player);
    const void gestionBack();
    const void unloadKeysTexture() const;
    const void displayKeys() const;
    const void displayPlayerKeys(std::vector<int> player) const;
    const void startKeys();
    const void deleteKeys() const;

    ChangePlayer *_changePlayer;

    std::vector<int> _playerOneKey;
    std::vector<int> _playerTwoKey;
    std::vector<int> _playerThreeKey;
    std::vector<int> _playerFourKey;
    int _keyClicked;
};

#endif