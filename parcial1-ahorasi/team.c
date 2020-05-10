/*
  @file team.c
  @brief Implements team structure and methods
*/
#include <stdio.h>
#include <stdlib.h>
#include "team.h"

static const char SEPARATOR = ' ';

/**
 * @brief reads characters from file until feof or separator is reached. read characters are stored in 'result'
 *
 * @param[in]  file             An opened stream file
 * @param[in]  separator        string separator
 * @param[out] result           the read characters wil be stored here
 * @param[in]  result_max_size  The maximum of characters that result allow.
 *
 * @return Amount of read characters
 */
static unsigned int process_string(FILE *file, char separator, char result[], unsigned int result_max_size)
{
    unsigned int str_size = 0u;
    char c = (char)((int)separator + 1);
    while (!feof(file) && c != separator) {
        c = fgetc(file);
        if (c != separator && str_size < result_max_size - 1u)
        {
            result[str_size] = c;
            ++str_size;    
        }
        else if (c != separator && str_size >= result_max_size - 1u)
        {
            fprintf(stderr, "Max string length reached: %u \n", result_max_size);
            exit(EXIT_FAILURE);           
        }
    }
    result[str_size] = '\0';

    return str_size;
}

Team team_from_file(FILE* file)
{
    Team team;
    process_string(file, SEPARATOR, team.name, MAX_TEAM_NAME_CHARS);
    unsigned int read_vars = 0u;
    read_vars = fscanf(file, EXPECTED_TEAM_FILE_FORMAT, &team.points,
            &team.game_played, &team.win, &team.tie, &team.lost,
            &team.goal_favor, &team.goal_against);
    //completar aqui
    if(read_vars != AMOUNT_OF_TEAM_DATA - 1u)
    {
        fprintf(stderr, "Wrong team data for %s\n", team.name);
        exit(EXIT_FAILURE);           
    }
    return team;	
}

void team_to_file(FILE* file, Team team)
{
    fprintf(file, "%s ", team.name);
    fprintf(file, EXPECTED_TEAM_FILE_FORMAT, team.points,
            team.game_played, team.win, team.tie, team.lost,
            team.goal_favor, team.goal_against);
}

int goal_diff(Team t)
{
    return t.goal_favor - t.goal_against;
}
