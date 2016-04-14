/****************************************************************************
** Copyright (c) 2001-2014
**
** This file is part of the QuickFIX FIX Engine
**
** This file may be distributed under the terms of the quickfixengine.org
** license as defined by quickfixengine.org and appearing in the file
** LICENSE included in the packaging of this file.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** See http://www.quickfixengine.org/LICENSE for licensing information.
**
** Contact ask@quickfixengine.org if any conditions of this licensing are
** not clear to you.
**
****************************************************************************/

#ifdef _MSC_VER
#pragma warning( disable : 4503 4355 4786 )
#else

#include "config.h"

#endif

#include "quickfix/FileStore.h"
#include "quickfix/ThreadedSocketAcceptor.h"
#include "Application.h"

#include "ExecutorConfig.h"

void wait() {
    std::cout << "Type Ctrl-C to quit" << std::endl;
    while (true) {
        FIX::process_sleep(1);
    }
}

int main(int argc, char **argv) {
    std::cout << "Executor v." << int(Executor_VERSION_MAJOR) << "." << int(Executor_VERSION_MINOR) << std::endl;
    if (argc != 2) {
        std::cout << "Usage: " << argv[0]
        << " FILE." << std::endl;
        return 0;
    }
    std::string file = argv[1];

    try {
        FIX::SessionSettings settings(file);

        Application application;
        FIX::FileStoreFactory storeFactory(settings);
        FIX::ScreenLogFactory logFactory(settings);
        FIX::ThreadedSocketAcceptor acceptor(application, storeFactory, settings, logFactory);

        acceptor.start();
        wait();
        acceptor.stop();
        return 0;
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
        return 1;
    }
}
