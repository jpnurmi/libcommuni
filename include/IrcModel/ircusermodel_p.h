/*
  Copyright (C) 2008-2020 The Communi Project

  You may use this file under the terms of BSD license as follows:

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the copyright holder nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR
  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef IRCUSERMODEL_P_H
#define IRCUSERMODEL_P_H

#include "ircuser.h"
#include "ircchannel_p.h"
#include "ircusermodel.h"
#include <qpointer.h>

IRC_BEGIN_NAMESPACE

class IrcUserModelPrivate
{
    Q_DECLARE_PUBLIC(IrcUserModel)

public:
    IrcUserModelPrivate();

    void addUser(IrcUser* user, bool notify = true);
    void insertUser(int index, IrcUser* user, bool notify = true);
    void removeUser(IrcUser* user, bool notify = true);
    void setUsers(const QList<IrcUser*>& users, bool reset = true);
    void renameUser(IrcUser* user);
    void setUserMode(IrcUser* user);
    void promoteUser(IrcUser* user);
    bool updateUser(IrcUser* user);
    bool updateTitles();

    static IrcUserModelPrivate* get(IrcUserModel* model)
    {
        return model->d_func();
    }

    IrcUserModel* q_ptr = nullptr;
    Irc::DataRole role = Irc::TitleRole;
    QStringList titles;
    QList<IrcUser*> userList;
    QPointer<IrcChannel> channel;
    Irc::SortMethod sortMethod = Irc::SortByHand;
    Qt::SortOrder sortOrder = Qt::AscendingOrder;
};

IRC_END_NAMESPACE

#endif // IRCUSERMODEL_P_H
