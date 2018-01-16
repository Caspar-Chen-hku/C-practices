void sharpen(int source[][IMAGE_WIDTH], int result[][IMAGE_WIDTH], int amount)
{
    int arr[IMAGE_HEIGHT][IMAGE_WIDTH];
    blur( source,arr );
    for ( int i=0; i<IMAGE_HEIGHT; i++ )
    {
        for ( int j=0; j<IMAGE_WIDTH; j++)
        {
            int unsharp = source[i][j]-arr[i][j];
            result[i][j] = source[i][j] + unsharp*amount/100;
            result[i][j] = clip(result[i][j]);
        }
    }
}
