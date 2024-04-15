#include <stdio.h>


int main(int argc, char* argv[]){

FILE * fichero = fopen(argv[1], "rb");

unsigned long long limit = 0;
unsigned long long i = 0;
long long int lint = 0;
int sint = 0;
float sfloat = 0;
double dfloat = 0;

short int pint = 0;

int WHsize = 0;
char single_char;


//16-BYTES HEADER

printf("\nFile header [\n\t");

    //2-BYTES CHARACTER Cookie
limit = 2;


printf("Cookie : ");
for(i = 0 ; i < limit ; i++){
    single_char = getc(fichero);
    if(single_char != 00){
        printf("%c",single_char);
    }
}
printf("\n\t");

    //2-BYTES CHARACTER Version
limit = 2;
printf("Version : ");
for(i = 0 ; i < limit ; i++){
    single_char = getc(fichero);
    if(single_char != 00){
        printf("%#x ",single_char);
    }
}

printf("\n\t");

    //8-BYTES LONG INTEGER File Size

limit = 8;

printf("File Size : ");
fread(&lint,sizeof(lint),1,fichero);
printf("%lld",lint);

printf("\n\t");
    //4-BYTES INTEGER N Waveforms

limit = 4;
printf("Numero de Waveforms : ");
fread(&sint,sizeof(sint),1,fichero);
printf("%d",sint);

printf("\n\t");
printf("]\n");



//N-BYTES WAVEFORM HEADER
printf("\nWaveform Header [\n\t");

    //4-BYTES INTEGER N Waveforms
printf("Header size : ");
fread(&sint,sizeof(sint),1,fichero);
WHsize =sint;
printf("%d",WHsize);


printf("\n\t");
    //4-BYTES INTEGER Waveform Type

printf("Waveform Type : ");
fread(&sint,sizeof(sint),1,fichero);
printf("%d",sint);

printf("\n\t");
    //4-BYTES INTEGER Waveform Type

printf("Number of Waveform Buffers : ");
fread(&sint,sizeof(sint),1,fichero);
printf("%d",sint);


printf("\n\t");
    //4-BYTES INTEGER Number of points

printf("Number of Points : ");
fread(&sint,sizeof(sint),1,fichero);
printf("%d",sint);

printf("\n\t");
    //4-BYTES INTEGER Count

printf("Count : ");
fread(&sint,sizeof(sint),1,fichero);
printf("%d",sint);

printf("\n\t");
    //4-BYTES FLOAT X Display Range

printf("X Display Range : ");
fread(&sfloat,sizeof(sfloat),1,fichero);
printf("%f",sfloat);

printf("\n\t");
    //8-BYTES DOUBLE FLOAT X Display Origin

printf("X Display Origin : ");
fread(&dfloat,sizeof(dfloat),1,fichero);
printf("%lf",dfloat);

    //8-BYTES DOUBLE FLOAT X Increment
printf("\n\t");
printf("X Increment : ");
fread(&dfloat,sizeof(dfloat),1,fichero);
printf("%lf",dfloat);

    //8-BYTES DOUBLE FLOAT X Origin
printf("\n\t");
printf("X Origin : ");
fread(&dfloat,sizeof(dfloat),1,fichero);
printf("%lf",dfloat);

printf("\n\t");
    //4-BYTES INTEGER X units

printf("X units : ");
fread(&sint,sizeof(sint),1,fichero);
printf("%d",sint);


printf("\n\t");
    //4-BYTES INTEGER Y units

printf("Y units : ");
fread(&sint,sizeof(sint),1,fichero);
printf("%d",sint);

printf("\n\t");
    //16-BYTES CHARACTER Version
limit = 16;
printf("Fecha : ");
for(i = 0 ; i < limit ; i++){
    single_char = getc(fichero);
    if(single_char != 00){
        printf("%c",single_char);
    }
}

printf("\n\t");
    //16-BYTES CHARACTER Version
limit = 16;
printf("Hora : ");
for(i = 0 ; i < limit ; i++){
    single_char = getc(fichero);
    if(single_char != 00){
        printf("%c",single_char);
    }
}

printf("\n\t");
    //25-BYTES CHARACTER Modelo
limit = 24;
printf("Modelo : ");
for(i = 0 ; i < limit ; i++){
    single_char = getc(fichero);
    if(single_char != 00){
        printf("%c",single_char);
    }
}

printf("\n\t");
    //16-BYTES CHARACTER Channel name
limit = 16;
printf("Nombre de canal : ");
for(i = 0 ; i < limit ; i++){
    single_char = getc(fichero);
    if(single_char != 00){
        printf("%c",single_char);
    }
}


printf("\n\t");
printf("]\n");


//PADDING 12 BYTES
limit = 12;

for(i = 0 ; i < limit ; i++){
    single_char = getc(fichero);
}

//PADDING 12 BITS



//16-BYTES WAVEFORM DATA HEADER
printf("\nWaveform Data Header [\n\t");

    //4-BYTES INTEGER Header size :

printf("Header size : ");
fread(&sint,sizeof(sint),1,fichero);
printf("%d",sint);

printf("\n\t");
    //2-BYTES INTEGER buffer type :

printf("Buffer type : ");
fread(&pint,sizeof(pint),1,fichero);
printf("%d",pint);

printf("\n\t");
    //2-BYTES INTEGER buffer type :

printf("Bytes Per Point : ");
fread(&pint,sizeof(pint),1,fichero);
printf("%d",pint);


printf("\n\t");

    //8-BYTES LONG INTEGER Buffer Size
printf("Buffer Size : ");
fread(&lint,sizeof(lint),1,fichero);
printf("%lld",lint);



printf("\n\t");
printf("]\n");


printf("\nCH1 [\n\t");

limit = 1000;

for(i = 0 ; i < limit ; i++){
    fread(&sfloat,sizeof(sfloat),1,fichero);
    printf("\n\t");
    printf("%f",sfloat);
}




printf("\n\t");
printf("]\n");

printf("\nWaveform Header [\n\t");

    //4-BYTES INTEGER N Waveforms
printf("Header size : ");
fread(&sint,sizeof(sint),1,fichero);
WHsize =sint;
printf("%d",WHsize);


printf("\n\t");
    //4-BYTES INTEGER Waveform Type

printf("Waveform Type : ");
fread(&sint,sizeof(sint),1,fichero);
printf("%d",sint);

printf("\n\t");
    //4-BYTES INTEGER Waveform Type

printf("Number of Waveform Buffers : ");
fread(&sint,sizeof(sint),1,fichero);
printf("%d",sint);


printf("\n\t");
    //4-BYTES INTEGER Number of points

printf("Number of Points : ");
fread(&sint,sizeof(sint),1,fichero);
printf("%d",sint);

printf("\n\t");
    //4-BYTES INTEGER Count

printf("Count : ");
fread(&sint,sizeof(sint),1,fichero);
printf("%d",sint);

printf("\n\t");
    //4-BYTES FLOAT X Display Range

printf("X Display Range : ");
fread(&sfloat,sizeof(sfloat),1,fichero);
printf("%f",sfloat);

printf("\n\t");
    //8-BYTES DOUBLE FLOAT X Display Origin

printf("X Display Origin : ");
fread(&dfloat,sizeof(dfloat),1,fichero);
printf("%lf",dfloat);

    //8-BYTES DOUBLE FLOAT X Increment
printf("\n\t");
printf("X Increment : ");
fread(&dfloat,sizeof(dfloat),1,fichero);
printf("%lf",dfloat);

    //8-BYTES DOUBLE FLOAT X Origin
printf("\n\t");
printf("X Origin : ");
fread(&dfloat,sizeof(dfloat),1,fichero);
printf("%lf",dfloat);

printf("\n\t");
    //4-BYTES INTEGER X units

printf("X units : ");
fread(&sint,sizeof(sint),1,fichero);
printf("%d",sint);


printf("\n\t");
    //4-BYTES INTEGER Y units

printf("Y units : ");
fread(&sint,sizeof(sint),1,fichero);
printf("%d",sint);

printf("\n\t");
    //16-BYTES CHARACTER Version
limit = 16;
printf("Fecha : ");
for(i = 0 ; i < limit ; i++){
    single_char = getc(fichero);
    if(single_char != 00){
        printf("%c",single_char);
    }
}

printf("\n\t");
    //16-BYTES CHARACTER Version
limit = 16;
printf("Hora : ");
for(i = 0 ; i < limit ; i++){
    single_char = getc(fichero);
    if(single_char != 00){
        printf("%c",single_char);
    }
}

printf("\n\t");
    //25-BYTES CHARACTER Modelo
limit = 24;
printf("Modelo : ");
for(i = 0 ; i < limit ; i++){
    single_char = getc(fichero);
    if(single_char != 00){
        printf("%c",single_char);
    }
}

printf("\n\t");
    //16-BYTES CHARACTER Channel name
limit = 16;
printf("Nombre de canal : ");
for(i = 0 ; i < limit ; i++){
    single_char = getc(fichero);
    if(single_char != 00){
        printf("%c",single_char);
    }
}


printf("\n\t");
printf("]\n");

//PADDING 12 BYTES
limit = 12;

for(i = 0 ; i < limit ; i++){
    single_char = getc(fichero);
}

//PADDING 12 BITS



//16-BYTES WAVEFORM DATA HEADER
printf("\nWaveform Data Header [\n\t");

    //4-BYTES INTEGER Header size :

printf("Header size : ");
fread(&sint,sizeof(sint),1,fichero);
printf("%d",sint);

printf("\n\t");
    //2-BYTES INTEGER buffer type :

printf("Buffer type : ");
fread(&pint,sizeof(pint),1,fichero);
printf("%d",pint);

printf("\n\t");
    //2-BYTES INTEGER buffer type :

printf("Bytes Per Point : ");
fread(&pint,sizeof(pint),1,fichero);
printf("%d",pint);


printf("\n\t");

    //8-BYTES LONG INTEGER Buffer Size
printf("Buffer Size : ");
fread(&lint,sizeof(lint),1,fichero);
printf("%lld",lint);



printf("\n\t");
printf("]\n");

printf("\nCH4 [\n\t");

limit = 1000;

for(i = 0 ; i < limit ; i++){
    fread(&sfloat,sizeof(sfloat),1,fichero);
    printf("\n\t");
    printf("%f",sfloat);
}

printf("\n\t");
printf("]\n");



fclose(fichero);

printf("\n");



	


}