//
// Created by anton on 13/11/2024.
//

#ifndef PR3B_MALLATRIANGULOS_H
#define PR3B_MALLATRIANGULOS_H


#include <vector>

class MallaTriangulos {
public:
    std::vector<float> vertices;
    std::vector<float> normales;
    std::vector<unsigned int> indices;

    MallaTriangulos();

    void dibujar();

};

#endif //PR3B_MALLATRIANGULOS_H
