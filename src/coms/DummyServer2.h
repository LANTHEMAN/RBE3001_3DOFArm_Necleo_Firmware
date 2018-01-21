#ifndef  DummyServer2_H
#define DummyServer2_H
#include <PID_Bowler.h>
#include <PacketEvent.h>
#include "../drivers/MyPid.h"
#include <cmath>        // std::abs

#define DUMMY_SERVER2_ID 43      // identifier for this server


class DummyServer2: public PacketEventAbstract{

private:
	  PIDimp ** myObjects;    // array of PidServers - one for each joint
	  int myNumberOfChannels;
public:
	  DummyServer2 (PIDimp ** Objects, int numberOfChannels)
	      : PacketEventAbstract(DUMMY_SERVER2_ID)
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
