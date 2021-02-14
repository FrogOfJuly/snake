//
// Created by Kirill on 09.02.2021.
//

#ifndef SNAKE_RENDERER_H
#define SNAKE_RENDERER_H

#include <string>

#include "../include/common.h"
#include "../include/field.h"

class Renderer {
    std::uint32_t w, h;
    std::string ascii_pic;
    std::string flush_string;

    void draw_line();

    static void draw_food(std::string &buffer, const Field &f);

    static void draw_snake(std::string &buffer, const Field &f);

    static void draw_obstacles(std::string &buffer, const Field &f);

public:
    Renderer(std::uint32_t w, std::uint32_t h);

    const std::string &render(const Field &f);

};


#endif //SNAKE_RENDERER_H
