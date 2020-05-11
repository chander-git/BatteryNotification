#include <stdio.h>
#include <gstreamer-1.0/gst/gst.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string>
#include<iostream>
using namespace std;
#include "gstreamerclass.h"

void * gst::Audio::audio(string paths, int vol)
{
	cout<<"vol -> "<<vol<<" path --> "<<paths<<endl;

	/* Set the URI to play */
	g_object_set(playbin, "uri", (char *) paths.c_str(), NULL);
	bus =gst_element_get_bus(playbin);

	gst_element_set_state(playbin, GST_STATE_PLAYING);
	msg	=gst_bus_timed_pop_filtered(bus, GST_CLOCK_TIME_NONE,(GstMessageType)(GST_MESSAGE_ERROR | GST_MESSAGE_EOS));

	/* Free resources */
	if (msg != NULL) {
		gst_element_set_state(playbin, GST_STATE_NULL);
		gst_message_unref(msg);
		usleep(100000);
	}
	return (void*) NULL;
}

int playaudio(int *argc, char ***argv,string file_path,int vol)
{
	if(file_path == "" || vol <= 0){
		printf("Please Give audio file path or vol correctly\n");
		return EXIT_FAILURE;
	}
	else{
		gst::Audio object(argc,argv);
		object.audio(file_path,vol);
	}
	return  EXIT_SUCCESS;
}
