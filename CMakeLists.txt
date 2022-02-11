cmake_minimum_required(VERSION 3.11)

project(bomberman)

find_package(raylib 3.6 QUIET)

if (NOT raylib_FOUND) # If there's none, fetch and build raylib
  include(FetchContent)

  FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/b6c8d343dca2ef19c23c50975328a028124cf3cb.tar.gz
  )

  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib)

    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples

    # build raylib
    add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})

  endif()

endif()

add_executable(
    ${PROJECT_NAME}
    WIN32
    ./src/main.cpp
    ./src/Error.cpp
    ./src/Game/Game.cpp
    ./src/Game/Player.cpp
    ./src/Game/Map.cpp
    ./src/Game/Menu.cpp
    ./src/Game/Bomb.cpp
    ./src/Game/BombList.cpp
    ./src/Game/Pause.cpp
    ./src/Game/RangeMax.cpp
    ./src/Game/SpeedMax.cpp
    ./src/Game/BombMax.cpp
    ./src/Game/ThroughWall.cpp
    ./src/Game/WallPass.cpp
    ./src/Game/Introduction.cpp
    ./src/Game/AI.cpp
    ./src/Game/MoveAI.cpp
    ./src/Input/Key.cpp
    ./src/Input/Start.cpp
    ./src/Input/Quit.cpp
    ./src/Input/Plus.cpp
    ./src/Input/Minus.cpp
    ./src/Input/HowToPlay.cpp
    ./src/Input/Button.cpp
    ./src/Input/Background.cpp
    ./src/Input/ChangeSizeMap.cpp
    ./src/Input/Setting.cpp
    ./src/Input/ArrowRight.cpp
    ./src/Input/ArrowLeft.cpp
    ./src/Input/ArrowUp.cpp
    ./src/Input/ArrowDown.cpp
    ./src/Input/Border.cpp
    ./src/Input/ChangePlayer.cpp
    ./src/Input/SplashScreen.cpp
    ./src/Component/Textures.cpp
    ./src/Component/Model.cpp
    ./src/Component/Window.cpp
    ./src/Component/Mouse.cpp
    ./src/Component/Text.cpp
    ./src/Component/Sound.cpp
    ./src/Component/KeyEvent.cpp
    ./src/Component/Camera.cpp
    ./src/Component/Image.cpp
    ./src/Component/Music.cpp
    ./src/Component/Save.cpp
    ./src/Component/Controller.cpp
    ./include/Component/Controller.hpp
    ./include/Component/Save.hpp
    ./include/Component/Music.hpp
    ./include/Component/Image.hpp
    ./include/Component/Camera.hpp
    ./include/Component/Sound.hpp
    ./include/Component/Text.hpp
    ./include/Component/Model.hpp
    ./include/Component/Mouse.hpp
    ./include/Component/Textures.hpp
    ./include/Component/Window.hpp
    ./include/Component/KeyEvent.hpp
    ./include/Component/IComponent.hpp
    ./include/Game/Game.hpp
    ./include/Game/Map.hpp
    ./include/Game/Pause.hpp
    ./include/Game/Player.hpp
    ./include/Game/Menu.hpp
    ./include/Game/Bomb.hpp
    ./include/Game/BombList.hpp
    ./include/Game/RangeMax.hpp
    ./include/Game/BombMax.hpp
    ./include/Game/SpeedMax.hpp
    ./include/Game/ThroughWall.hpp
    ./include/Game/WallPass.hpp
    ./include/Game/Introduction.hpp
    ./include/Game/AI.hpp
    ./include/Game/MoveAI.hpp
    ./include/ICore.hpp
    ./include/Input/Key.hpp
    ./include/Input/Start.hpp
    ./include/Input/Quit.hpp
    ./include/Input/Minus.hpp
    ./include/Input/Plus.hpp
    ./include/Input/HowToPlay.hpp
    ./include/Input/Button.hpp
    ./include/Input/Background.hpp
    ./include/Input/ChangeSizeMap.hpp
    ./include/Input/Setting.hpp
    ./include/Input/ArrowLeft.hpp
    ./include/Input/ArrowRight.hpp
    ./include/Input/ArrowUp.hpp
    ./include/Input/ArrowDown.hpp
    ./include/Input/Border.hpp
    ./include/Input/ChangePlayer.hpp
    ./include/Input/SplashScreen.hpp
    ./include/Input/InputHandler.hpp
    ./include/Error.hpp
)

target_link_libraries(${PROJECT_NAME} raylib)
