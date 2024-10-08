#include <math.h>
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Obtenha os valores de vermelho, verde e azul
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            // Calcule a média e arredonde
            int average = round((red + green + blue) / 3.0);

            // Defina cada cor como o valor da média
            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop through each row of pixels
    for (int i = 0; i < height; i++)
    {
        // Loop through half of the row
        for (int j = 0; j < width / 2; j++)
        {
            // Swap the pixel on the left with the pixel on the right
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    // Copiar a imagem original para temp
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    // Aplicar o blur
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int redSum = 0;
            int greenSum = 0;
            int blueSum = 0;
            int counter = 0;

            // Percorrer os pixels vizinhos em um quadrado 3x3
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ni = i + di;
                    int nj = j + dj;

                    // Verificar se o pixel está dentro dos limites
                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        redSum += temp[ni][nj].rgbtRed;
                        greenSum += temp[ni][nj].rgbtGreen;
                        blueSum += temp[ni][nj].rgbtBlue;
                        counter++;
                    }
                }
            }

            // Calcular a média e arredondar
            image[i][j].rgbtRed = round(redSum / (float) counter);
            image[i][j].rgbtGreen = round(greenSum / (float) counter);
            image[i][j].rgbtBlue = round(blueSum / (float) counter);
        }
    }
}

// Detect edges using the Sobel operator
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Temporary copy of the original image
    RGBTRIPLE temp[height][width];

    // Copy the original image into temp
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    // Sobel kernels for Gx and Gy
    int Gx[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };

    int Gy[3][3] = {
        {-1, -2, -1},
        {0,  0,  0},
        {1,  2,  1}
    };

    // Loop through each pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int redX = 0, redY = 0;
            int greenX = 0, greenY = 0;
            int blueX = 0, blueY = 0;

            // Loop through the 3x3 grid around the pixel
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ni = i + di;
                    int nj = j + dj;

                    // Check if neighboring pixel is within image bounds
                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        RGBTRIPLE pixel = temp[ni][nj];

                        // Apply Gx to red, green, blue
                        redX += pixel.rgbtRed * Gx[di + 1][dj + 1];
                        greenX += pixel.rgbtGreen * Gx[di + 1][dj + 1];
                        blueX += pixel.rgbtBlue * Gx[di + 1][dj + 1];

                        // Apply Gy to red, green, blue
                        redY += pixel.rgbtRed * Gy[di + 1][dj + 1];
                        greenY += pixel.rgbtGreen * Gy[di + 1][dj + 1];
                        blueY += pixel.rgbtBlue * Gy[di + 1][dj + 1];
                    }
                }
            }

            // Calculate the final magnitude for each color
            int red = round(sqrt(redX * redX + redY * redY));
            int green = round(sqrt(greenX * greenX + greenY * greenY));
            int blue = round(sqrt(blueX * blueX + blueY * blueY));

            // Cap the values at 255
            image[i][j].rgbtRed = (red > 255) ? 255 : red;
            image[i][j].rgbtGreen = (green > 255) ? 255 : green;
            image[i][j].rgbtBlue = (blue > 255) ? 255 : blue;
        }
    }

    return;
}
