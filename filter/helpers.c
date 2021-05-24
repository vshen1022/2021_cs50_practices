#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
   for(int i = 0; i < height; i++)
   {
       for(int j = 0; j < width; j++)
       {
           int average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0 );
           image[i][j].rgbtBlue = average;
           image[i][j].rgbtGreen = average;
           image[i][j].rgbtRed = average;
       }
   }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
     for(int i = 0; i < height; i++)
   {
       for(int j = 0; j < width; j++)
       {
           int red = image[i][j].rgbtRed;
           int green = image[i][j].rgbtGreen;
           int blue = image[i][j].rgbtBlue;
           //sepia formula
           int sepiaBlue = round(red * .272 + green * .534 + blue * .131);
           int sepiaGreen = round(red * .349 + green * .686 + blue * .168);
           int sepiaRed = round(red * .393 + green * .769 + blue * .189);
           //maxium rgbst is 255
           if (sepiaBlue > 255)
           {
              sepiaBlue = 255;
           }
           if (sepiaGreen > 255)
           {
               sepiaGreen = 255;
           }
           if (sepiaRed > 255)
           {
               sepiaRed = 255;
           }

          image[i][j].rgbtRed =  sepiaRed;
          image[i][j].rgbtGreen =  sepiaGreen;
          image[i][j].rgbtBlue =  sepiaBlue;
       }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {

            image[i][j] = temp[i][width - j - 1];
        }
    }

    return;
}

// Blur image
 int pixel_valid_check(int i, int j, int n, int m, int height, int width)
    {
        if(i + n >= 0 && i + n <= height && j + m >= 0 && j + m <= width)
        {
           return 1;
        }
        else
        {
            return 0;
        }
    }

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
        {
            int blue_sum, green_sum, red_sum;
            blue_sum = green_sum = red_sum = 0;

            int count = 0;

            for(int n = -1; n <= 1; n++)
            {
                for(int m = -1; m <= 1; m++)
                {
                    if(pixel_valid_check(i, j, n, m, height, width))
                    {
                        count++;
                        blue_sum = blue_sum + temp[i + n][j + m].rgbtBlue;
                        green_sum = green_sum + temp[i + n][j + m].rgbtGreen;
                        red_sum = red_sum + temp[i + n][j + m].rgbtRed;
                    }

                }
            }

           image[i][j].rgbtBlue = round(blue_sum / count);
           image[i][j].rgbtGreen = round(green_sum / count);
           image[i][j].rgbtRed = round(red_sum / count);

        }
    }

    return;
}
