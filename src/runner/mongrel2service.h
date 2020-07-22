/*
 * Copyright (C) 2016-2020 Fanout, Inc.
 *
 * This file is part of Pushpin.
 *
 * $FANOUT_BEGIN_LICENSE:AGPL$
 *
 * Pushpin is free software: you can redistribute it and/or modify it under
 * the terms of the GNU Affero General Public License as published by the Free
 * Software Foundation, either version 3 of the License, or (at your option)
 * any later version.
 *
 * Pushpin is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for
 * more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 * Alternatively, Pushpin may be used under the terms of a commercial license,
 * where the commercial license agreement is provided with the software or
 * contained in a written agreement between you and Fanout. For further
 * information use the contact form at <https://fanout.io/enterprise/>.
 *
 * $FANOUT_END_LICENSE$
 */

#ifndef MONGREL2SERVICE_H
#define MONGREL2SERVICE_H

#include "service.h"
#include "listenport.h"

class Mongrel2Service : public Service
{
	Q_OBJECT

public:
	Mongrel2Service(
		const QString &binFile,
		const QString &configFile,
		const QString &serverName,
		const QString &runDir,
		const QString &logDir,
		const QString &filePrefix,
		int port,
		bool ssl,
		int logLevel,
		QObject *parent = 0);

	static bool generateConfigFile(const QString &m2shBinFile, const QString &configTemplateFile, const QString &runDir, const QString &logDir, const QString &ipcPrefix, const QString &filePrefix, const QString &certsDir, int clientBufferSize, int maxconn, const QList<ListenPort> &ports, int logLevel);

	// reimplemented

	virtual QStringList arguments() const;
	virtual bool acceptSighup() const;
	virtual QString formatLogLine(const QString &line) const;

private:
	QStringList args_;
	QString prefix_;
	int logLevel_;

	QString filterLogLine(int, const QString&) const;
};

#endif
