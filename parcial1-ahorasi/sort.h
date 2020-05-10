/*
  @file sort.h
  @brief Sort functions declarations
*/
#ifndef _SORT_H
#define _SORT_H
#include <stdbool.h>
#include "team.h"

/**
 * @brief Returns true if team 'x' goes before team 'y' in a sorted array of players. 
 *
 * @param[in]  x Team 'x'
 * @param[in]  y Team 'y'
 *
 * @return true if team 'x' goes before team 'y' in a sorted array of teams.
 */
bool goes_before(Team x, Team y);

/**
 * @brief    Checks if the array 'a' is in descending order according 
 *           to the goes_before function
 *
 * @param[in]  t     The Team array
 * @param[in]  length  Length of Team array
 *
 * @return True if array is sorted in descending order according to goes_before function, false otherwise
 */
bool array_is_sorted(Team t[], unsigned int length);


/**
 * @brief Sort the array 'a' using any sorting algorithm. The resulting sort 
 *        will be descending according to the goes_before function. 
 *        The array 'a' must have exactly 'length' elements.
 *
 * @param[in]      a       Team array
 * @param[in]      length  Length of players array
 */
void sort(Team t[], unsigned int length);


#endif
