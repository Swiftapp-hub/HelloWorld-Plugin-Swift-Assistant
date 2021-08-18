/* Swift Assistant is a simple, user-friendly assistant based on an extension system.

   Copyright (C) <2021>  <SwiftApp>

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>. */

#include "helloworldplugin.h"

#include <QFile>
#include <QLocale>

QString HelloWorldPlugin::getDataXml()
{
    QString locale = QLocale::system().name().section('_', 0, 0);
    QFile file(":/XML/HelloWorldData_"+locale+".xml");
    if (!file.exists()) {
        file.setFileName(":/XML/HelloWorldData_en.xml");
    }
    file.open(QIODevice::ReadOnly);

    return file.readAll();
}

QString HelloWorldPlugin::pluginIid()
{
    return "fr.swift.helloworld";
}

QList<QString> HelloWorldPlugin::getCommande()
{
    QList<QString> list;
    QString locale = QLocale::system().name().section('_', 0, 0);

    if (locale == "fr") {
        list << "Comment ça va ?";
        list << "Salut" << "Bonjour" << "Coucou";
        list << "Je vais bien" << "Je me sens bien";
        list << "Comment tu t'appelles ?" << "Quel est ton nom ?";
        list << "Comment je m'appelle ?" << "Quel est mon nom ?";
        list << "Dis moi une blague" << "Connais tu une blague?";
        list << "Ton nom est Swift Assistant" << "Peut on changer ton nom ?";
    }
    else {
        list << "How are you ?";
        list << "Hello" << "Hi";
        list << "I'm fine" << "I feel good";
        list << "What's your name?";
        list << "What is my name?";
        list << "Tell me a joke" << "Do you know a joke?";
        list << "Your name is Swift Assistant" << "Can we change your name?";
    }

    return list;
}

void HelloWorldPlugin::execAction(QList<QString>) {}

void HelloWorldPlugin::messageReceived(QString, QString) {}
