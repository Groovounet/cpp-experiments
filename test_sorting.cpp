#include "test_sorting.hpp"
#include <cstdint>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>

std::size_t const COUNT(1000000);

struct DrawElementsIndirectCommand
{
	std::uint32_t primitiveCount;
	std::uint32_t instanceCount;
	std::uint32_t firstIndex;
	std::int32_t  baseVertex;
	std::uint32_t baseInstance;
};

bool less(DrawElementsIndirectCommand const & a, DrawElementsIndirectCommand const & b)
{
	return a.firstIndex < b.firstIndex;
}

struct DrawElementsIndirectCommandCache
{
	std::uint32_t primitiveCount;
	std::uint32_t firstIndex;
};

bool less_cache(DrawElementsIndirectCommandCache const & a, DrawElementsIndirectCommandCache const & b)
{
	return a.firstIndex < b.firstIndex;
}

void test_sorting_elements_SoA()
{
	// Generating the test data
	std::random_device Rd;
	std::mt19937 Gen(Rd());
	std::uniform_int_distribution<std::uint32_t> PrimRand(1, 6);
	std::uniform_int_distribution<std::uint32_t> FirstRand(0, 1);
	std::uniform_int_distribution<std::uint32_t> OffsetRand(1, 6);

	std::vector<DrawElementsIndirectCommand> Data(COUNT);
	Data[0].primitiveCount = PrimRand(Gen) * 3;
	Data[0].instanceCount = 1;
	Data[0].firstIndex = FirstRand(Gen) == 0 ? 0 : PrimRand(Gen);
	Data[0].baseVertex = 0;
	Data[0].baseInstance = 0;
	for(std::size_t i = 1; i < Data.size(); ++i)
	{
		Data[i].primitiveCount = PrimRand(Gen) * 3;
		Data[i].instanceCount = 1;
		Data[i].firstIndex = Data[i - 1].firstIndex + Data[i - 1].primitiveCount + (std::rand() % 10 ? 0 : OffsetRand(Gen));
		Data[i].baseVertex = 0;
		Data[i].baseInstance = 0;
	}

	// Randomize the data
	std::uniform_int_distribution<std::uint32_t> DataRand(0, Data.size() - 1);
	for(std::size_t i = 0; i < Data.size(); ++i)
	{
		DrawElementsIndirectCommand Temp;
		Temp.primitiveCount = Data[i].primitiveCount;
		Temp.instanceCount = Data[i].instanceCount;
		Temp.firstIndex = Data[i].firstIndex;
		Temp.baseVertex = Data[i].baseVertex;
		Temp.baseInstance = Data[i].baseInstance;

		std::uint32_t SwapIndex = DataRand(Gen);

		Data[i].primitiveCount = Data[SwapIndex].primitiveCount;
		Data[i].instanceCount = Data[SwapIndex].instanceCount;
		Data[i].firstIndex = Data[SwapIndex].firstIndex;
		Data[i].baseVertex = Data[SwapIndex].baseVertex;
		Data[i].baseInstance = Data[SwapIndex].baseInstance;

		Data[SwapIndex].primitiveCount = Temp.primitiveCount;
		Data[SwapIndex].instanceCount = Temp.instanceCount;
		Data[SwapIndex].firstIndex = Temp.firstIndex;
		Data[SwapIndex].baseVertex = Temp.baseVertex;
		Data[SwapIndex].baseInstance = Temp.baseInstance;
	}

	{
		// Actual testing
		std::clock_t TimeStart = std::clock();
		
		// Reording the draws
		std::sort(Data.begin(), Data.end(), less);
		
		std::clock_t TimeEnd = std::clock();

		printf("Repack - sort: %d ms\n", (TimeEnd - TimeStart) * 1000 /  CLOCKS_PER_SEC);
	}

	// Packing the draws
	std::clock_t TimeStart = std::clock();

	std::vector<DrawElementsIndirectCommand> Copy(COUNT);
	std::size_t j = 0;
	{
		Copy[0].primitiveCount = Data[0].primitiveCount;
		Copy[0].instanceCount = Data[0].instanceCount;
		Copy[0].firstIndex = Data[0].firstIndex;
		Copy[0].baseVertex = Data[0].baseVertex;
		Copy[0].baseInstance = Data[0].baseInstance;
		for(std::size_t i = 1; i < Data.size(); ++i)
		{
			if(Copy[j].firstIndex + Copy[j].primitiveCount == Data[i].firstIndex)
			{
				Copy[j].primitiveCount += Data[i].primitiveCount;
			}
			else
			{
				++j;
				Copy[j].primitiveCount = Data[i].primitiveCount;
				Copy[j].instanceCount = Data[i].instanceCount;
				Copy[j].firstIndex = Data[i].firstIndex;
				Copy[j].baseVertex = Data[i].baseVertex;
				Copy[j].baseInstance = Data[i].baseInstance;
			}
		}

		std::clock_t TimeEnd = std::clock();

		printf("Repack - pack: %d ms\n", (TimeEnd - TimeStart) * 1000 /  CLOCKS_PER_SEC);
	}

	{
		std::clock_t TimeStart = std::clock();

		//std::vector<DrawElementsIndirectCommand> Result(j + 1);
		//memcpy(&Result[0], &Data[0], Result.size() * sizeof(DrawElementsIndirectCommand));
		Copy.resize(j + 1);
		Copy.shrink_to_fit();

		std::clock_t TimeEnd = std::clock();

		printf("Repack - shrink: %d ms\n", (TimeEnd - TimeStart) * 1000 /  CLOCKS_PER_SEC);
	}
}

void test_sorting_elements_SoA_cache()
{
	// Generating the test data
	std::random_device Rd;
	std::mt19937 Gen(Rd());
	std::uniform_int_distribution<std::uint32_t> PrimRand(1, 6);
	std::uniform_int_distribution<std::uint32_t> FirstRand(0, 1);
	std::uniform_int_distribution<std::uint32_t> OffsetRand(1, 6);

	std::vector<DrawElementsIndirectCommandCache> Data(COUNT);
	Data[0].primitiveCount = PrimRand(Gen) * 3;
	Data[0].firstIndex = FirstRand(Gen) == 0 ? 0 : PrimRand(Gen);
	for(std::size_t i = 1; i < Data.size(); ++i)
	{
		Data[i].primitiveCount = PrimRand(Gen) * 3;
		Data[i].firstIndex = Data[i - 1].firstIndex + Data[i - 1].primitiveCount + (std::rand() % 10 ? 0 : OffsetRand(Gen));
	}

	// Randomize the data
	std::uniform_int_distribution<std::uint32_t> DataRand(0, Data.size() - 1);
	for(std::size_t i = 0; i < Data.size(); ++i)
	{
		DrawElementsIndirectCommandCache Temp;
		Temp.primitiveCount = Data[i].primitiveCount;
		Temp.firstIndex = Data[i].firstIndex;

		std::uint32_t SwapIndex = DataRand(Gen);

		Data[i].primitiveCount = Data[SwapIndex].primitiveCount;
		Data[i].firstIndex = Data[SwapIndex].firstIndex;

		Data[SwapIndex].primitiveCount = Temp.primitiveCount;
		Data[SwapIndex].firstIndex = Temp.firstIndex;
	}

	{
		// Actual testing
		std::clock_t TimeStart = std::clock();
		
		// Reording the draws
		std::sort(Data.begin(), Data.end(), less_cache);
		
		std::clock_t TimeEnd = std::clock();

		printf("Cached - sort: %d ms\n", (TimeEnd - TimeStart) * 1000 /  CLOCKS_PER_SEC);
	}

	// Packing the draws
	std::clock_t TimeStart = std::clock();

	std::vector<DrawElementsIndirectCommandCache> Copy(COUNT);
	std::size_t j = 0;
	{
		Copy[0].primitiveCount = Data[0].primitiveCount;
		Copy[0].firstIndex = Data[0].firstIndex;
		for(std::size_t i = 1; i < Data.size(); ++i)
		{
			if(Copy[j].firstIndex + Copy[j].primitiveCount == Data[i].firstIndex)
			{
				Copy[j].primitiveCount += Data[i].primitiveCount;
			}
			else
			{
				++j;
				Copy[j].primitiveCount = Data[i].primitiveCount;
				Copy[j].firstIndex = Data[i].firstIndex;
			}
		}

		std::clock_t TimeEnd = std::clock();

		printf("Cached - pack: %d ms\n", (TimeEnd - TimeStart) * 1000 /  CLOCKS_PER_SEC);
	}

	{
		std::clock_t TimeStart = std::clock();

		//std::vector<DrawElementsIndirectCommand> Result(j + 1);
		//memcpy(&Result[0], &Data[0], Result.size() * sizeof(DrawElementsIndirectCommand));
		Copy.resize(j + 1);
		Copy.shrink_to_fit();

		std::clock_t TimeEnd = std::clock();

		printf("Cached - shrink: %d ms\n", (TimeEnd - TimeStart) * 1000 /  CLOCKS_PER_SEC);
	}
}

struct DrawArraysIndirectCommand
{
	std::uint32_t count;
	std::uint32_t primCount;
	std::uint32_t first;
	std::uint32_t baseInstance;
};

void test_sorting_arrays_SoA()
{
	std::vector<DrawArraysIndirectCommand> Input(COUNT);
}

void test_sorting()
{
	test_sorting_elements_SoA();
	test_sorting_elements_SoA_cache();
	test_sorting_elements_SoA();
	test_sorting_elements_SoA_cache();
	//test_sorting_arrays_SoA();

	return;
}
