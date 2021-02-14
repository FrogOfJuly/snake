//
// Created by Kirill on 08.02.2021.
//

#ifndef SNAKE_FIELD_H
#define SNAKE_FIELD_H

#include <cstdint>
#include <vector>
#include <deque>
#include <string>
#include <unordered_set>


#include "common.h"
#include "snake.h"


class Field {

    Snake snake;
    std::vector<cell_state> cells{};
    std::uint32_t w, h;
    cell_t food_loc;

public:

    [[nodiscard]] const std::vector<cell_state> &get_cells() const;

    Field(std::uint32_t w, std::uint32_t h);

    [[nodiscard]] std::pair<std::uint32_t, std::uint32_t> to_pair(cell_t cell) const;

    [[nodiscard]] cell_t from_pair(std::pair<std::uint32_t, std::uint32_t> p) const;

    [[nodiscard]] cell_t from_pair(std::uint32_t x, std::uint32_t y) const;

    [[nodiscard]] std::pair<std::uint32_t, std::uint32_t>
    wrap_pair(std::pair<std::int32_t, std::int32_t> p) const;

    [[nodiscard]] std::pair<std::uint32_t, std::uint32_t>
    wrap_pair(std::int32_t x, std::int32_t y) const;

    void spawn_snake(cell_t pos);

    bool update(head_direction d);

    void gen_obstacles(double p);

    [[nodiscard]] const Snake &get_snake() const;

    [[nodiscard]] cell_t get_food_loc() const noexcept;

    void gen_food();

};




#endif //SNAKE_FIELD_H
