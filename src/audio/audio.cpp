/***************************************************************************
 *   Copyright (C) 2009 by The qGo Project                                 *
 *                                                                         *
 *   This file is part of qGo.   					   *
 *                                                                         *
 *   qGo is free software: you can redistribute it and/or modify           *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, see <http://www.gnu.org/licenses/>   *
 *   or write to the Free Software Foundation, Inc.,                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/


#include "audio/audio.h"
#include <QDir>
#include <defines.h>
#include <QtMultimedia/QMediaPlayer>

Sound::Sound(const QString &filename, QObject *parent, int delay_msec)
    : QObject(parent), delay(delay_msec)
{
    player = new QMediaPlayer;
    if (QDir().exists(SOUND_PATH_PREFIX + filename))
        player->setSource(QUrl::fromLocalFile(QDir().absoluteFilePath(SOUND_PATH_PREFIX + filename)));
    nextSound = QTime::currentTime();
}

Sound::~Sound()
{
    delete player;
}

void Sound::play(void)
{
    // Do not play the same sound too often (by default every 250 ms)
    if (QTime::currentTime() < nextSound)
        return;

    nextSound = QTime::currentTime();
    nextSound = nextSound.addMSecs(delay);
    player->play();
}
