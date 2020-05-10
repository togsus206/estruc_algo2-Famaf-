#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
    if (a <= b) {
        return (a);
    } else {
        return (b);
    }
}

int max(int a, int b) {
    if (a >= b) {
        return (a);
    } else {
        return (b);
    }
}

const char* getMonthName(t_month month) {
    switch (month) {
        case january:
            return "january";
        case february:
            return "february";
        case march:
            return "march";
        case april:
            return "april";
        case may:
            return "may";
        case june:
            return "june";
        case july:
            return "july";
        case august:
            return "august";
        case september:
            return "september";
        case october:
            return "october";
        case november:
            return "november";
        case december:
            return "december";
    }
    return "error";
}

int hist_min_temp(WeatherTable array) {
    int min_temp = (array[0][0][0])._min_temp;
    for (int year = 0; year < 37; year++) {
        for (int month = 0; month < 12; month++) {
            for (int day = 0; day < 28; day++) {
                min_temp = min(min_temp, (array[year][month][day])._min_temp);
            }
        }
    }
    return (min_temp);
}

void yearly_max_temp(WeatherTable array, int output[37]) {
    for (int year = 0; year < 37; year++) {
        int max_temp = (array[year][0][0])._max_temp;
        for (int month = 0; month < 12; month++) {
            for (int day = 0; day < 28; day++) {
                max_temp = max(max_temp, (array[year][month][day])._max_temp);
            }
        }
        output[year] = max_temp;
    }
}

void rainiest_month(WeatherTable array, t_month output[37]) {
    for (int year = 0; year < 37; year++) {
        unsigned int max_month = 0u;
        unsigned int rain_max = 0u;
        for (int day = 0; day < 28; day++) {
            rain_max += ((array[year][january][day])._rainfall);
        }
        for (int month = 1; month < 12; month++) {
            unsigned int new_rain = 0u;
            for (int day = 0; day < 28; day++) {
                new_rain += ((array[year][month][0])._rainfall);
            }
            if (rain_max < new_rain) {
                max_month = month;
                rain_max = new_rain;
            }
        }

        output[year] = max_month;
    }
}
