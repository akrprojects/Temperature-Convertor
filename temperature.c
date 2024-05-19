#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

string temperature(char temp);
float conversion(char temp, char convert, float value);

int main(void)
{
    printf("Temperature Converter\n");
    printf("Note: Celsius = C, Fahrenheit = F, Kelvin = K\n");
    printf("Enter degrees\n");

    char temp, convert;

    temp = tolower(get_char("From(C/F/K): "));
    convert = tolower(get_char("To(C/F/K): "));

    float temp_value;

    temp_value = get_float("Enter %s: ", temperature(temp));
    printf("The value in %s is : %f\n", temperature(convert), conversion(temp, convert, temp_value));

    return 0;
}

string temperature(char temp)
{
    if (temp == 'c')
    {
        return "celsius";
    }
    else if (temp == 'f')
    {
        return "fahrenheit";
    }
    else
    {
        return "kelvin";
    }
}


float conversion(char temp, char convert, float value)
{
    float converted;
    if ((temp == 'c' || temp == 'f') && convert == 'k')
    {
        if (temp == 'c')
        {
            converted = value + 273.15;
        }
        else
        {
            converted =  (5.0/9)*(value - 32) + 273.15;
        }
    }

    else if ((temp == 'f' || temp == 'k') && convert == 'c')
    {
        if (temp == 'f')
        {
            converted = (5.0/9)*(value - 32);
        }
        else
        {
            converted = value - 273.15;
        }
    }

    else
    {
        if (temp == 'k')
        {
            converted =  (9.0/5)*(value - 273.15) + 32;
        }
        else
        {
            printf("converting celsius to fahrenheit\n");
            converted = (9.0/5)*(value) + 32;
        }
    }
    return converted;
}
