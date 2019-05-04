/* Copyright 2019 Tim Crenshaw
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include "quantum.h"

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.
 */
/*
#define LAYOUT(                                                                   \
//┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐  Left Hand
     K00L,    K10L,    K20L,    K30L,    K40L,    K50L,    K60L,                  \
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     K01L,    K11L,    K21L,    K31L,    K41L,    K51L,    K61L,                  \
//├────────┼────────┼────────┼────────┼────────┼────────┤        │
     K02L,    K12L,    K22L,    K32L,    K42L,    K52L,                           \
//├────────┼────────┼────────┼────────┼────────┼────────┼────────┘
     K03L,    K13L,    K23L,    K33L,    K43L,    K53L,                           \
//├────────┼────────┼────────┼────────┼────────┼────────┘   ┌────────┬────────┐
     K04L,    K14L,    K24L,    K34L,    K44L,                 K62L,    K72L,     \
//└────────┴────────┴────────┴────────┴────────┘   ┌────────┼────────┼────────┤
                                                      K54L,    K64L,    K73L,     \
//                                                 │        │        ├────────┤
                                                                         K74L,    \
//                                                 └────────┴────────┴────────┘
                                                                                  \
// Right Hand  ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┐
                  K60R,    K50R,    K40R,    K30R,    K20R,    K10R,    K00R,     \
//             ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
                  K61R,    K51R,    K41R,    K31R,    K21R,    K11R,    K01R,     \
//             │        ├────────┼────────┼────────┼────────┼────────┼────────┤
                           K52R,    K42R,    K32R,    K22R,    K12R,    K02R,     \
//             └────────┼────────┼────────┼────────┼────────┼────────┼────────┤
                           K53R,    K43R,    K33R,    K23R,    K13R,    K03R,     \
//┌────────┬────────┐   └────────┼────────┼────────┼────────┼────────┼────────┤
     K72R,    K62R,                 K44R,    K34R,    K24R,    K14R,    K04R,     \
//├────────┼────────┼────────┐   └────────┴────────┴────────┴────────┴────────┘
     K73R,    K64R,    K54R,                                                      \
//├────────┤        │        │
     K74R,                                                                        \
//└────────┴────────┴────────┘
) */
#define LAYOUT(                                                              \
K00L,    K10L,    K20L,    K30L,    K40L,    K50L,    K60L,                  \
K01L,    K11L,    K21L,    K31L,    K41L,    K51L,    K61L,                  \
K02L,    K12L,    K22L,    K32L,    K42L,    K52L,                           \
K03L,    K13L,    K23L,    K33L,    K43L,    K53L,                           \
K04L,    K14L,    K24L,    K34L,    K44L,                 K62L,    K72L,     \
K54L,    K64L,    K73L,                                                      \
K74L,                                                                        \
K60R,    K50R,    K40R,    K30R,    K20R,    K10R,    K00R,                  \
K61R,    K51R,    K41R,    K31R,    K21R,    K11R,    K01R,                  \
K52R,    K42R,    K32R,    K22R,    K12R,    K02R,                           \
K53R,    K43R,    K33R,    K23R,    K13R,    K03R,                           \
K72R,    K62R,                 K44R,    K34R,    K24R,    K14R,    K04R,     \
K73R,    K64R,    K54R,                                                      \
K74R                                                                         \
)                                                                            \
{                                                                            \
    { K00L, K10L, K20L, K30L, K40L, K50L, K60L,  KC_NO  },                   \
    { K01L, K11L, K21L, K31L, K41L, K51L, K61L,  KC_NO  },                   \
    { K02L, K12L, K22L, K32L, K42L, K52L, K62L,  K72L   },                   \
    { K03L, K13L, K23L, K33L, K43L, K53L, KC_NO, K73L   },                   \
    { K04L, K14L, K24L, K34L, K44L, K54L, K64L,  K74L   },                   \
    { K00R, K10R, K20R, K30R, K40R, K50R, K60R,  KC_NO  },                   \
    { K01R, K11R, K21R, K31R, K41R, K51R, K61R,  KC_NO  },                   \
    { K02R, K12R, K22R, K32R, K42R, K52R, K62R,  K72R   },                   \
    { K03R, K13R, K23R, K33R, K43R, K53R, KC_NO, K73R   },                   \
    { K04R, K14R, K24R, K34R, K44R, K54R, K64R,  K74R   }                    \
}
