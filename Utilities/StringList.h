//
//  StringList.h
//  Lab03_CatalogoLibros
//
//  Created by Manuel E Santiago on 1/20/15.
//  Copyright (c) 2015 Manuel. All rights reserved.
//

#ifndef __Lab03_CatalogoLibros__StringList__
#define __Lab03_CatalogoLibros__StringList__

#include <stdio.h>
#include "MyString.h"
const int MAX_CAD = 80;

class StringList{ //TODO
private:
    MyString cadena[MAX_CAD]; //Partes
    int cantidad;
    
public:
    //Necesssary
    StringList();
    StringList(const StringList & listInstance);
    ~StringList();
    StringList & operator=(const StringList & listInstance);
    
    int cantidadDeCadenas() const;
    
    bool operator ==(const StringList & listInstance) const;
    bool operator !=(const StringList & listInstance) const;
    
    StringList & operator+(const MyString & stringInstance);
    StringList & operator+(const char *cadena);
    StringList & operator+(const StringList & listInstance);
    friend StringList & operator+(const char *cadena, StringList & listInstance);
    friend StringList & operator+(const MyString & stringInstance, StringList & listInstance);
    
    StringList & operator-(const MyString & stringInstance);
    StringList & operator-(const char *cadena);
    StringList & operator-(int indice);
    friend StringList & operator-(const char *cadena, StringList & listInstance);
    friend StringList & operator-(const MyString & stringInstance, StringList & listInstance);
    
    const MyString & operator[](int index) const;
    MyString & operator[](int index);
    
    bool insertar(int indice, const MyString & stringInstance);
    bool insertar(int indice, const char *cadena);
    bool insertar(int indice, const StringList & listInstance);
    bool insertarAlComienzo(const MyString & stringInstance);
    bool insertarAlComienzo(const char *cadena);
    bool insertarAlComienzo(const StringList & listInstance);
    bool insertarAlFinal(const MyString & stringInstance);
    bool insertarAlFinal(const char *cadena);
    bool insertarAlFinal(const StringList & listInstance);
    
    bool remover(int indice);
    bool remover(int indice, MyString & stringInstance);
    bool removerElPrimero();
    bool removerElPrimero(MyString & stringInstance);
    bool removerElUltimo();
    bool removerElUltimo(MyString & stringInstance);
    
    bool estaLlena() const;
    bool estaVacia() const;
    
    bool reemplazar(int indice, const MyString & stringInstance);
    bool reemplazar(int indice, const char *cadena);
    
    bool incluye (const MyString & stringInstance) const;
    bool incluye (const char *cadena) const;
    
    int indiceDe(const MyString & stringInstance) const;
    int indiceDe(const char *cadena) const;
    int indiceDeUltima(const MyString & stringInstance) const;
    int indiceDeUltima(const char *cadena) const;
    
    int frecuencia(const MyString & stringInstance) const;
    int frecuencia(const char *cadena) const;
    
    void vaciar();
    void ordenarAscendente();
    void ordenarDescendente();
    
    friend ostream & operator <<(ostream & out, const StringList & listInstance);
    
    static int MaxCadenas();

};

#endif /* defined(__Lab03_CatalogoLibros__StringList__) */
