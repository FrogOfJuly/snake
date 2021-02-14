//
// Created by Kirill on 09.02.2021.
//

#include "../include/common.h"

bool is_opposite(head_direction one, head_direction another) {
    if (one == up and another == down) {
        return true;
    }
    if (one == left and another == right) {
        return true;
    }
    if (one == right and another == left) {
        return true;
    }
    if (one == down and another == up) {
        return true;
    }
    return false;
}