// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }
    // Loop over the rows of the image.
    for (int i = 0; i < height; i++)
    {
        // Looop over the columns of the image.
        for (int j = 0; j < width; j++)
        {
            int average_red = 0;
            int average_green = 0;
            int average_blue = 0;
            int average = 0;
            if (i - 1 >= 0 && j - 1 >= 0)
            {
                average++;
                average_red += copy[i - 1][j - 1].rgbtRed;
                average_green += copy[i - 1][j - 1].rgbtGreen;
                average_blue += copy[i - 1][j - 1].rgbtBlue;
            }
            if (i - 1 >= 0)
            {
                average++;
                average_red += copy[i - 1][j].rgbtRed;
                average_green += copy[i - 1][j].rgbtGreen;
                average_blue += copy[i - 1][j].rgbtBlue;
            }
            if (i - 1 >= 0 && j + 1 < width)
            {
                average++;
                average_red += copy[i - 1][j + 1].rgbtRed;
                average_green += copy[i - 1][j + 1].rgbtGreen;
                average_blue += copy[i - 1][j + 1].rgbtBlue;
            }
            if (j - 1 >= 0)
            {
                average++;
                average_red += copy[i][j - 1].rgbtRed;
                average_green += copy[i][j - 1].rgbtGreen;
                average_blue += copy[i][j - 1].rgbtBlue;
            }
            if (j + 1 < width)
            {
                average++;
                average_red += copy[i][j + 1].rgbtRed;
                average_green += copy[i][j + 1].rgbtGreen;
                average_blue += copy[i][j + 1].rgbtBlue;
            }
            if (i + 1 < height && j - 1 >= 0)
            {
                average++;
                average_red += copy[i + 1][j  - 1].rgbtRed;
                average_green += copy[i + 1][j - 1].rgbtGreen;
                average_blue += copy[i + 1][j - 1].rgbtBlue;
            }
            if (i + 1 < height)
            {
                average++;
                average_red += copy[i + 1][j].rgbtRed;
                average_green += copy[i + 1][j].rgbtGreen;
                average_blue += copy[i+ 1][j].rgbtBlue;
            }
            if (i + 1 < height && j + 1 < width)
            {
                average++;
                average_red += copy[i + 1][j + 1].rgbtRed;
                average_green += copy[i + 1][j + 1].rgbtGreen;
                average_blue += copy[i + 1][j + 1].rgbtBlue;
            }
            average_red =  average_red / average;
            average_green = average_green / average;
            average_blue =  average_blue / average;
            image[i][j].rgbtRed = average_red;
            image[i][j].rgbtGreen = average_green;
            image[i][j].rgbtBlue = average_blue;
        }
    }

    return;
}
