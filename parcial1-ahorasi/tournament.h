/*
  @file tournament.h
  @brief defines tournament methods. 
*/
#ifndef _TOURNAMENT_H
#define _TOURNAMENT_H

#include <stdbool.h>
#include "team.h"
#define MAX_TEAM_AMOUNT 26

typedef  Team Tournament [MAX_TEAM_AMOUNT];

/**
 * @brief Write the content of the array 't' into stdout.
 * @param[in] a array to dump in stdout
 * @param[in] amount_of_teams amount of teams in tornament
 */
void tournament_dump(Tournament t, unsigned int amount_of_teams);


/**
 * @brief reads an array of weather information from file 
 * @details 
 * 
 *  Each element is read from the file located at 'filepath'.
 *  The file must exist in disk and must have its contents in a sequence of
 *  lines, each with the following format:
 *   
 *   <year> <month> <day> <temperature> <high> <low> <pressure> <moisture> <precipitations>
 *   
 *   Those elements are copied into the multidimensional array 'a'.
 *   The dimensions of the array are given by the macro tclimate.
 * 
 * @param[in] t array which will contain read file
 * @param[in] filepath file with weather data
 * @return amount of teams read from file
 */
unsigned int tournament_from_file(Tournament t, const char *filepath);


void tournament_goal_difference(Tournament t, unsigned int amount_of_teams, int goal_diff[]);

#endif
