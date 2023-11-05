/*
RGB_LED - Arduino Library for controlling RGB LEDs
Copyright (C) 2023  dxcfl

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef RGB_LED_H
#define RGB_LED_H

class RGB_LED
{
public:
  RGB_LED(int red_channel, int green_channel, int blue_channel, bool common_anode = false);
  void begin();
  void setOn();
  void setOff();
  void toggle();
  void setColor(int red, int blue, int green, bool updateIfOn = true);
  void setColor(const int rgb[3], bool updateIfOn = true);
  void setBrightness(float brightness, bool updateIfOn = true);
  bool isOn();

  const static int COLOR_RED[3];
  const static int COLOR_GREEN[3];
  const static int COLOR_BLUE[3];
  const static int COLOR_WHITE[3];
  const static int COLOR_YELLOW[3];
  const static int COLOR_ORANGE[3];
  const static int COLOR_PURPLE[3];

private:
  int red_channel, green_channel, blue_channel;
  bool common_anode;
  int red, green, blue;
  float brightness;
  bool on;
  void write_rgb(int red, int blue, int green);
};

#endif
