#include "factory.h"
#include "beep.h"
#include "blink.h"
#include "console.h"
#include "disk.h"

factory::factory()
{
	switchOutput = nullptr;
	orders = " ";
}

factory::factory(factory & copy)
{
	orders = copy.orders;
	switchOutput = copy.switchOutput;
}


factory::~factory()
{
}

void factory::convert(std::string txtToConvert) const
{
	switchOutput->convert(txtToConvert);
}

void factory::convert(int integerToConvert) const
{
	switchOutput->convert(integerToConvert);
}

void factory::convert(double doubleToConvert) const
{
	switchOutput->convert(doubleToConvert);
}

void factory::setExternalInfo(std::string prodOrders)
{
	orders = prodOrders;
}

void factory::setOutput(int switcher)
{
	switch (switcher)
	{
	case 1:
		switchOutput = new beeper::beep(orders);
		break;
	case 2:
		switchOutput = new blinker::blink(orders);
		break;
	case 3:
		switchOutput = new consoler::console(orders);
		break;
	case 4:
		switchOutput = new filer::disk(orders);
		break;
	default:
		break;
	}
}

morse * factory::getAcctualMachine()
{
	return switchOutput;
}

std::string factory::getAcctualOrders()
{
	return orders;
}
