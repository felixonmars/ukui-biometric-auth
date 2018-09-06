#include "biotypes.h"
#include <QDBusInterface>

QStringList bioTypeStrings = QStringList{QObject::tr("FingerPrint"),
                          QObject::tr("FingerVein"),
                          QObject::tr("Iris"),
                          QObject::tr("Face"),
                          QObject::tr("VoicePrint")};

QDBusArgument &operator<<(QDBusArgument &argument, const DeviceInfo &deviceInfo)
{
    argument.beginStructure();
    argument << deviceInfo.device_id << deviceInfo.device_shortname
        << deviceInfo.device_fullname << deviceInfo.driver_enable
        << deviceInfo.device_available
        << deviceInfo.biotype << deviceInfo.stotype
        << deviceInfo.eigtype << deviceInfo.vertype
        << deviceInfo.idtype << deviceInfo.bustype
        << deviceInfo.dev_status << deviceInfo.ops_status;
    argument.endStructure();
    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, DeviceInfo &deviceInfo)
{
    argument.beginStructure();
    argument >> deviceInfo.device_id >> deviceInfo.device_shortname
        >> deviceInfo.device_fullname >> deviceInfo.driver_enable
        >> deviceInfo.device_available
        >> deviceInfo.biotype >> deviceInfo.stotype
        >> deviceInfo.eigtype >> deviceInfo.vertype
        >> deviceInfo.idtype >> deviceInfo.bustype
        >> deviceInfo.dev_status >> deviceInfo.ops_status;
    argument.endStructure();
    return argument;
}

bool DeviceInfo::operator==(const DeviceInfo& deviceInfo) const
{
    if(this->device_shortname == deviceInfo.device_shortname &&
       this->device_available == deviceInfo.device_available)
        return true;
    return false;
}

QDebug& operator<<(QDebug &stream, const DeviceInfo &deviceInfo)
{
    stream << deviceInfo.device_id << deviceInfo.device_shortname
           << deviceInfo.biotype << deviceInfo.device_available;
    return stream;
}
