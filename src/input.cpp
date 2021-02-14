//
// Created by Kirill on 09.02.2021.
//

#include "../include/input.h"

#include <thread>
#include <chrono>

int get_hd_with_timeout(std::istream &is, std::ostream &os, std::uint16_t timeout_in_sec) {
    bool was_input = false;
    char key;
    std::thread input_thread([&]() mutable -> void {
        os << ">";
        is >> key;
        os << "\b\b";
        was_input = true;
    });

    std::this_thread::sleep_for(std::chrono::seconds(timeout_in_sec));
    input_thread.detach();
    os << "\b\b";
    if (was_input) {
        return static_cast<int>(key);
    }
    return -1;
}

head_direction get_direction_with_default(char key, head_direction def) {
    head_direction hd;
    switch (key) {
        case 'w':
            std::cout << "w key pressed" << std::endl;
            hd = up;
            break;
        case 's':
            std::cout << "s key pressed" << std::endl;
            hd = down;
            break;
        case 'a':
            std::cout << "a key pressed" << std::endl;
            hd = left;
            break;
        case 'd':
            std::cout << "d key pressed" << std::endl;
            hd = right;
            break;
        default:
            hd = def;
            break;
    }
    return hd;
}

