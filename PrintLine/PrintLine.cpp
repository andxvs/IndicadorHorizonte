#include "Arduino.h"
#include "PrintLine.h"
#include "math.h"


//Constructor
PrintLine::PrintLine(int x0, int y0, int x1, int y1, int yoffset)
{
    x0 = _x0;
    y0 = _y0;
    x1 = _x1;
    y1 = _y1;
    yoffset = _yoffset;
}

int PrintLine::x0_val(int x0, int y0, int x1, int y1, int yoffset)
{
    if (yoffset > 42 && x0 == 0 && y0 > 0 && x1 == 84 && y1 < 84)
    {
        return 0;
    }
    if (yoffset < 42 && x0 == 0 && y0 > 0 && x1 == 84 && y1 < 84)
    {
        y0 = y0-yoffset;
        if (y0 < 0)
        {
            return abs(y0);
        }   
        else
        {
            return 0;
        }
    }
    if (yoffset > 42 && x0 > 0 && y0 == 0 && x1 < 84 && y1 == 84)
    {
        x0 = x0 - yoffset;
        if (x0 < 0)
        {
            return 0;
        }
        else
        {
            return x0;
        }
        
    }
    if (yoffset < 42 && x0 > 0 && y0 == 0 && x1 < 84 && y1 == 84)
    {
        x0 = x0 + yoffset;
        return x0;
    }
    if (yoffset > 42 && x0 == 0 && y0 < 84 && x1 == 84 && y1 > 0)
    {
        y0 = y0 + yoffset;
        if (y0 > 84)
        {
            x0 = y0 - 84;
            return x0;
        }
        else
        {
            return 0;
        }
        
    }
    if (yoffset < 42 && x0 == 0 && y0 < 84 && x1 == 84 && y1 > 0)
    {
        return 0;
    }
    if (yoffset > 42 && x0 > 0 && y0 == 0 && x1 < 84 && y1 == 84)
    {
        x0 = x0 + yoffset;
        if (x0 > 84)
        {
            return 84;
        }
        else
        {
            return x0;
        }
    }
    if (yoffset < 42 && x0 > 0 && y0 == 0 && x1 < 84 && y1 == 84)
    {
        x0 = x0 - yoffset;
        if (x0 < 0)
        {
            return 0;
        }
        else
        {
            return x0;
        }   
    }
    else
    {
        return -1;
    }
    
}

int PrintLine::y0_val(int x0, int y0, int x1, int y1, int yoffset)
{
    if (yoffset > 42 && x0 == 0 && y0 > 0 && x1 == 84 && y1 < 84)
    {
        y0 = y0 + yoffset;
        if (y0 > 84)
        {
            return 84;
        }
        else
        {
            return y0;
        }
        
    }
    if (yoffset < 42 && x0 == 0 && y0 > 0 && x1 == 84 && y1 < 84)
    {
        y0 = y0 - yoffset;
        if (y0 < 0)
        {
            return 0;
        }
        else
        {
            return y0;
        }
        
    }
    if (yoffset > 42 && x0 > 0 && y0 == 0 && x1 < 84 && y1 == 84)
    {
        x0 = x0 - yoffset;
        if (x0 < 0)
        {
            abs(x0);
        }
        else
        {
            return 0;
        }
        
    }
    if (yoffset < 42 && x0 > 0 && y0 == 0 && x1 < 84 && y1 == 84)
    {
        return 0;
    }
    if (yoffset > 42 && x0 == 0 && y0 < 84 && x1 == 84 && y1 > 0)
    {
        y0 = y0 + yoffset;
        if (y0 > 84)
        {
            return 84;
        }
        else
        {
            return y0;
        }
        
    }
    if (yoffset < 42 && x0 == 0 && y0 < 84 && x1 == 84 && y1 > 0)
    {
        x0 = x0 - yoffset;
        if (x0 < 0)
        {
            y0 = 84 - abs(x0);
            return y0;
        }
        else
        {
            return 84;
        }
        
    }
    if (yoffset > 42 && x0 > 0 && y0 == 0 && x1 < 84 && y1 == 84)
    {
        return 0;
    }
    if (yoffset < 42 && x0 > 0 && y0 == 0 && x1 < 84 && y1 == 84)
    {
        int result = x0 - yoffset;
        if (result < 0)
        {
            y0 = 84 + result;
            return y0;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return -1;
    }
}

int PrintLine::x1_val(int x0, int y0, int x1, int y1, int yoffset)
{
    if (yoffset > 42 && x0 == 0 && y0 > 0 && x1 == 84 && y1 < 84)
    {
        y1 = y1 + yoffset;
        if (y1 > 84)
        {
            y1 = 84 - abs(y1);
            return y1;
        }
        else
        {
            return 0;
        }      
    }
    if (yoffset < 42 && x0 == 0 && y0 > 0 && x1 == 84 && y1 < 84)
    {
        return 0;
    }
    if (yoffset > 42 && x0 > 0 && y0 == 0 && x1 < 84 && y1 == 84)
    {
        y1 = x1 - yoffset;
        if (y1 < 0)
        {
            return 0;
        }
        else
        {
            return y1;
        }  
    }
    if (yoffset < 42 && x0 > 0 && y0 == 0 && x1 < 84 && y1 == 84)
    {
        x1 = y1 + yoffset;
        if (x1 > 84)
        {
            return 84;
        }
        else
        {
            return x1;
        }   
    }
    if (yoffset > 42 && x0 == 0 && y0 < 84 && x1 == 84 && y1 > 0)
    {
        return 0;
    }
    if (yoffset < 42 && x0 == 0 && y0 < 84 && x1 == 84 && y1 > 0)
    {
        y1 = y1 - yoffset;
        if (y1 < 0)
        {
            y1 = 84 - abs(y1);
            return y1;
        }
        else
        {
            return 0;
        }
    }
    if (yoffset > 42 && x0 > 0 && y0 == 0 && x1 < 84 && y1 == 84)
    {
        x1 = x1 + yoffset;
        if (x1 < 84)
        {
            return 84;
        }
        else
        {
            return x1;
        }        
    }
    
    if (yoffset < 42 && x0 > 0 && y0 == 0 && x1 < 84 && y1 == 84)
    {
        x1 = x1 - yoffset;
        if (x1 < 0)
        {
            return 0;
        }
        else
        {
            return x1;
        }   
    }
    else
    {
        return -1;
    }
}

int PrintLine::y1_val(int x0, int y0, int x1, int y1, int yoffset)
{
    if (yoffset > 42 && x0 == 0 && y0 > 0 && x1 == 84 && y1 < 84)
    {
        y1 = y1 + yoffset;
        if (y1 > 84)
        {
            return 84;
        }
        else
        {
            return y1;
        }  
    }
    if (yoffset < 42 && x0 == 0 && y0 > 0 && x1 == 84 && y1 < 84)
    {
        y1 = y1 - yoffset;
        if (y1 < 0)
        {
            return 0;
        }
        else
        {
            return y1;
        }        
    }
    if (yoffset > 42 && x0 > 0 && y0 == 0 && x1 < 84 && y1 == 84)
    {
        return 0;
    }
    if (yoffset < 42 && x0 > 0 && y0 == 0 && x1 < 84 && y1 == 84)
    {
        y1 = x1 + yoffset;
        if (y1 > 84)
        {
            y1 = y1 - 84;
            y1 = y1 + 42;
            return y1;
        }
        else
        {
            return 0;
        }
        
    }
    if (yoffset > 42 && x0 == 0 && y0 < 84 && x1 == 84 && y1 > 0)
    {
        y1 = y1 + yoffset;
        if (y1 > 84)
        {
            return 84;
        }
        else
        {
            return y1;
        }        
    }
    if (yoffset < 42 && x0 == 0 && y0 < 84 && x1 == 84 && y1 > 0)
    {
        y1 = y1 - yoffset;
        if (y1 < 0)
        {
            return 0;
        }
        else
        {
            return y1;
        }  
    }
    if (yoffset > 42 && x0 > 0 && y0 == 0 && x1 < 84 && y1 == 84)
    {
        y1 = x1 + yoffset;
        if (y1 > 84)
        {
            y1 = y1 - 84;
            return y1;
        }
        else
        {
            return 0;
        }
        
    }
    if (yoffset < 42 && x0 > 0 && y0 == 0 && x1 < 84 && y1 == 84)
    {
        return 0;
    }
    else
    {
        return -1;
    }
        
}