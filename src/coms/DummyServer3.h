#ifndef  DummyServer3_H
#define DummyServer3_H
#include <PID_Bowler.h>
#include <PacketEvent.h>
#include "../drivers/MyPid.h"
#include <cmath>        // std::abs

#define DUMMY_SERVER3_ID 44      // identifier for this server

class DummyServer3: public PacketEventAbstract{

private:
	  PIDimp ** myObjects;    // array of PidServers - one for each joint
	  int myNumberOfChannels;
public:

	  DummyServer3 (PIDimp ** Objects, int numberOfChannels)
	      : PacketEventAbstract(DUMMY_SERVER3_ID)
	    {
		  myObjects = Objects;
	      myNumberOfChannels = numberOfChannels;
	    }
  //User function to be called when a packet comes in
  // Buffer contains data from the packet coming in at the start of the function
  // User data is written into the buffer to send it back
  void event(float * packet);
};


#endif /* end of include guard: Pid_server */
