#ifndef StatDatagramH
#define StatDatagramH
// =============================================================================
// wolf-stat-client
// -----------------------------------------------------------------------------
//    Copyright (C) 2019      Petr Kulhanek, kulhanek@chemi.muni.cz
//
//     This program is free software; you can redistribute it and/or modify
//     it under the terms of the GNU General Public License as published by
//     the Free Software Foundation; either version 2 of the License, or
//     (at your option) any later version.
//
//     This program is distributed in the hope that it will be useful,
//     but WITHOUT ANY WARRANTY; without even the implied warranty of
//     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//     GNU General Public License for more details.
//
//     You should have received a copy of the GNU General Public License along
//     with this program; if not, write to the Free Software Foundation, Inc.,
//     51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
// =============================================================================

#include <SmallString.hpp>
#include <ostream>

// -----------------------------------------------------------------------------

#define HEADER_SIZE 4
#define NAME_SIZE   64
#define MAX_TTYS    12

// -----------------------------------------------------------------------------

class CStatDatagram {
public:
    CStatDatagram(void);

// setters ---------------------------------------------------------------------
    void SetDatagram(void);

// getters ---------------------------------------------------------------------
    CSmallString GetShortNodeName(void);
    CSmallString GetNodeName(void);
    CSmallString GetLocalUserName(void);
    CSmallString GetLocalLoginName(void);
    CSmallString GetLocalUserName(int id);
    CSmallString GetLocalLoginName(int id);
    CSmallString GetXUserName(int id);
    CSmallString GetXLoginName(int id);
    int          GetTimeStamp(void);
    void         PrintInfo(std::ostream& vout);
    bool         IsValid(void);

// private data ----------------------------------------------------------------
private:
    char    Header[HEADER_SIZE];
    char    NodeName[NAME_SIZE];
    char    LocalUserName[MAX_TTYS][NAME_SIZE];
    char    LocalLoginName[MAX_TTYS][NAME_SIZE];
    int     ActiveTTY;                      // active tty
    int     NumOfIUsers;                    // number of interactive user sessions
    int     NumOfAUsers;                    // number of all sessions
    char    XUserName[MAX_TTYS][NAME_SIZE];
    char    XLoginName[MAX_TTYS][NAME_SIZE];
    int     NumOfXUsers;                    // number of X user sessions
    int     TimeStamp;                      // time of "meassurement"
    int     CheckSum;

    friend class CFCGIStatServer;
};

// -----------------------------------------------------------------------------

#endif
