//
// Created by Kirill on 09.02.2021.
//


#ifndef SNAKE_INPUT_H
#define SNAKE_INPUT_H

#include <iostream>
#include "field.h"

int get_hd_with_timeout(std::istream &is,
                        std::ostream &os,
                        std::uint16_t timeout_in_sec);

head_direction get_direction_with_default(char key, head_direction def);

#endif //SNAKE_INPUT_H
