#include <stdio.h>
#include <stdlib.h>

int main () {
    int sizeMax = 15*1024;
    FILE *fr, *fw;
    char buff[15*1024];

    fr = fopen( "godzilla.gif" , "rb+" );
    fw = fopen( "godzilla22.gif" , "wb+" );
    fread(buff, 1, 1024*15, fr);
    fwrite(buff , 1 , 15*1024, fw);

    fclose(fr);
    fclose(fw);

    return(0);
}