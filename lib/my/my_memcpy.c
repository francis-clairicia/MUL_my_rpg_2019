/*
** EPITECH PROJECT, 2020
** my lib
** File description:
** my_memcpy
*/

#include <stddef.h>

void *my_memcpy(void *dest, const void *src, size_t n)
{
    size_t index = 0;

    if (!dest || !src)
        return (NULL);
    while (index < n) {
        *((char *)dest + index) = *((char *)src + index);
        index++;
    }
    return (dest);
}
