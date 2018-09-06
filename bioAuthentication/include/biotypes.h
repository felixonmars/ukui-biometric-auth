#ifndef BIOCUSTOMTYPE_H
#define BIOCUSTOMTYPE_H

#include <QObject>
#include <QtDBus>

#define BIO_DBUS_SERVICE "org.ukui.Biometric"
#define BIO_DBUS_PATH "/org/ukui/Biometric"
#define BIO_DBUS_INTERFACE "org.ukui.Biometric"

#define BIOMETRIC_PAM       "BIOMETRIC_PAM"
#define BIOMETRIC_IGNORE    "BIOMETRIC_IGNORE"
#define BIOMETRIC_SUCESS    "BIOMETRIC_SUCCESS"


#ifdef LOG
#undef LOG
#endif
#define LOG() qDebug() << "[BIOMETRIC]"

extern QStringList bioTypeStrings;

/* the type of device */
enum BioType {
    BIOTYPE_FINGERPRINT,
    BIOTYPE_FINGERVEIN,
    BIOTYPE_IRIS,
    BIOTYPE_FACE,
    BIOTYPE_VOICEPRINT,
    __MAX_NR_BIOTYPES
};

/* StatusChanged D-Bus 信号触发时的状态变化类型 */
enum StatusType {
    STATUS_DEVICE,
    STATUS_OPERATION,
    STATUS_NOTIFY
};

/* 录入/删除/搜索等 D-Bus 调用的最终结果，即返回值里的 result */
enum DBusResult {
    DBUS_RESULT_SUCCESS = 0,
    DBUS_RESULT_ERROR,
    DBUS_RESULT_DEVICEBUSY,
    DBUS_RESULT_NOSUCHDEVICE,
    DBUS_RESULT_PERMISSIONDENIED
};


/* the info of device */
struct DeviceInfo {
    int device_id;
    QString device_shortname; /* aka driverName */
    QString device_fullname;
    int driver_enable; /* The corresponding driver is enabled/disabled */
    int device_available; /* The driver is enabled and the device is connected */
    int biotype;
    int stotype;
    int eigtype;
    int vertype;
    int idtype;
    int bustype;
    int dev_status;
    int ops_status;

    bool operator==(const DeviceInfo&) const;

    bool operator !=(const DeviceInfo &deviceInfo) const
    {
        return !(*this == deviceInfo);
    }
    friend QDebug& operator<<(QDebug &stream, const DeviceInfo &deviceInfo);

};
Q_DECLARE_METATYPE(DeviceInfo)

QDBusArgument &operator<<(QDBusArgument &argument, const DeviceInfo &deviceInfo);
const QDBusArgument &operator>>(const QDBusArgument &argument, DeviceInfo &deviceInfo);



#endif // BIOCUSTOMTYPE_H
