//
// Created by Kirill on 08.02.2021.
//

#include "../include/field.h"
#include <random>

Field::Field(std::uint32_t w, std::uint32_t h) :
        cells(w * h, cell_state::empty), w(w), h(h), food_loc(0) {
    spawn_snake(w / 2 + w * h / 2);
    gen_food();
    gen_obstacles(0.05);
}

std::pair<std::uint32_t, std::uint32_t> Field::to_pair(cell_t cell) const {
    assert(cell < w * h);
    return std::make_pair(cell % w, cell / w);
}

cell_t Field::from_pair(std::pair<std::uint32_t, std::uint32_t> p) const {
    return from_pair(p.first, p.second);
}

cell_t Field::from_pair(std::uint32_t x, std::uint32_t y) const {
    cell_t cell = x + y * w;
    assert(cell < w * h);
    return cell;
}

std::pair<std::uint32_t, std::uint32_t> Field::wrap_pair(std::pair<std::int32_t, std::int32_t> p) const {
    std::int32_t x = p.first;
    std::int32_t y = p.second;
    return wrap_pair(x, y);
}

std::pair<std::uint32_t, std::uint32_t> Field::wrap_pair(std::int32_t x, std::int32_t y) const {
    std::int32_t sign_w = static_cast<std::int64_t>(w);
    std::int32_t sign_h = static_cast<std::int64_t>(h);
    assert(-sign_w < x < 2 * sign_w);
    assert(-sign_h < y < 2 * sign_h);
    return std::make_pair(static_cast<std::uint32_t>((sign_w + x) % sign_w),
                          static_cast<std::uint32_t>((sign_h + y) % sign_h));
}

void Field::spawn_snake(cell_t pos) {
    snake.init(pos);
}

bool Field::update(head_direction d) {
    auto head = snake.head();
    auto head_pair = to_pair(head);
    auto sign_head_x = static_cast<std::int64_t>(head_pair.first);
    auto sign_head_y = static_cast<std::int64_t>(head_pair.second);
    cell_t next_cell;
    switch (d) {
        case up:
            next_cell = from_pair(wrap_pair(sign_head_x - 1, sign_head_y));
            break;
        case down:
            next_cell = from_pair(wrap_pair(sign_head_x + 1, sign_head_y));
            break;
        case left:
            next_cell = from_pair(wrap_pair(sign_head_x, sign_head_y - 1));
            break;
        case right:
            next_cell = from_pair(wrap_pair(sign_head_x, sign_head_y + 1));
            break;
    }

    if (snake.is_occ(food_loc)) {
        gen_food();
    }

    return snake.update(next_cell, cells[next_cell]);
}

const Snake &Field::get_snake() const {
    return snake;
}

cell_t Field::get_food_loc() const noexcept {
    return food_loc;
}

void Field::gen_food() {
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_int_distribution<std::uint32_t> uni(0, w * h);

    cells[food_loc] = empty;

    auto food_loc_cond = uni(rng);
    while (snake.is_occ(food_loc_cond) or cells[food_loc_cond] != empty) {
        food_loc_cond = (food_loc_cond + w * h + 1) % (w * h);
    }

    food_loc = food_loc_cond;

    cells[food_loc] = food;
}

void Field::gen_obstacles(double p) {
    assert(0.0 <= p <= 1.0);
    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_real_distribution<double> uni(0.0, 1.0);
    for (auto &cell : cells) {
        auto rnd = uni(rng);
        if (rnd < p and not snake.is_occ(cell)) {
            cell = obstacle;
        }
    }
}

const std::vector<cell_state> &Field::get_cells() const {
    return cells;
}

