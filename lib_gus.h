#pragma once
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void vordshell(float *v, int tam);              //ordena vect. c/shell
void vordbubble(float *v, int tam);             //ordena vect. c/bubble
void vbusqueda(float *v,int tam,int num);     //busqueda vect. c/binario
void vord_busq(float *v,int tam,float num);     //ordena y busca vect. c/shell y binaria

//tp profe:

float *re_sizefun(float *p, int n0, int nf);           
//cambia el tamaño de "vectores" puntero
// 'void *' Es una funcion puntero generica, lo que significa
// que puede almacenar la DIRECCION de cualquier 
// tipo de dato (int, float, char,struct)
int *removeItem(int *p,int tam,int position_rm);
int *insertItem(int *p,int tam,int insert_pos,int insert_value);
int *concat(int* p1,int p1_size,int* p2,int p2_size);

//tp profe pero con procedimientos:

//[**p] Direccion de memoria del vector puntero (&p)
//[*n0] Direccion de memoria del tamaño inicial del vect  
//[nf] Tamaño final del vect
void re_sizepro(int **p,int *n0, int nf);
//[**p] Direccion de memoria del vector puntero (&p)
//[*tam] Direccion del tamaño del vector para hacerla variar en el main (&n)
void removeitempro(int **p, int *tam);
//[**p] Direccion de memoria del vector puntero (&p)
//[*tam] Direccion del tamaño del vector para hacerla variar en el main (&n)
void insertItempro(int **p,int *tam);
//[**p1] Direccion de memoria del vector puntero (&p)
//[p1_size] Tamaño del vect p1
//Asi tambien para p2 y p2_size
void concatpro(int **p1,int p1_size,int **p2,int p2_size);



//PARA OPERACIONES BINNARIAS:
void show_bin8(uint8_t n);
void show_bin16(uint16_t n);
void show_bin32(uint32_t n);
void show_bin64(uint64_t n);
void show_hex32(uint32_t n);

void show_bin_generic(uint16_t n);

//tp01_extra
uint32_t setear_bit(uint32_t n_inside, int bit_pos, bool flag);
uint32_t invert_bit(uint32_t n_inside, int bit_pos);
uint32_t bin_rotate(uint32_t n_inside, int n_shiteos);

//tp2_avanzaos
uint32_t extraccion(uint32_t n_inside,int starbite, int endbite);
uint16_t inter_segment16(uint16_t n_inside, int nbit_rotate);

//F. Propias:
bool bin_pos16(uint16_t n_inside, int bit_pos);
bool bin_equality16(uint16_t n1_inside, uint16_t n2_inside, int bit_pose); 

//FUNCIONES PARCIAL
//estructuras necesarias:

struct header{
    uint32_t sample_rate;
    uint32_t sample_count;
    char sound_name[64];
};

struct muestras_audios{
    //vector float de las muestras de audio
    float *sound_data;
};

struct pistas{
    struct header encabezado;
    struct muestras_audios muestra_sound;
};

void lectura(FILE *f_music, struct header **v_encabezado,struct muestras_audios **v_muestras_audios,uint32_t *cantidad_pistas,struct pistas **v_pistas);

#include "audio_player.h"

void reproduccion(struct pistas *v_pistas,uint32_t cantidad_pistas);
