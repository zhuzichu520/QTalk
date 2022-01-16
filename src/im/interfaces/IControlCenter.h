#ifndef ICONTROLCENTER_H
#define ICONTROLCENTER_H

#include <QObject>
#include "IServer.h"

namespace IM
{

class IControlCenter : public QObject
{
	Q_OBJECT

public:

	static IControlCenter* instance();

    virtual IServer* messageServer() = 0;

protected:

	static IControlCenter* m_instance;


	explicit IControlCenter(QObject* parent = nullptr);


	~IControlCenter() override;

};

}

#endif
