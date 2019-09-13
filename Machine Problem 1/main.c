/*
 * MP1 - Sunrise, Sunset
 * Author: <Abdullah Aljandali>
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int main()
{

    double Latitude;
    double Longitude;
    double Timezone;
    double day_of_year;
    double pi = 3.1415926;
    double gama;
    double eqtime;
    double decl;
    double ha;
    double sunrise;
    double sunset;
    int sunrise_hour;
    int sunset_hour;
    int sunset_minute;
    int sunrise_minute;

    printf("Daylight-Sensitive Zombie Protection System\n");
    printf("This program will calculate sunrise and sunset time for any date and location\n\n");

    printf("Enter latitude, longitude:");
    scanf("%lf", &Latitude);

    scanf("%lf", &Longitude);

    printf("Enter Timezone:");
    scanf("%lf", &Timezone);

    printf("Enter day of year:");
    scanf("%lf", &day_of_year);

    gama = 2*(pi)/ 365*(day_of_year - 1);

    eqtime = 229.18 * (0.000075 + 0.001868 * cos(gama) - 0.032077 * sin(gama) - 0.014615* cos(2 * gama) - 0.040849* sin(2*gama));

    decl = 0.006918 - 0.3999912 * cos(gama) + 0.070257 * sin(gama) - 0.006758 * cos(2*gama) + 0.000907 * sin(2* gama) - 0.002697* cos(3* gama) + 0.00148 * sin(3 * gama );

    ha = acos( (cos(1.5853))/(cos(Latitude*pi/180)*cos(decl)) -tan(Latitude*pi/180)*tan(decl) ) * (180/pi);

    sunrise = 720 + 4* (Longitude -ha) - eqtime - 60 * Timezone;

    sunset = 720 + 4*(Longitude + ha)-eqtime - 60* Timezone;

    sunrise_hour = sunrise/60;

    sunrise_minute = sunrise - (sunrise_hour * 60);

    sunset_hour = sunset/60;

    sunset_minute = sunset - (sunset_hour * 60);

    printf("Sunrise: %d:%02d\n" ,sunrise_hour,sunrise_minute);

    printf("Sunset: %d:%02d\n", sunset_hour,sunset_minute);



    return 0;
}
