void average(int source[][IMAGE_WIDTH], int result[][IMAGE_WIDTH])
{
    for ( int i=0; i<IMAGE_HEIGHT; i++ )
    {
        for ( int j=0; j<IMAGE_WIDTH; j++)
        {
            if (!(( i==0||i==IMAGE_HEIGHT-1)||(j==0||j==IMAGE_WIDTH-1)))
            {
                int sum = source[i-1][j-1] + source[i-1][j] + source[i-1][j+1]
                          + source[i][j-1] + source[i][j] + source[i][j+1]
                          + source[i+1][j-1] + source[i+1][j] + source[i+1][j+1];
                result[i][j] = sum/9;
            }
        }
    }
}
