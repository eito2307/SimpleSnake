// SimpleSnake.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <conio.h>
using namespace std;
bool gameOver;

const int width = 20;//variables for the map
const int height = 20;
int x, y, fruitX,fruitY, score;//variables for snake position variables for fruit, variable for score
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
    //directions key left right, up, down
eDirection dir;
void Setup()
{
    gameOver = false;
    dir = STOP; //stop the snake not going to move at the beggining no se va a mover al inicio
    x = width / 2;//ancho
    y = height / 2;//largo
    //the snake display in the middle of the map
    fruitX = rand() % width;//fruit in random part of the map
    fruitY = rand() % height;
    score = 0;
}
void Draw()
{/*****
  *   *
  *****
 */
    system("cls"); // system("clear");
    //top wall of the map
    for (int i = 0; i < width+2; i++)
        cout << "*";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0) //part left wall
                cout << "*";
           
            if (i == y && j == x)//position snake
                cout << "0";
            else if (i == fruitY && j == fruitX)//position fruit
                cout << "F";
            else
                cout << " ";//position space in blank

            if (j == width - 1)//part right wakk
                cout << "*";

        }
        cout << endl;
    }
    //bottom wall of the map
    for (int i = 0; i < width+2; i++)
        cout << "*";
    cout << endl;
    cout << "Score:" << score << "\n";
}
void Input() //directions INPUT
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}
void Logic()
{
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default: break;
    }
    if (x > width || x<0 || y>height || y < 0)
        gameOver = true;
    if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
    }
}
int main()
{
    Setup();
    while (!gameOver)
    {
        Draw();
        Input();
        Logic();
        //Sleep(10); sleep(10); You cannot implement at the moment
    }
    std::cout << "Hello World!\n";
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
