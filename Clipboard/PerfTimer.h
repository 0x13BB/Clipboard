#pragma once
template<typename Period>
class PerfTimer
{
public:
	PerfTimer<Period>(const std::string& Name)
	{
		this->start = std::chrono::steady_clock::now();
		this->name = Name;
	}

	~PerfTimer()
	{
		this->end = std::chrono::steady_clock::now();
		this->ElapsedTime = std::chrono::duration_cast<Period>(end - start).count();
		std::cout << "PerfTimer " << "[" << name << "] " << ElapsedTime << " " << std::endl;
	}

private:
	std::chrono::steady_clock::time_point start;
	std::chrono::steady_clock::time_point end;
	std::string name;
	long ElapsedTime;
};

