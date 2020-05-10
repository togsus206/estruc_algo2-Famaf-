/*
  @file main.c
  @brief Defines main program function
*/

/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "tournament.h"
#include "sort.h"

/**
 * @brief print usage help
 * @param[in] program_name Executable name
 */
void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Load torunament data from a given file in disk.\n"
           "\n"
           "The input file must exist in disk and every line in it must have the following format:\n\n"
           "<team_name> <points> <game_played> <win> <tie> <lost> <goal_favor> <goal_against> \n\n"
           "Those elements must be  unsigned integers except team_name(string)"
           "\n\n",
           program_name);
}

/**
 * @brief reads file path from command line
 * 
 * @param[in] argc amount of command line arguments
 * @param[in] argv command line arguments
 * 
 * @return An string containing read filepath
 */
char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}

/**
 * @brief Main program function
 * 
 * @param[in] argc amount of command line arguments
 * @param[in] argv command line arguments
 * 
 * @return EXIT_SUCCESS when programs executes correctly, EXIT_FAILURE otherwise
 */


void print_goal_diff(Tournament t, unsigned int amount_of_teams, int goal_diff []){
      for (unsigned int i = 0 ; i < amount_of_teams; i++){
              printf("%s %i\n", t[i].name ,goal_diff[i]);
      }   
}



int main(int argc, char *argv[]) {
    char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);
    
    /* create a tournament*/
    Tournament array;
    unsigned int amount_of_teams;
    
    /* parse the file to fill the array and obtain the actual length */
    amount_of_teams = tournament_from_file(array, filepath);
    sort(array, amount_of_teams);
    /* show the array in the screen */
    tournament_dump(array, amount_of_teams);

    int otro_array[MAX_TEAM_AMOUNT];
    tournament_goal_difference(array, amount_of_teams,otro_array);
    printf("\n\n");
    print_goal_diff(array,amount_of_teams, otro_array);
    
    return (EXIT_SUCCESS);
}
