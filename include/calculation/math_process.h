/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** math_process
*/

#ifndef MATH_PROCESS_H_
#define MATH_PROCESS_H_

//Returns a random integer between the given boudings.
int get_randomnb(int min, int max);

//Magnetize the nb passed as parameter with given parameters :
//-magnet is the given number which one of it's multiple will magnetize the
//nb given as parameter if it's close enough
//-offset is the scalar of magnet value representing the minimum range to
//magnetize nb
//-acc is the accuracy of this accuracy for float to int conversion
//Use at least 100 for enough accuracy
bool magnet_number(float *nb, const float offset,
                    const int acc, const float magnet);

#endif /* !MATH_PROCESS_H_ */