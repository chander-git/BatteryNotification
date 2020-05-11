CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		main.o GetFromTerm.o RemoveSpace.o PlayAudio.o
LIBS = -L./lib -lgobject-2.0 -lplayaudio -lglib-2.0 -lgstreamer-1.0 -I./include -I./include/gstreamer-1.0/ -I./include/glib-2.0 -I./include/glib-2.0/glib

INCLUDES ?= -g -I. -I./include -I ./include/gstreamer-1.0/ -I ./include/glib-2.0 -I ./include/glib-2.0/glib 

TARGET =	Audio

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS) $(INCLUDES)
	rm *.o

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
