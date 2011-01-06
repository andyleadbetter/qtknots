/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the demonstration applications of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** No Commercial Usage
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions
** contained in the Technology Preview License Agreement accompanying
** this package.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
**
**
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "networkaccessmanager.h"

#include <QtCore/QSettings>

#include <QtGui/QDesktopServices>
#include <QtGui/QDialog>
#include <QtGui/QMessageBox>
#include <QtGui/QStyle>
#include <QtGui/QTextDocument>

#include <QtNetwork/QAuthenticator>
#include <QtNetwork/QNetworkDiskCache>
#include <QtNetwork/QNetworkProxy>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QSslError>
#include <QMutex>
#include <QMutexLocker>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QFileInfoList>

NetworkAccessManager::NetworkAccessManager(QObject *parent)
    : QNetworkAccessManager(parent),
    requestFinishedCount(0), requestFinishedFromCacheCount(0), requestFinishedPipelinedCount(0),
    requestFinishedSecureCount(0)
{
    QNetworkDiskCache *diskCache = new QNetworkDiskCache(this);
    QString location = QDesktopServices::storageLocation(QDesktopServices::CacheLocation);

    location += QString::number((int) this);

    connect(this, SIGNAL(finished(QNetworkReply*)),
            SLOT(requestFinished(QNetworkReply*)));
    diskCache->setCacheDirectory(location);
    setCache(diskCache);
}


bool NetworkAccessManager::removeCacheDirectory(const QString &dirName)
{
    bool result = true;
    QDir dir(dirName);

    if (dir.exists(dirName)) {
        Q_FOREACH(QFileInfo info, dir.entryInfoList(QDir::NoDotAndDotDot | QDir::System | QDir::Hidden  | QDir::AllDirs | QDir::Files, QDir::DirsFirst)) {
            if (info.isDir()) {
                result = removeCacheDirectory(info.absoluteFilePath());
            }
            else {
                result = QFile::remove(info.absoluteFilePath());
            }

            if (!result) {
                return result;
            }
        }
        result = dir.rmdir(dirName);
    }

    return result;

}

NetworkAccessManager::~NetworkAccessManager()
{
    QNetworkDiskCache* theCache  = static_cast<QNetworkDiskCache*>(cache());

    if( theCache )
    {
        theCache->clear();
        removeCacheDirectory(theCache->cacheDirectory());
    }
}

QNetworkReply* NetworkAccessManager::createRequest(Operation op, const QNetworkRequest & req, QIODevice * outgoingData)
{
    QMutex serializer;
    QMutexLocker locker(&serializer);

    QNetworkRequest request = req; // copy so we can modify
    // this is a temporary hack until we properly use the pipelining flags from QtWebkit
    // pipeline everything! :)
    qDebug() << request.url();
    request.setAttribute(QNetworkRequest::HttpPipeliningAllowedAttribute, true);
    request.setAttribute(QNetworkRequest::CacheLoadControlAttribute, QNetworkRequest::PreferCache);
    return QNetworkAccessManager::createRequest(op, request, outgoingData);
}

void NetworkAccessManager::requestFinished(QNetworkReply *reply)
{
    requestFinishedCount++;
    if (reply->attribute(QNetworkRequest::SourceIsFromCacheAttribute).toBool() == true)
        requestFinishedFromCacheCount++;

    if (reply->attribute(QNetworkRequest::HttpPipeliningWasUsedAttribute).toBool() == true)
        requestFinishedPipelinedCount++;

    if (reply->attribute(QNetworkRequest::ConnectionEncryptedAttribute).toBool() == true)
        requestFinishedSecureCount++;

    if (requestFinishedCount % 10)
        return;

    double pctCached = (double(requestFinishedFromCacheCount) * 100.0/ double(requestFinishedCount));
    double pctPipelined = (double(requestFinishedPipelinedCount) * 100.0/ double(requestFinishedCount));
    double pctSecure = (double(requestFinishedSecureCount) * 100.0/ double(requestFinishedCount));

    qDebug("STATS [%lli requests total] [%3.2f%% from cache] [%3.2f%% pipelined] [%3.2f%% SSL/TLS]", requestFinishedCount, pctCached, pctPipelined, pctSecure);

}

void NetworkAccessManager::loadSettings()
{
    QSettings settings;
    settings.beginGroup(QLatin1String("proxy"));
    QNetworkProxy proxy;
    if (settings.value(QLatin1String("enabled"), false).toBool()) {
        if (settings.value(QLatin1String("type"), 0).toInt() == 0)
            proxy = QNetworkProxy::Socks5Proxy;
        else
            proxy = QNetworkProxy::HttpProxy;
        proxy.setHostName(settings.value(QLatin1String("hostName")).toString());
        proxy.setPort(settings.value(QLatin1String("port"), 1080).toInt());
        proxy.setUser(settings.value(QLatin1String("userName")).toString());
        proxy.setPassword(settings.value(QLatin1String("password")).toString());
    }
    setProxy(proxy);
}

QNetworkAccessManager *MyQmlNetworkCache::create(QObject *parent)
{
    QNetworkAccessManager *nam = new NetworkAccessManager(parent);

    return nam;
}




