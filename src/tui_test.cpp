#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <iostream>
#include <string>
#include <thread>

using namespace std;
using namespace ftxui;
int main(int argc, char const *argv[])
{
    /*const string texto = "Hola mundo";
    Element textElement = text(texto);*/
    int fotograma = 0;
    string reset;

    while (true)
    {
        fotograma++;
        Element personaje = spinner(21, fotograma);
        Decorator colorFondo = bgcolor(Color::Aquamarine1Bis);
        Decorator colorTexto = color(Color::IndianRed1);
        Element dibujo = border({hbox(personaje) | colorFondo | colorTexto});

        // Element dibujo = border(hbox(cuadro));

        Dimensions Alto = Dimension::Fixed(10);
        Dimensions Ancho = Dimension::Full();

        Screen pantalla = Screen::Create(Ancho, Alto);

        Render(pantalla, dibujo);

        pantalla.Print();
        reset = pantalla.ResetPosition();
        cout << reset;
        this_thread::sleep_for(0.1s);
    }

    return 0;
}
