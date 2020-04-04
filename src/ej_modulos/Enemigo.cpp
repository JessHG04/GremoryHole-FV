#include "Enemigo.h"

Enemigo::Enemigo() {
    // constructor por defecto
}

Enemigo::Enemigo(int vidas) {
    this->vidas = vidas;
}

Enemigo::~Enemigo() {
    // Destruye su corespondiente NPC
}

void Enemigo::perderVida(){
    if(!muerto){
        vidas--;
        if(vidas == 0){
            muerto = true;
        }
    }
}

bool Enemigo::getMuerte(){
    return muerto;
}


void Enemigo::recibeGolpe() {
    // Golpea su corespondiente NPC
}


void Enemigo::Update(float deltaTime) {
    // Actualiza su corespondiente NPC
}


void Enemigo::Draw(RenderWindow &window) {
    // Dibuja su corespondiente NPC
}