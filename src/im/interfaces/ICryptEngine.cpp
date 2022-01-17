#include "ICryptEngine.h"

#include <QObject>

namespace IM
{

ICryptEngine::ICryptEngine(QObject* parent) : QObject(parent)
{
}

ICryptEngine::~ICryptEngine()
{
}

}
