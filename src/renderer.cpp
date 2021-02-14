//
// Created by Kirill on 09.02.2021.
//
#include "../include/renderer.h"


Renderer::Renderer(std::uint32_t w, std::uint32_t h)
        : w(w), h(h), flush_string(w * h, ' ') {}

void Renderer::draw_line() {
    for (std::uint32_t i = 0; i < w + 2; ++i) {
        ascii_pic.push_back('-');
    }
    ascii_pic.push_back('\n');
}

void Renderer::draw_food(std::string &buffer, const Field &f) {
    buffer[f.get_food_loc()] = '*';
}

void Renderer::draw_snake(std::string &buffer, const Field &f) {
    for (const auto &body_cell : f.get_snake().get_body()) {
        buffer[body_cell] = '+';
    }
}

void Renderer::draw_obstacles(std::string &buffer, const Field &f) {
    for (std::uint32_t i = 0; i < f.get_cells().size(); ++i)
        if (f.get_cells()[i] == obstacle) {
            buffer[i] = '@';
        }
}



const std::string &Renderer::render(const Field &f) {
    auto snake_body = f.get_snake().get_body();
    auto proto_ascii_pic = flush_string;
    ascii_pic = "";

    draw_food(proto_ascii_pic, f);

    draw_obstacles(proto_ascii_pic, f);

    draw_snake(proto_ascii_pic, f);

    draw_line();

    for (std::uint32_t i = 0; i < h; ++i) {
        ascii_pic.push_back('|');
        for (std::uint32_t j = 0; j < h; ++j) {
            ascii_pic.push_back(proto_ascii_pic[f.from_pair(i, j)]);
        }
        ascii_pic.push_back('|');
        ascii_pic.push_back('\n');
    }

    draw_line();

    return ascii_pic;

}




