
#include <stdio.h>
#include <stdlib.h>
#include "estructuras.h"


int main(int argc, char** argv){

   fileHeader mainHeader;
   waveHeader *wHeader;
   waveDataHeader *wdHeader;
   void ** data;



    //CSV EXPORT FLAG -> 0 = VERBOSE ALL | 1 = CSV EXPORT
   int csvFlag = 0;
   if(argc > 2 ){
    csvFlag = 1;
   }



    FILE * fichero = fopen(argv[1], "rb");


    //Read file header
    readFileHeader(&mainHeader, fichero);

    

    wHeader = (waveHeader * )malloc(mainHeader.nWave * sizeof(waveHeader));
    wdHeader = (waveDataHeader * )malloc(mainHeader.nWave * sizeof(waveDataHeader));
    data = (void * )malloc(mainHeader.nWave * sizeof(void *));


    for(int i = 0 ; i < mainHeader.nWave;i ++ ){

        //Read Wave header
        readWaveHeader(&wHeader[i], fichero);

        //Read Wave Data Header 
        readWaveDataHeader(&wdHeader[i], fichero);

        //Read channel data
        readChannelData(&wdHeader[i],&data[i],fichero);

    }


    if(csvFlag){

        for(int i = 0 ; i < mainHeader.nWave;i ++ ){

            printf("%s",wHeader[i].channel);
            if(i< mainHeader.nWave -1){
                printf(",");
            }
        }
        printf("\n");

        for(int i = 0 ; i < wHeader[0].nPoints;i ++ ){

            for(int j = 0 ; j < mainHeader.nWave;j ++ ){

                printf("%f",*((float *)data[j] + i));
                
                if(j< mainHeader.nWave -1){
                    printf(",");
                }
            }
            printf("\n");

        }
    }else{

        //Verbose Header info:
        showFileHeader(mainHeader);


        for(int i = 0 ; i < mainHeader.nWave;i ++ ){

            //Verbose Wave Header info:
            showWaveHeader(wHeader[i]);

            //Verbose Wave Data Header info:
            showWaveDataHeader(wdHeader[i]);

            //Read channel data
            showChannelData(wHeader[i],wdHeader[i],data[i]);

        }
    
    }

}
