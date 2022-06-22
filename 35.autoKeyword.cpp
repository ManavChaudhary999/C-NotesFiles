// auto keyword is used as a replacement of data type. 
// It's usecase is when we are writing some api or some functionality where client or user dont have to know the return type.
#include <iostream>
#include <vector>
#include <unordered_map>

auto GetValue()
{
	return "Manav";
}

std::string GetString()
{
	return "Manav";
}

// Use case of auto
class Device{};

class DeviceManager {
private:
	std::unordered_map<std::string, std::vector<Device*>> m_Devices;
public:
	const std::unordered_map<std::string, std::vector<Device*>> GetDevices() const 
	{
		return m_Devices;
	}
};

int main() 
{
	int value = 4;
	auto b = value; // compiler will automatically assign this as int.

	auto a = 10;
	
	// There are some problem using auto like
	auto x = GetValue();
	x.size(); // only work for string but this is const char*

	auto y = GetString(); // but this is worthless as we are only returning string so we already know type
	y.size();

	std::string x = GetValue(); 
	x.size(); // will work cause implicitly converting in string
	
	DeviceManager dm;
	// So here we have to type this long data type.
	const std::unordered_map<std::string, std::vector<Device*>>& devices = dm.GetDevices();
	
	// So to fix this we have three ways
	using	DeviceMap = std::unordered_map<std::string, std::vector<Device*>>; // 1 way
	const DeviceMap& devices = dm.GetDevices();

	typedef std::unordered_map<std::string, std::vector<Device*>> DeviceMap; // 2 way
	const DeviceMap& devices = dm.GetDevices();

	//Third way with auto
	const auto& devices = dm.GetDevices();
}