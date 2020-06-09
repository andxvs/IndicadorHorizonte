#ifndef PrintLine_h
#define PrintLine_h

// Clase para la impresion de lineas en la pantalla NOKIA 5110 LCD
class PrintLine
{
    private:
        int _x0, _y0, _x1, _y1, _yoffset;
    public:
        PrintLine(int, int, int, int, int);
        int x0_val(int x0, int y0, int x1, int y1, int yoffset);
        int y0_val(int x0, int y0, int x1, int y1, int yoffset);
        int x1_val(int x0, int y0, int x1, int y1, int yoffset);
        int y1_val(int x0, int y0, int x1, int y1, int yoffset);
};

// Constructores de la clase
#endif






