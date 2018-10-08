#include <string>
#include "libcolor.hpp"

int main() {
    printf("Color from '#123'\n");
    auto c = Color::fromHexString("#123");
    printf("  RGB: %d, %d, %d\n", c.red(), c.green(), c.blue());
    printf("  HEX: %s\n", c.hex().c_str());

    printf("\nBlend #fff color with #000 (k = 0.5)\n");
    auto w = Color::fromHexString("#ffffff");
    auto b = Color::fromHexString("#000");
    w.blend(b);
    printf("  RGB: %d, %d, %d\n", w.red(), w.green(), w.blue());
    printf("  HEX: %s\n", w.hex().c_str());

    printf("\nBlend #fff color with #000 (k = 1)\n");
    w = Color::fromHexString("#ffffff");
    w.blend(b, 1);
    printf("  RGB: %d, %d, %d\n", w.red(), w.green(), w.blue());
    printf("  HEX: %s\n", w.hex().c_str());
}
