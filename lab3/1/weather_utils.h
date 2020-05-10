#include "weather_utils.c"



int min(int a, int b);
int max(int a, int b);
int hist_min_temp (WeatherTable array);
void yearly_max_temp(WeatherTable array, int output[37]);
void rainiest_month(WeatherTable array, t_month output[37]);