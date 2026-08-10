#include "Input.h"

Input::Input() : keyActions{
    {"up", GLFW_KEY_UP},
    {"down", GLFW_KEY_DOWN},
    {"left", GLFW_KEY_LEFT},
    {"right", GLFW_KEY_RIGHT},
    {"dodge", GLFW_KEY_SPACE},

    {"menu", GLFW_KEY_TAB},
    {"pause", GLFW_KEY_ESCAPE}
} {}

using KeyPressCallback = std::function<void(int)>;



//using CallbackId = uint32_t; //unsigned 32bit int
//event thing
// unsigned int addListener(KeyPressCallback callback)
// {

// }

// void removeListener(unsigned int id)
// {

// }

// events are too hard i give up
// void Input::keyPressed(int key)
// {
//     keyPress(this->keyActions[key]);
// }

std::string Input::translateToAction(int key)
{
    for (const auto& pair : this->keyActions) {
        if (pair.second == key) {
            return pair.first;
        }
    }
    return std::string();
}

int Input::translateToKeyID(std::string action)
{
    //couldve done .at but this checks for no key
    auto it = this->keyActions.find(action);
    if (it == this->keyActions.end()) {
        return -1;
    }
    return it->second;
}
