#include "controlcenter.h"

#include <QObject>

namespace IPConnect
{

ControlCenter* ControlCenter::m_instance = nullptr;

ControlCenter::ControlCenter(QObject* parent) : IControlCenter(parent){}

ControlCenter::~ControlCenter()
{

}

ControlCenter* ControlCenter::instance()
{
	return m_instance;
}

void ControlCenter::init()
{
	m_instance = new ControlCenter();
}

}
