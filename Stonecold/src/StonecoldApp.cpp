
#include <Wal.h>

//basic class for testing
class Stonecold : public Wal::Application
{
public:
	Stonecold()
	{

	}

	~Stonecold() 
	{

	}
};

int main()
{
	// testing the entry point Run()
	Stonecold* stonecold = new Stonecold();
	stonecold->Run();
	delete stonecold;
}