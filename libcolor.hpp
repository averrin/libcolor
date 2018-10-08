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

/* Web colors
{
  {"maroon", "#800000"},
  {"dark red", "#8B0000"},
  {"brown", "#A52A2A"},
  {"firebrick", "#B22222"},
  {"crimson", "#DC143C"},
  {"red", "#FF0000"},
  {"tomato", "#FF6347"},
  {"coral", "#FF7F50"},
  {"indian red", "#CD5C5C"},
  {"light coral", "#F08080"},
  {"dark salmon", "#E9967A"},
  {"salmon", "#FA8072"},
  {"light salmon", "#FFA07A"},
  {"orange red", "#FF4500"},
  {"dark orange", "#FF8C00"},
  {"orange", "#FFA500"},
  {"gold", "#FFD700"},
  {"dark golden rod", "#B8860B"},
  {"golden rod", "#DAA520"},
  {"pale golden rod", "#EEE8AA"},
  {"dark khaki", "#BDB76B"},
  {"khaki", "#F0E68C"},
  {"olive", "#808000"},
  {"yellow", "#FFFF00"},
  {"yellow green", "#9ACD32"},
  {"dark olive green", "#556B2F"},
  {"olive drab", "#6B8E23"},
  {"lawn green", "#7CFC00"},
  {"chart reuse", "#7FFF00"},
  {"green yellow", "#ADFF2F"},
  {"dark green", "#006400"},
  {"green", "#008000"},
  {"forest green", "#228B22"},
  {"lime", "#00FF00"},
  {"lime green", "#32CD32"},
  {"light green", "#90EE90"},
  {"pale green", "#98FB98"},
  {"dark sea green", "#8FBC8F"},
  {"medium spring green", "#00FA9A"},
  {"spring green", "#00FF7F"},
  {"sea green", "#2E8B57"},
  {"medium aqua marine", "#66CDAA"},
  {"medium sea green", "#3CB371"},
  {"light sea green", "#20B2AA"},
  {"dark slate gray", "#2F4F4F"},
  {"teal", "#008080"},
  {"dark cyan", "#008B8B"},
  {"aqua", "#00FFFF"},
  {"cyan", "#00FFFF"},
  {"light cyan", "#E0FFFF"},
  {"dark turquoise", "#00CED1"},
  {"turquoise", "#40E0D0"},
  {"medium turquoise", "#48D1CC"},
  {"pale turquoise", "#AFEEEE"},
  {"aqua marine", "#7FFFD4"},
  {"powder blue", "#B0E0E6"},
  {"cadet blue", "#5F9EA0"},
  {"steel blue", "#4682B4"},
  {"corn flower blue", "#6495ED"},
  {"deep sky blue", "#00BFFF"},
  {"dodger blue", "#1E90FF"},
  {"light blue", "#ADD8E6"},
  {"sky blue", "#87CEEB"},
  {"light sky blue", "#87CEFA"},
  {"midnight blue", "#191970"},
  {"navy", "#000080"},
  {"dark blue", "#00008B"},
  {"medium blue", "#0000CD"},
  {"blue", "#0000FF"},
  {"royal blue", "#4169E1"},
  {"blue violet", "#8A2BE2"},
  {"indigo", "#4B0082"},
  {"dark slate blue", "#483D8B"},
  {"slate blue", "#6A5ACD"},
  {"medium slate blue", "#7B68EE"},
  {"medium purple", "#9370DB"},
  {"dark magenta", "#8B008B"},
  {"dark violet", "#9400D3"},
  {"dark orchid", "#9932CC"},
  {"medium orchid", "#BA55D3"},
  {"purple", "#800080"},
  {"thistle", "#D8BFD8"},
  {"plum", "#DDA0DD"},
  {"violet", "#EE82EE"},
  {"magenta", "#FF00FF"},
  {"fuchsia", "#FF00FF"},
  {"orchid", "#DA70D6"},
  {"medium violet red", "#C71585"},
  {"pale violet red", "#DB7093"},
  {"deep pink", "#FF1493"},
  {"hot pink", "#FF69B4"},
  {"light pink", "#FFB6C1"},
  {"pink", "#FFC0CB"},
  {"antique white", "#FAEBD7"},
  {"beige", "#F5F5DC"},
  {"bisque", "#FFE4C4"},
  {"blanched almond", "#FFEBCD"},
  {"wheat", "#F5DEB3"},
  {"corn silk", "#FFF8DC"},
  {"lemon chiffon", "#FFFACD"},
  {"light golden rod yellow", "#FAFAD2"},
  {"light yellow", "#FFFFE0"},
  {"saddle brown", "#8B4513"},
  {"sienna", "#A0522D"},
  {"chocolate", "#D2691E"},
  {"peru", "#CD853F"},
  {"sandy brown", "#F4A460"},
  {"burly wood", "#DEB887"},
  {"tan", "#D2B48C"},
  {"rosy brown", "#BC8F8F"},
  {"moccasin", "#FFE4B5"},
  {"navajo white", "#FFDEAD"},
  {"peach puff", "#FFDAB9"},
  {"misty rose", "#FFE4E1"},
  {"lavender blush", "#FFF0F5"},
  {"linen", "#FAF0E6"},
  {"old lace", "#FDF5E6"},
  {"papaya whip", "#FFEFD5"},
  {"sea shell", "#FFF5EE"},
  {"mint cream", "#F5FFFA"},
  {"slate gray", "#708090"},
  {"light slate gray", "#778899"},
  {"light steel blue", "#B0C4DE"},
  {"lavender", "#E6E6FA"},
  {"floral white", "#FFFAF0"},
  {"alice blue", "#F0F8FF"},
  {"ghost white", "#F8F8FF"},
  {"honeydew", "#F0FFF0"},
  {"ivory", "#FFFFF0"},
  {"azure", "#F0FFFF"},
  {"snow", "#FFFAFA"},
  {"black", "#000000"},
  {"dim grey", "#696969"},
  {"grey", "#808080"},
  {"dark grey", "#A9A9A9"},
  {"light grey", "#D3D3D3"},
  {"dim gray", "#696969"},
  {"gray", "#808080"},
  {"dark gray", "#A9A9A9"},
  {"light gray", "#D3D3D3"},
  {"silver", "#C0C0C0"},
  {"gainsboro", "#DCDCDC"},
  {"white smoke", "#F5F5F5"},
  {"white", "#FFFFFF"}
}
  */

#endif // __LIBCOLOR_HPP_
