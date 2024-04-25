#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <iostream>
#include <string>
#include <thread>
#include <list>
#include <fstream>

using namespace std;
using namespace ftxui;
int main(int argc, char const *argv[])
{
    list<string> textos;
    fstream imagen;
    imagen.open("./assets/imagen.txt");

    string linea;
    while (getline(imagen, linea))
    {
        textos.push_back(linea);
    }
    imagen.close();

    /*const string texto = "Hola mundo";
    Element textElement = text(texto);*/
    int fotograma = 0;
    string reset;
    int posX = 0;
    int posY = 6;

    while (true)
    {
        fotograma++;
        Element personaje = spinner(21, fotograma);
        Decorator colorFondo = bgcolor(Color::Aquamarine1Bis);
        Decorator colorTexto = color(Color::IndianRed1);
        Element dibujo = border({hbox(personaje) | colorFondo | colorTexto});

        // Element dibujo = border(hbox(cuadro));

        Dimensions Alto = Dimension::Full();
        Dimensions Ancho = Dimension::Full();

        Screen pantalla = Screen::Create(Ancho, Alto);

        Render(pantalla, dibujo);

        /*textos.push_back("Primera linea");
        textos.push_back("Segunda linea");
        textos.push_back("Tercera linea");*/
        int l = 0;
        for (auto &&texto : textos)
        {
            int i = 0;
            for (auto &&letra : texto)
            {
                pantalla.PixelAt(posX + i, posY + l).character = letra;
                i++;
            }
            l++;
        }

        posX++;
        /*pantalla.PixelAt(posX+1,6).character = "O";
        pantalla.PixelAt(posX+2,6).character = "L";
        pantalla.PixelAt(posX+3,6).character = "A";*/

        pantalla.Print();
        reset = pantalla.ResetPosition();
        cout << reset;
        this_thread::sleep_for(0.1s);
    }

    return 0;
}
