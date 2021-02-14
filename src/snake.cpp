//
// Created by Kirill on 09.02.2021.
//

#include "../include/common.h"
#include "../include/snake.h"

void Snake::init(cell_t cell) {
    body.push_front(cell);
    occ_cells.insert(cell);
}

bool Snake::update(cell_t cell, cell_state st) {

    if (is_occ(cell)) {
        return false;
    }

    switch (st) {
        case empty:
            occ_cells.erase(body.back());
            body.pop_back();
            break;
        case obstacle:
            return false;
            break;
        case food:
            break;
    }
    body.push_front(cell);
    occ_cells.insert(cell);
    return true;
}

cell_t Snake::head() const noexcept {
    return body.front();
}

const std::deque<cell_t> &Snake::get_body() const {
    return body;
}

bool Snake::is_occ(cell_t cell) const {
    return occ_cells.count(cell) != 0;
}

size_t Snake::get_size() const noexcept {
    return body.size();
}
