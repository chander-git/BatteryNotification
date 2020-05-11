#include"GetFromTerm.h"
#include "declaration.h"
void AlgrothimAndPlay(struct HardwareInfo info,int* argc,char*** argv)
{
	if(info.isAdapterConnected==true && isConnectedAudioPlayed==false)
	{
		playaudio(argc,argv,"file:///home/thread_login/Desktop/Audio/file.mp3/BTLOW.MP3",10);
		isConnectedAudioPlayed=true;
	}
	if(info.isAdapterConnected==false && !isConnectedAudioPlayed==false)
	{
		playaudio(argc,argv,"file:///home/thread_login/Desktop/Audio/file.mp3/BTLOW.MP3",10);
		isConnectedAudioPlayed=false;
	}
	return ;
}
struct HardwareInfo ParseString(char *str)
{
	struct HardwareInfo BatteryInfo;
	string token;
	token= strtok(str,",");

	if(token=="Battery0:Charging")
		BatteryInfo.isAdapterConnected=true;

	else if(token == "Battery0:Discharging")
		BatteryInfo.isAdapterConnected=false;

	token=strtok(NULL,",");
	BatteryInfo.BatteryPercentage=stoi(token);
	return BatteryInfo;
}


int main (int argc,char** argv)
{
	vector<string >data;
	isConnectedAudioPlayed=false;
	isLowAudioPlayed=false;
	isMediumAudioPlayed=false;
	isFullAudioPlayed=false;
	while(1){
	data=GetFromTerm("acpi");
	PrintVector(data);

	AlgrothimAndPlay(ParseString(const_cast<char*>(RemoveSpaces(const_cast<char*>(data.at(0).c_str())).c_str())),&argc,&argv);
		sleep(1);
	}
}
