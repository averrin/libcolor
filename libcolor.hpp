#ifndef __LIBCOLOR_HPP_
#define __LIBCOLOR_HPP_
#include <sstream>
#include <string>
#include <tuple>

typedef std::tuple<int, int, int> RGB;

class Color {
public:
  int r = 0;
  int red() { return r; }
  Color* red(int v) { r = v; return this;}
  int g = 0;
  int green() { return g; }
  Color* green(int v) { g = v; return this;}
  int b = 0;
  int blue() { return b; }
  Color* blue(int v) { b = v; return this;}

  std::string hex() {
    char hexcol[16];
    snprintf(hexcol, sizeof hexcol, "#%02x%02x%02x", r, g, b);
    return std::string(hexcol);
  }

  Color(int _r, int _g, int _b) : r(_r), g(_g), b(_b) {}

  static RGB parseHexString(std::string hexString) {
    if (hexString.front() != '#')
        throw std::invalid_argument("hexString");
    hexString = hexString.substr(1, hexString.size() - 1);
    if (hexString.size() == 3) {
      char hexcol[8];
      snprintf(hexcol, sizeof hexcol, "%c%c%c%c%c%c", hexString[0],
               hexString[0], hexString[1], hexString[1], hexString[2],
               hexString[2]);
      hexString = std::string(hexcol);
    }
    std::stringstream st;
    st << hexString;
    int color;
    st >> std::hex >> color;
    int _r = (color & 0xff0000) >> 16;
    int _g = (color & 0x00ff00) >> 8;
    int _b = (color & 0x0000ff);
    return std::make_tuple(_r, _g, _b);
  }

  static Color fromHexString(std::string hexString) {
    auto rgb = parseHexString(hexString);
    return Color(std::get<0>(rgb), std::get<1>(rgb), std::get<2>(rgb));
  }

  void blend(Color color, float k = 0.5) {
    r = r * (1 - k) + color.r * k;
    g = g * (1 - k) + color.g * k;
    b = b * (1 - k) + color.b * k;

    if (r > 255)
      r = 255;
    if (g > 255)
      g = 255;
    if (b > 255)
      b = 255;
  }
};

#endif // __LIBCOLOR_HPP_
