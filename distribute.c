#include "final.c"
int main(){
    for(int i = 101; i<111; i++){
        int fv = fork();
        if(! fv){ssh_client(i); return 0;}
    }

}
