//
// Created by anton on 13/11/2024.
//
#include <cstdlib>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include "MallaTriangulos.h"
#include "Cilindro.h"
#include <GL/glut.h>

MallaTriangulos::MallaTriangulos() {}


void MallaTriangulos::dibujar() {
    glBegin(GL_TRIANGLES);
    for (size_t i = 0; i < indices.size(); i++) {
        int index = indices[i];
        glVertex3f(vertices[3 * index], vertices[3 * index + 1], vertices[3 * index + 2]);
    }
    glEnd();
}



