/*
  @file team.h
  @brief Defines team results structure
*/

#ifndef _TEAM_H
#define _TEAM_H
#include <stdio.h>

#define EXPECTED_TEAM_FILE_FORMAT "%u %u %u %u %u %u %u\n" 
#define MAX_TEAM_NAME_CHARS 100
#define AMOUNT_OF_TEAM_DATA 8

/** @brief Type used to represent a team result in a tournament.*/
typedef struct _team
{
    char name[MAX_TEAM_NAME_CHARS]; //nombre del equipo
    unsigned int points; // puntos
    unsigned int game_played; // partidos jugados
    unsigned int win; // partidos ganados
    unsigned int tie; // partidos empatados
    unsigned int lost; // partidos perdidos
    unsigned int goal_favor; // goles a favor
    unsigned int goal_against; // goles en contra
} Team;

/**
 * @brief reads team tournament results from file line
 * @details 
 * Team file line must contain:
 * <string> <unsigned int> <unsigned int> <unsigned int> <unsigned int> <unsigned int> <unsigned int> <unsigned int>
 *  which represents:
 *  Team_name points game_played win tie lost goal_favor goal_against
 *
 * @param[in] file Opened file stream
 * @return Team structure which contain read information from file
 */
Team team_from_file(FILE* file);

/**
 * @brief writes Team information into opened file stream
 * @details 
 * The line will be written using this format:
 * <name> <points> <game_played> <win> <tie> <lost> <goal_favor> <goal_against>
 * 
 * @param[in] file Opened file stream
 * @param[in] weather Weather mesuarement to be written
 */
void team_to_file(FILE* file, Team team);

/**
 * @brief returns goal difference between favor and against
 * 
 * @param[in] t Team
 * @return goal difference between favor and against
 */
int goal_diff(Team t);


#endif //_TEAM_H
