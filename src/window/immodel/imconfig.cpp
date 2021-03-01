/*
* Copyright (C) 2021 ~ 2021 Deepin Technology Co., Ltd.
*
* Author:     liuwenhao <liuwenhao@uniontech.com>
*
* Maintainer: liuwenhao <liuwenhao@uniontech.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "imconfig.h"
#include "publisher/publisherfunc.h"
#include <fcitxqtinputmethoditem.h>
QString IMConfig::prefix {QDir::homePath()};

QString IMConfig::defaultIM()
{
    return configFile(prefix + "/.config/fcitx/conf/fcitx-defaultim.config", QString("IMNAME"));
}

bool IMConfig::setDefaultIM(const QString &str)
{
    return setConfigFile(prefix + "/.config/fcitx/conf/fcitx-defaultim.config", "IMNAME", str);
}

QString IMConfig::IMSwitchKey()
{
    return configFile(prefix + "/.config/fcitx/config", QString("IMSwitchHotkey"));
}

bool IMConfig::setIMSwitchKey(const QString &str)
{
    return setConfigFile(prefix + "/.config/fcitx/config", "IMSwitchHotkey", str);
}

QString IMConfig::virtualKey()
{
    return configFile(prefix + "/.config/fcitx/conf/fcitx-onboard.config", QString("HOTKEY"));
}

bool IMConfig::setVirtualKey(const QString &str)
{
    return setConfigFile(prefix + "/.config/fcitx/conf/fcitx-onboard.config", "HOTKEY", str);
}

QString IMConfig::defaultIMKey()
{
    return configFile(prefix + "/.config/fcitx/conf/fcitx-defaultim.config", QString("HOTKEY"));
}

bool IMConfig::setDefaultIMKey(const QString &str)
{
    return setConfigFile(prefix + "/.config/fcitx/conf/fcitx-defaultim.config", "HOTKEY", str);
}

QString IMConfig::IMPluginKey(const QString &str)
{
    return configFile(prefix + "/.config/fcitx/conf/fcitx-implugin.config", str, QString("Setting"));
}

bool IMConfig::checkShortKey(const QStringList &str)
{
    Q_UNUSED(str)
    return true;
}

QString IMConfig::configFile(const QString &filePath, const QString &group, const QString &key)
{
    QString read = publisherFunc::readFile(filePath);
    if (read.isEmpty() || key.isEmpty())
        return QString();

    bool lock = false;
    foreach (QString str, read.split("\n")) {
        if (!lock && str.indexOf(group) != -1) {
            lock = true;
        }
        if (lock && str.indexOf(key) != -1) {
            auto list = str.split("=");

            if (list[0].compare(key) != 0 && list[0].compare('#' + key) != 0) {
                continue;
            }

            if (list.count() != 2) {
                return QString();
            } else {
                return list[1];
            }
        }
    }
    return QString();
}

QString IMConfig::configFile(const QString &filePath, const QString &key)
{
    QString read = publisherFunc::readFile(filePath);
    if (read.isEmpty() || key.isEmpty())
        return QString();

    foreach (QString str, read.split("\n")) {
        if (str.indexOf(key) != -1) {
            auto list = str.split("=");
            if (list.count() != 2) {
                return QString();
            } else {
                return list[1];
            }
        }
    }
    return QString();
}

bool IMConfig::setConfigFile(const QString &filePath, const QString &key, const QString &value)
{
    QString read = publisherFunc::readFile(filePath);
    if (read.isEmpty() || key.isEmpty() || value.isEmpty())
        return false;

    QString file;
    foreach (QString tmp, read.split("\n")) {
        if (tmp.indexOf(key) != -1) {
            file += QString(key + "=" + value + "\n");
        } else {
            if (!tmp.isEmpty())
                file += tmp + "\n";
        }
    }
    file = file + "\n";
    if (file.isEmpty())
        return false;
    else {
        return publisherFunc::createFile(filePath, file);
    }
}
