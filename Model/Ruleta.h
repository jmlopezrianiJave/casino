#ifndef CASINO_RULETA_H
#define CASINO_RULETA_H

#include "Juego.h"
#include <cstdlib>
#include <time.h>

class Ruleta : public Juego{
    public:
        ~Ruleta();
        virtual float jugar(float gonzosApostar) override;
    protected:
        int numeroRuleta;
        int tipoApuesta;
        virtual float calcularResultado(float gonzosApostar) override;
};

#endif //CASINO_RULETA_H
