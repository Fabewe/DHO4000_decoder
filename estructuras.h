

typedef struct fileHeader {


    // Cookie - Two-byte characters, RG, indicating that the file is the RIGOL binary data file format.
    unsigned char cookie[2];

    // Version - Two-byte, indicating the file version.
    unsigned char version[2];


    // File Size - An 8-byte long integer, indicating the number of bytes in thefile. It includes the header.
    long long int fileSize;


    // Number of Waveforms - A 4-byte integer, indicating the number of waveforms that are stored in the file.
    int nWave;



}fileHeader;


typedef struct waveHeader {


    // Header Size - A 4-byte integer, indicating the number of bytes in the header
    int hSize;

    // Waveform Type - A 4-byte integer, indicating the type of the waveform stored inthe file. It is fixed to 1
    int wType;


    // Number of Waveform Buffers A 4-byte integer, indicating the number of waveform buffers required to read the data. It is fixed to 1.
    int nBuffers;

    // Number of Points - A 4-byte integer, indicating the number of waveform points in the data.
    int nPoints;

    // Count - A 4-byte integer. It is fixed to 0.
    int Count;

    // X Display Range - A 4-byte float, indicating the X-axis duration of the waveform that is displayed. For time-domain waveforms, it indicates the duration of the display. If the value is zero, then no data has been acquired.
    float xDrange;

    // X Display Origin - An 8-byte double-precision floating-point, indicating the Xaxis value at the left edge of the screen. For time-domain waveforms, it indicates the time at the start of the display. The value is treated as a double precision 64-bit float point number. If the value is zero, then no data has been acquired.
    double xDorigin;

    // X Increment - An 8-byte double-precision floating-point, indicating the Xaxis value of the first data point in the data recording. For time-domain waveforms, it indicates the time of the first point. The value is treated as a double precision 64-bit float point number. If the value is zero, then no data has been acquired.
    double inc;

    // X Origin - An 8-byte double-precision floating-point, indicating the Xaxis value of the first data point in the data recording. Fortime-domain waveforms, it indicates the time of the first point. The value is treated as a double precision 64-bit float point number. If the value is zero, then no data has been acquired.
    double xOrigin;

    // X Units - A 4-byte integer, indicating the unit of measurement for X values in the acquired data. It is fixed to 2.
                            //{0 = Unknown | - 1 = Volts (V) | 2 = Seconds (s) | 3 = Constant | 4 = Amps (A) | 5 = Decibel (dB) | 6 = Hertz (Hz)}
    int xUnits;

    // Y Units - A 4-byte integer, indicating the unit of measurement for Y values in the acquired data. TThe possible values are listedabove under X Units.
    int yUnits;


    // Date - A 16-byte character array, indicating the date when the file is saved.
    char date[16];

    // Time - A 16-byte character array, indicating the time when the file is saved.
    char time[16];

    // Model - A 24-byte character array in the format of MODEL#:SERIAL#,indicating the oscilloscope's model and serial number
    char model[24];

    // Channel Name - A 16-byte character array that contains the label assigned to the waveform.
    char channel[16];



}waveHeader;




typedef struct waveDataHeader {


    // Header Size  - A 4-byte integer, indicating the number of bytes in the waveform data header.
    int hSize;

    // Buffer Type - A 2-byte integer, indicating the type of the waveform data stored in the file.
    short int bType;


    // Bytes Per Point - A 2-byte short integer, indicating the number of bytes per data point.
    short int bPoint;


    // Buffer Size - An 8-byte long integer, indicating the number of bytes of the current channel waveform data
    long long int  bSize;



}waveDataHeader;


void readFileHeader(fileHeader* FH,FILE* fichero){

    //16-bytes read
    unsigned char auxReg[16];

    fread(&auxReg,sizeof(auxReg),1,fichero);


    FH->cookie[0] = auxReg[0];
    FH->cookie[1] = auxReg[1];

    FH->version[0] = auxReg[2];
    FH->version[1] = auxReg[3];

    long long unsigned int res=0;
    long long unsigned int auxlld=0;

    

    for(int i = 0; i < 8 ; i++){

        auxlld = auxReg[4+i];
        auxlld = auxlld<<(i*8);
        res = res +auxlld;
        
    }

    FH->fileSize = res;

    res = 0;

    for(int i = 0; i < 4 ; i++){

        auxlld = auxReg[12+i];
        auxlld = auxlld<<(i*8);
        res = res + auxlld;
        
    }

    FH->nWave = res;
}


void readWaveHeader(waveHeader* WH,FILE* fichero){

    //"140"-bytes read
    fread(WH,sizeof(waveHeader),1,fichero);


    //Padding
    for(int i = 0; i <  (WH->hSize) - sizeof(waveHeader);i++){ 
        getc(fichero);
    }

}

void readWaveDataHeader(waveDataHeader* WDH,FILE* fichero){

    //16-bytes read
    fread(WDH,sizeof(waveDataHeader),1,fichero);

}

void  readChannelData(waveDataHeader* WDH,void  **data,FILE* fichero){


    *data = malloc(WDH->bSize);
    fread(*data,WDH->bSize,1,fichero);    
}

void showFileHeader(fileHeader mainHeader){

    printf("\nFile header [\n\t");

            printf("Cookie : %c%c\n\t",mainHeader.cookie[0],mainHeader.cookie[1]);
            printf("Version : %#x,%#x\n\t",mainHeader.version[0],mainHeader.version[1]);
            printf("File Size :%lld\n\t",mainHeader.fileSize);
            printf("Number of Waveforms :%d\n\t",mainHeader.nWave);
    printf("]\n");

}


void showWaveHeader(waveHeader wHeader){

    printf("\nWave header [\n\t");

            printf("Header size : %d\n\t",wHeader.hSize);
            printf("Waveform type : %d\n\t",wHeader.wType);
            printf("Number of Waveform Buffers : %d\n\t",wHeader.nBuffers);
            printf("Number of Points : %d\n\t",wHeader.nPoints);
            printf("Count : %d\n\t",wHeader.Count);
            printf("X Display Range : %f\n\t",wHeader.xDrange);
            printf("X Display Origin : %f\n\t",wHeader.xDorigin);
            printf("X Increment : %f\n\t",wHeader.inc);
            printf("X Origin : %f\n\t",wHeader.xOrigin);
            printf("X Units : %d\n\t",wHeader.xUnits);
            printf("Y Units : %d\n\t",wHeader.yUnits);
            printf("Date  : %s\n\t",wHeader.date);
            printf("Time : %s\n\t",wHeader.time);
            printf("Model %s\n\t",wHeader.model);
            printf("Channel Name %s\n\t",wHeader.channel);
    printf("]\n");

}

void showWaveDataHeader(waveDataHeader wdHeader){

    printf("\nWave Data header [\n\t");

            printf("Header size : %d\n\t",wdHeader.hSize);
            printf("Buffer type : %d\n\t",wdHeader.bType);
            printf("Bytes Per Point : %d\n\t",wdHeader.bPoint);
            printf("Buffer Size : %lli\n\t",wdHeader.bSize);
    printf("]\n");

}

void showChannelData(waveHeader wHeader,waveDataHeader wdHeader,void * data){

    printf("\n%s data [\n",wHeader.channel);

            for(int i  =  0 ; i<wHeader.nPoints ; i++){
                printf("\t%f\n", *((float *)data + i));
            }
    printf("]\n");



}