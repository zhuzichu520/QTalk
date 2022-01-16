#include "IControlCenter.h"

#include <QObject>

namespace IM
{

IControlCenter* IControlCenter::m_instance = nullptr;

IControlCenter::IControlCenter(QObject *parent) : QObject(parent)
{
	Q_ASSERT(m_instance == nullptr);
}

IControlCenter::~IControlCenter()= default;

IControlCenter* IControlCenter::instance()
{
	return m_instance;
}

}
