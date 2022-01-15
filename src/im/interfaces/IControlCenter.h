#ifndef ICONTROLCENTER_H
#define ICONTROLCENTER_H

#include <QObject>

namespace IPConnect
{


class IControlCenter : public QObject
{
	Q_OBJECT

public:

	static IControlCenter* instance();

protected:

	static IControlCenter* m_instance;


	explicit IControlCenter(QObject* parent = nullptr);


	~IControlCenter();

};

}

#endif
