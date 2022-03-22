
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

Wal::Application* Wal::CreateApplication()
{
	return new Stonecold;
}