#include "DummyServer3.h"
#include "main.h"
void DummyServer3::event(float * packet){

 // DO something
 // set values back to Buffer




  /*
   * ======= PART 1: Decode setpoints and send commands to the PID controller ==
   */

  bool skipLink = false; //!FIXME Do we need this? If not, let's get rid of it
  AXX1 = packet[3];
  for (int i = 0; i < myNumberOfChannels; i++)
    {

    }

  /*
   * ======= PART 2: Generate a response to be sent back to MATLAB =============
   */

  // we will be using the same memory area in which the incoming packet was stored,
  // however, a we need to perform a type cast first (for convenience).
  uint8_t * buff = (uint8_t *) packet;

  // re-initialize the packet to all zeros
  for(int i = 4; i < 64;i++)
      buff[i]=0;

  /**
   * The following loop reads sensor data (encoders ticks, joint velocities and
   * force readings) and writes it in the response packet.
   */
  for(int i = 0; i < myNumberOfChannels; i++)
    {
      float position = myObjects[i]->GetPIDPosition();


      packet[(i*3)+0] = position;

    }
}
