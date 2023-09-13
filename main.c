 #include "final.h"

int main(){
//New plan
/*Break into 2 at first. Child will listen for incoming stuff and pass it through a pipe to the parent, that
way the parent can do a loop where one of the steps is reading. Need to make sure this works
with the other parts of the project but think it should be fine. This is all server side

Now, flow is clients send in the number inside and the number outside, recieved by forked
server, which pipes that info to main server. that main server then adds those numbers to the total,
and prints out the new total ratio (using the good float version or wtv). this way its ok
that reading blocks.

Clients must now get set up first and not using a continous socket, so will be more like
function SSHs to every machine, runs client, and kills those sockets, then those clients
send their info back whenever they finish one at a time to the open port/socket thing.
*/
//SSH thing will go here

int piper[2];
pipe(piper);

int fv = fork();
if(fv){//networking Child
  close(piper[READ]);
  opensockets(piper); // for server - client
}
else{ //parent
  //processing Child
  close(piper[WRITE]);
  double pi = 0; // estimated pi avg
  double totalguess = 0; // sun of client pi's
  int buff[2];
  int numguess = 0; // num trials (clients)
  while(1){
    double inpiguess = 0; // client side pi calculation
    read(piper[READ],&inpiguess,sizeof(double));
    numguess++;
    printf("\n[MAIN] recieved estimate %f from client\n",inpiguess);
    totalguess += inpiguess;
    pi = totalguess /(1.0 * numguess);
    printf("[MAIN] average estimate : %f from %d client(s)\n",pi, numguess);
  } //while
} //parent
} //main
