//
//  StringList.cpp
//  Lab03_CatalogoLibros
//
//  Created by Manuel E Santiago on 1/20/15.
//  Copyright (c) 2015 Manuel. All rights reserved.
//

#include "StringList.h"

StringList::StringList(){
    //We can't use initialization by list to create MyString objects because they are in an array. The constructor of "TODO" calls the default MyString constructor 80 times to create the 80 objects
    this->cantidad = 0; //We do not require any of the 80 objects created, the list is empty
}
StringList::StringList(const StringList & listInstance){
    (*this) = listInstance;
}
StringList::~StringList(){
}
StringList & StringList::operator=(const StringList & listInstance){
    this->cantidad = listInstance.cantidad;
    for(int i = 0; i < listInstance.cantidad; i++){
        (*this)[i] = listInstance[i];
    }
    return (*this);
}
int StringList::cantidadDeCadenas() const{
    return (this->cantidad);
}

bool StringList::operator ==(const StringList & listInstance) const{
    bool equal(this->cantidad == listInstance.cantidad);
    if(equal){
        for(int j = 0; j < this->cantidad && equal; j++){
            if((*this)[j] != listInstance[j]){
                equal = false;
            }
        }
    }
    return (equal);
}
bool StringList::operator !=(const StringList & listInstance) const{
    return (!((*this) == listInstance));
}
//Operator +
StringList & StringList::operator+(const MyString & stringInstance){
    this->insertarAlFinal(stringInstance);
    return (*this);
}
StringList & StringList::operator+(const char *cadena){
    this->insertarAlFinal(cadena);
    return (*this);
}
StringList & StringList::operator+(const StringList & listInstance){
    this->insertarAlFinal(listInstance);
    return (*this);
}
StringList & operator+(const char *cadena, StringList & listInstance){
    listInstance.insertarAlComienzo(cadena);
    return(listInstance);
}
StringList & operator+(const MyString & stringInstance, StringList & listInstance){
    listInstance.insertarAlComienzo(stringInstance);
    return(listInstance);
}
//Operator -
StringList & StringList::operator-(const MyString & stringInstance){
    this->remover(this->indiceDeUltima(stringInstance));
    return (*this);
}
StringList & StringList::operator-(const char *cadena){
    this->remover(this->indiceDeUltima(cadena));
    return (*this);
}
StringList & StringList::operator-(int indice){
    this->remover(indice);
    return (*this);
}
StringList & operator-(const char *cadena, StringList & listInstance){
    listInstance.remover(listInstance.indiceDe(cadena));
    return (listInstance);
}
StringList & operator-(const MyString & stringInstance, StringList & listInstance){
    listInstance.remover(listInstance.indiceDe(stringInstance));
    return (listInstance);
}
const MyString & StringList::operator[](int index) const{
    return ((this->cadena)[index]);
}
MyString & StringList::operator[](int index){
    return ((this->cadena)[index]);
}
bool StringList::insertar(int indice, const MyString & stringInstance){
    bool inserted = false;

    if(!(this->estaLlena()) && indice >= 0 && indice <= this->cantidad){
        for(int i = this->cantidad - 1; i >= indice; i--){
            (*this)[i+1] = (*this)[i];
        }
        (*this)[indice] = stringInstance;
        ++(this->cantidad);
        inserted = true;
    }
    return (inserted);
}
bool StringList::insertar(int indice, const char *cadena){
    return(this->insertar(indice, MyString(cadena)));
}
bool StringList::insertar(int indice, const StringList & listInstance){
    bool inserted = false;
    if(((this->cantidad + listInstance.cantidad) <= MAX_CAD) && (indice >= 0 && indice <= this->cantidad)){
        for(int i = 0; i < listInstance.cantidad; i++){
            this->insertar(indice + i, listInstance[i]);
        }
        inserted = true;
    }
    return (inserted);
}
bool StringList::insertarAlComienzo(const MyString & stringInstance){
    return (this->insertar(0, stringInstance));
}
bool StringList::insertarAlComienzo(const char *cadena){
    return (this->insertar(0, cadena));
}
bool StringList::insertarAlComienzo(const StringList & listInstance){
    return (this->insertar(0, listInstance));
}
bool StringList::insertarAlFinal(const MyString & stringInstance){
    return (this->insertar(this->cantidad, stringInstance));
}
bool StringList::insertarAlFinal(const char *cadena){
    return (this->insertar(this->cantidad, cadena));
}
bool StringList::insertarAlFinal(const StringList & listInstance){
    return (this->insertar(this->cantidad, listInstance));
}
bool StringList::remover(int indice){
    MyString temporero;
    return (this->remover(indice, temporero));
}
bool StringList::remover(int indice, MyString & stringInstance){
    bool removed = false;
    if(indice >= 0 && indice < this->cantidad){
        stringInstance = (*this)[indice];
        for(int i = indice; i < (this->cantidad - 1); i++){
            (*this)[i] = (*this)[i+1];
            --(this->cantidad);
            removed = true;
        }
    }
    return (removed);
}
bool StringList::removerElPrimero(){
    MyString temporero;
    return (this->removerElPrimero(temporero));
}
bool StringList::removerElPrimero(MyString & stringInstance){
    return (this->remover(0, stringInstance));
}
bool StringList::removerElUltimo(){
    MyString temporero;
    return (this->removerElUltimo(temporero));
}
bool StringList::removerElUltimo(MyString & stringInstance){
    return (this->remover(this->cantidad - 1, stringInstance));
}
bool StringList::estaLlena() const{
    return (this->cantidad == MAX_CAD);
}
bool StringList::estaVacia() const{
    return (this->cantidad == 0);
}
bool StringList::reemplazar(int indice, const MyString & stringInstance){
    bool replaced = false;
    if(indice >= 0 && indice < this->cantidad){
        (*this)[indice] = stringInstance;
        replaced = true;
    }
    return (replaced);
}
bool StringList::reemplazar(int indice, const char *cadena){
    return (this->reemplazar(indice, MyString(cadena)));
}
bool StringList::incluye (const MyString & stringInstance) const{
    return (this->indiceDe(stringInstance) != -1);
}
bool StringList::incluye (const char *cadena) const{
    return (this->indiceDe(MyString(cadena)) != -1);
}
int StringList::indiceDe(const MyString & stringInstance) const{
    int indice = -1;
    
    for(int i = 0; i < this->cantidad && indice == -1; i++){
        if((*this)[i] == stringInstance){
            indice = i;
        }
    }
    return (indice);
}
int StringList::indiceDe(const char *cadena) const{
    return (this->indiceDe(MyString(cadena)));
}
int StringList::indiceDeUltima(const MyString & stringInstance) const{
    int indice = -1;
    
    for(int i = this->cantidad - 1; i >= 0 && indice == -1; i--){
        if((*this)[i] == stringInstance){
            indice = i;
        }
    }
    return (indice);
}
int StringList::indiceDeUltima(const char *cadena) const{
    return(indiceDeUltima(MyString(cadena)));
}
int StringList::frecuencia(const MyString & stringInstance) const{
    int freq = 0;
    
    for(int i = 0; i < this->cantidad; i++){
        if((*this)[i] == stringInstance){
            ++freq;
        }
    }
    return (freq);
}
int StringList::frecuencia(const char *cadena) const{
    return (this->frecuencia(MyString(cadena)));
}
void StringList::vaciar(){
    this->cantidad = 0;
}
void StringList::ordenarAscendente(){
    int n = this->cantidad;
    MyString temp;
    bool switched = true;
    
    for(int pass = 0; pass < (n - 1) && switched; pass++){
        switched = false;
        for(int j = 0; j < (n-1-pass); j++){
            if((*this)[j] > (*this)[j+1]){
                temp = (*this)[j];
                (*this)[j] = (*this)[j+1];
                (*this)[j+1] = temp;
                switched = true;
            }
        }
    }
}
void StringList::ordenarDescendente(){
    int n = this->cantidad;
    MyString temp;
    bool switched = true;
    
    for(int pass = 0; pass < (n - 1) && switched; pass++){
        switched = false;
        for(int j = 0; j < (n-1-pass); j++){
            if((*this)[j] < (*this)[j+1]){
                temp = (*this)[j];
                (*this)[j] = (*this)[j+1];
                (*this)[j+1] = temp;
                switched = true;
            }
        }
    }
}
ostream & operator <<(ostream & out, const StringList & listInstance){
    if(listInstance.estaVacia()){
        out << "The list is empty." << endl;
    }else{
        for(int i = 0; i < listInstance.cantidad; i++){
            out << (i+1) << ". " << listInstance[i] << endl;
        }
    }
    return (out);
}

int StringList::MaxCadenas(){
    return (MAX_CAD);
}

