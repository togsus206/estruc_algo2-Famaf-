/*
  @file weather.c
  @brief Implements weather mesuarement structure and methods
*/
#include "weather.h"
#include <stdlib.h>

static const int AMOUNT_OF_WEATHER_VARS = 6;

Weather weather_from_file(FILE* file) {
    Weather weather;
    int test = 0;
    int avg_temp = 0;
    int max_temp = 0;
    int min_temp = 0;
    unsigned int pressure = 0;
    unsigned int moisture = 0;
    unsigned int rainfall = 0;

    test = fscanf(file, " %d %d %d %u %u %u ", &avg_temp, &max_temp, &min_temp,
                  &pressure, &moisture, &rainfall);
    if (test != 6) {
        fprintf(stderr, "Invalid array.\n");
        exit(EXIT_FAILURE);
    }
    weather._average_temp = avg_temp;
    weather._max_temp = max_temp;
    weather._min_temp = min_temp;
    weather._pressure = pressure;
    weather._moisture = moisture;
    weather._rainfall = rainfall;
    return weather;
}

void weather_to_file(FILE* file, Weather weather) {
    fprintf(file, EXPECTED_WEATHER_FILE_FORMAT, weather._average_temp,
            weather._max_temp, weather._min_temp, weather._pressure,
            weather._moisture, weather._rainfall);
}
