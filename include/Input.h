#pragma once

#include <functional>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <string>
#include <map>

#include <GLFW/glfw3.h>




class Input {
public:
    using KeyPressCallback = std::function<void(int)>;

    Input();

    //using CallbackId = uint32_t; //unsigned 32bit int
    //event thing
    unsigned int addListener(KeyPressCallback callback);

    void removeListener(unsigned int id);

    void keyPressed(int key);

    std::string translateToAction(int key);

    int translateToKeyID(std::string action);


private: 
    std::vector<KeyPressCallback> listeners;
    
    //actions
    std::map<std::string, int> keyActions; //map of action name to key id
    
};