int clip(int value)
{
    if ( value<PURE_BLACK )
    {
        return PURE_BLACK;
    }
    else if ( value>PURE_WHITE )
    {
        return PURE_WHITE;
    }
    else
    {
        return value;
    }
}
