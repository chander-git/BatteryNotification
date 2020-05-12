#include"GetFromTerm.h"
#include "declaration.h"
#include "INIReader.h"

INIReader Reader("Config.ini");

void AlgrothimAndPlay(struct HardwareInfo info,int* argc,char*** argv)
{
/////////////////////////For Adapter Connected ////////////////////////////////////////////

	if(info.isAdapterConnected==true && isConnectedAudioPlayed==false){

		playaudio(argc,argv, "file://"+Reader.Get("Apath","CHCONNECTED"," "),20);
		isConnectedAudioPlayed=true;

	}else if(info.isAdapterConnected==false && !isConnectedAudioPlayed==false){

		playaudio(argc,argv,"file://"+Reader.Get("Apath","CHCONNECTED"," "),10);
		isConnectedAudioPlayed=false;
	}
/////////////////////////For Percentage ////////////////////////////////////////////

	if(info.BatteryPercentage == 100 && isFullAudioPlayed==false){

		playaudio(argc,argv,"file://" + Reader.Get("Apath","BTFULL"," "),10);
		isFullAudioPlayed=true;
		isCriticalAudioPlayed=false;

	}else if(info.BatteryPercentage >= 90 && info.BatteryPercentage <= 90 && isMediumAudioPlayed==false){

//		playaudio(argc,argv,"file://"+Reader.Get("Apath","BTMEDIUM"," "),10);
		isMediumAudioPlayed=true;
		isFullAudioPlayed=false;
		isCriticalAudioPlayed=false;


	}else if(info.BatteryPercentage<=20 && info.BatteryPercentage >=11 && isLowAudioPlayed==false){

		playaudio(argc,argv,"file://"+Reader.Get("Apath","BTLOW"," "),10);
		isLowAudioPlayed=true;
		isFullAudioPlayed=false;
		isMediumAudioPlayed=false;
		isCriticalAudioPlayed=false;


	}else if(info.BatteryPercentage<=10 && isCriticalAudioPlayed==false && !info.isAdapterConnected){

		playaudio(argc,argv,"file://"+Reader.Get("Apath","BTCRITICAL"," "),10);
		isCriticalAudioPlayed=true;
		isFullAudioPlayed=false;
		isMediumAudioPlayed=false;
		isLowAudioPlayed=false;
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
