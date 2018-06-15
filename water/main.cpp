//Created by Bramory 11.06.18

#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
//#include "const.h"

using namespace std;

const int N = 3;
int *a = (int*) malloc(sizeof(int) * N);

int width  = glutGet(GLUT_SCREEN_HEIGHT) * 0.5;
int height = glutGet(GLUT_SCREEN_HEIGHT) * 0.5;
int dx = width / N;
int dy = dx;
int x_pos = 300;
int y_pos = 300;

///return element from [a ... b]
///in C++ use template <typename T>
int randFromRange (int min, int max)
{
    return rand() % (max-min+1) + min;
}

///return max number from integer array
int findMax(int  n, int a[])
{
    int max = a[0];
    for(int i = 1; i < n; i++){
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

void Initialize ()
{
    glClearColor(1, 1, 1, 1);

//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
    glOrtho(0, width, 0, height, -1, 1);
}

void drawCell(int i, int n)
{
    glRectf(i * dx  , 0,
            (i+1)*dx, n*dy);
}

void display()
{
    system("cls");
    printf("Width %d\n", width);
    printf("height %d\n", height);
    printf("dx %d\n", dx);
    printf("dy %d\n", dy);

    for(int i = 0; i < N; i++)
        a[i] = randFromRange(0, N-1);

    int max = findMax(N, a);
    printf("\n\nMAX = %d\n", max);
    printf("N = %d\n", N);

    printf("\nArray: ");
    for(int i = 0; i < N; i++)
      printf("%d, ", a[i]);

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1, 1, 0);///yellow cells
    for (int i = 0; i < N; ++i)
        drawCell(i, a[i]);

    glColor3f(0, 0, 0); ///black
    glBegin(GL_LINES);
    for (int i = 1; i < N; ++i) /// N-1 vertical lines
    {
        glVertex2f(i * dx, 0);
        glVertex2f(i * dx,  height);
    }
    for (int i = 1; i < N; ++i) /// N-1 horizontal lines
    {
        glVertex2f(0, i * dx);
        glVertex2f(width, i * dx);
    }
    glEnd();

    glutSwapBuffers();

        int water = 0, water_units = 0;
    for(int j = 0; j < max; j++)
        {
        for(int i = 0; i < N; i++)
        {
            //there is ground
            GROUND:
            if (a[i] > 0){
                water_units = 0;
                // count units of water
                for(int z = i+1; z < N; z++){
                    //find water
                    if(a[z] == 0)
                        water_units++;
                //find second ground
                    else{
                        water+=water_units;
                        i++;
                        goto GROUND;
                    }
                }
            }
        }
            for(int m = 0; m < N; m++)
                if (a[m] > 0)
                    a[m]--;
    }

     printf("Water Unit = %d\n", water );
}

//void MyIdle()
//{
//    display();
//}


int main(int argc, char **argv)
{
    srand(time(0));

    //Initialization
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(x_pos, y_pos);
    glutCreateWindow("Water search ");

    //Registration
    glutDisplayFunc(display);
    Initialize();
    //glutIdleFunc(MyIdle);

    glutMainLoop();
    free(a);
    return 0;
}
