#include "test_function_template_parameter.hpp"

template <typename T>
class templateParameterClass
{

};

template <template<typename> class C>
static void functionWithTemplateParameter
(
	C<int> const & TemplateParameter
)
{

};

void test_function_template_parameter()
{
	templateParameterClass<int> TemplateParameterClass;

	functionWithTemplateParameter(TemplateParameterClass);
	int Value = 76;
	//functionWithTemplateParameter(Value);
}
