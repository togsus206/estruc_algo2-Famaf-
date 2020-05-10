/*
  @file tournament.c
  @brief tournament implementation
*/
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "tournament.h"

void tournament_dump(Tournament t, unsigned int team_amount) {
    assert(MAX_TEAM_AMOUNT >= team_amount);
    for(unsigned int team = 0u; team < team_amount; ++team)
    {
        team_to_file(stdout, t[team]);
    }
}


unsigned int  tournament_from_file(Tournament t, const char *filepath) {
    FILE *file = NULL;
    
    file = fopen(filepath, "r");
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }
    unsigned int read_teams = 0u;
    while (!feof(file)) {
        if (read_teams >= MAX_TEAM_AMOUNT)
        {
            fprintf(stderr, "Maximum amount of teams (%u) rechead\n", MAX_TEAM_AMOUNT);
            exit(EXIT_FAILURE);
        }
        t[read_teams] = team_from_file(file);
        ++read_teams;

    }
    fclose(file);
    return read_teams;
}




void tournament_goal_difference(Tournament t, unsigned int amount_of_teams, int goal_diff[]){
        
      for (unsigned int i = 0 ; i <= amount_of_teams; i++){
              goal_diff[i] = t[i].goal_favor - t[i].goal_against;
      }   
}

























