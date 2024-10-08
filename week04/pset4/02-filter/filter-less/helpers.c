#include "helpers.h"
#include <math.h> // Para usar round()

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

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Obtenha as cores originais
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            // Aplique a fórmula sepia
            int sepiaRed =
                round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue);
            int sepiaGreen =
                round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue);
            int sepiaBlue =
                round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue);

            // Garanta que os valores não excedam 255
            image[i][j].rgbtRed = sepiaRed > 255 ? 255 : sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen > 255 ? 255 : sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue > 255 ? 255 : sepiaBlue;
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
