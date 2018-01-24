#include "DummyServer.h"

void DummyServer::event(float * packet){

 // DO something
 // set values back to Buffer




  /*
   * ======= PART 1: Decode setpoints and send commands to the PID controller ==
   */

  bool skipLink = false; //!FIXME Do we need this? If not, let's get rid of it

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
      float position = 1.0;//hard code all position to 1.0
      float velocity = 2.0;//hard code velocity to 2.0
      float torque   = 3.0;//torque to 3.0

      packet[(i*3)+0] = position;//re-write packet to hard code value
      packet[(i*3)+1] = velocity;
      packet[(i*3)+2] = torque;
    }
}
