void adjust_brightness(int source[][IMAGE_WIDTH],
                       int result[][IMAGE_WIDTH],
                       int adjustment)
{
    for ( int i=0; i<IMAGE_HEIGHT; i++ )
    {
        for ( int j=0; j<IMAGE_WIDTH; j++)
        {
            result[i][j] = source[i][j] + adjustment;
            result[i][j] = clip ( result[i][j] );
        }
    }
}
