#include "Factory/AbstractFactory.h"

AbstractFactory::AbstractFactory() {}

AbstractFactory::~AbstractFactory() {}

AbstractFactory::AbstractFactory(const AbstractFactory &other) : AbstractFactory(other) {}

AbstractFactory &AbstractFactory::operator=(const AbstractFactory &rhs)
{
    return *this;
}