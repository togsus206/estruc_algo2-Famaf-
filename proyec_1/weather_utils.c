#include <stdlib.h>
#include "weather.h"


int minth(Weather WeatherTable array){
    int y = (array [1980] [1] [1])._min_temp;
    for (unsigned int year = 0u; year < YEARS; ++year) {
        for (t_month month = january; month <= december; ++month) {
            for (unsigned int day = 0u; day < DAYS; ++day) {
                if ((array [year] [month] [day])._min_temp) < y) {
                    y =  (array [year] [month] [day])._min_temp;
                }
             }
         }
     }
}
                 
