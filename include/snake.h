//
// Created by Kirill on 09.02.2021.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H

#include <unordered_set>
#include <deque>


class Snake {
    std::deque<cell_t> body;
    std::unordered_set<cell_t> occ_cells;
public:

    void init(cell_t cell);

    bool update(cell_t cell, cell_state st);

    [[nodiscard]] cell_t head() const noexcept;

    [[nodiscard]] const std::deque<cell_t> &get_body() const;

    [[nodiscard]] bool is_occ(cell_t cell) const;

    [[nodiscard]] size_t get_size() const noexcept;

};


#endif //SNAKE_SNAKE_H
