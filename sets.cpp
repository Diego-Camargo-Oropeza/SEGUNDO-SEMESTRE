#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

void printSet(set<string>& s, const string& name) {
    cout << name << ": { ";
    for (auto elem : s) {
        cout << elem << " ";
    }
    cout << "}" << endl;
}

int main() {
    set<string> A = {"w", "e", "j", "c", "p", "r"};
    printSet(A, "Set A");
    cout << "Set A cardinalidad: " << A.size() << endl;

    set<string> B = {"x", "p", "m", "j", "w", "m"};
    printSet(B, "Set B");
    cout << "Set B cardinalidad: " << B.size() << endl;

    cout << "a esta en A " << (A.count("a")) << endl;
    cout << "p esta en B " << (B.count("p")) << endl;

    // Union
    set<string> unionAB;
    set_union(A.begin(), A.end(), B.begin(), B.end(), inserter(unionAB, unionAB.begin()));
    printSet(unionAB, "Union de A y B");

    // Interseccion
    set<string> interseccion;
    set_intersection(A.begin(), A.end(), B.begin(), B.end(), inserter(interseccion, interseccion.begin()));
    printSet(interseccion, "Interseccion de A y B");

    // Diferencia A - B
    set<string> diferencia;
    set_difference(A.begin(), A.end(), B.begin(), B.end(), inserter(diferencia, diferencia.begin()));
    printSet(diferencia, "Diferencia A - B");

    // Diferencia simétrica
    set<string> diferenciaSim;
    set_symmetric_difference(A.begin(), A.end(), B.begin(), B.end(), inserter(diferenciaSim, diferenciaSim.begin()));
    printSet(diferenciaSim, "Diferencia simetrica A ^ B");

    // Métodos con sets
    set<string> C = {"h", "s", "q"};
    printSet(C, "Set C");

    C.insert("b");
    printSet(C, "Set C despues de agregar 'b'");

    C.erase("s");
    printSet(C, "Set C despues de eliminar 's'");

    if (C.erase("z") == 0)
        cout << "El elemento 'z' no existe en el set" << endl;

    C.erase("a"); // No genera error si no está
    printSet(C, "Set C despues de intentar eliminar 'a'");

    if (!C.empty()) {
        cout << "Elemento eliminado con pop: " << *C.begin() << endl;
        C.erase(C.begin());
    }
    printSet(C, "Set C despues de pop");

    C.clear();
    printSet(C, "Set C despues de clear");

    // Ejemplo practico 1:
    vector<string> correos = {"juan@gmail.com", "ana@yahoo.com", "juan@gmail.com",
                              "luis@hotmail.com", "ana@yahoo.com", "maria@gmail.com"};
    set<string> correosUnicos(correos.begin(), correos.end());

    cout << "Correos unicos:" << endl;
    for (auto correo : correosUnicos) {
        cout << correo << endl;
    }

    // Ejemplo practico 2
    vector<string> evento_A = {"Juan", "Ana", "Luis", "Carlos", "Maria"};
    vector<string> evento_B = {"Ana", "Luis", "Pedro", "Maria", "Carlos"};

    set<string> set_A(evento_A.begin(), evento_A.end());
    set<string> set_B(evento_B.begin(), evento_B.end());

    set<string> ambos;
    set_intersection(set_A.begin(), set_A.end(), set_B.begin(), set_B.end(), inserter(ambos, ambos.begin()));
    printSet(ambos, "Asistieron a ambos eventos");

    set<string> soloUno;
    set_symmetric_difference(set_A.begin(), set_A.end(), set_B.begin(), set_B.end(), inserter(soloUno, soloUno.begin()));
    printSet(soloUno, "Asistieron solo a un evento");

    set<string> soloA;
    set_difference(set_A.begin(), set_A.end(), set_B.begin(), set_B.end(), inserter(soloA, soloA.begin()));
    printSet(soloA, "Asistieron solo al evento A");

    return 0;
}
