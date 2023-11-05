/*
RGB_LED - Arduino Library for GUVA-S12SD UV Sensors
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

#include "Arduino.h"
#include "RGB_LED.h"

const int RGB_LED::COLOR_RED[3] = {255, 0, 0};
const int RGB_LED::COLOR_GREEN[3] = {0, 255, 0};
const int RGB_LED::COLOR_BLUE[3] = {0, 0, 255};
const int RGB_LED::COLOR_WHITE[3] = {255, 255, 255};
const int RGB_LED::COLOR_YELLOW[3] = {255, 255, 0};
const int RGB_LED::COLOR_ORANGE[3] = {255, 165, 0};
const int RGB_LED::COLOR_PURPLE[3] = {128, 0, 128};


RGB_LED::RGB_LED(int red_channel, int green_channel, int blue_channel, bool common_anode)
{
    this->red_channel = red_channel;
    this->green_channel = green_channel;
    this->blue_channel = blue_channel;
    this->common_anode = common_anode;
    this->on = false;
    this->brightness = 1.0;
    this->red = 0;
    this->green = 0;
    this->blue = 0;
}

void RGB_LED::begin()
{
    pinMode(this->red_channel, OUTPUT);
    pinMode(this->green_channel, OUTPUT);
    pinMode(this->blue_channel, OUTPUT);
    this->setOff();
}

void RGB_LED::setOn() {
    int r = (int) red * brightness;
    int g = (int) green * brightness;
    int b = (int) blue * brightness;
    if (common_anode) {
        r = 255 - r;
        g = 255 - g;
        b = 255 - b;
    }
    write_rgb(r, g, b);
    on = true;
}

void RGB_LED::setOff() {
    if (common_anode) {
        write_rgb(255, 255, 255);
    } else {
        write_rgb(0, 0, 0);
    }
    on = false;
}

void RGB_LED::toggle() {
    if ( on ) {
        setOff();
    } else {
        setOn();
    }
}

void RGB_LED::setColor(int red, int green, int blue, bool write)
{
    this->red = constrain(red, 0, 255);
    this->green = constrain(green, 0, 255);
    this->blue = constrain(blue, 0, 255);
    if (on && write) {
        setOn();
    }
}

void RGB_LED::setColor(const int rgb[3], bool write)
{
    setColor(rgb[0], rgb[1], rgb[2], write);
}

void RGB_LED::setBrightness(float brightness, bool write) {
    this->brightness = constrain(brightness, 0.0, 1.0);
    if (on & write ) {
        setOn();
    }
}

void RGB_LED::write_rgb(int red, int green, int blue)
{
    analogWrite(red_channel, red);
    analogWrite(green_channel, green);
    analogWrite(blue_channel, blue);
}
