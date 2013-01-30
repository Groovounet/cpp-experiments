#include "test_template_template.hpp"

template <typename genType>
class surface
{
	
};

template
<
	typename genType,
	template <typename> class surfaceType
>
class mipmap
{
	surfaceType<genType> Surface;
};

template
<
	typename genType, 
	template <typename> class surfaceType
>
class imageA 
{
	mipmap<genType, surfaceType> Mipmaps;
};

template
<
	typename genType, 
	typename surfaceType = surface<genType>
>
class imageB
{
//	mipmap<genType, surfaceType> Mipmaps;
};

template <template<typename> class C>
void f(C<int> const & Ref)
{

};

template
<
	typename genType, 
	template <typename> class surfaceType = surface
>
class imageC
{
	mipmap<genType, surfaceType> Mipmaps;
};

void test_template_template()
{
	imageA<int, surface> Image;

	imageB<int, surface<int> > ImageB;

	int Value = 76;
	surface<int> Surface;

	imageC<int, surface> ImageC;

	f(Surface);
}
