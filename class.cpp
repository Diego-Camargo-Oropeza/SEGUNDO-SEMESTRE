#include <iostream>
using namespace std;

class Televisor
{
    bool m_bEncendido;
    unsigned int m_iuCanal;
    unsigned int m_uiVolumen;

public:
    void encender();
    void apagar();
    bool modificarVolumen(unsigned int ui_volumen);
    bool modificarCanal(unsigned int ui_canal);
};

int main()
{
    Televisor tv1;
    tv1.encender();
    tv1.modificarCanal(50);
    tv1.modificarVolumen(34);
    tv1.apagar();
}

void Televisor::encender()
{
    m_bEncendido = true;
}

void Televisor::apagar()
{
    m_bEncendido = false;
}

bool Televisor::modificarCanal(unsigned int ui_canal)
{
    if (m_bEncendido)
    {
        m_iuCanal = ui_canal;
        return true;
    }
    return false;
}

bool Televisor::modificarVolumen(unsigned int ui_volumen)
{
    if (m_bEncendido)
    {
        m_uiVolumen = ui_volumen;
        return true;
    }
    return false;
}