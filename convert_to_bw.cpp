void convert_to_bw(int source[][IMAGE_WIDTH], int result[][IMAGE_WIDTH])
{
    for ( int i=0; i<IMAGE_HEIGHT; i++ )
    {
        for ( int j=0; j<IMAGE_WIDTH; j++)
        {
            if ( source[i][j] < (PURE_WHITE+1)/2)
            {
                result[i][j] = PURE_BLACK;
            }
            else
            {
                result[i][j] = PURE_WHITE;
            }
        }
    }
}
