/* Spamtify - mIRC.cc
 * Copyright (C) 2013 Juan Baez
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *  
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details. 
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#include "Spamtify/Pre.h"


std::string SpotifyGetCurrentTrack()
{
  HWND hWnd = FindWindow(L"SpotifyMainWindow", NULL);

  if (!hWnd) 
    return std::string("Spotify not found...");

  wchar_t buffer[10240] = {0};
  
  if (GetWindowText(hWnd, buffer, 1024) > 0) {
    std::wstring wstr_title(buffer, 1024);

    return std::string(wstr_title.begin(), wstr_title.end());
  }
  return std::string("Le Error");
}


int __stdcall SpamtifyGetCurrentTrack(HWND mWnd, HWND aWnd, char *data, char *parms, BOOL show, BOOL nopause)
{
  std::string str_title = SpotifyGetCurrentTrack();

  std::strcpy(data, str_title.c_str());

  return 3;
}

// EOF

