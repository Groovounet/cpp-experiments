#include "test_elementsof.hpp"
#include <cstddef>
#include <cstdlib>

//https://msdn.microsoft.com/en-us/library/ms175773.aspx

#define ENABLE 0
#if ENABLE

template <typename T>
constexpr std::size_t countofA(T & a)
{
	return sizeof(a) / sizeof(a[0]);
}

template <typename T, std::size_t N>
constexpr std::size_t countof(T const (&)[N])
{
	return N;
}

enum shader
{
	SHADER_VERT,
	SHADER_FRAG,
	SHADER_LAST = SHADER_FRAG
};

std::size_t ProgramNames[] =
{
	1,
	2
};

static_assert(countof(ProgramNames) == SHADER_LAST + 1, "GNI");

void AttachPipelinePrograms(std::size_t PipelineName, std::size_t const (&ProgramNames)[SHADER_LAST + 1])
{
	static std::size_t const ShaderBit[] = // Implicitly sized
	{
		1 << 0,	// STAGE_VERTEX
		1 << 1	// STAGE_FRAGMENT
	};

	std::size_t const Count = countof(ProgramNames);

	for(std::size_t i = 0; i < Count; ++i)
	{}
}

void test_countof()
{
	std::size_t * pointer = NULL;
	std::size_t const A = countof(ProgramNames);
	//std::size_t const B = countof(pointer);
	//std::size_t const B = countofB(pointer);
	//std::size_t const C = _countof(ShaderStage);
	//std::size_t const D = _countof(pointer);
}

#else

void test_countof()
{
}

#endif
