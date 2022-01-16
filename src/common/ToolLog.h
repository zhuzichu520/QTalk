#ifndef TOOLLOG_H
#define TOOLLOG_H

#define LOGD(data) DLOG(INFO)<<ToolLog::toStdString(data)
#define LOGI(data) LOG(INFO)<<ToolLog::toStdString(data)
#define LOGW(data) LOG(WARNING)<<ToolLog::toStdString(data)
#define LOGE(data) LOG(ERROR)<<ToolLog::toStdString(data)

#include "glog/logging.h"
#include <QObject>
#include <QStandardPaths>
#include <QDir>
#include <QDebug>

class ToolLog {
public:
    ToolLog(char* argv[]);
    ~ToolLog();
    static std::string toStdString(const QString &data){
        return data.toLocal8Bit().toStdString();
    }
private:
    void configureGoogleLog();
    static void messageHandler(QtMsgType, const QMessageLogContext& context, const QString& message);
};


#endif
