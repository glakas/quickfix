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
#pragma warning(disable : 4503 4355 4786)
#include "stdafx.h"
#else
#include "config.h"
#endif

#include <Utility.h>

#include "catch_amalgamated.hpp"

using namespace FIX;

TEST_CASE("FileUtilitiesTests") {
  SECTION("separator") {
#ifdef _MSC_VER
    CHECK("\\" == file_separator());
#else
    CHECK("/" == file_separator());
#endif
  }

  SECTION("appendpath") {
    CHECK(("path" + file_separator() + "file") == file_appendpath("path", "file"));
    CHECK("path/file" == file_appendpath("path/", "file"));
    CHECK("path\\file" == file_appendpath("path\\", "file"));
  }
}
