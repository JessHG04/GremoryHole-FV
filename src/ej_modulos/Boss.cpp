#include "Boss.h"

using namespace std;


Boss::Boss(){
    vida = 15;
}

//actualiza al enemigo
void Boss::updateBoss(){
    if(restartear == true){
        impactado.restart();
        restartear = false;
    }
    this->impactoProyectil(); 
    if(!golpeado){
        setTraBoss(velBoss);
        cajaColisionesBoss.setPosition(getPosicionBoss().x - tamFrameBoss.x/2, getPosicionBoss().y - tamFrameBoss.y/2);
    }
}

void Boss::perderVida(){
    if(!muerto){
        vida--;
        if(vida == 0){
            muerto = true;
        }
    }
}

bool Boss::getMuerte(){
    return muerto;
}

void Boss::setMuerte(bool morir){
    muerto = morir;
}

void Boss::impactoProyectil(){
    float sgs = impactado.getElapsedTime().asSeconds();
    if(golpeado == true){
        if(contando % 2 == 0){
            spriteBoss->setColor(sf::Color::Red);
            contando++;
        }
        else{
            this->hacerTransparente();
            contando++;
        }
        if(sgs >= 1){
            this->restartSprite();
            golpeado = false;
        }
    }
}

bool Boss::colisionProyectil(Proyectil *p1){
    bool x = false;
    if(p1->get_sprite().getGlobalBounds().intersects(spriteBoss->getGlobalBounds()) && golpeado == false){
        this->perderVida();
        x = true;
        golpeado = true;
        restartear = true;           
    }
    return x;
}

bool Boss::morir(){
    bool x = false;
    if(this->getMuerte()){
        x = true;
    }
    return x;
}

void Boss::hacerTransparente(){
    spriteBoss->setColor(sf::Color::Transparent);
}

void Boss::restartSprite(){
    spriteBoss->setColor(sf::Color(255,255,255));
}

bool Boss::colisionProtagonista(spritePersonaje *sp){
    bool x = false;
    if(spriteBoss->getGlobalBounds().intersects(sp->getSprite().getGlobalBounds())){
        x = true;
    }
    return x;
}
