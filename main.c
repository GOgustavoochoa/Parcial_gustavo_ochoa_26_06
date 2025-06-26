#include "lib_gus.h"

int main(){
    FILE *f_music = fopen("audio_list.raw","rb");
    if(f_music == NULL){
        printf("error al abrir");
        return -1;
    }
    //primer elemento del archivo
    uint32_t cantidad_pistas;
    //declaracion de vector dinamico de estructuras
    struct header *v_encabezado=NULL;
    struct muestras_audios *v_muestras_audios=NULL;
    struct pistas *v_pistas=NULL;

    //lectura del archivo.
    lectura(f_music, &v_encabezado,&v_muestras_audios,&cantidad_pistas,&v_pistas);

    //muestro nombre de cada pista de audio.
    for (int i = 0; i < cantidad_pistas; i++) {
        printf("Pista [%d]: %s\n", i, v_pistas[i].encabezado.sound_name);
    }

    //Funcion para seleccionar desde consola una pista y reproducirla 
    reproduccion(v_pistas,cantidad_pistas);

    //Funcion para seleccionar desde consola cualquier pista y escribir las muestras de audio en un archivo 'sound.raw'
    FILE *f_write_sound = fopen("sound.raw","wb"); 
    if(f_write_sound == NULL){
        printf("error...");
        return -1;
    }
    escribir_raw(v_pistas,cantidad_pistas,f_write_sound);


    //Para probar la correcta escritura del .raw abro nuevamente el archivo en modo rb y verifico la correcta escritura

    FILE *f_read_sound = fopen("sound.raw", "rb");
    if(f_read_sound == NULL){
        printf("error al abrir sound.raw para lectura\n");
        return -1;
    }

    float *v = malloc(v_pistas[0].encabezado.sample_count * sizeof(float));
    fread(v, sizeof(float), v_pistas[0].encabezado.sample_count, f_read_sound);
    fclose(f_read_sound);

    // Reproducir la pista
    play_audio(v_pistas[0].encabezado.sample_rate, v_pistas[0].encabezado.sample_count, v);
    free(v);
    
    

    fclose(f_write_sound);
    fclose(f_music);
    free(v_encabezado);
    free(v_muestras_audios);
    free(v_pistas);
}