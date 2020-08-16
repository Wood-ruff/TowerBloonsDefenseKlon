#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Object.h"
#include "Globals.h"
#include "MoB.h"
#include "Timer.h"
#include "Game.h"

int main()
{
    Game* game = new Game();
    game->gameloop();

    return 0;
}