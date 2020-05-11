
#ifndef macro
#define macro

bool isConnectedAudioPlayed;
bool isLowAudioPlayed;
bool isMediumAudioPlayed;
bool isFullAudioPlayed;
string 	RemoveSpaces(char*);
int playaudio(int *argc, char ***argv,string file_path,int vol);

#endif

struct HardwareInfo
{
	bool isAdapterConnected;
	short unsigned BatteryPercentage;
};
