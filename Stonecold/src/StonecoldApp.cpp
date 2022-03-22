
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

// necessary to reach the entry point of Wal
Wal::Application* Wal::CreateApplication()
{
	return new Stonecold;
}