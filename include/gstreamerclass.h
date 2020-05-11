
namespace gst
{
class Audio
{
private:
	GstBus *bus;
	GstMessage *msg;
	GstElement *playbin;
public:
	Audio(int *argc , char***argv)
	{
		gst_init(argc, argv);

		playbin = gst_element_factory_make("playbin", "playbin");
		if (!playbin)
			printf("Not all elements could be created for audio playing.\n");

	}
	~Audio()
	{
		gst_object_unref(bus);
		gst_object_unref(playbin);
	}
	void* audio(string , int);
};
}


