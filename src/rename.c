/*
     This file is part of PlibC.
     (C) 2005 Nils Durner (and other contributing authors)

	   This library is free software; you can redistribute it and/or
	   modify it under the terms of the GNU Lesser General Public
	   License as published by the Free Software Foundation; either
	   version 2.1 of the License, or (at your option) any later version.
	
	   This library is distributed in the hope that it will be useful,
	   but WITHOUT ANY WARRANTY; without even the implied warranty of
	   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
	   Lesser General Public License for more details.
	
	   You should have received a copy of the GNU Lesser General Public
	   License along with this library; if not, write to the Free Software
	   Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

/**
 * @file src/rename.c
 * @brief rename()
 */

#include "plibc_private.h"

/**
 * @brief Rename a file
 *        If oldname is a link, the link itself is renamed
 */
int _win_rename(const char *oldname, const char *newname)
{
  char szOldName[_MAX_PATH + 1];
  char szNewName[_MAX_PATH + 1];
  long lRet;

  if ((lRet = plibc_conv_to_win_path_ex(oldname, szOldName, 0)) != ERROR_SUCCESS)
  {
    SetErrnoFromWinError(lRet);
    return -1;
  }

  if ((lRet = plibc_conv_to_win_path_ex(newname, szNewName, 0)) != ERROR_SUCCESS)
  {
    SetErrnoFromWinError(lRet);
    return -1;
  }

  /* rename sets errno */
  return rename(szOldName, szNewName);
}

/* end of rename.c */
