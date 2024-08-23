/*
Copyright 2020 Bryan Ong

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "quantum.h"

void keyboard_pre_init_kb(void) {
    gpio_set_pin_output(D7);
    gpio_set_pin_output(D6);
    gpio_set_pin_output(D4);
    
    keyboard_pre_init_user();
}

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if(res) {
        gpio_write_pin(D7, led_state.num_lock);
        gpio_write_pin(D6, led_state.caps_lock);
        gpio_write_pin(D4, led_state.scroll_lock);
    }
    return res;
}
