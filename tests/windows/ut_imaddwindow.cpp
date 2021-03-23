/*
* Copyright (C) 2021 ~ 2021 Deepin Technology Co., Ltd.
*
* Author:     chenshijie <chenshijie@uniontech.com>
*
* Maintainer: chenshijie <chenshijie@uniontech.com>
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

#include <iostream>
#include "gtest/gtest.h"
#include "window/imaddwindow.h"
class ut_imaddwindow : public ::testing::Test
{
protected:
    ut_imaddwindow()
    {
    }

    virtual ~ut_imaddwindow()
    {
    }

    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
    }
};

TEST_F(ut_imaddwindow, updateUI)
{
    IMAddWindow iMAddWindow;
    iMAddWindow.updateUI();
    EXPECT_TRUE(true);
}

TEST_F(ut_imaddwindow, initUI)
{
    IMAddWindow iMAddWindow;
    iMAddWindow.initUI();
}

TEST_F(ut_imaddwindow, initConnect)
{
    IMAddWindow iMAddWindow;
    iMAddWindow.initConnect();
}

TEST_F(ut_imaddwindow, onAddIM)
{
    IMAddWindow iMAddWindow;
    iMAddWindow.onAddIM();
}

TEST_F(ut_imaddwindow, onOpenStore)
{
    IMAddWindow iMAddWindow;
    iMAddWindow.onOpenStore();
}
