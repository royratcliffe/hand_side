/*
 * hand_side.h
 * Copyright (c) 2023, Roy Ratcliffe, Northumberland, United Kingdom
 *
 * Permission is hereby granted, free of charge,  to any person obtaining a
 * copy  of  this  software  and    associated   documentation  files  (the
 * "Software"), to deal in  the   Software  without  restriction, including
 * without limitation the rights to  use,   copy,  modify,  merge, publish,
 * distribute, sublicense, and/or sell  copies  of   the  Software,  and to
 * permit persons to whom the Software is   furnished  to do so, subject to
 * the following conditions:
 *
 *     The above copyright notice and this permission notice shall be
 *     included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT  WARRANTY OF ANY KIND, EXPRESS
 * OR  IMPLIED,  INCLUDING  BUT  NOT   LIMITED    TO   THE   WARRANTIES  OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR   PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS  OR   COPYRIGHT  HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY,  WHETHER   IN  AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM,  OUT  OF   OR  IN  CONNECTION  WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#pragma once

struct hand_side {
  void *left, *right;
  struct hand_side *pop;
};

/*!
 * \brief Pushes a new left and right
 * \param top Pointer to top
 * \param left Pointer to lefthand side
 * \param right Pointer to righthand side
 *
 * The push operation both pushes and creates if necessary. The top address is a
 * null pointer initially and this qualifies as a valid but empty hand-side
 * chain. Pushing the first left-right pair adds to the chain using
 * dynamically-allocated heap memory.
 */
struct hand_side *push_hand_side(struct hand_side **top, void *left,
                                 void *right);

void free_hand_side(struct hand_side **top);

void *for_left_and_right_hand_side(struct hand_side **top,
                                   void *(*and)(void *left, void *right,
                                                void *arg),
                                   void *arg);

void *right_for_left_hand_side(struct hand_side **top, void *left);

void *right_for_left_stricmp_hand_side(struct hand_side **top,
                                       const char *left);

void *left_for_right_hand_side(struct hand_side **top, void *right);
