//
// Created by Kirill on 09.02.2021.
//

#ifndef SNAKE_COMMON_H
#define SNAKE_COMMON_H

#include <cinttypes>

enum cell_state : short {
    empty = 0, obstacle, food
};

enum head_direction : short {
    left = 0, right, up, down
};

bool is_opposite(head_direction one, head_direction another);

using cell_t = std::uint32_t;

#endif //SNAKE_COMMON_H
