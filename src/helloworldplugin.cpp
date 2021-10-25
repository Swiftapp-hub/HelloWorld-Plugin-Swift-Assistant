/* Swifty Assistant is a simple, user-friendly assistant based on an extension system.

   Copyright (C) <2021>  <SwiftyApp>

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

/**
 * Return the keywords with the answers that match in xml format
 *
 * @return the keywords in xml format
 */
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

/**
 * Returns the unique identifier of the plugin
 *
 * @return the id
 */
QString HelloWorldPlugin::pluginId()
{
    return "fr.swifty.helloworld";
}

/**
 * Returns a list of proposals related to the plugin
 *
 * @return the list of proposals
 */
QList<QString> HelloWorldPlugin::getCommande()
{
    QList<QString> list;
    QString locale = QLocale::system().name().section('_', 0, 0);

    if (locale == "fr") {
        list << "Comment ça va ?";
        list << "Salut" << "Bonjour" << "Coucou" << "👋";
        list << "Je vais bien" << "Je me sens bien";
        list << "Je me sens mal" << "Je vais pas bien";
        list << "Comment tu t'appelles ?" << "Quel est ton nom ?";
        list << "Comment je m'appelle ?" << "Quel est mon nom ?";
        list << "Dis moi une blague" << "Connais tu une blague?";
        list << "Ton nom est Swifty Assistant" << "Peut on changer ton nom ?";
    }
    else {
        list << "How are you ?";
        list << "Hello" << "Hi";
        list << "I'm fine" << "I feel good";
        list << "I feel bad" << "I am not well";
        list << "What's your name?";
        list << "What is my name?";
        list << "Tell me a joke" << "Do you know a joke?";
        list << "Your name is Swifty Assistant" << "Can we change your name?";
    }

    return list;
}

/**
 * Called when a special action is defined in the xml
 */
void HelloWorldPlugin::execAction(QList<QString>) {}

/**
 * Called when a custom interface is displayed and sends a message
 */
void HelloWorldPlugin::messageReceived(QString, QString) {}
