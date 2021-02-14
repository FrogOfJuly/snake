#include <iostream>

#include "include/field.h"
#include "include/renderer.h"
#include "include/input.h"

int main() {
    std::uint32_t w = 10, h = 10;
    Field f(w, h);
    Renderer renderer(w, h);


    std::cout << "Controls are 'w' - for up, 's' - for down, 'a' - for left and 'd' - for right" << std::endl;
    std::cout << "Press any key to start the game" << std::endl;
    {
        char anykey;
        std::cin >> anykey;
    }
    head_direction hd = up;
    do {
        std::cout << renderer.render(f) << std::endl;
        char key;
        std::cin >> key;
        auto prev_hd = hd;
        hd = get_direction_with_default(key, prev_hd);
        if (is_opposite(hd, prev_hd) and f.get_snake().get_size() != 1) {
            hd = prev_hd;
        }
    } while (f.update(hd));

    std::cout << "You have lost!! Your score is " << f.get_snake().get_size() << std::endl;

    return 0;
}
