/* Webcamoid, webcam capture application.
 * Copyright (C) 2018  Gonzalo Exequiel Pedone
 *
 * Webcamoid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Webcamoid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Webcamoid. If not, see <http://www.gnu.org/licenses/>.
 *
 * Web-Site: http://webcamoid.github.io/
 */

#ifndef CAPTUREMMF_H
#define CAPTUREMMF_H

#include <QAbstractNativeEventFilter>

#include "capture.h"

class CaptureMMFPrivate;

class CaptureMMF:
        public Capture,
        public QAbstractNativeEventFilter
{
    Q_OBJECT

    public:
        enum IoMethod
        {
            IoMethodUnknown = -1,
            IoMethodSync,
            IoMethodASync
        };

        explicit CaptureMMF(QObject *parent=nullptr);
        ~CaptureMMF();

        Q_INVOKABLE QStringList webcams() const;
        Q_INVOKABLE QString device() const;
        Q_INVOKABLE QList<int> streams();
        Q_INVOKABLE QList<int> listTracks(const QString &mimeType);
        Q_INVOKABLE QString ioMethod() const;
        Q_INVOKABLE int nBuffers() const;
        Q_INVOKABLE QString description(const QString &webcam) const;
        Q_INVOKABLE QVariantList caps(const QString &webcam) const;
        Q_INVOKABLE QString capsDescription(const AkCaps &caps) const;
        Q_INVOKABLE QVariantList imageControls() const;
        Q_INVOKABLE bool setImageControls(const QVariantMap &imageControls);
        Q_INVOKABLE bool resetImageControls();
        Q_INVOKABLE QVariantList cameraControls() const;
        Q_INVOKABLE bool setCameraControls(const QVariantMap &cameraControls);
        Q_INVOKABLE bool resetCameraControls();
        Q_INVOKABLE AkPacket readFrame();

        bool nativeEventFilter(const QByteArray &eventType,
                               void *message,
                               long *result);

    private:
        CaptureMMFPrivate *d;

    public slots:
        bool init();
        void uninit();
        void setDevice(const QString &device);
        void setStreams(const QList<int> &streams);
        void setIoMethod(const QString &ioMethod);
        void setNBuffers(int nBuffers);
        void resetDevice();
        void resetStreams();
        void resetIoMethod();
        void resetNBuffers();
        void reset();
};

#endif // CAPTUREMMF_H
