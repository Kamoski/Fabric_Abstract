#include "factory.h"

int main()
{
	factory f;
	f.setExternalInfo("200 200 400");
	f.setOutput(factory::console);
	f.convert("Ala ma kota");
	f.setOutput(factory::disk);
	f.convert("a pies");
	f.convert(123);
	f.convert(1.23);
	
	return 0;
}